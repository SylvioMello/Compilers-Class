%{

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <map>
#include <string>

using namespace std;

string lexema;

int token;

extern "C" int yylex();  

void A();
void E();
void E_linha();
void T();
void T_linha();
void F();
void casa( int );

enum { INT = 256, CHAR, DOUBLE, ID, CTE_INT };

map<int,string> nome_tokens = {
  { INT,     "int" },
  { CHAR,    "char" },
  { DOUBLE,  "double" },
  { ID,      "nome de identificador" },
  { CTE_INT, "constante inteira" }
};

%}

WS	    [ \n\t]
DIGITO	[0-9]
LETRA	  [A-Za-z_]

NUM	    {DIGITO}+
ID	    {LETRA}({LETRA}|{DIGITO})*

%%

{WS}  		{ }
{NUM} 		{ return CTE_INT; }
"char"		{ return CHAR; }
"int"		  { return INT; }
"double"	{ return DOUBLE; }

{ID}		  { return ID; }

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

void A() {
  // Guardamos o lexema pois a função 'casa' altera o seu valor.
  string temp = lexema; 
  casa( ID );
  cout << temp << endl ;
  casa( '=' );
  E();
  printf( "=" );
}

void E() {
  T();
  E_linha();
}

void E_linha() {
  switch( token ) {
    case '+' : casa( '+' ); T(); printf(" +"); E_linha(); break;
    case '-' : casa( '-' ); T(); printf(" -"); E_linha(); break;
  }
}

void T() {
  F();
  T_linha();
}

void T_linha() {
  switch( token ) {
    case '*' : casa( '*' ); F(); printf(" *"); T_linha(); break;
    case '/' : casa( '/' ); F(); printf(" /"); T_linha(); break;
  }
}

void F() {
  switch( token ) {
    case ID : {
      string temp = lexema;
      casa( ID );
      cout << lexema.c_str() << endl; } 
      break;
    case CTE_INT : {
      string temp = lexema;
      casa( CTE_INT );
      cout << "CTE_INT" << endl;}
      break;
    case '(': 
      casa( '(' ); E(); casa( ')' ); break;
    default:
      cout << "Operando esperado, encontrado " << lexema << endl;
  }
}

int main() {
  token = next_token();
  A();
  
  if( token == 0 )
    cout << "Sintaxe ok!" << endl;
  else
    cout << "Caracteres encontrados após o final do programa" << endl;
  
  return 0;
}