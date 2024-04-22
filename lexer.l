%{
#include "parser.tab.h"
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
"return"            { return RETURN; }
"const"             { return CONST; }

      
"int"               { return INT; }         
"float"             { return FLOAT; }      
"bool"              { return BOOL; }      
"string"            { return STRING; }   
"char"              { return CHAR; } 
"void"              { return VOID; }   



"true"              { return TRUE; }   
"false"             { return FALSE; } 
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[-+]?[0-9]+\.[0-9]+ {yylval.f = atof(yytext); return FLOATING_NUMBER; }
""(\.|[^"])*""      { yylval.str = strdup(yytext); return STRING_LITERAL; }
'\''.'\''           { yylval.c = yytext[1]; return CHARACTER_LITERAL; }
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
"^"                 { return POWER; }  
"="                 { return ASSIGN; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
":"                 { return COLON; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
"^"                 { return POWER; }
"and"               { return AND; }
"or"                { return OR; }
"not"               { return NOT; }
\/\/.*              { ; }
\/\*(.*\n)*.*\*\/   { ; } 
[ \t\n]             ; // Ignore whitespace and newline
.                   { printf("Invalid character"); }
%%

int yywrap() {
    return 1;
}
