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

{DIGITO}+"."{DIGITO}+ {printf("REAL\n");return REAL;}
{DIGITO}* {yylval = atoi(yytext); printf("NUMI\n");return NUMI; /* Convierte el NUM a numero */}


"program" 	{printf("PROG\n");return PROGRAM;}
"begin"		{printf("BEGIN\n");return BEGINPROG;}
"end."		{printf("END.\n");return FINEXP;}
"let"		{printf("LET\n");return LET;}
";"			{printf(";\n");return PNTCMA;}
":"			{printf(":\n");return DSPNT;}
"int"		{printf("INT\n");return INT;}
"real"		{printf("REAL\n");return REAL;}
"bool"		{printf("BOOL\n");return BOOL;}
":="		{printf("ASIG\n");return ASIG;}
"if"		{printf("IF\n");return IF;}
"then"		{printf("THEN\n");return THEN;}
"fi"		{printf("FI\n");return FI;}
"else"		{printf("ELSE\n");return ELSE;}
"while"		{printf("WHILE\n");return WHILE;}
"do"		{printf("DO\n");return DO;}
"repeat"	{printf("REPEAT\n");return REPEAT;}
"until"		{printf("UNTIL\n");return UNTIL;}
"end"		{printf("END\n");return END;}
"read"		{printf("READ\n");return READ;}
"print"		{printf("PRINT\n");return PRINT;}
"+"       {printf("+\n");return SUMA;}	/* Se encontro un simbolo de suma */
"-"       {printf("-\n");return RESTA;}	/* Se encontro un simbolo de resta */
"*"       {printf("*\n");return MULTI;}	/* Se encontro un simbolo de multiplicacion */
"/"       {printf("/\n");return DIVIDE;}	/* Se encontro un simbolo de division */

"("       {printf("(\n");return PARENI;}	/* Se encontro un "(" */
")"       {printf(")\n");return PAREND;}	/* Se encontro un ")" */

"!"		{printf("!\n");return NEG;}
"|"		{printf("|\n");return OR;}
"&"		{printf("&\n");return AND;}

"<"		{printf("<\n");return MENOR;}
">"		{printf(">\n");return MAYOR;}
"="		{printf("=\n");return IGUAL;}
"True"	{printf("True\n");return TRUE;}
"False"	{printf("False\n");return FALSE;}

{IDENTIFICADOR} {printf("ID %s\n",yytext);return ID;}
%%
