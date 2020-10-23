#!/bin/bash
flex calculadora.lex && bison -d calculadora.y && gcc lex.yy.c calculadora.tab.c -lfl -lm && echo "Type operation " && ./a.out