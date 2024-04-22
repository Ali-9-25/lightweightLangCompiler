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
     IDENTIFIER = 259,
     IF = 260,
     ELSE = 261,
     WHILE = 262,
     REPEAT = 263,
     UNTIL = 264,
     FOR = 265,
     SWITCH = 266,
     CASE = 267,
     BREAK = 268,
     CONTINUE = 269,
     FUNCTION = 270,
     VAR = 271,
     CONST = 272,
     EQ = 273,
     NEQ = 274,
     LT = 275,
     GT = 276,
     LEQ = 277,
     GEQ = 278,
     PLUS = 279,
     MINUS = 280,
     TIMES = 281,
     DIVIDE = 282,
     ASSIGN = 283,
     LPAREN = 284,
     RPAREN = 285,
     LBRACE = 286,
     RBRACE = 287,
     SEMICOLON = 288,
     COLON = 289,
     UMINUS = 290
   };
#endif
/* Tokens.  */
#define NUMBER 258
#define IDENTIFIER 259
#define IF 260
#define ELSE 261
#define WHILE 262
#define REPEAT 263
#define UNTIL 264
#define FOR 265
#define SWITCH 266
#define CASE 267
#define BREAK 268
#define CONTINUE 269
#define FUNCTION 270
#define VAR 271
#define CONST 272
#define EQ 273
#define NEQ 274
#define LT 275
#define GT 276
#define LEQ 277
#define GEQ 278
#define PLUS 279
#define MINUS 280
#define TIMES 281
#define DIVIDE 282
#define ASSIGN 283
#define LPAREN 284
#define RPAREN 285
#define LBRACE 286
#define RBRACE 287
#define SEMICOLON 288
#define COLON 289
#define UMINUS 290




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 25 "parser.y"
{
    int num;
    char *str;
}
/* Line 1529 of yacc.c.  */
#line 124 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

