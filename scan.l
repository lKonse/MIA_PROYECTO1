%option noyywrap
%{
#include "parser.h"
#include <iostream>
#include <QString>
int columna=0;
%}
letra [a-zñA-ZÑ]
comentario "/*"[^'*']*"*/"
digito [0-9]
iden {letra}+
Numero {digito}+
%%
"print"         { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return print; }
[+]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return mas; }
[-]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return menos; }
[*]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return por; }
[=]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return igual; }
[;]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return coma; }
[(]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return aparen; }
[)]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return cparen; }
{iden}          { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return Niden; }
{Numero}        { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return Nnum; }
{comentario}    { /*Se ignoran*/ }
[[:blank:]]     { /*Se ignoran*/ }
.               {std::cout <<yytext<<"Error Lexico "<< std::endl;}
%%
