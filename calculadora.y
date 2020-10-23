
%{
#include<stdio.h>
#include<math.h>
extern int yylex();
int yyerror(char const * s);

%}

//Se generan tokens para que flex los pueda interpretar
%token PROGRAM ID BEGINPROG PNTCMA LET INT REAL BOOL ASIG IF THEN FI DSPNT
%token ELSE WHILE DO REPEAT UNTIL END READ PRINT NUMI NUMR SUMA RESTA DIVIDE
%token MULTI PAREND PARENI NEG OR AND MAYOR MENOR IGUAL BOOLEAN FINEXP COMA
%start prog

%%





prog : PROGRAM ID opt_decls BEGIN opt_stmts FINEXP {printf("Valor = %d\n", $1);}
;

opt_decls : decl lst | ;

decl_lst : decl PNTCMA decl_lst | decl;

decl : LET id_lst DSPNT tipo ;
id_lst :  ID COMA id_lst | ID;
tipo : INT | REAL | BOOL;

stmt : ID ASIG expr
| ID ASIG boolexpr
| IF boolexpr THEN stmt FI
| IF boolexpr THEN stmt ELSE stmt
| WHILE boolexpr DO stmt
| REPEAT stmt UNTIL boolexpr
| BEGINPROG opt_stmts END
| READ ID
| PRINT expr;

opt_stmts : stmt_lst | ;

stmt_lst : stmt_lst PNTCMA stmt | stmt;

expr : expr SUMA term
| expr RESTA term
| term;

term : term MULTI factor
| term DIVIDE factor
| factor;

factor → PARENI expr PAREND
| ID
| NUMI
| NUMR;

boolexpr : boolexpr OR boolexpr
| NEG boolterm
| boolterm;

boolterm : boolterm AND boolfactor
| boolfactor;

boolfactor : expr MENOR expr
| expr MAYOR expr
| expr IGUAL expr
| PARENI boolexpr PAREND
| BOOL;


expr : expr SUMA term    {$$ = $1 + $3;}
     | expr RESTA term   {$$ = $1 - $3;}
     | term
;

term : term MULTI factor   {$$ = $1 * $3;}
     | term DIVIDE factor  {$$ = $1 / $3;}
     | term MOD factor  {$$ = $1 % $3;}
     | opera
;

opera : opera POT factor {$$ = pow($1,$3);}
      | factor
;

factor : PARENI expr PAREND  {$$ = $2;}
       | NUM
;

%%

int yyerror(char const * s) {
  fprintf(stderr, "%s\n", s);
}

void main() {

  yyparse();
}

