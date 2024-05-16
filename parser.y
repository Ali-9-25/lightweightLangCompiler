%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "node.h"
#define MAX_SYMBOLS 1000
/* Symbol table structure */
struct symbol {
    char * name;
    char * data_type; // 0 for int, 1 for float
    char * type;  // keyword, constant, variable
    int line_no; // line number too check if the variable is initialized or if the closest scope control token
};

nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
//TODO: Add unary operators such as ++, --, !, ~, etc.
struct symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
// int count = 0;
extern FILE *yyin;
void yyerror(const char *s);
int yylex();
int lookup_symbol(char *name);
void add(char c, char * name, char * type);
char * charToString(char c);
extern int countn; // line count
%}

%union {
    int intval;
    float floatval;
    char *strval;
    int num;   // integer
    char *str; // string 
    float f;   // float
    int b;    // bool
    char c;    // char
    struct {
        int num;
        char *str;
        float f;
        int b;
        char c;
    } term;
    struct var_name {
        char name[100];
        struct node* nd;
    } nd_obj;
}

%token <num> NUMBER          // integer
%token <f> FLOATING_NUMBER   // floating number
%token <str> STRING_LITERAL  // string 
%token <str> IDENTIFIER      // variables
%token <c> CHARACTER_LITERAL // char
%token <b> TRUE FALSE        // boolean values
%token <c> COMMA //comma for seperation -> ,
/* keywords */
%token <nd_obj> IF ELSE WHILE REPEAT UNTIL FOR SWITCH CASE BREAK CONTINUE CONST INT FLOAT BOOL STRING CHAR VOID RETURN DEFAULT
/* operators */
%token <nd_obj> EQ NEQ LT GT LEQ GEQ PLUS MINUS TIMES DIVIDE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON POWER UNARY
%token <nd_obj> AND OR NOT 


%type <num> expr TERM
%type <str> stmt_list stmt if_stmt while_stmt repeat_stmt for_stmt switch_stmt func_decl var_decl const_decl func_call return_stmt DATATYPE assignment_stmt case_list dec_param_list call_param_list scope

%left PLUS MINUS
%left TIMES DIVIDE
%left EQ NEQ
%left LT GT LEQ GEQ
%right POWER
%right UNARY
%nonassoc UMINUS

%%
//program: This is the start symbol of the grammar. It represents the entire program and consists of a stmt_list
/* program: stmt_list
       ; */

/*stmt_list: This rule defines a list of statements. 
It can either be empty or consist of multiple statements (stmt) separated by semicolons.
*/
stmt_list   : stmt stmt_list   {printf("stmt_list\n");}
            | scope 
            |            {printf("stmt epsilon\n");}
            ;

//TODO: call func to construct symbol table
scope : LBRACE stmt_list RBRACE stmt_list  {printf("{scope}\n");} ;
/* 
scope_open: 



scope_close:  */

/*
stmt: This rule defines various types of statements in the language, 
including control flow statements (if, while, etc.), function declarations, variable and constant declarations, 
assignment statements, and simple expressions followed by a semicolon.
*/
stmt: if_stmt       {printf("if statement\n");}
    | while_stmt    {printf("while statement\n");}
    | repeat_stmt   {printf("repeat statement\n");}
    | for_stmt      {printf("for statement\n");}
    | switch_stmt   {printf("switch statement\n");}
    | func_decl     {printf("function declaration\n");}
    /* | func_call SEMICOLON     {printf("function call\n");} */
    | var_decl      {printf("variable declaration\n");}
    | const_decl    {printf("constant declaration\n");}
    | assignment_stmt   {printf("assignment statement\n");}
    | expr SEMICOLON    {printf("expression\n");}
    | return_stmt SEMICOLON   {printf("return statement\n");}
    | BREAK SEMICOLON   {printf("break statement\n");}
    | CONTINUE SEMICOLON   {printf("continue statement\n");}
    ;

return_stmt:  RETURN    {printf("return\n");          }
            | RETURN TERM   {printf("return term\n"); }
            | RETURN expr   {printf("return expr\n"); }
            ;
/*
if_stmt: This rule defines the syntax for if statements. 
It can be a simple if statement or an if-else statement, both followed by a block of statements.
Similarly, the rules for while_stmt, repeat_stmt, for_stmt, switch_stmt, func_decl, var_decl, 
and const_decl define the syntax for their respective constructs.
*/
if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE                                  {printf("if (expr) {stmt_list}\n");}
       | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE     {printf("if (expr) {stmt_list} else {stmt_list}\n");}
       ;

while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE    {printf("while (expr) {stmt_list}\n");}
          ;

repeat_stmt: REPEAT LBRACE stmt_list RBRACE UNTIL LPAREN expr RPAREN SEMICOLON  {printf("repeat {stmt_list} until (expr)\n");}
           ;

for_stmt: FOR LPAREN var_decl expr SEMICOLON IDENTIFIER ASSIGN expr RPAREN LBRACE stmt_list RBRACE {printf("for (assignment; expr; assignment) {stmt_list}\n"); }
        ;

switch_stmt: SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE  {printf("switch (expr) {case_list}\n"); }
            ;

