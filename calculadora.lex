/*	Tarea 3 - Practica para integrar Flex y Bison
	Theo Salvador Perez Tovar  A01328274 */
%{
#include<stdlib.h>
#include<math.h>
//Archivo para generar tokens
#include "calculadora.tab.h"
%}

LETRA [A-Za-z]
DIGITO [0-9]

%%

{DIGITO}* {yylval = atoi(yytext); return NUM; /* Convierte el NUM a numero */}
"+"       {return SUMA;}	/* Se encontro un simbolo de suma */
"-"       {return RESTA;}	/* Se encontro un simbolo de resta */
"*"       {return MULTI;}	/* Se encontro un simbolo de multiplicacion */
"/"       {return DIVIDE;}	/* Se encontro un simbolo de division */
"%"		  {return MOD;}		/* Se encontro un simbolo de modulo */
"^" 	  {return POT;}		/* Se encontro un simbolo de potencia */
"("       {return PARENI;}	/* Se encontro un "(" */
")"       {return PAREND;}	/* Se encontro un ")" */
"$"       {return FINEXP;}	/* Se encontro un $, que es simbolo de fin de expr */

%%
