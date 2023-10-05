%{

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string lexema;
int token;

void casa( int );
void S();
void A();
void E();
void E_linha();
void T();
void T_linha();
void U();
void POWER();
void POWER_LINHA();
void FACTORIAL();
void FACTORIAL_LINHA();
void ARGUMENTS();
void F();

enum { ID = 256, NUM, PRINT, FLOAT, STRING, FUNCTION };

map<int,string> nome_tokens = {
  { ID,       "nome de identificador"},
  { NUM,      "numero"},
  { PRINT,    "print"},
  { FLOAT,    "float"},
  { STRING,   "string"},
  { FUNCTION, "function"}
};

%}

WS	        [ \n\r\t]
ID	        {LETRA}({LETRA}|{DIGITO})*  
NUM	        {DIGITO}+ 
FLOAT       {NUM}([.]{NUM})?([eE][-+]?{NUM})?
LETRA	      [A-Za-z_]
STRING      (\"([^\"\n]*)\")|{ESCAPING}  
DIGITO	    [0-9]
ESCAPING    ["][^"]*([\\]|["])["][^"]*["]|['][^']*([\\]|['])['][^']*[']
PARENTHESIS "("

%%

{WS}               {                                  }
"print"            { lexema = yytext; return PRINT;   }
{NUM} 		         { lexema = yytext; return NUM;     }
{FLOAT}            { lexema = yytext; return FLOAT;   }
{STRING}           { lexema = yytext; return STRING;  }
{ID}/{PARENTHESIS} { lexema = yytext; return FUNCTION;}
{ID}		           { lexema = yytext; return ID;      }
.		               { return yytext[0];                }

%%

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
}

int next_token() {
  return yylex();
}

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
      cout << "Esperado " << nome_token( esperado ) 
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}

void S() {
  A();
  if(token == ';'){
    casa(';');
    S();
  }
}

void A(){
  switch( token ) {
    case PRINT : casa(PRINT); E(); cout << "print #" << ' '; break;
    case ID : cout << lexema << ' '; casa( ID ); casa('='); E(); cout << "= ^" << ' ';
  }
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); cout << '+' << ' '; E_linha(); break;
    case '-' : casa( '-' ); T(); cout << '-' << ' '; E_linha(); break;
  }
}

void T() {
  U();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); U(); cout << "*" << ' '; T_linha(); break;
    case '/' : casa( '/' ); U(); cout << "/" << ' '; T_linha(); break;
  }
}

void U(){
  switch( token ) {
    case '-' : cout << 0 << ' '; casa('-'); U(); cout <<  "-"  << ' '; break;
    case '+' : casa('+'); U(); break;
    default:   POWER();
  }
}

void POWER(){
  FACTORIAL();
  POWER_LINHA();
}

void POWER_LINHA(){
  if(token == '^'){ casa('^'); POWER(); cout << "power # ";}
}

void FACTORIAL(){
  F();
  FACTORIAL_LINHA();
}

void FACTORIAL_LINHA(){
  if (token == '!'){ casa('!'); cout << "fat # "; FACTORIAL_LINHA();}
}

void ARGUMENTS(){
  E();
  if (token == ','){ casa(','); ARGUMENTS(); }
}

void F() {
  string final_term  = lexema;
  switch( token ) {
    case ID      : cout << lexema << " @ "; casa( ID );     break;
    case NUM     : cout << lexema << ' '  ; casa( NUM );    break;
    case FLOAT   : cout << lexema << ' '  ; casa ( FLOAT ); break;
    case STRING  : cout << lexema << ' '  ; casa (STRING);  break;
    case FUNCTION: casa(FUNCTION);   casa('(');            ARGUMENTS();
                   casa(')');  cout << final_term << " # "; break;
    case '('     : casa( '(' );      E();   casa( ')' );    break;
  }
}

int main() {
  token = next_token();
  S();
  cout << '\n';
  return 0;
}