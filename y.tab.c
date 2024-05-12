/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "lex.yy.c"
/* Symbol table structure */
struct symbol {
    char* id_name;
    char* data_type; // 0 for int, 1 for float
    char* type;  // keyword, constant, variable
    int line_no; // line number too check if the variable is initialized or if the closest scope control token
};
//TODO: Add unary operators such as ++, --, !, ~, etc.

#define MAX_SYMBOLS 1000
struct symbol symbol_table[MAX_SYMBOLS];


// extern FILE *yyin;

void yyerror(const char *s);
int yylex();
int yywrap();
void add(char);
void insert_type();
int lookup_symbol(char *name);
// void add_symbol(char *name, int type, int initialized);

char type[10];
int q = 0;
int symbol_count = 0;
int countn = 0;


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 36 "parser.y"
{
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
}
/* Line 193 of yacc.c.  */
#line 253 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 266 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  57
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   815

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  124
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNRULES -- Number of states.  */
#define YYNSTATES  331

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   307

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     6,     7,     8,    15,    16,    18,    20,
      22,    24,    26,    28,    30,    32,    34,    37,    40,    43,
      46,    47,    50,    51,    55,    56,    60,    61,    62,    63,
      75,    76,    77,    78,    86,    87,    88,    89,    99,   100,
     101,   102,   103,   117,   118,   119,   120,   121,   122,   140,
     141,   142,   143,   154,   155,   162,   163,   170,   171,   176,
     177,   178,   179,   191,   192,   198,   199,   205,   206,   210,
     211,   214,   217,   218,   221,   222,   227,   228,   229,   236,
     239,   242,   243,   244,   245,   255,   256,   257,   263,   266,
     269,   270,   271,   277,   278,   279,   285,   286,   287,   293,
     294,   295,   301,   302,   303,   309,   310,   311,   317,   318,
     319,   325,   326,   327,   333,   334,   335,   341,   342,   343,
     349,   350,   351,   356,   357,   358,   363,   364,   369,   370,
     375,   376,   381,   382,   387,   388,   393,   394,   399,   400,
     405,   406,   411,   412,   417,   418,   423,   424,   429,   430,
     435,   436,   441,   442,   446,   450,   451,   458,   459,   466,
     467,   474,   475,   482,   483,   490,   491,   498,   499,   506,
     507,   514,   515,   522,   523,   530,   531,   538,   539,   546,
     547,   554,   559,   560,   563,   565,   566,   569,   570,   573,
     574,   577,   578,   581,   582,   585,   586,   589,   591,   593,
     595,   597,   599
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    57,    54,    -1,    -1,    -1,    43,    55,
      54,    44,    56,    54,    -1,    -1,    62,    -1,    70,    -1,
      73,    -1,    78,    -1,    84,    -1,    92,    -1,   103,    -1,
     108,    -1,   112,    -1,   116,    45,    -1,    58,    45,    -1,
      19,    45,    -1,    20,    45,    -1,    -1,    28,    59,    -1,
      -1,    28,    60,   169,    -1,    -1,    28,    61,   116,    -1,
      -1,    -1,    -1,    11,    63,    41,   116,    42,    43,    64,
      54,    44,    65,    66,    -1,    -1,    -1,    -1,    12,    67,
      43,    68,    54,    44,    69,    -1,    -1,    -1,    -1,    13,
      71,    41,   116,    42,    43,    72,    54,    44,    -1,    -1,
      -1,    -1,    -1,    14,    74,    43,    75,    54,    44,    76,
      15,    77,    41,   116,    42,    45,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    79,    41,   103,   116,    45,     6,    80,
      40,    81,   116,    42,    43,    82,    54,    44,    83,    -1,
      -1,    -1,    -1,    17,    85,    41,   116,    42,    43,    86,
      88,    44,    87,    -1,    -1,    18,    89,   116,    46,    54,
      88,    -1,    -1,    18,    90,   169,    46,    54,    88,    -1,
      -1,    29,    91,    46,    54,    -1,    -1,    -1,    -1,   176,
       6,    93,    41,    98,    42,    43,    94,    54,    44,    95,
      -1,    -1,     6,    97,    41,   101,    42,    -1,    -1,   176,
       6,    99,    10,    98,    -1,    -1,   176,     6,   100,    -1,
      -1,   116,   102,    -1,   169,   102,    -1,    -1,    10,   101,
      -1,    -1,   176,     6,   104,    45,    -1,    -1,    -1,   176,
       6,   105,    40,   106,   107,    -1,   169,    45,    -1,   116,
      45,    -1,    -1,    -1,    -1,    21,   109,   176,     6,   110,
      40,   111,   169,    45,    -1,    -1,    -1,     6,   113,    40,
     114,   115,    -1,   169,    45,    -1,   116,    45,    -1,    -1,
      -1,   116,    30,   117,     6,   118,    -1,    -1,    -1,   116,
      31,   119,     6,   120,    -1,    -1,    -1,   116,    32,   121,
       6,   122,    -1,    -1,    -1,   116,    33,   123,     6,   124,
      -1,    -1,    -1,   116,    34,   125,     6,   126,    -1,    -1,
      -1,   116,    35,   127,     6,   128,    -1,    -1,    -1,   116,
      39,   129,     6,   130,    -1,    -1,    -1,   116,    38,   131,
       6,   132,    -1,    -1,    -1,   116,    37,   133,     6,   134,
      -1,    -1,    -1,   116,    36,   135,     6,   136,    -1,    -1,
      -1,    48,   137,     6,   138,    -1,    -1,    -1,     6,   139,
      48,   140,    -1,    -1,   116,    36,   141,   169,    -1,    -1,
     116,    37,   142,   169,    -1,    -1,   116,    38,   143,   169,
      -1,    -1,   116,    39,   144,   169,    -1,    -1,   116,    30,
     145,   169,    -1,    -1,   116,    31,   146,   169,    -1,    -1,
     116,    32,   147,   169,    -1,    -1,   116,    33,   148,   169,
      -1,    -1,   116,    34,   149,   169,    -1,    -1,   116,    35,
     150,   169,    -1,    -1,   116,    47,   151,   169,    -1,    -1,
     116,    49,   152,   169,    -1,    -1,   116,    50,   153,   169,
      -1,    -1,    51,   154,   169,    -1,    41,   116,    42,    -1,
      -1,   116,    36,   155,    41,   116,    42,    -1,    -1,   116,
      37,   156,    41,   116,    42,    -1,    -1,   116,    38,   157,
      41,   116,    42,    -1,    -1,   116,    39,   158,    41,   116,
      42,    -1,    -1,   116,    30,   159,    41,   116,    42,    -1,
      -1,   116,    31,   160,    41,   116,    42,    -1,    -1,   116,
      32,   161,    41,   116,    42,    -1,    -1,   116,    33,   162,
      41,   116,    42,    -1,    -1,   116,    34,   163,    41,   116,
      42,    -1,    -1,   116,    35,   164,    41,   116,    42,    -1,
      -1,   116,    47,   165,    41,   116,    42,    -1,    -1,   116,
      49,   166,    41,   116,    42,    -1,    -1,   116,    50,   167,
      41,   116,    42,    -1,    51,    41,   116,    42,    -1,    -1,
       6,   168,    -1,    96,    -1,    -1,     3,   170,    -1,    -1,
       8,   171,    -1,    -1,     9,   172,    -1,    -1,     7,   173,
      -1,    -1,     5,   174,    -1,    -1,     4,   175,    -1,    22,
      -1,    24,    -1,    26,    -1,    25,    -1,    23,    -1,    27,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    97,    97,    98,    98,    98,    99,   107,   108,   109,
     110,   111,   112,   114,   115,   116,   117,   118,   119,   120,
     123,   123,   124,   124,   125,   125,   136,   136,   136,   136,
     139,   139,   139,   139,   140,   146,   146,   146,   149,   149,
     149,   149,   149,   152,   152,   152,   152,   152,   152,   155,
     155,   155,   155,   158,   158,   159,   159,   162,   162,   165,
     165,   165,   165,   169,   169,   179,   179,   180,   180,   181,
     184,   185,   186,   189,   196,   196,   197,   197,   197,   200,
     201,   208,   208,   208,   208,   215,   215,   215,   218,   219,
     227,   227,   227,   228,   228,   228,   229,   229,   229,   230,
     230,   230,   231,   231,   231,   232,   232,   232,   233,   233,
     233,   234,   234,   234,   235,   235,   235,   236,   236,   236,
     237,   237,   237,   238,   238,   238,   243,   243,   244,   244,
     245,   245,   246,   246,   247,   247,   248,   248,   249,   249,
     250,   250,   251,   251,   252,   252,   253,   253,   254,   254,
     255,   255,   256,   256,   257,   258,   258,   259,   259,   260,
     260,   261,   261,   262,   262,   263,   263,   264,   264,   265,
     265,   266,   266,   267,   267,   268,   268,   269,   269,   270,
     270,   271,   272,   272,   273,   285,   285,   286,   286,   287,
     287,   288,   288,   289,   289,   290,   290,   295,   296,   297,
     298,   299,   300
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "NUMBER", "FLOATING_NUMBER",
  "STRING_LITERAL", "IDENTIFIER", "CHARACTER_LITERAL", "TRUE", "FALSE",
  "COMMA", "IF", "ELSE", "WHILE", "REPEAT", "UNTIL", "FOR", "SWITCH",
  "CASE", "BREAK", "CONTINUE", "CONST", "INT", "FLOAT", "BOOL", "STRING",
  "CHAR", "VOID", "RETURN", "DEFAULT", "EQ", "NEQ", "LT", "GT", "LEQ",
  "GEQ", "PLUS", "MINUS", "TIMES", "DIVIDE", "ASSIGN", "LPAREN", "RPAREN",
  "LBRACE", "RBRACE", "SEMICOLON", "COLON", "POWER", "UNARY", "AND", "OR",
  "NOT", "UMINUS", "$accept", "stmt_list", "@1", "@2", "stmt",
  "return_stmt", "@3", "@4", "@5", "if_stmt", "@6", "@7", "@8",
  "else_stmt", "@9", "@10", "@11", "while_stmt", "@12", "@13",
  "repeat_stmt", "@14", "@15", "@16", "@17", "for_stmt", "@18", "@19",
  "@20", "@21", "@22", "switch_stmt", "@23", "@24", "@25", "case_list",
  "@26", "@27", "@28", "func_decl", "@29", "@30", "@31", "func_call",
  "@32", "dec_param_list", "@33", "@34", "call_param_list",
  "call_param_list_cont", "var_decl", "@35", "@36", "@37", "var_decl_cont",
  "const_decl", "@38", "@39", "@40", "assignment_stmt", "@41", "@42",
  "assignment_stmt_cont", "expr", "@43", "@44", "@45", "@46", "@47", "@48",
  "@49", "@50", "@51", "@52", "@53", "@54", "@55", "@56", "@57", "@58",
  "@59", "@60", "@61", "@62", "@63", "@64", "@65", "@66", "@67", "@68",
  "@69", "@70", "@71", "@72", "@73", "@74", "@75", "@76", "@77", "@78",
  "@79", "@80", "@81", "@82", "@83", "@84", "@85", "@86", "@87", "@88",
  "@89", "@90", "@91", "@92", "@93", "@94", "TERM", "@95", "@96", "@97",
  "@98", "@99", "@100", "DATATYPE", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    55,    56,    54,    54,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      59,    58,    60,    58,    61,    58,    63,    64,    65,    62,
      67,    68,    69,    66,    66,    71,    72,    70,    74,    75,
      76,    77,    73,    79,    80,    81,    82,    83,    78,    85,
      86,    87,    84,    89,    88,    90,    88,    91,    88,    93,
      94,    95,    92,    97,    96,    99,    98,   100,    98,    98,
     101,   101,   101,   102,   104,   103,   105,   106,   103,   107,
     107,   109,   110,   111,   108,   113,   114,   112,   115,   115,
     117,   118,   116,   119,   120,   116,   121,   122,   116,   123,
     124,   116,   125,   126,   116,   127,   128,   116,   129,   130,
     116,   131,   132,   116,   133,   134,   116,   135,   136,   116,
     137,   138,   116,   139,   140,   116,   141,   116,   142,   116,
     143,   116,   144,   116,   145,   116,   146,   116,   147,   116,
     148,   116,   149,   116,   150,   116,   151,   116,   152,   116,
     153,   116,   154,   116,   116,   155,   116,   156,   116,   157,
     116,   158,   116,   159,   116,   160,   116,   161,   116,   162,
     116,   163,   116,   164,   116,   165,   116,   166,   116,   167,
     116,   116,   168,   116,   116,   170,   169,   171,   169,   172,
     169,   173,   169,   174,   169,   175,   169,   176,   176,   176,
     176,   176,   176
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     6,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       0,     2,     0,     3,     0,     3,     0,     0,     0,    11,
       0,     0,     0,     7,     0,     0,     0,     9,     0,     0,
       0,     0,    13,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    10,     0,     6,     0,     6,     0,     4,     0,
       0,     0,    11,     0,     5,     0,     5,     0,     3,     0,
       2,     2,     0,     2,     0,     4,     0,     0,     6,     2,
       2,     0,     0,     0,     9,     0,     0,     5,     2,     2,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     4,     0,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     4,     0,     4,     0,     4,     0,     4,
       0,     4,     0,     3,     3,     0,     6,     0,     6,     0,
       6,     0,     6,     0,     6,     0,     6,     0,     6,     0,
       6,     0,     6,     0,     6,     0,     6,     0,     6,     0,
       6,     4,     0,     2,     1,     0,     2,     0,     2,     0,
       2,     0,     2,     0,     2,     0,     2,     1,     1,     1,
       1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,   182,    26,    35,    38,    43,    49,     0,     0,    81,
     197,   201,   198,   200,   199,   202,    22,     0,     3,   120,
     152,     0,     6,     0,     7,     8,     9,    10,    11,    12,
     184,    13,    14,    15,     0,     0,     0,     0,     0,   183,
       0,     0,     0,     0,     0,    18,    19,     0,    21,     0,
       0,   182,     0,     6,     0,     0,     0,     1,     2,    17,
     134,   136,   138,   140,   142,   144,   126,   128,   130,   132,
      16,   146,   148,   150,    59,    72,    86,   124,     0,     0,
      39,     0,     0,     0,   185,   195,   193,   191,   187,   189,
      23,    25,   154,     0,   121,     0,   153,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     125,     0,     0,     6,     0,     0,     0,    82,   186,   196,
     194,   192,   188,   190,     4,   122,   181,    91,   135,     0,
      94,   137,     0,    97,   139,     0,   100,   141,     0,   103,
     143,     0,   106,   145,     0,   118,   127,     0,   115,   129,
       0,   112,   131,     0,   109,   133,     0,   147,     0,   149,
       0,   151,     0,    69,    75,    77,    64,    72,    70,    71,
      87,     0,     0,     0,     0,     0,     0,    74,     0,     0,
       6,    92,     0,    95,     0,    98,     0,   101,     0,   104,
       0,   107,     0,   119,     0,   116,     0,   113,     0,   110,
       0,     0,     0,     0,     0,     0,     0,    73,    89,    88,
      27,    36,    40,     0,    50,    83,     5,   164,   166,   168,
     170,   172,   174,   156,   158,   160,   162,   176,   178,   180,
       0,    65,    78,     0,     0,     6,     6,     0,    44,     0,
       0,    60,     0,    68,    80,    79,     0,     0,    41,     0,
      55,    57,     0,     0,     6,    69,    28,    37,     0,    45,
       0,     0,     0,    51,    84,     0,    66,    34,     0,     0,
       0,     0,     6,    52,    61,    30,    29,     0,     0,     6,
       6,    58,    62,     0,     0,     0,     0,     0,    31,    42,
      46,    54,    56,     6,     6,     0,     0,    32,    47,    33,
      48
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    53,   210,    22,    23,    48,    49,    50,    24,
      40,   265,   297,   306,   313,   323,   329,    25,    41,   266,
      26,    42,   143,   267,   288,    27,    43,   279,   299,   324,
     330,    28,    44,   269,   303,   282,   290,   291,   292,    29,
     133,   284,   312,    30,    36,   234,   272,   273,   136,   198,
      31,   134,   135,   236,   262,    32,    47,   209,   270,    33,
      37,   139,   200,    34,    97,   211,   100,   213,   103,   215,
     106,   217,   109,   219,   112,   221,   124,   229,   121,   227,
     118,   225,   115,   223,    54,   155,    38,   140,   116,   119,
     122,   125,    98,   101,   104,   107,   110,   113,   127,   129,
     131,    56,   117,   120,   123,   126,    99,   102,   105,   108,
     111,   114,   128,   130,   132,    39,   138,   148,   152,   153,
     151,   150,   149,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -292
