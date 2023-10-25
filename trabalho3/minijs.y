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

extern "C" int yylex();
int yyparse();
void yyerror(const char *);
vector<string> concatena( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, vector<string> b );
vector<string> operator+( vector<string> a, string b );
vector<string> operator+( string a, vector<string> b );
vector<string> resolve_enderecos( vector<string> entrada );
string gera_label( string prefixo );
void print( vector<string> codigo );
void append_symbol_table( TipoDecl decl, Atributos var);
void check_var_decl(Atributos var);;

%}

%token ID IF ELSE LET OBJ ARRAY FOR WHILE
%token CDOUBLE CSTRING CINT
%token AND OR ME_IG MA_IG DIF IGUAL
%token MAIS_IGUAL MAIS_MAIS PRINT

%right '='
%nonassoc IGUAL MAIS_IGUAL MAIS_MAIS MA_IG ME_IG DIF
%nonassoc '<' '>' IF ELSE
%left AND OR
%left '+' '-'
%left '*' '/' '%'
%left '['
%left '.'

%%

S : CMDs { print( resolve_enderecos( $1.c  + ".") ); }
  ;

CMDs : CMDs CMD {$$.c = $1.c + $2.c;}
     | {$$.clear();}
     ;

CMD : CMD_LET ';'
    | CMD_FOR
    | CMD_IF
    | CMD_WHILE
    | PRINT E ';'
      { $$.c = $2.c + "println" + "#"; }
    | '{' CMDs '}' 
      { $$.c = $2.c; }
    | E ';'
      {$$.c = $1.c + "^";}
    | ';' 
      {$$.clear();}
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

CMD_WHILE : WHILE '(' E ')' CMD {
    string lbl_fim_while = gera_label( "fim_while" );
    string lbl_condicao_while = gera_label( "condicao_while" );
    string lbl_comando_while = gera_label( "comando_while" );
    string definicao_lbl_fim_while = ":" + lbl_fim_while;
    string definicao_lbl_condicao_while = ":" + lbl_condicao_while;
    string definicao_lbl_comando_while = ":" + lbl_comando_while;
    
    $$.c =  definicao_lbl_condicao_while +
            $3.c + lbl_comando_while + "?" + lbl_fim_while + "#" +
            definicao_lbl_comando_while + $5.c + lbl_condicao_while + "#" +
            definicao_lbl_fim_while;
            }
          ;

CMD_LET : LET VARs 
          { $$.c = $2.c; }
        ;

VARs : VAR ',' VARs 
       { $$.c = $1.c + $3.c; } 
     | VAR
     ;

VAR : ID                
      { append_symbol_table( DeclLet, $1 ); $$.c = $1.c + "&"; }
    | ID '=' E          
      { append_symbol_table( DeclLet, $1 ); $$.c = $1.c + "&" + $1.c + $3.c + "=" + "^"; }
    | ID '=' '{' '}'    
      { append_symbol_table( DeclLet, $1 ); $$.c = $1.c + "&" +  $1.c +  vector<string>{"{}"} + "=" + "^";} 
    ;
     
E : LVALUE '=' E 
    {check_var_decl($1); $$.c = $1.c + $3.c + "="; }
  | LVALUE '=' '{' '}'        
    {check_var_decl($1); $$.c = $1.c + vector<string>{"{}"} + "="; } 
  | LVALUE MAIS_MAIS 
    { $$.c = $1.c + "@" +  $1.c + $1.c + "@" + "1" + "+" + "=" + "^"; }
  | LVALUE MAIS_IGUAL E     
    {check_var_decl($1); $$.c = $1.c + $1.c + "@" + $3.c + "+" + "="; }  
  | LVALUEPROP '=' E 	
    {check_var_decl($1); $$.c = $1.c + $3.c + "[=]"; }
  | LVALUEPROP '=' '{' '}'    
    {check_var_decl($1); $$.c = $1.c + vector<string>{"{}"} + "[=]"; }
  | LVALUEPROP MAIS_IGUAL E
    {check_var_decl($1); $$.c = $1.c + $1.c + "[@]" + $3.c + "+" + "[=]"; }
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
  | '[' ']'             
    {$$.c = vector<string>{"[]"};}
  | CDOUBLE
  | CINT
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
       
LVALUEPROP : E '[' E ']' { $$.c = $1.c + $3.c;}
           | E '.' ID    { $$.c = $1.c + $3.c;}
           ;


%%

#include "lex.yy.c"

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

void check_var_decl(Atributos var){
     string var_identifier = var.c[0];
     auto it = ts.find(var_identifier);
     if (it == ts.end()) { cout << "Erro: a variável '" << var_identifier << "' não foi declarada." << '\n';
                           exit(1);
                         }
}

void append_symbol_table( TipoDecl decl, Atributos var){
    Var placeholder;
    placeholder.linha = var.linha;
    placeholder.coluna = var.coluna;
    placeholder.tipo = decl;
    string var_identifier = var.c[0];
    auto it = ts.find(var_identifier);
    if (it == ts.end()) { ts[var_identifier] = placeholder; } 
    else { cout << "Erro: a variável '" << var_identifier << "' ja foi declarada na linha " + to_string(ts[var_identifier].linha) +"." << endl;
           exit(1);
         }
}

void yyerror( const char* st ) {
   puts( st );
   printf( "Proximo a: %s\n", yytext );
   exit( 0 );
}

int main( int argc, char* argv[] ) {
  yyparse();

  return 0;
}