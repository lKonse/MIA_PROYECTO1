%option noyywrap
%option caseless
%{
#include "parser.h"
#include <iostream>
#include <QString>
int columna=0;
%}
letra [a-zñA-ZÑ]
digito [0-9]
numero {digito}+
identificador {letra}[{letra} | {numero}]*
ruta "/"[^".disk"]+
espacioBlanco [ \t\n]+

%%
"mkdisk"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return mkdisk; }
"rmdisk"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return rmdisk; }
"fdisk"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return fdisk; }
"mount"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return mount; }
"unmount"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return unmount; }
"rep"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return rep; }
"exec"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return exec; }
"size"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return size; }
"fit"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return fit; }
"unit"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return unit; }
"path"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return type; }
"type"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return type; }
"delete"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return borrar; }
"name"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return name; }
"add"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return add; }
"id"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return id; }
"BF"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return BF; }
"FF"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return FF; }
"WF"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return WF; }
"k"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return kilo; }
"m"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return mega; }
"b"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return byte; }
"p"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return primaria; }
"e"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return extendida; }
"l"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return logica; }
"fast"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return fast; }
"full"    { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return full; }

[=]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return igual; }
[-]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return guion; }
[\"]             { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return comillas; }
{espacioBlanco}     { /*Se ignoran*/ }
{ruta}  { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return ruta; }
{identificador}          { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return identificador; }
{numero}        { columna=columna+strlen(yylval.TEXT); strcpy(yylval.TEXT, yytext); return num; }
.               {std::cout <<yytext<<"Error Lexico "<< std::endl;}
%%
