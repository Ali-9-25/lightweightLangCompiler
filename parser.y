%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/* Symbol table structure */
struct datatype {
    char *id_name;
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
int yywrap();
void insert_type();
void add(char c);

char type[10];
int q = 0;

extern int countn;
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


/*
H -> Header files
K -> Keywords -> for , if , else
V -> variables
C -> constant
F ->functions

*/
%token <num> NUMBER          // integer
%token <f> FLOATING_NUMBER   // floating number
%token <str> STRING_LITERAL  // string 
%token <str> IDENTIFIER      // variables
%token <c> CHARACTER_LITERAL // char
%token <b> TRUE FALSE        // boolean values
%token <c> COMMA //comma for seperation -> ,
/* keywords */
%token <str> IF ELSE WHILE REPEAT UNTIL FOR SWITCH CASE BREAK CONTINUE CONST INT FLOAT BOOL STRING CHAR VOID RETURN DEFAULT
/* operators */
%token <str> EQ NEQ LT GT LEQ GEQ PLUS MINUS TIMES DIVIDE ASSIGN LPAREN RPAREN LBRACE RBRACE SEMICOLON COLON POWER UNARY
%token <str> AND OR NOT 



%type <num> expr TERM
%type <str> stmt_list stmt if_stmt while_stmt repeat_stmt for_stmt switch_stmt func_decl var_decl const_decl func_call return_stmt DATATYPE assignment_stmt case_list dec_param_list call_param_list 

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
            | LBRACE {add("S");}  stmt_list RBRACE {add("S");}  stmt_list  {printf("{stmt_list}\n");}
            |                   {printf("stmt epsilon\n");}
            ;

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
    | BREAK SEMICOLON   {printf("break statement\n"); add("K");}
    | CONTINUE SEMICOLON   {printf("continue statement\n"); add("K");}
    ;

return_stmt:  RETURN {add("K");}        {printf("return\n");}
            | RETURN {add("K");} TERM   {printf("return term\n");}
            | RETURN {add("K");} expr   {printf("return expr\n");}
            ;
/*
if_stmt: This rule defines the syntax for if statements. 
It can be a simple if statement or an if-else statement, both followed by a block of statements.
Similarly, the rules for while_stmt, repeat_stmt, for_stmt, switch_stmt, func_decl, var_decl, 
and const_decl define the syntax for their respective constructs.
*/
if_stmt: IF {add("K");} LPAREN expr RPAREN LBRACE {add("S");} stmt_list RBRACE {add("S");}                                                                  {printf("if (expr) {stmt_list}\n");}
       | IF {add("K");} LPAREN expr RPAREN LBRACE {add("S");} stmt_list RBRACE {add("S");} ELSE {add("K");} LBRACE {add("S");} stmt_list RBRACE {add("S");} {printf("if (expr) {stmt_list} else {stmt_list}\n");}
       ;

while_stmt: WHILE{ add("K"); } LPAREN expr RPAREN LBRACE{ add("S"); } stmt_list RBRACE {add("S"); printf("while (expr) {stmt_list}\n");}
          ;

repeat_stmt: REPEAT{ add("K"); } LBRACE{ add("S"); } stmt_list RBRACE{ add("S"); } UNTIL{ add("K"); } LPAREN expr RPAREN SEMICOLON    {printf("repeat {stmt_list} until (expr)\n");}
           ;

for_stmt: FOR{ add("K"); } LPAREN var_decl expr SEMICOLON IDENTIFIER{ add("V"); } ASSIGN { add("O");} expr RPAREN LBRACE {add("S");} stmt_list RBRACE {add("S");} {printf("for (assignment; expr; assignment) {stmt_list}\n");}
        ;

switch_stmt: SWITCH {add("K");} LPAREN expr RPAREN LBRACE {add("S");} case_list RBRACE { add("S");} {printf("switch (expr) {case_list}\n");}
            ;

case_list:    CASE{ add("K");} expr COLON stmt_list case_list  {printf("case expr: stmt_list case_list\n");}
            | CASE{ add("K");} TERM COLON stmt_list  case_list  {printf("case term: stmt_list case_list\n");}
            /* | CASE{ add("K");} expr COLON stmt_list             {printf("case expr: stmt_list\n");}
            | CASE{ add("K");} TERM COLON stmt_list            {printf("case term: stmt_list\n");} */
            | DEFAULT{ add("K");} COLON stmt_list               {printf("default: stmt_list\n");}
            ;  

func_decl: DATATYPE IDENTIFIER {add("F");} LPAREN dec_param_list RPAREN LBRACE { add("S");}  stmt_list RBRACE {add("S");} {printf("data_type identifier (dec_param_list) {stmt_list}\n");}
         /* | DATATYPE IDENTIFIER {add("F");} LPAREN RPAREN  LBRACE { add("S");}  stmt_list RBRACE {add("S");}               {printf("data_type identifier () {stmt_list}\n");} */
         ;

func_call: IDENTIFIER {add("F");} LPAREN  call_param_list RPAREN  {printf("identifier (call_param_list) ;\n");}
         /* | IDENTIFIER {add("F");} LPAREN RPAREN                   {printf("identifier () ;\n");} */
         |
         ;

/* param_list: param_list IDENTIFIER
          | IDENTIFIER
          | /* Empty */
          /* ; */

dec_param_list: DATATYPE IDENTIFIER {add("V");} COMMA dec_param_list        {printf("data_type identifier , dec_param_list\n");}
              | DATATYPE IDENTIFIER {add("V");}                             {printf("data_type identifier\n");}
              |
              ;

call_param_list: expr COMMA call_param_list     {printf("identifier , call_param_list\n");}
               | expr                           {printf("data_type identifier\n");}
               | TERM COMMA call_param_list     {printf("term , call_param_list\n");}
               | TERM                           {printf("term\n");}
               ;

/*
var_decl: This rule defines the syntax for variable declarations, 
where a variable is declared with the VAR keyword followed by an identifier and a semicolon.
*/
var_decl: DATATYPE IDENTIFIER {add("V");} SEMICOLON             {printf("data_type identifier; \n");}
        | DATATYPE IDENTIFIER {add("V");} ASSIGN {add("O");} TERM SEMICOLON {printf("data_type identifier = term ;\n");} 
        | DATATYPE IDENTIFIER {add("V");} ASSIGN {add("O");} expr SEMICOLON  {printf("data_type identifier = expr ;\n");}
        ;

/*
const_decl: This rule defines the syntax for constant declarations, 
where a constant is declared with the CONST keyword followed by an identifier, an assignment operator, a number, and a semicolon.
*/
const_decl: CONST{ add("K");} DATATYPE IDENTIFIER{ add("V");} ASSIGN { add("O");} TERM SEMICOLON  {printf("const data_type identifier = term ;\n");}
          ;

/*
assignment_stmt: This rule defines the syntax for assignment statements, 
where an identifier is assigned the value of an expression followed by a semicolon.
*/
assignment_stmt: IDENTIFIER {add("V");} ASSIGN { add("O");} TERM SEMICOLON   {printf("identifier = term ;\n");}
               | IDENTIFIER {add("V");} ASSIGN { add("O");} expr SEMICOLON   {printf("identifier = expr ;\n");}
               ;

/*
expr: This rule defines arithmetic expressions, 
which can involve addition, subtraction, multiplication, division, parentheses, identifiers, and numbers.
*/

expr: expr EQ {add("O");} IDENTIFIER {add("V");}    {printf("expr == identifer\n");}
    | expr NEQ {add("O");} IDENTIFIER {add("V");}   {printf("expr != identifer\n");}
    | expr LT {add("O");} IDENTIFIER {add("V");}    {printf("expr < identifer\n");}
    | expr GT {add("O");} IDENTIFIER {add("V");}    {printf("expr > identifer\n");}
    | expr LEQ {add("O");} IDENTIFIER {add("V");}   {printf("expr <= identifer\n");}
    | expr GEQ {add("O");} IDENTIFIER {add("V");}   {printf("expr >= identifer\n");}
    | expr DIVIDE {add("O");} IDENTIFIER {add("V");}    {printf("expr / identifer\n");}
    | expr TIMES {add("O");} IDENTIFIER {add("V");} {printf("expr * identifer\n");}
    | expr MINUS {add("O");} IDENTIFIER {add("V");} {printf("expr - identifer\n");}
    | expr PLUS {add("O");} IDENTIFIER {add("V");}  {printf("expr + identifer\n");}
    | UNARY {add("O");} IDENTIFIER {add("V");}           {printf("unary expr\n");}
    | IDENTIFIER {add("V");} UNARY {add("O");}          {printf("identifer unary\n");}
    /* | expr POWER IDENTIFIER  
    | expr AND IDENTIFIER
    | expr OR IDENTIFIER
    | NOT expr  */
    | expr PLUS {add("O");} TERM    {printf("expr + term\n");}
    | expr MINUS {add("O");} TERM   {printf("expr - term\n");}
    | expr TIMES {add("O");} TERM   {printf("expr * term\n");}
    | expr DIVIDE {add("O");} TERM  {printf("expr / term\n");}
    | expr EQ {add("O");} TERM      {printf("expr == term\n");}    
    | expr NEQ {add("O");} TERM     {printf("expr != term\n");}
    | expr LT {add("O");} TERM      {printf("expr < term\n");}
    | expr GT {add("O");} TERM      {printf("expr > term\n");}
    | expr LEQ {add("O");} TERM     {printf("expr <= term\n");}
    | expr GEQ {add("O");} TERM     {printf("expr >= term\n");}
    | expr POWER {add("O");} TERM   {printf("expr ^ term\n");}
    | expr AND {add("O");} TERM     {printf("expr && term\n");}
    | expr OR {add("O");} TERM      {printf("expr || term\n");}
    | NOT {add("O");} TERM          {printf("!term\n");}
    | LPAREN expr RPAREN %prec UMINUS       {printf("(expr)\n");}
    | expr PLUS {add("O");} LPAREN expr RPAREN {printf("expr + (expr)\n");}
    | expr MINUS {add("O");} LPAREN expr RPAREN {printf("expr - (expr)\n");}
    | expr TIMES {add("O");} LPAREN expr RPAREN {printf("expr * (expr)\n");}
    | expr DIVIDE {add("O");} LPAREN expr RPAREN {printf("expr / (expr)\n");}
    | expr EQ {add("O");} LPAREN expr RPAREN {printf("expr == (expr)\n");}
    | expr NEQ {add("O");} LPAREN expr RPAREN {printf("expr != (expr)\n");}
    | expr LT {add("O");} LPAREN expr RPAREN {printf("expr < (expr)\n");}
    | expr GT {add("O");} LPAREN expr RPAREN {printf("expr > (expr)\n");}
    | expr LEQ {add("O");} LPAREN expr RPAREN {printf("expr <= (expr)\n");}
    | expr GEQ {add("O");} LPAREN expr RPAREN {printf("expr >= (expr)\n");}
    | expr POWER {add("O");} LPAREN expr RPAREN {printf("expr ^ (expr)\n");}
    | expr AND {add("O");} LPAREN expr RPAREN {printf("expr && (expr)\n");}
    | expr OR {add("O");} LPAREN expr RPAREN {printf("expr || (expr)\n");}
    | NOT LPAREN expr RPAREN {printf("! (expr)\n");}
    | IDENTIFIER {add("V");}    {printf("identifier\n");}
    | func_call    {printf("function call\n");}
    ;

/*     
TERM: NUMBER
    | TRUE
    | FALSE
    | CHARACTER_LITERAL
    | STRING_LITERAL
    | FLOATING_NUMBER
    ; */
    
TERM: NUMBER {add("C");}             {printf("number\n");}
    | TRUE {add("C");}               {printf("true\n");}
    | FALSE {add("C");}              {printf("false\n");}
    | CHARACTER_LITERAL {add("C");}  {printf("char\n");}
    | STRING_LITERAL {add("C");}     {printf("string\n");}
    | FLOATING_NUMBER {add("C");}    {printf("float\n");}
    ;



DATATYPE: INT {add("K");}
        | BOOL {add("K");}
        | CHAR {add("K");}
        | STRING {add("K");}
        | FLOAT {add("K");}
        | VOID {add("K");}
%%



void insert_type(){
    strcpy(type, yytext);
}
/*
yyerror: This function is called when there's a syntax error in the input.
It prints an error message and exits the program.
*/
void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
    exit(1);
}
/**/
void add(char c){
    q = search(yytext);
    if(!q){
        if(c == "H"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Header");
            symbol_count++;
        }
        else if(c == "K"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Keyword\t");
            symbol_count++;
        }
        else if(c == "V"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Variable");
            symbol_count++;
        }
        else if(c == "C"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("CONST");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Constant");
            symbol_count++;
        }
        else if(c == "F"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Function");
            symbol_count++;
        }
        else if(c == "O"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Operator");
            symbol_count++;
        }
        else if(c == "S"){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Scope");
            symbol_count++;
        }
    }
}
/*
lookup_symbol: This function searches for a symbol in the symbol table by name.
If the symbol is found, it returns its index in the table; otherwise, it returns -1.
*/
int lookup_symbol(char *type) {
    for (int i = symbol_count - 1; i >=0; i--) {
        if (strcmp(symbol_table[i].id_name, type) == 0) {
            return -1;
            break;
        }
        return 0;
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
      printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    fclose(input_file);
    return 0;
}
