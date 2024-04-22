%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
%}

%%
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"repeat"            { return REPEAT; }
"until"             { return UNTIL; }
"for"               { return FOR; }
"switch"            { return SWITCH; }
"case"              { return CASE; }
"break"             { return BREAK; }
"continue"          { return CONTINUE; }
"function"          { return FUNCTION; }
"var"               { return VAR; }
"const"             { return CONST; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }
"=="                { return EQ; }
"!="                { return NEQ; }
"<"                 { return LT; }
">"                 { return GT; }
"<="                { return LEQ; }
">="                { return GEQ; }
"+"                 { return PLUS; }
"-"                 { return MINUS; }
"*"                 { return TIMES; }
"/"                 { return DIVIDE; }
"="                 { return ASSIGN; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
":"                 { return COLON; }
";"                 { return SEMICOLON; }
[ \t\n]             ; // Ignore whitespace and newline
.                   { printf("Invalid character"); }
%%

int yywrap() {
    return 1;
}
