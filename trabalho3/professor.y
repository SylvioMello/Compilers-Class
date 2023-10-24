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
extern "C" FILE *yyin;
int yylex();
int yyparse();
void yyerror(const char *);

enum TipoDecl { DeclVar, DeclConst, DeclLet };

struct Var {
  int linha, coluna;
  TipoDecl tipo;
};

map<string,Var> ts; // Tabela de Símbolos

// Dispara um erro se não pode declarar
void insere_tabela_de_simbolos( TipoDecl, Atributos );

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

%token ID IF ELSE LET OBJ ARRAY FOR
%token CDOUBLE CSTRING CINT
%token AND OR ME_IG MA_IG DIF IGUAL
%token MAIS_IGUAL MAIS_MAIS PRINT

%right '=' MAIS_IGUAL
%left AND OR
%left MA_IG ME_IG IGUAL DIF
%nonassoc '<' '>' IF ELSE
%left '+' '-'
%left '*' '/' '%'

%left '['
%left '.'

%%

S : CMDs { print( resolve_enderecos( $1.c  + ".") ); }
  ;

CMDs : CMDs CMD {$$.c = $1.c + $2.c;}
     | CMD
     ;

CMD : CMD_LET ';'
    | CMD_FOR
    | CMD_IF
    | PRINT E ';'
      { $$.c = $2.c + "println" + "#"; }
    | '{' CMD_LIST '}' { $$.c = $2.c; }
    | E ';'
      {$$.c = $1.c + "^";}
    ;

CMD_LIST : CMD
         | CMD_LIST CMD     { $$.c = $1.c + $2.c; }
	 ;

CMD_FOR : FOR '(' PRIM_E ';' E ';' E ')' CMD
        { string lbl_fim_for = gera_label( "fim_for" );
          string lbl_condicao_for = gera_label( "condicao_for" );
          string lbl_comando_for = gera_label( "comando_for" );
          string definicao_lbl_fim_for = ":" + lbl_fim_for;
          string definicao_lbl_condicao_for = ":" + lbl_condicao_for;
          string definicao_lbl_comando_for = ":" + lbl_comando_for;

          $$.c = $3.c + definicao_lbl_condicao_for +
                 $5.c + lbl_comando_for + "?" + lbl_fim_for + "#" +
                 definicao_lbl_comando_for + $9.c +
                 $7.c + "^" + lbl_condicao_for + "#" +
                 definicao_lbl_fim_for;
        }
        ;

PRIM_E : CMD_LET
       | E
         { $$.c = $1.c + "^"; }
       ;

CMD_IF : IF '(' E ')' CMD
        {   string lbl_fim_if = gera_label( "lbl_fim_if" );
          $$.c = $3.c + "!" + lbl_fim_if + "?" +
                 $5.c + (":" + lbl_fim_if);
        }
        | IF '(' E ')' CMD ELSE CMD
        {  string lbl_true = gera_label( "lbl_true" );
           string lbl_fim_if = gera_label( "lbl_fim_if" );
           string definicao_lbl_true = ":" + lbl_true;
           string definicao_lbl_fim_if = ":" + lbl_fim_if;

            $$.c = $3.c +                       // Codigo da expressão
                   lbl_true + "?" +             // Código do IF
                   $7.c + lbl_fim_if + "#" +    // Código do False
                   definicao_lbl_true + $5.c +  // Código do True
                   definicao_lbl_fim_if         // Fim do IF
                   ;
         }
       ;

CMD_LET : LET VARs { $$.c = $2.c; }
        ;

VARs : VAR ',' VARs { $$.c = $1.c + $3.c; }
     | VAR
     ;

VAR : ID
      { $$.c = $1.c + "&"; }
    | ID '=' E
      { $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; }
    ;

E : LVALUE '=' E 
    { $$.c = $1.c + $3.c + "="; }
  | LVALUE '=' '{' '}'        
    { $$.c = $1.c + vector<string>{"{}"} + "="; } 
  | LVALUE MAIS_MAIS 
    { $$.c = $1.c + "@" +  $1.c + $1.c + "@" + vector<string>{"1"} + vector<string>{"+"} + vector<string>{"="} + "^"; }
  | LVALUE MAIS_IGUAL E     
    { $$.c = $1.c + $1.c + "@" + $3.c + "+" + "="; }  
  | LVALUEPROP '=' E 	
    { $$.c = $1.c + $3.c + "[=]"; }
  | LVALUEPROP '=' '{' '}'    
    { $$.c = $1.c + vector<string>{"{}"} + "[=]"; }
  | LVALUEPROP MAIS_IGUAL E
    { $$.c = $1.c + $1.c + "@" + $3.c + "+" + "[=]"; }
  | E ME_IG E   
    { $$.c = $1.c + $3.c + "<="; }
  | E MA_IG E   
    { $$.c = $1.c + $3.c + ">="; }
  | E IGUAL E   
    { $$.c = $1.c + $3.c + "=="; }
  | E DIF E     
    { $$.c = $1.c + $3.c + "!="; }
  | E '<' E
    { $$.c = $1.c + $3.c + "<"; }
  | E '>' E
    { $$.c = $1.c + $3.c + ">"; }
  | E '+' E
    { $$.c = $1.c + $3.c + "+"; }
  | E '-' E
    { $$.c = $1.c + $3.c + "-"; }
  | E '*' E
    { $$.c = $1.c + $3.c + "*"; }
  | E '/' E
    { $$.c = $1.c + $3.c + "/"; }
  | E '%' E
    { $$.c = $1.c + $3.c + "%"; }
  | '-' E 
    {$$.c = "0" + $2.c + $1.c;}
  | CDOUBLE
  | CINT
  | OBJ 
    { $$.c = $1.c + vector<string>{"{}"} + "="; } 
  | ARRAY 
    {$$.c = vector<string>{"[]"};}
  | CSTRING
  | LVALUE 
    { $$.c = $1.c + "@"; } 
  | LVALUEPROP
    { $$.c = $1.c + "[@]"; }
  | '(' E ')' 
    { $$.c = $2.c; }
  ;

LVALUE : ID 
       ;
       
LVALUEPROP : E '[' E ']'
           | E '.' ID
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