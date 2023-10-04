%{

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string lexema;

int token;

void S();
void A();
void E();
void E_linha();
void T();
void T_linha();
void U();
void F();
void casa( int );

enum { ID = 256, NUM, PRINT, FLOAT, STRING };

map<int,string> nome_tokens = {
  { ID,     "nome de identificador" },
  { NUM,    "numero" },
  { PRINT,  "print"},
  { FLOAT,  "float"},
  { STRING, "string"}
};

%}

WS	     [ \n\t]
DIGITO	 [0-9]
LETRA	   [A-Za-z_]
ESCAPING ["][^"]*([\\]|["])["][^"]*["]|['][^']*([\\]|['])['][^']*[']
STRING   (\"([^\"\n]*)\")|{ESCAPING}
FLOAT    [-+]?{DIGITO}*\.?{DIGITO}+([eE][-+]?{DIGITO}+)?
NUM	     {DIGITO}+
ID	     {LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
"print"   { lexema = yytext; return PRINT;   }

{NUM} 		{ lexema = yytext; return NUM; }
{ID}		  { lexema = yytext; return ID;      }
{STRING}  { lexema = yytext; return STRING;  }
{FLOAT}   { lexema = yytext; return FLOAT;   }

.		      { return yytext[0]; }

%%

int next_token() {
  return yylex();
}

string nome_token( int token ) {
  if( nome_tokens.find( token ) != nome_tokens.end() )
    return nome_tokens[token];
  else {
    string r;
    
    r = token;
    return r;
  }
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
    case '+' : cout << 0 << ' '; casa('+'); U(); cout <<  "+"  << ' '; break;
    default:   F();
  }
}

void F() {
  switch( token ) {
    case ID      : cout << lexema << ' '; casa( ID );      break;
    case NUM     : cout << lexema << ' '; casa( NUM );     break;
    case FLOAT   : cout << lexema << ' '; casa ( FLOAT );  break;
    case STRING  : cout << lexema << ' '; casa (STRING);   break;
    case '('     : casa( '(' );      E(); casa( ')' );     break;
  }
}

int main() {
  token = next_token();
  S();
  cout << '\n';
  
  return 0;
}