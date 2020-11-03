
%{
#include<stdio.h>
#include<math.h>
#include "tabla.h"
extern int yylex();
int yyerror(char const * s);

%}

%union{
	int entero;
	float real;
	char * ident;
	int tipo;
	struct variable * var;
}

//Se generan tokens para que flex los pueda interpretar
%token PROGRAM BEGINPROG PNTCMA LET INT REAL BOOL ASIG IF THEN FI DSPNT
%token ELSE WHILE DO REPEAT UNTIL END READ PRINT SUMA RESTA DIVIDE
%token MULTI PAREND PARENI NEG OR AND MAYOR MENOR IGUAL TRUE FALSE FINEXP COMA
%token <entero> NUMI
%token <real> NUMR
%token <ident> ID
%type<var> id_lst

%start prog



%%



prog : PROGRAM ID opt_decls BEGINPROG opt_stmts {printTable();} FINEXP ;

opt_decls : decl_lst | ;

decl_lst : decl PNTCMA decl_lst | decl ;

decl : LET id_lst  DSPNT tipo {setTipoTmpList(yylval.tipo);};

id_lst : ID {insertId(yylval.ident);} COMA id_lst | ID {insertId(yylval.ident);};

tipo : INT  | REAL | BOOL ;

stmt : ID ASIG expr {checkId($1);}
| ID ASIG boolexpr 
| IF boolexpr THEN stmt FI
| IF boolexpr THEN stmt ELSE stmt
| WHILE boolexpr DO stmt
| REPEAT stmt UNTIL boolexpr
| BEGINPROG opt_stmts END
| READ ID
| PRINT expr;

opt_stmts : stmt_lst {printf("opt_stmts\n");} | ;

stmt_lst : stmt_lst PNTCMA stmt | stmt;

expr : expr SUMA term
| expr RESTA term
| term;

term : term MULTI factor
| term DIVIDE factor
| factor;

factor : PARENI expr PAREND
| ID
| NUMI 
| NUMR ;

boolexpr : boolexpr OR boolexpr
| NEG boolterm
| boolterm;

boolterm : boolterm AND boolfactor
| boolfactor;

boolfactor : expr MENOR expr
| expr MAYOR expr
| expr IGUAL expr
| PARENI boolexpr PAREND
| TRUE | FALSE;

%%

int yyerror(char const * s) {
  fprintf(stderr, "%s\n", s);
}

void main() {

  yyparse();
}

