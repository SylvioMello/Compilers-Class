%{

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>

using namespace std;

int token;

void A();
void E();
void E_linha();
void T();
void T_linha();
void F();
void casa( int );

enum { INT = 256, CHAR, tk_double, ID, CTE_INT };

map<int,string> nome_tokens = {
  { INT, "int" },
  { CHAR, "char" },
  { tk_double, "double" },
  { ID, "nome de identificador" },
  { CTE_INT, "constante inteira" }
};

%}

WS	    [ \n\t]
DIGITO	[0-9]
LETRA	[A-Za-z_]

NUM	{DIGITO}+
ID	{LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
{NUM} 		{ return CTE_INT; }
"char"		{ return CHAR; }
"int"		{ return INT; }
"double"	{ return tk_double; }

{ID}		{ return ID; }

.		{ return yytext[0]; }

%%

void casa( int esperado ) {
  if( token == esperado )
    token = next_token();
  else {
      cout << "Esperado " << nome_token( esperado ) 
	   << " , encontrado: " << nome_token( token ) << endl;
    exit( 1 );
  }
}

void A() {
// Guardamos o lexema pois a função 'casa' altera o seu valor.
  string temp = lexema; 
  casa( ID );
  print( temp );
  casa( '=' );
  E();
  print( "=" );
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); print( "+"); E_linha(); break;
    case '-' : casa( '-' ); T(); print( "-"); E_linha(); break;
  }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); F(); print( "*"); T_linha(); break;
    case '/' : casa( '/' ); F(); print( "/"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case ID : {
      string temp = lexema;
      casa( ID ); print( temp + "@" ); } 
      break;
    case NUM : {
      string temp = lexema;
      casa( NUM ); print( temp ); }
      break;
    case '(': 
      casa( '(' ); E(); casa( ')' ); break;
    default:
      erro( "Operando esperado, encontrado " + lexema );
  }
}

int main() {
  token = next_token();
  VS();
  
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    cout << "Caracteres encontrados após o final do programa" << endl;
  
  return 0;
}