case_list:    CASE expr COLON stmt_list case_list   {printf("case expr: stmt_list case_list\n"); }
            | CASE TERM COLON stmt_list  case_list  {printf("case term: stmt_list case_list\n"); }
            | CASE expr COLON stmt_list             {printf("case expr: stmt_list\n");           }
            | CASE TERM COLON stmt_list             {printf("case term: stmt_list\n");           }
            | DEFAULT COLON stmt_list               {printf("default: stmt_list\n");             }
            ;  

func_decl: DATATYPE IDENTIFIER LPAREN dec_param_list RPAREN LBRACE stmt_list RBRACE  {printf("data_type identifier (dec_param_list) {stmt_list}\n");  add('F', $2, $1);}
         | DATATYPE IDENTIFIER LPAREN dec_param_list RPAREN SEMICOLON                {printf("data_type identifier () {stmt_list}\n");                add('F', $2, $1);}
         ;

func_call: IDENTIFIER LPAREN  call_param_list RPAREN  {printf("identifier (call_param_list) ;\n"); add('F', $1, "N/A");}
         | IDENTIFIER LPAREN RPAREN                   {printf("identifier () ;\n");                add('F', $1, "N/A");}
         ;

/* param_list: param_list IDENTIFIER
          | IDENTIFIER
          | /* Empty */
          /* ; */

dec_param_list: DATATYPE IDENTIFIER COMMA dec_param_list        {printf("data_type identifier , dec_param_list\n");  add('V', $2, $1);}
              | DATATYPE IDENTIFIER                             {printf("data_type identifier\n");                   add('V', $2, $1);}
              ;

call_param_list: expr COMMA call_param_list      {printf("identifier , call_param_list\n");}
               | expr                            {printf("data_type identifier\n");}
               | TERM COMMA call_param_list      {printf("term , call_param_list\n");}
               | TERM                            {printf("term\n");}
               ;

/*
var_decl: This rule defines the syntax for variable declarations, 
where a variable is declared with the VAR keyword followed by an identifier and a semicolon.
*/
var_decl: DATATYPE IDENTIFIER SEMICOLON              {printf("data_type identifier; \n");         add('V', $2, $1);}
        | DATATYPE IDENTIFIER ASSIGN TERM SEMICOLON  {printf("%s %s %s Term;\n",$1, $2, $3);      add('V', $2, $1); }
        | DATATYPE IDENTIFIER ASSIGN expr SEMICOLON  {printf("data_type identifier = expr ;\n");  add('V', $2, $1); }
        ;

/*
const_decl: This rule defines the syntax for constant declarations, 
where a constant is declared with the CONST keyword followed by an identifier, an assignment operator, a number, and a semicolon.
*/
const_decl: CONST DATATYPE IDENTIFIER ASSIGN TERM SEMICOLON  {printf("const data_type identifier = term ;\n"); add('V', $3, $2);}
          ;

/*
assignment_stmt: This rule defines the syntax for assignment statements, 
where an identifier is assigned the value of an expression followed by a semicolon.
*/
//TODO: add function to check if identifier is available in symbol table
assignment_stmt: IDENTIFIER ASSIGN TERM SEMICOLON   {printf("identifier = term ;\n");   add('V', $1, "N/A");}
               | IDENTIFIER ASSIGN expr SEMICOLON   {printf("identifier = expr ;\n");   add('V', $1, "N/A");}
               ;

/*
expr: This rule defines arithmetic expressions, 
which can involve addition, subtraction, multiplication, division, parentheses, identifiers, and numbers.
*/

