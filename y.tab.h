/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     NUMBER = 258,
     FLOATING_NUMBER = 259,
     STRING_LITERAL = 260,
     IDENTIFIER = 261,
     CHARACTER_LITERAL = 262,
     TRUE = 263,
     FALSE = 264,
     COMMA = 265,
     IF = 266,
     ELSE = 267,
     WHILE = 268,
     REPEAT = 269,
     UNTIL = 270,
     FOR = 271,
     SWITCH = 272,
     CASE = 273,
     BREAK = 274,
     CONTINUE = 275,
     CONST = 276,
     INT = 277,
     FLOAT = 278,
     BOOL = 279,
     STRING = 280,
     CHAR = 281,
     VOID = 282,
     RETURN = 283,
     DEFAULT = 284,
     EQ = 285,
     NEQ = 286,
     LT = 287,
     GT = 288,
     LEQ = 289,
     GEQ = 290,
     PLUS = 291,
     MINUS = 292,
     TIMES = 293,
     DIVIDE = 294,
     ASSIGN = 295,
     LPAREN = 296,
     RPAREN = 297,
     LBRACE = 298,
     RBRACE = 299,
     SEMICOLON = 300,
     COLON = 301,
     POWER = 302,
     UNARY = 303,
     AND = 304,
     OR = 305,
     NOT = 306,
     UMINUS = 307
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define FLOATING_NUMBER 259
#define STRING_LITERAL 260
#define IDENTIFIER 261
#define CHARACTER_LITERAL 262
#define TRUE 263
#define FALSE 264
#define COMMA 265
#define IF 266
#define ELSE 267
#define WHILE 268
#define REPEAT 269
#define UNTIL 270
#define FOR 271
#define SWITCH 272
#define CASE 273
#define BREAK 274
#define CONTINUE 275
#define CONST 276
#define INT 277
#define FLOAT 278
#define BOOL 279
#define STRING 280
#define CHAR 281
#define VOID 282
#define RETURN 283
#define DEFAULT 284
#define EQ 285
#define NEQ 286
#define LT 287
#define GT 288
#define LEQ 289
#define GEQ 290
#define PLUS 291
#define MINUS 292
#define TIMES 293
#define DIVIDE 294
#define ASSIGN 295
#define LPAREN 296
#define RPAREN 297
#define LBRACE 298
#define RBRACE 299
#define SEMICOLON 300
#define COLON 301
#define POWER 302
#define UNARY 303
#define AND 304
#define OR 305
#define NOT 306
#define UMINUS 307




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 35 "parser.y"
{
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
/* Line 1529 of yacc.c.  */
#line 168 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

