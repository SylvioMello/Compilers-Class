%{
// Código em c/c++

#include <iostream>

using namespace std;

string lexema;

string cut_aspas(string lexema) {
    return lexema.substr(1, lexema.length() - 2);
}

%}

DIGITO      [0-9]
LETRA       [A-Za-z]
NUM         {DIGITO}+
UNDERLINE    "_"
DOLAR        "$"
STRING      (\"([^\"\n]*)\")
ID          ({DOLAR})({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({DOLAR})
FLOAT       [-+]?{DIGITO}*\.?{DIGITO}+([eE][-+]?{DIGITO}+)?
ERRO        ({LETRA}|{UNDERLINE}|{DOLAR}|{DIGITO})({UNDERLINE}|{LETRA}|{DOLAR}|{DIGITO})*
CRASE       [`][^`{}]*[`]
ESCAPING    ['"]([^"\\]*(\\.[^"\\]*)*)['"]

COMENTARIO1 \/\*\s*([^*]*\*[^\/]*)\\*\/
COMENTARIO2 [/][/].*

%% 

[ \n\r\t]   { }

"for"                  { lexema = yytext; return _FOR; }
"if"                   { lexema = yytext; return _IF; }
"<="                   { lexema = yytext; return _MEIG; }
">="                   { lexema = yytext; return _MAIG; }
"=="                   { lexema = yytext; return _IG; }
"!="                   { lexema = yytext; return _DIF; }

{NUM}                  { lexema = yytext; return _INT; }
{FLOAT}                { lexema = yytext; return _FLOAT;}

{ESCAPING}             { lexema = yytext; lexema = cut_aspas(lexema); return _STRING; }
{STRING}               { lexema = yytext; lexema = cut_aspas(lexema); return _STRING; }
{CRASE}                { lexema = yytext; lexema = cut_aspas(lexema); return _STRING2; }

{COMENTARIO1}          { lexema = yytext; return _COMENTARIO; }
{COMENTARIO2}          { lexema = yytext; return _COMENTARIO; }

{ID}                   { lexema = yytext; return _ID; }
{ERRO}                 { lexema = yytext; cout << "Erro: Identificador invalido: " << lexema.c_str() << endl; }

.                      { lexema = yytext; return yytext[0]; }
 
%%