static const yytype_int16 yypact[] =
{
      81,   -20,  -292,  -292,  -292,  -292,  -292,   -41,    -8,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,     0,     5,  -292,  -292,
     -18,    38,    81,    26,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,   216,    63,    33,    40,    42,  -292,
      45,    47,    46,    50,    55,  -292,  -292,   112,  -292,   111,
       5,   -19,   261,    81,    93,     5,   111,  -292,  -292,  -292,
      -1,     1,     2,     3,    13,    27,    41,    43,    71,    72,
    -292,    69,    70,    76,   -13,     9,  -292,  -292,     5,     5,
    -292,   112,     5,   119,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,   765,  -292,    82,  -292,   282,  -292,   121,   111,    89,
     125,   111,    92,   134,   111,   100,   136,   111,   103,   139,
     111,   106,   144,   111,   110,   147,   111,   113,   150,   111,
     116,   153,   111,   122,   154,   111,   124,   111,   127,   111,
     128,   111,   132,   137,   117,   126,   133,   161,   167,     9,
    -292,   303,   324,    81,     5,   173,   345,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,     5,
    -292,  -292,     5,  -292,  -292,     5,  -292,  -292,     5,  -292,
    -292,     5,  -292,  -292,     5,  -292,  -292,     5,  -292,  -292,
       5,  -292,  -292,     5,  -292,  -292,     5,  -292,     5,  -292,
       5,  -292,     5,   112,  -292,  -292,  -292,     9,  -292,  -292,
    -292,   366,   135,   140,   141,   138,   387,   145,   143,   149,
      81,  -292,   408,  -292,   429,  -292,   450,  -292,   471,  -292,
     492,  -292,   513,  -292,   534,  -292,   555,  -292,   576,  -292,
     597,   618,   639,   660,   159,   181,     9,  -292,  -292,  -292,
    -292,  -292,  -292,   196,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
     160,   162,  -292,   681,   164,    81,    81,   190,  -292,     6,
     111,  -292,   197,  -292,  -292,  -292,   168,   169,  -292,   166,
      24,  -292,   170,   171,    81,   112,  -292,  -292,   174,  -292,
       5,   111,   172,  -292,  -292,   175,  -292,   205,     5,     5,
     702,   176,    81,  -292,  -292,  -292,  -292,   723,   744,    81,
      81,  -292,  -292,   178,   180,   183,     6,     6,  -292,  -292,
    -292,  -292,  -292,    81,    81,   179,   184,  -292,  -292,  -292,
    -292
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -292,   -22,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -291,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,   -58,  -292,  -292,    32,    94,
     152,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,   -16,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,  -292,
    -292,  -292,  -292,  -292,  -292,  -292,   -46,  -292,  -292,  -292,
    -292,  -292,  -292,   -45
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -180
static const yytype_int16 yytable[] =
{
      58,    52,    83,    90,    45,   -90,   -24,   -93,   -96,   -99,
      96,    51,    84,    85,    86,    51,    87,    88,    89,  -102,
     -85,   -63,   -63,    55,   280,   321,   322,   -76,  -123,  -123,
     -53,    93,   -74,  -105,    91,   281,   145,    46,    57,    95,
    -163,   -24,  -165,  -167,  -169,   -20,    17,  -117,   -24,  -114,
      17,   -24,   158,    19,  -171,   161,    20,    19,   164,   137,
      20,   167,   141,   142,   170,   -53,   146,   173,  -173,    74,
     176,    59,   -53,   179,    75,   -53,   182,  -111,  -108,   185,
      76,   187,  -155,   189,  -157,   191,    78,     1,    79,    80,
      77,    81,     2,   202,     3,     4,    82,     5,     6,    94,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
    -175,  -177,  -159,  -161,    84,    85,    86,  -179,    87,    88,
      89,   205,    17,   201,    18,   147,   154,   157,   206,    19,
     159,   160,    20,   162,    10,    11,    12,    13,    14,    15,
     163,   165,   166,   212,   168,   169,   214,   171,   235,   216,
     172,   174,   218,   175,   177,   220,   178,   180,   222,   181,
     184,   224,   194,   183,   226,   186,   195,   228,   188,   190,
     230,   197,   231,   192,   232,   196,   233,   197,   193,   207,
     239,   137,   242,   240,   241,   -76,   244,   261,   246,   245,
     264,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,   260,   268,   271,   -67,   278,   289,   285,    71,   275,
      72,    73,   286,   287,   293,   298,   294,   305,   302,   304,
     263,   318,   310,   327,   283,   319,   320,   296,   328,   237,
       0,     0,   199,   144,     0,     0,     0,     0,     0,     0,
     235,     0,     0,   276,   277,   301,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,    70,   295,    71,     0,    72,    73,     0,     0,     0,
       0,     0,     0,     0,   300,     0,     0,     0,     0,     0,
     311,     0,   307,   308,     0,     0,     0,   316,   317,     0,
       0,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,   325,   326,    92,     0,     0,     0,     0,    71,     0,
      72,    73,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,   156,     0,     0,     0,     0,    71,
       0,    72,    73,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,   203,     0,     0,     0,     0,
      71,     0,    72,    73,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,   204,     0,     0,     0,
       0,    71,     0,    72,    73,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,   208,     0,     0,
       0,     0,    71,     0,    72,    73,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,     0,     0,
       0,   238,     0,    71,     0,    72,    73,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,     0,
       0,     0,   243,     0,    71,     0,    72,    73,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
     247,     0,     0,     0,     0,    71,     0,    72,    73,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,   248,     0,     0,     0,     0,    71,     0,    72,    73,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,   249,     0,     0,     0,     0,    71,     0,    72,
      73,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,   250,     0,     0,     0,     0,    71,     0,
      72,    73,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,   251,     0,     0,     0,     0,    71,
       0,    72,    73,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,   252,     0,     0,     0,     0,
      71,     0,    72,    73,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,   253,     0,     0,     0,
       0,    71,     0,    72,    73,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,   254,     0,     0,
       0,     0,    71,     0,    72,    73,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,     0,     0,   255,     0,
       0,     0,     0,    71,     0,    72,    73,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     0,   256,
       0,     0,     0,     0,    71,     0,    72,    73,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
     257,     0,     0,     0,     0,    71,     0,    72,    73,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,     0,
       0,   258,     0,     0,     0,     0,    71,     0,    72,    73,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
       0,     0,   259,     0,     0,     0,     0,    71,     0,    72,
      73,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,   274,     0,    71,     0,
      72,    73,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,     0,     0,     0,   309,    71,
       0,    72,    73,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,     0,     0,   314,     0,     0,     0,     0,
      71,     0,    72,    73,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,     0,     0,   315,     0,     0,     0,
       0,    71,     0,    72,    73,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,     0,     0,
       0,     0,    71,     0,    72,    73
};

static const yytype_int16 yycheck[] =
{
      22,    17,    47,    49,    45,     6,     6,     6,     6,     6,
      56,     6,     3,     4,     5,     6,     7,     8,     9,     6,
      40,    41,    41,    41,    18,   316,   317,    40,    48,    48,
       6,    53,    45,     6,    50,    29,    81,    45,     0,    55,
      41,    41,    41,    41,    41,    45,    41,     6,    48,     6,
      41,    51,    98,    48,    41,   101,    51,    48,   104,    75,
      51,   107,    78,    79,   110,    41,    82,   113,    41,     6,
     116,    45,    48,   119,    41,    51,   122,     6,     6,   125,
      40,   127,    41,   129,    41,   131,    41,     6,    41,    43,
      48,    41,    11,   139,    13,    14,    41,    16,    17,     6,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      41,    41,    41,    41,     3,     4,     5,    41,     7,     8,
       9,   143,    41,   139,    43,     6,    44,     6,   144,    48,
      41,     6,    51,    41,    22,    23,    24,    25,    26,    27,
       6,    41,     6,   159,    41,     6,   162,    41,   193,   165,
       6,    41,   168,     6,    41,   171,     6,    41,   174,     6,
       6,   177,    45,    41,   180,    41,    40,   183,    41,    41,
     186,    10,   188,    41,   190,    42,   192,    10,    41,     6,
      45,   197,    44,    43,    43,    40,    43,     6,   210,    40,
     236,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    42,     6,    43,    42,    15,    40,    10,    47,    45,
      49,    50,    44,    44,    44,    41,    45,    12,    46,    44,
     236,    43,    46,    44,   270,    45,    43,   285,    44,   197,
      -1,    -1,   138,    81,    -1,    -1,    -1,    -1,    -1,    -1,
     285,    -1,    -1,   265,   266,   291,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,   284,    47,    -1,    49,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   290,    -1,    -1,    -1,    -1,    -1,
     302,    -1,   298,   299,    -1,    -1,    -1,   309,   310,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,   323,   324,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    14,    16,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    43,    48,
      51,    54,    57,    58,    62,    70,    73,    78,    84,    92,
      96,   103,   108,   112,   116,   176,    97,   113,   139,   168,
      63,    71,    74,    79,    85,    45,    45,   109,    59,    60,
      61,     6,   116,    55,   137,    41,   154,     0,    54,    45,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      45,    47,    49,    50,     6,    41,    40,    48,    41,    41,
      43,    41,    41,   176,     3,     4,     5,     7,     8,     9,
     169,   116,    42,    54,     6,   116,   169,   117,   145,   159,
     119,   146,   160,   121,   147,   161,   123,   148,   162,   125,
     149,   163,   127,   150,   164,   135,   141,   155,   133,   142,
     156,   131,   143,   157,   129,   144,   158,   151,   165,   152,
     166,   153,   167,    93,   104,   105,   101,   116,   169,   114,
     140,   116,   116,    75,   103,   176,   116,     6,   170,   175,
     174,   173,   171,   172,    44,   138,    42,     6,   169,    41,
       6,   169,    41,     6,   169,    41,     6,   169,    41,     6,
     169,    41,     6,   169,    41,     6,   169,    41,     6,   169,
      41,     6,   169,    41,     6,   169,    41,   169,    41,   169,
      41,   169,    41,    41,    45,    40,    42,    10,   102,   102,
     115,   116,   169,    42,    42,    54,   116,     6,    42,   110,
      56,   118,   116,   120,   116,   122,   116,   124,   116,   126,
     116,   128,   116,   136,   116,   134,   116,   132,   116,   130,
     116,   116,   116,   116,    98,   176,   106,   101,    45,    45,
      43,    43,    44,    45,    43,    40,    54,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,     6,   107,   116,   169,    64,    72,    76,     6,    86,
     111,    43,    99,   100,    45,    45,    54,    54,    15,    80,
      18,    29,    88,   169,    94,    10,    44,    44,    77,    40,
      89,    90,    91,    44,    45,    54,    98,    65,    41,    81,
     116,   169,    46,    87,    44,    12,    66,   116,   116,    46,
      46,    54,    95,    67,    42,    42,    54,    54,    43,    45,
      43,    88,    88,    68,    82,    54,    54,    44,    44,    69,
      83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 97 "parser.y"
    {printf("stmt_list\n");}
    break;

  case 3:
#line 98 "parser.y"
    {add('S');}
    break;

  case 4:
#line 98 "parser.y"
    {add('S');}
    break;

  case 5:
#line 98 "parser.y"
    {printf("{stmt_list}\n");}
    break;

  case 6:
#line 99 "parser.y"
    {printf("stmt epsilon\n");}
    break;

  case 7:
#line 107 "parser.y"
    {printf("if statement\n");}
    break;

  case 8:
#line 108 "parser.y"
    {printf("while statement\n");}
    break;

  case 9:
#line 109 "parser.y"
    {printf("repeat statement\n");}
    break;

  case 10:
#line 110 "parser.y"
    {printf("for statement\n");}
    break;

  case 11:
#line 111 "parser.y"
    {printf("switch statement\n");}
    break;

  case 12:
#line 112 "parser.y"
    {printf("function declaration\n");}
    break;

  case 13:
#line 114 "parser.y"
    {printf("variable declaration\n");}
    break;

  case 14:
#line 115 "parser.y"
    {printf("constant declaration\n");}
    break;

  case 15:
#line 116 "parser.y"
    {printf("assignment statement\n");}
    break;

  case 16:
#line 117 "parser.y"
    {printf("expression\n");}
    break;

  case 17:
#line 118 "parser.y"
    {printf("return statement\n");}
    break;

  case 18:
#line 119 "parser.y"
    {printf("break statement\n"); add('K');}
    break;

  case 19:
#line 120 "parser.y"
    {printf("continue statement\n"); add('K');}
    break;

  case 20:
#line 123 "parser.y"
    {add('K');}
    break;

  case 21:
#line 123 "parser.y"
    {printf("return\n");}
    break;

  case 22:
#line 124 "parser.y"
    {add('K');}
    break;

  case 23:
#line 124 "parser.y"
    {printf("return term\n");}
    break;

  case 24:
#line 125 "parser.y"
    {add('K');}
    break;

  case 25:
#line 125 "parser.y"
    {printf("return expr\n");}
    break;

  case 26:
#line 136 "parser.y"
    {add('K');}
    break;

  case 27:
#line 136 "parser.y"
    {add('S');}
    break;

  case 28:
#line 136 "parser.y"
    {add('S');}
    break;

  case 29:
#line 136 "parser.y"
    {printf("if (expr) {stmt_list}\n");}
    break;

  case 30:
#line 139 "parser.y"
    {add('K');}
    break;

  case 31:
#line 139 "parser.y"
    {add('S');}
    break;

  case 32:
#line 139 "parser.y"
    {add('S');}
    break;

  case 33:
#line 139 "parser.y"
    {printf("else {stmt_list}\n");}
    break;

  case 34:
#line 140 "parser.y"
    {printf("else epsilon\n");}
    break;

  case 35:
#line 146 "parser.y"
    { add('K'); }
    break;

  case 36:
#line 146 "parser.y"
    { add('S'); }
    break;

  case 37:
#line 146 "parser.y"
    {add('S'); printf("while (expr) {stmt_list}\n");}
    break;

  case 38:
#line 149 "parser.y"
    { add('K'); }
    break;

  case 39:
#line 149 "parser.y"
    { add('S'); }
    break;

  case 40:
#line 149 "parser.y"
    { add('S'); }
    break;

  case 41:
#line 149 "parser.y"
    { add('K'); }
    break;

  case 42:
#line 149 "parser.y"
    {printf("repeat {stmt_list} until (expr)\n");}
    break;

  case 43:
#line 152 "parser.y"
    { add('K'); }
    break;

  case 44:
#line 152 "parser.y"
    { add('V'); }
    break;

  case 45:
#line 152 "parser.y"
    { add('O');}
    break;

  case 46:
#line 152 "parser.y"
    {add('S');}
    break;

  case 47:
#line 152 "parser.y"
    {add('S');}
    break;

  case 48:
#line 152 "parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n");}
    break;

  case 49:
#line 155 "parser.y"
    {add('K');}
    break;

  case 50:
#line 155 "parser.y"
    {add('S');}
    break;

  case 51:
#line 155 "parser.y"
    { add('S');}
    break;

  case 52:
#line 155 "parser.y"
    {printf("switch (expr) {case_list}\n");}
    break;

  case 53:
#line 158 "parser.y"
    { add('K');}
    break;

  case 54:
#line 158 "parser.y"
    {printf("case expr: stmt_list case_list\n");}
    break;

  case 55:
#line 159 "parser.y"
    { add('K');}
    break;

  case 56:
#line 159 "parser.y"
    {printf("case term: stmt_list case_list\n");}
    break;

  case 57:
#line 162 "parser.y"
    { add('K');}
    break;

  case 58:
#line 162 "parser.y"
    {printf("default: stmt_list\n");}
    break;

  case 59:
#line 165 "parser.y"
    {add('F');}
    break;

  case 60:
#line 165 "parser.y"
    { add('S');}
    break;

  case 61:
#line 165 "parser.y"
    {add('S');}
    break;

  case 62:
#line 165 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");}
    break;

  case 63:
#line 169 "parser.y"
    {add('F');}
    break;

  case 64:
#line 169 "parser.y"
    {printf("identifier (call_param_list) ;\n");}
    break;

  case 65:
#line 179 "parser.y"
    {add('V');}
    break;

  case 66:
#line 179 "parser.y"
    {printf("data_type identifier , dec_param_list\n");}
    break;

  case 67:
#line 180 "parser.y"
    {add('V');}
    break;

  case 68:
#line 180 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 69:
#line 181 "parser.y"
    {printf("epsilon\n");}
    break;

  case 70:
#line 184 "parser.y"
    {printf("identifier , call_param_list\n");}
    break;

  case 71:
#line 185 "parser.y"
    {printf("term\n");}
    break;

  case 72:
#line 186 "parser.y"
    {printf("epsilon\n");}
    break;

  case 73:
#line 189 "parser.y"
    {printf(", call_param_list\n");}
    break;

  case 74:
#line 196 "parser.y"
    {add('V');}
    break;

  case 75:
#line 196 "parser.y"
    {printf("data_type identifier; \n");}
    break;

  case 76:
#line 197 "parser.y"
    {add('V');}
    break;

  case 77:
#line 197 "parser.y"
    {add('O');}
    break;

  case 78:
#line 197 "parser.y"
    {printf("data_type identifier = term ;\n");}
    break;

  case 79:
#line 200 "parser.y"
    {printf("term ;\n");}
    break;

  case 80:
#line 201 "parser.y"
    {printf("expr ;\n");}
    break;

  case 81:
#line 208 "parser.y"
    { add('K');}
    break;

  case 82:
#line 208 "parser.y"
    { add('V');}
    break;

  case 83:
#line 208 "parser.y"
    { add('O');}
    break;

  case 84:
#line 208 "parser.y"
    {printf("const data_type identifier = term ;\n");}
    break;

  case 85:
#line 215 "parser.y"
    {add('V');}
    break;

  case 86:
#line 215 "parser.y"
    { add('O');}
    break;

  case 87:
#line 215 "parser.y"
    {printf("identifier = term ;\n");}
    break;

  case 88:
#line 218 "parser.y"
    {printf("identifier = term ;\n");}
    break;

  case 89:
#line 219 "parser.y"
    {printf("identifier = expr ;\n");}
    break;

  case 90:
#line 227 "parser.y"
    {add('O');}
    break;

  case 91:
#line 227 "parser.y"
    {add('V');}
    break;

  case 92:
#line 227 "parser.y"
    {printf("expr == identifer\n");}
    break;

  case 93:
#line 228 "parser.y"
    {add('O');}
    break;

  case 94:
#line 228 "parser.y"
    {add('V');}
    break;

  case 95:
#line 228 "parser.y"
    {printf("expr != identifer\n");}
    break;

  case 96:
#line 229 "parser.y"
    {add('O');}
    break;

  case 97:
#line 229 "parser.y"
    {add('V');}
    break;

  case 98:
#line 229 "parser.y"
    {printf("expr < identifer\n");}
    break;

  case 99:
#line 230 "parser.y"
    {add('O');}
    break;

  case 100:
#line 230 "parser.y"
    {add('V');}
    break;

  case 101:
#line 230 "parser.y"
    {printf("expr > identifer\n");}
    break;

  case 102:
#line 231 "parser.y"
    {add('O');}
    break;

  case 103:
#line 231 "parser.y"
    {add('V');}
    break;

  case 104:
#line 231 "parser.y"
    {printf("expr <= identifer\n");}
    break;

  case 105:
#line 232 "parser.y"
    {add('O');}
    break;

  case 106:
#line 232 "parser.y"
    {add('V');}
    break;

  case 107:
#line 232 "parser.y"
    {printf("expr >= identifer\n");}
    break;

  case 108:
#line 233 "parser.y"
    {add('O');}
    break;

  case 109:
#line 233 "parser.y"
    {add('V');}
    break;

  case 110:
#line 233 "parser.y"
    {printf("expr / identifer\n");}
    break;

  case 111:
#line 234 "parser.y"
    {add('O');}
    break;

  case 112:
#line 234 "parser.y"
    {add('V');}
    break;

  case 113:
#line 234 "parser.y"
    {printf("expr * identifer\n");}
    break;

  case 114:
#line 235 "parser.y"
    {add('O');}
    break;

  case 115:
#line 235 "parser.y"
    {add('V');}
    break;

  case 116:
#line 235 "parser.y"
    {printf("expr - identifer\n");}
    break;

  case 117:
#line 236 "parser.y"
    {add('O');}
    break;

  case 118:
#line 236 "parser.y"
    {add('V');}
    break;

  case 119:
#line 236 "parser.y"
    {printf("expr + identifer\n");}
    break;

  case 120:
#line 237 "parser.y"
    {add('O');}
    break;

  case 121:
#line 237 "parser.y"
    {add('V');}
    break;

  case 122:
#line 237 "parser.y"
    {printf("unary expr\n");}
    break;

  case 123:
#line 238 "parser.y"
    {add('V');}
    break;

  case 124:
#line 238 "parser.y"
    {add('O');}
    break;

  case 125:
#line 238 "parser.y"
    {printf("identifer unary\n");}
    break;

  case 126:
#line 243 "parser.y"
    {add('O');}
    break;

  case 127:
#line 243 "parser.y"
    {printf("expr + term\n");}
    break;

  case 128:
#line 244 "parser.y"
    {add('O');}
    break;

  case 129:
#line 244 "parser.y"
    {printf("expr - term\n");}
    break;

  case 130:
#line 245 "parser.y"
    {add('O');}
    break;

  case 131:
#line 245 "parser.y"
    {printf("expr * term\n");}
    break;

  case 132:
#line 246 "parser.y"
    {add('O');}
    break;

  case 133:
#line 246 "parser.y"
    {printf("expr / term\n");}
    break;

  case 134:
#line 247 "parser.y"
    {add('O');}
    break;

  case 135:
#line 247 "parser.y"
    {printf("expr == term\n");}
    break;

  case 136:
#line 248 "parser.y"
    {add('O');}
    break;

  case 137:
#line 248 "parser.y"
    {printf("expr != term\n");}
    break;

  case 138:
#line 249 "parser.y"
    {add('O');}
    break;

  case 139:
#line 249 "parser.y"
    {printf("expr < term\n");}
    break;

  case 140:
#line 250 "parser.y"
    {add('O');}
    break;

  case 141:
#line 250 "parser.y"
    {printf("expr > term\n");}
    break;

  case 142:
#line 251 "parser.y"
    {add('O');}
    break;

  case 143:
#line 251 "parser.y"
    {printf("expr <= term\n");}
    break;

  case 144:
#line 252 "parser.y"
    {add('O');}
    break;

  case 145:
#line 252 "parser.y"
    {printf("expr >= term\n");}
    break;

  case 146:
#line 253 "parser.y"
    {add('O');}
    break;

  case 147:
#line 253 "parser.y"
    {printf("expr ^ term\n");}
    break;

  case 148:
#line 254 "parser.y"
    {add('O');}
    break;

  case 149:
#line 254 "parser.y"
    {printf("expr && term\n");}
    break;

  case 150:
#line 255 "parser.y"
    {add('O');}
    break;

  case 151:
#line 255 "parser.y"
    {printf("expr || term\n");}
    break;

  case 152:
#line 256 "parser.y"
    {add('O');}
    break;

  case 153:
#line 256 "parser.y"
    {printf("!term\n");}
    break;

  case 154:
#line 257 "parser.y"
    {printf("(expr)\n");}
    break;

  case 155:
#line 258 "parser.y"
    {add('O');}
    break;

  case 156:
#line 258 "parser.y"
    {printf("expr + (expr)\n");}
    break;

  case 157:
#line 259 "parser.y"
    {add('O');}
    break;

  case 158:
#line 259 "parser.y"
    {printf("expr - (expr)\n");}
    break;

  case 159:
#line 260 "parser.y"
    {add('O');}
    break;

  case 160:
#line 260 "parser.y"
    {printf("expr * (expr)\n");}
    break;

  case 161:
#line 261 "parser.y"
    {add('O');}
    break;

  case 162:
#line 261 "parser.y"
    {printf("expr / (expr)\n");}
    break;

  case 163:
#line 262 "parser.y"
    {add('O');}
    break;

  case 164:
#line 262 "parser.y"
    {printf("expr == (expr)\n");}
    break;

  case 165:
#line 263 "parser.y"
    {add('O');}
    break;

  case 166:
#line 263 "parser.y"
    {printf("expr != (expr)\n");}
    break;

  case 167:
#line 264 "parser.y"
    {add('O');}
    break;

  case 168:
#line 264 "parser.y"
    {printf("expr < (expr)\n");}
    break;

  case 169:
#line 265 "parser.y"
    {add('O');}
    break;

  case 170:
#line 265 "parser.y"
    {printf("expr > (expr)\n");}
    break;

  case 171:
#line 266 "parser.y"
    {add('O');}
    break;

  case 172:
#line 266 "parser.y"
    {printf("expr <= (expr)\n");}
    break;

  case 173:
#line 267 "parser.y"
    {add('O');}
    break;

  case 174:
#line 267 "parser.y"
    {printf("expr >= (expr)\n");}
    break;

  case 175:
#line 268 "parser.y"
    {add('O');}
    break;

  case 176:
#line 268 "parser.y"
    {printf("expr ^ (expr)\n");}
    break;

  case 177:
#line 269 "parser.y"
    {add('O');}
    break;

  case 178:
#line 269 "parser.y"
    {printf("expr && (expr)\n");}
    break;

  case 179:
#line 270 "parser.y"
    {add('O');}
    break;

  case 180:
#line 270 "parser.y"
    {printf("expr || (expr)\n");}
    break;

  case 181:
#line 271 "parser.y"
    {printf("! (expr)\n");}
    break;

  case 182:
#line 272 "parser.y"
    {add('V');}
    break;

  case 183:
#line 272 "parser.y"
    {printf("identifier\n");}
    break;

  case 184:
#line 273 "parser.y"
    {printf("function call\n");}
    break;

  case 185:
#line 285 "parser.y"
    {add('C');}
    break;

  case 186:
#line 285 "parser.y"
    {printf("number\n");}
    break;

  case 187:
#line 286 "parser.y"
    {add('C');}
    break;

  case 188:
#line 286 "parser.y"
    {printf("true\n");}
    break;

  case 189:
#line 287 "parser.y"
    {add('C');}
    break;

  case 190:
#line 287 "parser.y"
    {printf("false\n");}
    break;

  case 191:
#line 288 "parser.y"
    {add('C');}
    break;

  case 192:
#line 288 "parser.y"
    {printf("char\n");}
    break;

  case 193:
#line 289 "parser.y"
    {add('C');}
    break;

  case 194:
#line 289 "parser.y"
    {printf("string\n");}
    break;

  case 195:
#line 290 "parser.y"
    {add('C');}
    break;

  case 196:
#line 290 "parser.y"
    {printf("float\n");}
    break;

  case 197:
#line 295 "parser.y"
    {add('K');}
    break;

  case 198:
#line 296 "parser.y"
    {add('K');}
    break;

  case 199:
#line 297 "parser.y"
    {add('K');}
    break;

  case 200:
#line 298 "parser.y"
    {add('K');}
    break;

  case 201:
#line 299 "parser.y"
    {add('K');}
    break;

  case 202:
#line 300 "parser.y"
    {add('K');}
    break;


/* Line 1267 of yacc.c.  */
#line 2906 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 301 "parser.y"




void insert_type(){
    strcpy(type, yytext);
}
/*
yyerror: This function is called when there's a syntax error in the input.
It prints an error message and exits the program.
*/
void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    /* exit(1); */
}
/**/
/*
lookup_symbol: This function searches for a symbol in the symbol table by name.
If the symbol is found, it returns its index in the table; otherwise, it returns -1.
*/
int lookup_symbol(char *type) {
    for (int i = symbol_count - 1; i >=0; i--) {
        if (symbol_table[i].id_name && type) {
            return -1;
            break;
        }
        return 0;
    }
    return -1;
}

void add(char c){
    q = lookup_symbol(yytext);
    if(!q){
        if(c == 'H'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Header");
            symbol_count++;
        }
        else if(c == 'K'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Keyword\t");
            symbol_count++;
        }
        else if(c == 'V'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Variable");
            symbol_count++;
        }
        else if(c == 'C'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("CONST");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Constant");
            symbol_count++;
        }
        else if(c == 'F'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup(type);
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Function");
            symbol_count++;
        }
        else if(c == 'O'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Operator");
            symbol_count++;
        }
        else if(c == 'S'){
            symbol_table[symbol_count].id_name = strdup(yytext);
            symbol_table[symbol_count].data_type = strdup("N/A");
            symbol_table[symbol_count].line_no = countn;
            symbol_table[symbol_count].type = strdup("Scope");
            symbol_count++;
        }
    }
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
	for(i=0; i<symbol_count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<symbol_count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    fclose(input_file);
    return 0;
}

