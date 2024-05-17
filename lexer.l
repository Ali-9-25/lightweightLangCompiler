%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countn = 1;
%}
%option yylineno

/* #define YY_DECL int yylex() */
/* #define YY_DECL int yylex(yylval_param_type *yylval, yytext_param_type *yytext, yystate_param_type *yystate) */
/* %option yylineno */
unary "++"|"--"

%%
"if"                {yylval.str = strdup(yytext); return IF; }
"else"              {yylval.str = strdup(yytext); return ELSE; }
"while"             {yylval.str = strdup(yytext); return WHILE; }
"repeat"            {yylval.str = strdup(yytext); return REPEAT; }
"until"             {yylval.str = strdup(yytext); return UNTIL; }
"for"               {yylval.str = strdup(yytext); return FOR; }
"switch"            {yylval.str = strdup(yytext); return SWITCH; }
"case"              {yylval.str = strdup(yytext); return CASE; }
"break"             {yylval.str = strdup(yytext); return BREAK; }
"default"           {yylval.str = strdup(yytext); return DEFAULT; }
"continue"          {yylval.str = strdup(yytext); return CONTINUE; }
"return"            {yylval.str = strdup(yytext); return RETURN; }
"const"             {yylval.str = strdup(yytext); return CONST; }

"int"               {yylval.str = strdup(yytext); return INT; }         
"float"             {yylval.str = strdup(yytext); return FLOAT; }      
"bool"              {yylval.str = strdup(yytext); return BOOL; }      
"string"            {yylval.str = strdup(yytext); return STRING; }   
"char"              {yylval.str = strdup(yytext); return CHAR; } 
"void"              {yylval.str = strdup(yytext); return VOID; }   

"true"              {yylval.str = strdup(yytext); return TRUE; }   
"false"             {yylval.str = strdup(yytext); return FALSE; } 
"=="                {yylval.str = strdup(yytext); return EQ; }
"!="                {yylval.str = strdup(yytext); return NEQ; }
"<"                 {yylval.str = strdup(yytext); return LT; }
">"                 {yylval.str = strdup(yytext); return GT; }
"<="                {yylval.str = strdup(yytext); return LEQ; }
">="                {yylval.str = strdup(yytext); return GEQ; }
"+"                 {yylval.str = strdup(yytext); return PLUS; }
"-"                 {yylval.str = strdup(yytext); return MINUS; }
"*"                 {yylval.str = strdup(yytext); return TIMES; }
"/"                 {yylval.str = strdup(yytext); return DIVIDE; }
{unary}             {yylval.str = strdup(yytext); return UNARY;}
"^"                 {yylval.str = strdup(yytext); return POWER; }  
"="                 {yylval.str = strdup(yytext); return ASSIGN; }
"("                 {yylval.str = strdup(yytext); return LPAREN; }
")"                 {yylval.str = strdup(yytext); return RPAREN; }
"{"                 {yylval.str = strdup(yytext); return LBRACE;} 
"}"                 {yylval.str = strdup(yytext); return RBRACE; }
":"                 {yylval.str = strdup(yytext); return COLON; }
";"                 {yylval.str = strdup(yytext); return SEMICOLON; countn++; printf("%d\n",countn);}
","                 {yylval.str = strdup(yytext); return COMMA; }
"and"               {yylval.str = strdup(yytext); return AND; }
"or"                {yylval.str = strdup(yytext); return OR; }
"not"               {yylval.str = strdup(yytext); return NOT; }
[0-9]+              { yylval.str = strdup(yytext); return NUMBER; }
[-+]?[0-9]+\.[0-9]+ { yylval.str = strdup(yytext); return FLOATING_NUMBER; }
"\"([^\"\\]|\\.)*\"" { yylval.str = strdup(yytext); return STRING_LITERAL; }
"\'([^\"\\]|\\.)*\'" { yylval.str = strdup(yytext); return CHARACTER_LITERAL; }
[a-zA-Z_][a-zA-Z0-9_]*  { yylval.str = strdup(yytext); return IDENTIFIER; }


\/\/.*                   { ; }
\/\*([^*]|\*[^/])*\*\/   { ; } 
\t             ; // Ignore whitespace and newline
\n                       { countn++; printf("%d\n",countn);}

%%

int yywrap() {
    return 1;
}
