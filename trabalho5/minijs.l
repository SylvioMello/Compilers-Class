%{
int token( int tk );
%}

ID      {LETRA}({LETRA}|{DIGITO})*
INT     {DIGITO}+
LETRA   [A-Za-z_]
DIGITO  [0-9]
BOOL	  "true"|"false"
STRING  (\"([^\"\n]|(\\\")|\"\")+\")|(\'([^\'\n]|(\\\')|\'\')+\')
DOUBLE  {DIGITO}+"."{DIGITO}+([Ee][+\-]?{DIGITO}+)?

%%

"\t"        { coluna += 4;                       }
" "         { coluna++;                          }
"\n"        { linha++; coluna = 1;               }
"{}"        { return token( OBJ );               }
"[]"        { return token( ARRAY );             }
"&&"        { return token( AND );               }
"||"        { return token( OR );                }
"=>"        { return token( SETA );              }
"<="        { return token( ME_IG );             }
">="        { return token( MA_IG );             }
"!="        { return token( DIF );               }
"=="        { return token( IGUAL );             }
"+="        { return token( MAIS_IGUAL );        }
"++"        { return token( MAIS_MAIS );         }
"if"        { return token( IF );                }
"for"       { return token( FOR );               }
"let"       { return token( LET );               }
"var"       { return token( VAR );               }
"else"      { return token( ELSE );              }
"const"     { return token( CONST );             }
"while"     { return token( WHILE );             }
"return"    { return token( RETURN );            }
"function"  { return token( FUNCTION );          }
")"/[*]"=>" { return token( PARENTESIS_FUNCAO ); }
"asm{".*"}"  {  string lexema = trim( yytext + 3, "{}" ); 
                yylval.c = tokeniza( lexema );
                coluna += strlen( yytext ); 
                return ASM; }

{BOOL}    { return token( BOOL );    }
{INT}     { return token( CINT );       }   
{DOUBLE}  { return token( CDOUBLE );    }
{STRING}  { return token( CSTRING );    }
{ID}      { return token( ID );         }
[ \n\r\t] {                             }
.         { return token( *yytext );    }

%%

int token( int tk ) {  
  yylval.c = vector<string>{ yytext };
  coluna += strlen( yytext ); 
  
  yylval.linha = linha;
  yylval.coluna = coluna;

  return tk;
}
