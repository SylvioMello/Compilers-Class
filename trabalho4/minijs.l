%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
string lexema;
int token( int tk );
std::vector<std::string> tokeniza(const std::string& str);
std::string trim(const std::string& input_string, const std::string& chars_to_trim);
%}

ID      {LETRA}({LETRA}|{DIGITO})*
INT     {DIGITO}+
LETRA   [A-Za-z_]
DIGITO  [0-9]
ASM     "asm"
ASMFULL {ASM}[{".*"}]
STRING  (\"([^\"\n]|(\\\")|\"\")+\")|(\'([^\'\n]|(\\\')|\'\')+\')
DOUBLE  {DIGITO}+"."{DIGITO}+([Ee][+\-]?{DIGITO}+)?

%%

"\t"        { coluna += 4;                }
" "         { coluna++;                   }
"\n"        { linha++; coluna = 1;        }
"{}"        { return token( OBJ );        }
"[]"        { return token( ARRAY );      }
"&&"        { return token( AND );        }
"||"        { return token( OR );         }
"<="        { return token( ME_IG );      }
">="        { return token( MA_IG );      }
"!="        { return token( DIF );        }
"=="        { return token( IGUAL );      }
"+="        { return token( MAIS_IGUAL ); }
"++"        { return token( MAIS_MAIS );  }
"if"        { return token( IF );         }
"for"       { return token( FOR );        }
"let"       { return token( LET );        }
"var"       { return token( VAR );        }
"else"      { return token( ELSE );       }
"const"     { return token( CONST );      }
"print"     { return token( PRINT );      }
"while"     { return token( WHILE );      }
"function"  { return token( FUNCTION );   }
{ASMFULL}   {   lexema   = trim( yytext + 3, "{}" ); 
                yylval.c = tokeniza( lexema );
                coluna  += strlen( yytext ); 
                return token( ASM ); }

{INT}     { return token( CINT );       }   
{DOUBLE}  { return token( CDOUBLE );    }
{STRING}  { return token( CSTRING );    }
{ID}      { return token( ID );         }
[ \n\r\t] {                             }
.         { return token( *yytext );    }

%%

// Function to split a string into tokens using a space as a separator
std::vector<std::string> tokeniza(const std::string& str) {
    std::vector<std::string> tokens;
    std::string token;
    size_t start = 0, end = 0;

    while (end != std::string::npos) {
        end = str.find(' ', start);

        if (end != std::string::npos) {
            token = str.substr(start, end - start);
            start = end + 1;
        } else {
            token = str.substr(start);
        }

        tokens.push_back(token);
    }

    return tokens;
}

// Function to trim specified characters from the beginning and end of a string
std::string trim(const std::string& input_string, const std::string& chars_to_trim) {
    size_t start = input_string.find_first_not_of(chars_to_trim);
    if (start == std::string::npos) {
        // The string contains only characters to trim
        return "";
    }

    size_t end = input_string.find_last_not_of(chars_to_trim);
    if (end == std::string::npos) {
        // This shouldn't occur, but for safety
        end = start;
    }

    return input_string.substr(start, end - start + 1);
}

int token( int tk ) {  
  yylval.c = vector<string>{ yytext };
  coluna += strlen( yytext ); 
  
  yylval.linha = linha;
  yylval.coluna = coluna;

  return tk;
}