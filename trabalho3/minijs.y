%{
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int linha = 1, coluna = 1; 

struct Atributos {
  vector<string> c; // Código
  int linha = 0, coluna = 0;
  void clear() {
    c.clear();
    linha = 0;
    coluna = 0;
  }
};

#define YYSTYPE Atributos

enum TipoDecl { DeclVar, DeclConst, DeclLet };

struct Var {
  int linha, coluna;
  TipoDecl tipo;
};

map<string,Var> ts; // Tabela de Símbolos

// Dispara um erro se não pode declarar
void insere_tabela_de_simbolos( TipoDecl, Atributos );

extern "C" int yylex();
int yyparse();
void yyerror(const char *);

vector<string> concatena( vector<string> a, vector<string> b ) {
  a.insert( a.end(), b.begin(), b.end() );
  return a;
}

vector<string> operator+( vector<string> a, vector<string> b ) {
  return concatena( a, b );
}

vector<string> operator+( vector<string> a, string b ) {
  a.push_back( b );
  return a;
}

vector<string> operator+( string a, vector<string> b ) {
  return vector<string>{ a } + b;
}

vector<string> resolve_enderecos( vector<string> entrada ) {
  map<string,int> label;
  vector<string> saida;
  for( int i = 0; i < entrada.size(); i++ ) 
    if( entrada[i][0] == ':' ) 
        label[entrada[i].substr(1)] = saida.size();
    else
      saida.push_back( entrada[i] );
  
  for( int i = 0; i < saida.size(); i++ ) 
    if( label.count( saida[i] ) > 0 )
        saida[i] = to_string(label[saida[i]]);
    
  return saida;
}

string gera_label( string prefixo ) {
  static int n = 0;
  return prefixo + "_" + to_string( ++n ) + ":";
}

void print( vector<string> codigo ) {
  for( string s : codigo )
    cout << s << " ";
    
  cout << endl;  
}

%}

%token ID IF ELSE LET 
%token CDOUBLE CSTRING CINT
%token AND OR ME_IG MA_IG DIF IGUAL
%token MAIS_IGUAL MAIS_MAIS

%nonassoc '<' '>'

%%

S : CMDs { print( resolve_enderecos( $1.c ) ); }
  ; 

CMDs : CMDs CMD {$$.c = $1.c + $2.c;}
     | CMD
     ;

CMD : DECL_LET
    | CMD_IF 
    ;

DECL_LET : LET LET_IDs ';' { $$.c = $2.c; }
         ;
         
LET_IDs : LET_ID ',' LET_IDs { $$.c = $1.c + $3.c; }
        | LET_ID
        ;

CMD_IF : IF '(' E ')' CMD ELSE CMD
       ;

LET_ID : ID   
         { $$.c = $1.c + "&"; }
       | ID '=' CDOUBLE
         { $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; }
       ;

E : E '<' E
  | E '>' E
  | ID
  | CDOUBLE
  | CINT
  ;

%%

#include "lex.yy.c"

void yyerror( const char* st ) {
   puts( st ); 
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();
  
  return 0;
}