expr: expr EQ IDENTIFIER                    {printf("expr == identifer\n");  add('V', $3, "N/A");}
    | expr NEQ IDENTIFIER                   {printf("expr != identifer\n");  add('V', $3, "N/A");}
    | expr LT IDENTIFIER                    {printf("expr < identifer\n");   add('V', $3, "N/A");}
    | expr GT IDENTIFIER                    {printf("expr > identifer\n");   add('V', $3, "N/A");}
    | expr LEQ IDENTIFIER                   {printf("expr <= identifer\n");  add('V', $3, "N/A");}
    | expr GEQ IDENTIFIER                   {printf("expr >= identifer\n");  add('V', $3, "N/A");}
    | expr DIVIDE IDENTIFIER                {printf("expr / identifer\n");   add('V', $3, "N/A");}
    | expr TIMES IDENTIFIER                 {printf("expr * identifer\n");   add('V', $3, "N/A");}
    | expr MINUS IDENTIFIER                 {printf("expr - identifer\n");   add('V', $3, "N/A");}
    | expr PLUS IDENTIFIER                  {printf("expr + identifer\n");   add('V', $3, "N/A");}
    | UNARY IDENTIFIER                      {printf("unary expr\n");     add('V', $2, "N/A");}
    | IDENTIFIER UNARY                      {printf("identifer unary\n");add('V', $1, "N/A");}
    | expr PLUS TERM                        {printf("expr + term\n");  }
    | expr MINUS TERM                       {printf("expr - term\n");  }
    | expr TIMES TERM                       {printf("expr * term\n");  }
    | expr DIVIDE TERM                      {printf("expr / term\n");  }
    | expr EQ TERM                          {printf("expr == term\n"); }    
    | expr NEQ TERM                         {printf("expr != term\n"); }
    | expr LT TERM                          {printf("expr < term\n");  }
    | expr GT TERM                          {printf("expr > term\n");  }
    | expr LEQ TERM                         {printf("expr <= term\n"); }
    | expr GEQ TERM                         {printf("expr >= term\n"); }
    | expr POWER TERM                       {printf("expr ^ term\n");  }
    | expr AND TERM                         {printf("expr && term\n"); }
    | expr OR TERM                          {printf("expr || term\n"); }
    | NOT TERM                              {printf("!term\n");        }
    | LPAREN expr RPAREN %prec UMINUS       {printf("(expr)\n");}
    | expr PLUS LPAREN expr RPAREN          {printf("expr + (expr)\n"); }
    | expr MINUS LPAREN expr RPAREN         {printf("expr - (expr)\n"); }
    | expr TIMES LPAREN expr RPAREN         {printf("expr * (expr)\n"); }
    | expr DIVIDE LPAREN expr RPAREN        {printf("expr / (expr)\n"); }
    | expr EQ LPAREN expr RPAREN            {printf("expr == (expr)\n");}
    | expr NEQ LPAREN expr RPAREN           {printf("expr != (expr)\n");}
    | expr LT LPAREN expr RPAREN            {printf("expr < (expr)\n"); }
    | expr GT LPAREN expr RPAREN            {printf("expr > (expr)\n"); }
    | expr LEQ LPAREN expr RPAREN           {printf("expr <= (expr)\n");}
    | expr GEQ LPAREN expr RPAREN           {printf("expr >= (expr)\n");}
    | expr POWER LPAREN expr RPAREN         {printf("expr ^ (expr)\n"); }
    | expr AND LPAREN expr RPAREN           {printf("expr && (expr)\n");}
    | expr OR LPAREN expr RPAREN            {printf("expr || (expr)\n");}
    | NOT LPAREN expr RPAREN                {printf("! (expr)\n");      }  
    | IDENTIFIER                            {printf("identifier\n");    }
    | func_call                             {printf("function call\n");}
    ;

/*     
TERM: NUMBER
    | TRUE
    | FALSE
    | CHARACTER_LITERAL
    | STRING_LITERAL
    | FLOATING_NUMBER
    ; */
    
TERM: NUMBER            {printf("number\n");}
    | TRUE              {printf("true\n");}
    | FALSE             {printf("false\n");}                  
    | CHARACTER_LITERAL {printf("char\n");}
    | STRING_LITERAL    {printf("string\n");}
    | FLOATING_NUMBER   {printf("float\n");}
    ;



DATATYPE: INT     {printf("int\n");    $$ = $1}
        | BOOL    {printf("bool\n");   $$ = $1}
        | CHAR    {printf("char\n");   $$ = $1}
        | STRING  {printf("string\n"); $$ = $1}
        | FLOAT   {printf("float\n");  $$ = $1}
        | VOID    {printf("void\n");   $$ = $1}
        ;
%%
char * charToString(char c) {
    static char str[2]; // Make sure it's large enough to hold the character and the null terminator
    str[0] = c;
    str[1] = '\0'; // Null-terminate the string
    return str;
}

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}
void add(char c, char * name, char * type){
    else if(c == 'V'){ //variable
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].data_type = type;
        symbol_table[symbol_count].type = "Variable";
        symbol_table[symbol_count].line_no = countn;
        symbol_count++;
    }
    else if(c == 'F'){
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].data_type = type;
        symbol_table[symbol_count].type = "Function";
        symbol_table[symbol_count].line_no = countn;
        symbol_count++; 
    }
    printf("current symbol count = %d\n", symbol_count);
}
/*
yyerror: This function is called when there's a syntax error in the input.
It prints an error message and exits the program.
*/
void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    /* exit(1); */
}

/*
lookup_symbol: This function searches for a symbol in the symbol table by name.
If the symbol is found, it returns its index in the table; otherwise, it returns -1.
*/
int lookup_symbol(char *name) {
    for (int i = 0; i < symbol_count; i++) {
        if (strcmp(symbol_table[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

/*
add_symbol: This function adds a new symbol to the symbol table.
It checks if the symbol is already declared or if the table is full before adding the symbol.
*/
/*
main: This is the entry point of the program. It checks if the input file is provided as a command-line argument, 
opens the file, sets yyin to point to it, calls yyparse() to start parsing, and then closes the file. 
If there's an error opening the file, it prints an error message and exits.
*/
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s input_file\n", argv[0]);
        return 1;
    }
    FILE *input_file = fopen(argv[1], "r");
    if (!input_file) {
        fprintf(stderr, "Error: Cannot open input file %s\n", argv[1]);
        return 1;
    }
    yyin = input_file;
    yyparse();
    fclose(input_file);
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<symbol_count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<symbol_count;i++) {
		free(symbol_table[i].name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    return 0;
}

/* int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
} */