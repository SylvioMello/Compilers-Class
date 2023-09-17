%{
// Código em c/c++

#include <iostream>

using namespace std;

string lexema;

string cut_aspas(string lexema) {
    return lexema.substr(1, lexema.length() - 2);
}

string formatString(string lexema) {
    size_t pos = 1; // Começa apos a primeira aspas
    size_t len = lexema.length() - 1; // Remove as duas aspas
    string resultado = "";
    while (pos < len) {
        if (lexema[pos] == '\\') {
            // Caractere de escape
            pos++;
            switch (lexema[pos]) {
                case '\'':
                    resultado += '\'';
                    break;
                case '"':
                    resultado += '"';
                    break;
                default:
                    resultado += '\\';
                    resultado += lexema[pos];
                    break;
            }
        } else if (lexema[pos] == '\'') {
            if (lexema[pos + 1] == '\'') {
                resultado += '\'';
                pos++;
            } else {
                resultado += '\'';
            }
        } else if (lexema[pos] == '"') {
            if (lexema[pos + 1] == '"') {
                if (lexema[pos + 2] == '\'') {
                    resultado += '"';
                }
                resultado += '"';
                pos++;
            } else {
                resultado += '"';
            }         
        } else {
            resultado += lexema[pos];
        }
        pos++;
    }
    return resultado;
}

%}

DIGITO        [0-9]
LETRA         [A-Za-z]
NUM           {DIGITO}+
UNDERLINE      "_"
DOLAR          "$"
STRING        (\"([^\"\n]*)\")
ID            ({DOLAR})({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({DOLAR})
FLOAT         [-+]?{DIGITO}*\.?{DIGITO}+([eE][-+]?{DIGITO}+)?
ERRO          ({LETRA}|{UNDERLINE}|{DOLAR}|{DIGITO})({UNDERLINE}|{LETRA}|{DOLAR}|{DIGITO})*
CRASE         [`][^`{}]*[`]
ESCAPING      ["][^"]*([\\]|["])["][^"]*["]|['][^']*([\\]|['])['][^']*[']
START         [`][^`{}]*{DOLAR}
EXPR          [{].*
END           [}][^`{}]*[`]
COMENTARIO1   \/\*\s*([^*]*\*[^\/]*)\\*\/
COMENTARIO2   [/][/].*

%% 

[ \n\r\t]     { }

"=="          { lexema = yytext; return _IG;   }
"if"          { lexema = yytext; return _IF;   }
"!="          { lexema = yytext; return _DIF;  }
"for"         { lexema = yytext; return _FOR;  }
"<="          { lexema = yytext; return _MEIG; }
">="          { lexema = yytext; return _MAIG; }

{NUM}         { lexema = yytext; return _INT; }
{FLOAT}       { lexema = yytext; return _FLOAT;}

{ESCAPING}    { lexema = yytext; lexema = formatString(lexema);  return _STRING; }
{STRING}      { lexema = yytext; lexema = formatString(lexema);  return _STRING; }
{CRASE}       { lexema = yytext; lexema =    cut_aspas(lexema);  return _STRING2;}
        
{START}       { lexema = yytext; lexema = cut_aspas(lexema);                     return _STRING2; }
{EXPR}/"}"    { lexema = yytext; lexema = lexema.substr(1, lexema.length() - 1); return _EXPR;    }  
{END}         { lexema = yytext; lexema = cut_aspas(lexema);                     return _STRING2; }  

{COMENTARIO1} { lexema = yytext; return _COMENTARIO; }
{COMENTARIO2} { lexema = yytext; return _COMENTARIO; }

{ID}          { lexema = yytext; return _ID; }
{ERRO}        { lexema = yytext; cout << "Erro: Identificador invalido: " << lexema.c_str() << endl; }

.             { lexema = yytext; return yytext[0]; }
 
%%