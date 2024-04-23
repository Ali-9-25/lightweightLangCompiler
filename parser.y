%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* Symbol table structure */
struct symbol {
    char *name;
    char* data_type; // 0 for int, 1 for float
    char * type;  // keyword, constant, variable
    int line_no; // line number too check if the variable is initialized or if the closest scope control token
};
//TODO: Add unary operators such as ++, --, !, ~, etc.

#define MAX_SYMBOLS 1000
struct symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
// int count = 0;
extern FILE *yyin;
void yyerror(const char *s);
int yylex();
int lookup_symbol(char *name);
void add_symbol(char *name, int type, int initialized);
// void insert_type();
// int search(char *type);
// void add(char c);
%}

%union {
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
}

%token <num> NUMBER          // integer
%token <f> FLOATING_NUMBER   // floating number
%token <str> STRING_LITERAL  // string 
%token <str> IDENTIFIER      // variables
%token <c> CHARACTER_LITERAL // char
%token <b> TRUE FALSE        // boolean values
%token <c> COMMA //comma for seperation -> ,
/* keywords */
%token <str> IF ELSE WHILE REPEAT UNTIL FOR SWITCH CASE BREAK CONTINUE CONST INT FLOAT BOOL STRING CHAR VOID RETURN
/* operators */
%token <str> EQ NEQ LT GT LEQ GEQ PLUS MINUS TIMES DIVIDE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON POWER
%token <str> AND OR NOT 



%type <term> expr TERM
%type <str> stmt_list stmt if_stmt while_stmt repeat_stmt for_stmt switch_stmt func_decl var_decl const_decl func_call return_stmt DATATYPE assignment_stmt case_list dec_param_list call_param_list 

%left PLUS MINUS
%left TIMES DIVIDE
%left EQ NEQ
%left LT GT LEQ GEQ
%right POWER
%nonassoc UMINUS

%%
//program: This is the start symbol of the grammar. It represents the entire program and consists of a stmt_list
/* program: stmt_list
       ; */

/*stmt_list: This rule defines a list of statements. 
It can either be empty or consist of multiple statements (stmt) separated by semicolons.
*/
stmt_list: stmt stmt_list 
         | stmt
         ;

/*
stmt: This rule defines various types of statements in the language, 
including control flow statements (if, while, etc.), function declarations, variable and constant declarations, 
assignment statements, and simple expressions followed by a semicolon.
*/
stmt: if_stmt
    | while_stmt
    | repeat_stmt
    | for_stmt
    | switch_stmt
    | func_decl
    | func_call
    | var_decl
    | const_decl
    | assignment_stmt
    | expr SEMICOLON
    | return_stmt
    | BREAK
    | CONTINUE
    ;

return_stmt:  RETURN
            | RETURN TERM
            ;
/*
if_stmt: This rule defines the syntax for if statements. 
It can be a simple if statement or an if-else statement, both followed by a block of statements.
Similarly, the rules for while_stmt, repeat_stmt, for_stmt, switch_stmt, func_decl, var_decl, 
and const_decl define the syntax for their respective constructs.
*/
if_stmt: IF LPAREN expr RPAREN LBRACE stmt_list RBRACE
       | IF LPAREN expr RPAREN LBRACE stmt_list RBRACE ELSE LBRACE stmt_list RBRACE 
       ;

while_stmt: WHILE LPAREN expr RPAREN LBRACE stmt_list RBRACE
          ;

repeat_stmt: REPEAT LBRACE stmt_list RBRACE UNTIL LPAREN expr RPAREN SEMICOLON
           ;

for_stmt: FOR LPAREN assignment_stmt SEMICOLON expr SEMICOLON assignment_stmt RPAREN LBRACE stmt_list RBRACE
        ;

switch_stmt: SWITCH LPAREN expr RPAREN LBRACE case_list RBRACE
            ;

case_list: CASE expr COLON stmt_list case_list
         | CASE expr COLON stmt_list
         ;

func_decl: DATATYPE IDENTIFIER LPAREN dec_param_list RPAREN LBRACE stmt_list RBRACE
         ;

func_call: IDENTIFIER LPAREN  call_param_list RPAREN SEMICOLON
         | IDENTIFIER LPAREN RPAREN SEMICOLON
         ;

/* param_list: param_list IDENTIFIER
          | IDENTIFIER
          | /* Empty */
          /* ; */

dec_param_list: DATATYPE IDENTIFIER COMMA dec_param_list
              | DATATYPE IDENTIFIER 
              ;

call_param_list: IDENTIFIER COMMA call_param_list
               | DATATYPE IDENTIFIER
               ;

/*
var_decl: This rule defines the syntax for variable declarations, 
where a variable is declared with the VAR keyword followed by an identifier and a semicolon.
*/
var_decl: DATATYPE IDENTIFIER SEMICOLON
        | DATATYPE IDENTIFIER ASSIGN TERM SEMICOLON
        ;

/*
const_decl: This rule defines the syntax for constant declarations, 
where a constant is declared with the CONST keyword followed by an identifier, an assignment operator, a number, and a semicolon.
*/
const_decl: CONST IDENTIFIER ASSIGN TERM SEMICOLON
          ;

/*
assignment_stmt: This rule defines the syntax for assignment statements, 
where an identifier is assigned the value of an expression followed by a semicolon.
*/
assignment_stmt: IDENTIFIER ASSIGN expr SEMICOLON
               ;

/*
expr: This rule defines arithmetic expressions, 
which can involve addition, subtraction, multiplication, division, parentheses, identifiers, and numbers.
*/

expr: expr EQ IDENTIFIER
    | expr NEQ IDENTIFIER
    | expr LT IDENTIFIER
    | expr GT IDENTIFIER
    | expr LEQ IDENTIFIER
    | expr GEQ IDENTIFIER 
    | expr DIVIDE IDENTIFIER
    | expr TIMES IDENTIFIER
    | expr MINUS IDENTIFIER
    | expr PLUS IDENTIFIER
    /* | expr POWER IDENTIFIER
    | expr AND IDENTIFIER
    | expr OR IDENTIFIER
    | NOT expr  */
    | expr PLUS TERM
    | expr MINUS TERM
    | expr TIMES TERM
    | expr DIVIDE TERM
    | expr EQ TERM
    | expr NEQ TERM
    | expr LT TERM
    | expr GT TERM
    | expr LEQ TERM
    | expr GEQ TERM
    | expr POWER TERM
    | expr AND TERM
    | expr OR TERM
    | NOT TERM 
    | LPAREN expr RPAREN %prec UMINUS
    | IDENTIFIER
    | TERM
    ;

    
TERM: NUMBER
    | TRUE
    | FALSE
    | CHARACTER_LITERAL
    | STRING_LITERAL
    | FLOATING_NUMBER
    ;



DATATYPE: INT
        | BOOL
        | CHAR
        | STRING
        | FLOAT
        | VOID
%%

/*
yyerror: This function is called when there's a syntax error in the input.
It prints an error message and exits the program.
*/
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
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
/* /*
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
    return 0;
}
