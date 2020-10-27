/* A Bison parser, made by GNU Bison 3.7.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_CALCULADORA_TAB_H_INCLUDED
# define YY_YY_CALCULADORA_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    PROGRAM = 258,                 /* PROGRAM  */
    ID = 259,                      /* ID  */
    BEGINPROG = 260,               /* BEGINPROG  */
    PNTCMA = 261,                  /* PNTCMA  */
    LET = 262,                     /* LET  */
    INT = 263,                     /* INT  */
    REAL = 264,                    /* REAL  */
    BOOL = 265,                    /* BOOL  */
    ASIG = 266,                    /* ASIG  */
    IF = 267,                      /* IF  */
    THEN = 268,                    /* THEN  */
    FI = 269,                      /* FI  */
    DSPNT = 270,                   /* DSPNT  */
    ELSE = 271,                    /* ELSE  */
    WHILE = 272,                   /* WHILE  */
    DO = 273,                      /* DO  */
    REPEAT = 274,                  /* REPEAT  */
    UNTIL = 275,                   /* UNTIL  */
    END = 276,                     /* END  */
    READ = 277,                    /* READ  */
    PRINT = 278,                   /* PRINT  */
    NUMI = 279,                    /* NUMI  */
    NUMR = 280,                    /* NUMR  */
    SUMA = 281,                    /* SUMA  */
    RESTA = 282,                   /* RESTA  */
    DIVIDE = 283,                  /* DIVIDE  */
    MULTI = 284,                   /* MULTI  */
    PAREND = 285,                  /* PAREND  */
    PARENI = 286,                  /* PARENI  */
    NEG = 287,                     /* NEG  */
    OR = 288,                      /* OR  */
    AND = 289,                     /* AND  */
    MAYOR = 290,                   /* MAYOR  */
    MENOR = 291,                   /* MENOR  */
    IGUAL = 292,                   /* IGUAL  */
    TRUE = 293,                    /* TRUE  */
    FALSE = 294,                   /* FALSE  */
    FINEXP = 295,                  /* FINEXP  */
    COMA = 296                     /* COMA  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_CALCULADORA_TAB_H_INCLUDED  */
