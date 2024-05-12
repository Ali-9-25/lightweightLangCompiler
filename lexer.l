%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countn = 1;
%}

/* #define YY_DECL int yylex() */
/* #define YY_DECL int yylex(yylval_param_type *yylval, yytext_param_type *yytext, yystate_param_type *yystate) */
/* %option yylineno */
unary "++"|"--"

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
"default"           { return DEFAULT; }
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
{unary}             {return UNARY;}
"^"                 { return POWER; }  
"="                 { return ASSIGN; }
"("                 { return LPAREN; }
")"                 { return RPAREN; }
"{"                 { return LBRACE;} 
"}"                 { return RBRACE; }
":"                 { return COLON; }
";"                 { return SEMICOLON; }
","                 { return COMMA; }
"and"               { return AND; }
"or"                { return OR; }
"not"               { return NOT; }
[0-9]+              { yylval.num = atoi(yytext); return NUMBER; }
[-+]?[0-9]+\.[0-9]+ { yylval.f = atof(yytext); return FLOATING_NUMBER; }
"\"([^\"\\]|\\.)*\"" { yylval.str = strdup(yytext); return STRING_LITERAL; }
'\''.'\''           { yylval.c = yytext[1]; return CHARACTER_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }


\/\/.*              { ; }
\/\*([^*]|\*[^/])*\*\/   { ; } 
\t             ; // Ignore whitespace and newline
.                   { printf("Invalid character\n"); }
\n                  { countn++; }

%%

int yywrap() {
    return 1;
}
