# lightweightLangCompiler

## Project Overview
The project aims to design and implement a programming language using Lex and Yacc compiler generating packages. The language includes features such as variables and constants declaration, mathematical and logical expressions, control flow statements (if-then-else, while loops, repeat-until loops, for loops, switch statement), block structure, and functions.

## Tools and Technologies Used
Lex and Yacc for lexical analysis and parsing
C programming language for implementation

## Tokens
The lexer recognizes the following tokens:
  Identifier: A sequence of letters and digits starting with a letter.
  Integer: A sequence of digits representing an integer number.
  Real: A sequence of digits with a decimal point representing a real number.
  String: A sequence of characters enclosed within double quotes.
  Keywords: Reserved words such as if, else, while, repeat, until, for, switch, case, break, continue, function, etc.
  Operators: Mathematical and logical operators such as +, -, *, /, ==, !=, >, <, >=, <=, &&, ||, etc.
  Punctuation: Symbols like ;, ,, (, ), {, }, [, ], etc.

## Syntax
Add description of our syntax if needed


## Quadruples
The parser generates quadruples for the program's control flow and expressions. Each quadruple consists of an operation and its operands. Example quadruples include:
  JMP L: Unconditional jump to label L.
  NEG V1, V2: V2 = -V1.

## Syntax Error Handling
A proper syntax error handler is implemented to display syntax errors found in the program.

## Semantic Analysis
A simple semantic analyzer is implemented to check for:
  Variable declaration conflicts
  Improper usage of variables regarding their type
  Variables used before being initialized and unused variables
