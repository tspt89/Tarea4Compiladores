/*	Tarea 3 - Practica para integrar Flex y Bison
	Theo Salvador Perez Tovar  A01328274 */
%{
#include<stdlib.h>
#include<math.h>
//Archivo para generar tokens
#include "calculadora.tab.h"
%}

LETRA [A-Za-z]
IDENTIFICADOR [a-zA-Z][a-zA-Z0-9]*
DIGITO [1-9][0-9]*

%%

{DIGITO}+"."{DIGITO}+ {return REAL;}
{DIGITO}* {yylval = atoi(yytext); return NUMI; /* Convierte el NUM a numero */}
{IDENTIFICADOR} {return ID;}

"program" {return PROGRAM;}
"begin"	  {return BEGINPROG;}
"end."		{return FINEXP;}
"let"		{return LET;}
","			{return PNTCMA;}
"int"		{return INT;}
"real"		{return REAL;}
"bool"		{return BOOL;}
":="		{return ASIG;}
"if"		{return IF;}
"then"		{return THEN;}
"fi"		{return FI;}
"else"		{return ELSE;}
"while"		{return WHILE;}
"do"		{return DO;}
"repeat"		{return ASIG;}
"until"		{return ASIG;}
"begin"		{return ASIG;}
"end"		{return ASIG;}
"read"		{return ASIG;}
"print"		{return ASIG;}
"+"       {return SUMA;}	/* Se encontro un simbolo de suma */
"-"       {return RESTA;}	/* Se encontro un simbolo de resta */
"*"       {return MULTI;}	/* Se encontro un simbolo de multiplicacion */
"/"       {return DIVIDE;}	/* Se encontro un simbolo de division */

"("       {return PARENI;}	/* Se encontro un "(" */
")"       {return PAREND;}	/* Se encontro un ")" */

"!"		{return NEG;}
"|"		{return OR;}
"&"		{return AND;}

"<"		{return MENOR;}
">"		{return MAYOR;}
"="		{return IGUAL;}
"True"	{return TRUE;}
"False"	{return FALSE;}


%%
