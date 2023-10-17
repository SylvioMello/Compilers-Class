%{
#include <iostream>
#include <string>
#include <vector>
#include <map>
int token( int tk );
%}

DIGITO        [0-9]
LETRA         [A-Za-z]
INT           {DIGITO}+
UNDERLINE      "_"
DOLAR          "$"
STRING        (\"([^\"\n]*)\")|{ESCAPING}  
ESCAPING      ["][^"]*([\\]|["])["][^"]*["]|['][^']*([\\]|['])['][^']*[']
ID            ({DOLAR})({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({LETRA}|{UNDERLINE})({LETRA}|{DIGITO}|{UNDERLINE})*|({DOLAR})
DOUBLE         [-+]?{DIGITO}*\.?{DIGITO}+([eE][-+]?{DIGITO}+)?
ERRO          ({LETRA}|{UNDERLINE}|{DOLAR}|{DIGITO})({UNDERLINE}|{LETRA}|{DOLAR}|{DIGITO})*
CRASE         [`][^`{}]*[`]
START         [`][^`{}]*{DOLAR}
EXPR          [{].*
END           [}][^`{}]*[`]
COMENTARIO1   \/\*\s*([^*]*\*[^\/]*)\\*\/
COMENTARIO2   [/][/].*

%%

"\t"       { coluna += 4; }
" "        { coluna++; }
"\n"       { linha++; coluna = 1; }
[ \n\r\t]  { }
"{}"       { return token( OBJ ); } 
"[]"       { return token( ARRAY ); } 
"&&"       { return token( AND ); }
"||"       { return token( OR ); }
"<="       { return token( ME_IG ); }
">="       { return token( MA_IG ); }
"!="       { return token( DIF ); }
"=="       { return token( IGUAL ); }
"+="       { return token( MAIS_IGUAL ); }
"++"       { return token( MAIS_MAIS ); }
"let"      { return token( LET ); }
"if"       { return token( IF ); }
"else"     { return token( ELSE ); }
{INT}      { return token( CINT ); } 
{DOUBLE}   { return token( CDOUBLE ); }
{STRING}   { return token( CSTRING );}
{ID}       { return token( ID ); }
.          { return token( *yytext ); }

%%

int token( int tk ) {  
  yylval.c = vector<string>{ yytext };
  coluna += strlen( yytext ); 
  
  yylval.linha = linha;
  yylval.coluna = coluna;

  return tk;
}