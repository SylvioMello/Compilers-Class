%{
int token( int tk );
%}

DIGITO        [0-9]
LETRA         [A-Za-z_]
INT           {DIGITO}+
STRING        (\"([^\"\n]|(\\\")|\"\")+\")|(\'([^\'\n]|(\\\')|\'\')+\')
ID            {LETRA}({LETRA}|{DIGITO})*
DOUBLE        {DIGITO}+"."{DIGITO}+([Ee][+\-]?{DIGITO}+)?

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
"var"      { return token( VAR ); }
"const"    { return token( CONST ); }
"if"       { return token( IF ); }
"else"     { return token( ELSE ); }
"for"      { return token( FOR ); }
"print"    { return token( PRINT ); }
"while"    { return token( WHILE ); }
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