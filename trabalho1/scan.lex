%{
// Código em c/c++

#include <iostream>

using namespace std;

string lexema;

string cut_aspas(string lexema) {
  return lexema.substr(1, lexema.length() - 2);
}

void formatString(const char* input, char** formatted) {
    int length = strlen(input);
    char* result = (char*)malloc((2 * length + 1) * sizeof(char));  // Double the length plus 1 for null-terminator

    if (!result) {
        fprintf(stderr, "Memory allocation error\n");
        exit(1);
    }

    int i = 0;  // Index for the input string
    int j = 0;  // Index for the result string

    while (i < length) {
        if (input[i] == '\"') {
            result[j++] = input[i++];  // Copy the opening double quote
            while (i < length && input[i] != '\"') {
                if (input[i] == '\\') {
                    result[j++] = input[i++];  // Copy the backslash
                    if (i < length) {
                        result[j++] = input[i++];  // Copy the escaped character
                    }
                } else {
                    result[j++] = input[i++];  // Copy the character inside the string
                }
            }
            if (i < length && input[i] == '\"') {
                result[j++] = input[i++];  // Copy the closing double quote
            }
        } else if (input[i] == '\'') {
            result[j++] = input[i++];  // Copy the opening single quote
            while (i < length && input[i] != '\'') {
                result[j++] = input[i++];  // Copy the character inside the character literal
            }
            if (i < length && input[i] == '\'') {
                result[j++] = input[i++];  // Copy the closing single quote
            }
        } else {
            result[j++] = input[i++];  // Copy other characters unchanged
        }
    }

    result[j] = '\0';  // Null-terminate the result string

    *formatted = result;
}

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
CRASE      [`][^`{}]*[`]
ESCAPING   ['"]([^"\\]*(\\.[^"\\]*)*)['"]


%% 

[ \n\r\t]   { }
 
  /* Todas as palavras reservadas devem aparecer antes do padrão do ID */
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


{ID}                   { lexema = yytext; return _ID; }
{ERRO}                 { lexema = yytext; cout << "Erro: Identificador invalido: " << lexema.c_str() << endl;}


  /* Trata todos os símbolos de um caracter usando o código ASCII */
.                      { lexema = yytext; return yytext[0]; }
 
%%