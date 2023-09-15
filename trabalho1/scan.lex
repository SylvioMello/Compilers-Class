%{
// Código em c/c++

#include <iostream>

using namespace std;

string lexema;

%}

DIGITO     [0-9]
LETRA      [A-Za-z]
NUM        {DIGITO}+
UNDERLINE   "_"
DOLAR       "$"
STRING     (\"([^\"\n]*)\")
ID         ({DOLAR})({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({DOLAR})
FLOAT      [-+]?{DIGITO}*\.?{DIGITO}+([eE][-+]?{DIGITO}+)?
ERRO       ({LETRA}|{UNDERLINE}|{DOLAR}|{DIGITO})({UNDERLINE}|{LETRA}|{DOLAR}|{DIGITO})*

%% 

[ \n\r\t]   { }
 
  /* Todas as palavras reservadas devem aparecer antes do padrão do ID */
"for"                  { lexema = yytext; return _FOR; }
"if"                   { lexema = yytext; return _IF; }
"<="                   { lexema = yytext; return _MEIG; }
">="                   { lexema = yytext; return _MAIG; }


{STRING}               { lexema = yytext; return _STRING; }
{ID}                   { lexema = yytext; return _ID; }
{NUM}                  { lexema = yytext; return _INT; }
{FLOAT}                { lexema = yytext; return _FLOAT;}
{ERRO}                 { lexema = yytext; fprintf(stderr, "Erro: Identificador invalido: %s\n", yytext);}


  /* Trata todos os símbolos de um caracter usando o código ASCII */
.                      { lexema = yytext; return yytext[0]; }
 
%%