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
/* Line 193 of yacc.c.  */
#line 249 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 262 "y.tab.c"

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
#define YYFINAL  60
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   860

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  131
/* YYNRULES -- Number of rules.  */
#define YYNRULES  213
/* YYNRULES -- Number of states.  */
#define YYNSTATES  359

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
      74,    75,    76,    77,    78,    79,    80,    98,    99,   100,
     110,   111,   112,   113,   114,   128,   129,   130,   131,   132,
     133,   151,   152,   153,   154,   165,   166,   173,   174,   181,
     182,   188,   189,   195,   196,   201,   202,   203,   204,   216,
     217,   225,   226,   232,   233,   238,   239,   245,   246,   250,
     254,   256,   260,   262,   263,   268,   269,   270,   278,   279,
     280,   288,   289,   290,   291,   301,   302,   303,   310,   311,
     312,   319,   320,   321,   327,   328,   329,   335,   336,   337,
     343,   344,   345,   351,   352,   353,   359,   360,   361,   367,
     368,   369,   375,   376,   377,   383,   384,   385,   391,   392,
     393,   399,   400,   401,   406,   407,   408,   413,   414,   419,
     420,   425,   426,   431,   432,   437,   438,   443,   444,   449,
     450,   455,   456,   461,   462,   467,   468,   473,   474,   479,
     480,   485,   486,   491,   492,   496,   500,   501,   508,   509,
     516,   517,   524,   525,   532,   533,   540,   541,   548,   549,
     556,   557,   564,   565,   572,   573,   580,   581,   588,   589,
     596,   597,   604,   609,   610,   613,   615,   616,   619,   620,
     623,   624,   627,   628,   631,   632,   635,   636,   639,   641,
     643,   645,   647,   649
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    57,    54,    -1,    -1,    -1,    43,    55,
      54,    44,    56,    54,    -1,    -1,    62,    -1,    72,    -1,
      75,    -1,    80,    -1,    86,    -1,    96,    -1,   108,    -1,
     114,    -1,   118,    -1,   123,    45,    -1,    58,    45,    -1,
      19,    45,    -1,    20,    45,    -1,    -1,    28,    59,    -1,
      -1,    28,    60,   176,    -1,    -1,    28,    61,   123,    -1,
      -1,    -1,    -1,    11,    63,    41,   123,    42,    43,    64,
      54,    44,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    66,    41,   123,    42,    43,    67,    54,    44,    68,
      12,    69,    43,    70,    54,    44,    71,    -1,    -1,    -1,
      13,    73,    41,   123,    42,    43,    74,    54,    44,    -1,
      -1,    -1,    -1,    -1,    14,    76,    43,    77,    54,    44,
      78,    15,    79,    41,   123,    42,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    81,    41,   108,   123,    45,     6,
      82,    40,    83,   123,    42,    43,    84,    54,    44,    85,
      -1,    -1,    -1,    -1,    17,    87,    41,   123,    42,    43,
      88,    90,    44,    89,    -1,    -1,    18,    91,   123,    46,
      54,    90,    -1,    -1,    18,    92,   176,    46,    54,    90,
      -1,    -1,    18,    93,   123,    46,    54,    -1,    -1,    18,
      94,   176,    46,    54,    -1,    -1,    29,    95,    46,    54,
      -1,    -1,    -1,    -1,   183,     6,    97,    41,   104,    42,
      43,    98,    54,    44,    99,    -1,    -1,   183,     6,   100,
      41,   104,    42,    45,    -1,    -1,     6,   102,    41,   107,
      42,    -1,    -1,     6,   103,    41,    42,    -1,    -1,   183,
       6,   105,    10,   104,    -1,    -1,   183,     6,   106,    -1,
     123,    10,   107,    -1,   123,    -1,   176,    10,   107,    -1,
     176,    -1,    -1,   183,     6,   109,    45,    -1,    -1,    -1,
     183,     6,   110,    40,   111,   176,    45,    -1,    -1,    -1,
     183,     6,   112,    40,   113,   123,    45,    -1,    -1,    -1,
      -1,    21,   115,   183,     6,   116,    40,   117,   176,    45,
      -1,    -1,    -1,     6,   119,    40,   120,   176,    45,    -1,
      -1,    -1,     6,   121,    40,   122,   123,    45,    -1,    -1,
      -1,   123,    30,   124,     6,   125,    -1,    -1,    -1,   123,
      31,   126,     6,   127,    -1,    -1,    -1,   123,    32,   128,
       6,   129,    -1,    -1,    -1,   123,    33,   130,     6,   131,
      -1,    -1,    -1,   123,    34,   132,     6,   133,    -1,    -1,
      -1,   123,    35,   134,     6,   135,    -1,    -1,    -1,   123,
      39,   136,     6,   137,    -1,    -1,    -1,   123,    38,   138,
       6,   139,    -1,    -1,    -1,   123,    37,   140,     6,   141,
      -1,    -1,    -1,   123,    36,   142,     6,   143,    -1,    -1,
      -1,    48,   144,     6,   145,    -1,    -1,    -1,     6,   146,
      48,   147,    -1,    -1,   123,    36,   148,   176,    -1,    -1,
     123,    37,   149,   176,    -1,    -1,   123,    38,   150,   176,
      -1,    -1,   123,    39,   151,   176,    -1,    -1,   123,    30,
     152,   176,    -1,    -1,   123,    31,   153,   176,    -1,    -1,
     123,    32,   154,   176,    -1,    -1,   123,    33,   155,   176,
      -1,    -1,   123,    34,   156,   176,    -1,    -1,   123,    35,
     157,   176,    -1,    -1,   123,    47,   158,   176,    -1,    -1,
     123,    49,   159,   176,    -1,    -1,   123,    50,   160,   176,
      -1,    -1,    51,   161,   176,    -1,    41,   123,    42,    -1,
      -1,   123,    36,   162,    41,   123,    42,    -1,    -1,   123,
      37,   163,    41,   123,    42,    -1,    -1,   123,    38,   164,
      41,   123,    42,    -1,    -1,   123,    39,   165,    41,   123,
      42,    -1,    -1,   123,    30,   166,    41,   123,    42,    -1,
      -1,   123,    31,   167,    41,   123,    42,    -1,    -1,   123,
      32,   168,    41,   123,    42,    -1,    -1,   123,    33,   169,
      41,   123,    42,    -1,    -1,   123,    34,   170,    41,   123,
      42,    -1,    -1,   123,    35,   171,    41,   123,    42,    -1,
      -1,   123,    47,   172,    41,   123,    42,    -1,    -1,   123,
      49,   173,    41,   123,    42,    -1,    -1,   123,    50,   174,
      41,   123,    42,    -1,    51,    41,   123,    42,    -1,    -1,
       6,   175,    -1,   101,    -1,    -1,     3,   177,    -1,    -1,
       8,   178,    -1,    -1,     9,   179,    -1,    -1,     7,   180,
      -1,    -1,     5,   181,    -1,    -1,     4,   182,    -1,    22,
      -1,    24,    -1,    26,    -1,    25,    -1,    23,    -1,    27,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    94,    94,    95,   103,   104,   105,
     106,   107,   108,   110,   111,   112,   113,   114,   115,   116,
     119,   119,   120,   120,   121,   121,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   133,   133,   133,
     136,   136,   136,   136,   136,   139,   139,   139,   139,   139,
     139,   142,   142,   142,   142,   145,   145,   146,   146,   147,
     147,   148,   148,   149,   149,   152,   152,   152,   152,   153,
     153,   156,   156,   157,   157,   165,   165,   166,   166,   169,
     170,   171,   172,   179,   179,   180,   180,   180,   181,   181,
     181,   188,   188,   188,   188,   195,   195,   195,   196,   196,
     196,   204,   204,   204,   205,   205,   205,   206,   206,   206,
     207,   207,   207,   208,   208,   208,   209,   209,   209,   210,
     210,   210,   211,   211,   211,   212,   212,   212,   213,   213,
     213,   214,   214,   214,   215,   215,   215,   220,   220,   221,
     221,   222,   222,   223,   223,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   235,   235,   236,   236,
     237,   237,   238,   238,   239,   239,   240,   240,   241,   241,
     242,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     247,   247,   248,   249,   249,   250,   262,   262,   263,   263,
     264,   264,   265,   265,   266,   266,   267,   267,   272,   273,
     274,   275,   276,   277
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
  "return_stmt", "@3", "@4", "@5", "if_stmt", "@6", "@7", "@8", "@9",
  "@10", "@11", "@12", "@13", "@14", "while_stmt", "@15", "@16",
  "repeat_stmt", "@17", "@18", "@19", "@20", "for_stmt", "@21", "@22",
  "@23", "@24", "@25", "switch_stmt", "@26", "@27", "@28", "case_list",
  "@29", "@30", "@31", "@32", "@33", "func_decl", "@34", "@35", "@36",
  "@37", "func_call", "@38", "@39", "dec_param_list", "@40", "@41",
  "call_param_list", "var_decl", "@42", "@43", "@44", "@45", "@46",
  "const_decl", "@47", "@48", "@49", "assignment_stmt", "@50", "@51",
  "@52", "@53", "expr", "@54", "@55", "@56", "@57", "@58", "@59", "@60",
  "@61", "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69", "@70",
  "@71", "@72", "@73", "@74", "@75", "@76", "@77", "@78", "@79", "@80",
  "@81", "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", "@90",
  "@91", "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100",
  "@101", "@102", "@103", "@104", "@105", "TERM", "@106", "@107", "@108",
  "@109", "@110", "@111", "DATATYPE", 0
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
      66,    67,    68,    69,    70,    71,    62,    73,    74,    72,
      76,    77,    78,    79,    75,    81,    82,    83,    84,    85,
      80,    87,    88,    89,    86,    91,    90,    92,    90,    93,
      90,    94,    90,    95,    90,    97,    98,    99,    96,   100,
      96,   102,   101,   103,   101,   105,   104,   106,   104,   107,
     107,   107,   107,   109,   108,   110,   111,   108,   112,   113,
     108,   115,   116,   117,   114,   119,   120,   118,   121,   122,
     118,   124,   125,   123,   126,   127,   123,   128,   129,   123,
     130,   131,   123,   132,   133,   123,   134,   135,   123,   136,
     137,   123,   138,   139,   123,   140,   141,   123,   142,   143,
     123,   144,   145,   123,   146,   147,   123,   148,   123,   149,
     123,   150,   123,   151,   123,   152,   123,   153,   123,   154,
     123,   155,   123,   156,   123,   157,   123,   158,   123,   159,
     123,   160,   123,   161,   123,   123,   162,   123,   163,   123,
     164,   123,   165,   123,   166,   123,   167,   123,   168,   123,
     169,   123,   170,   123,   171,   123,   172,   123,   173,   123,
     174,   123,   123,   175,   123,   123,   177,   176,   178,   176,
     179,   176,   180,   176,   181,   176,   182,   176,   183,   183,
     183,   183,   183,   183
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     0,     6,     0,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     2,     2,
       0,     2,     0,     3,     0,     3,     0,     0,     0,    10,
       0,     0,     0,     0,     0,     0,    17,     0,     0,     9,
       0,     0,     0,     0,    13,     0,     0,     0,     0,     0,
      17,     0,     0,     0,    10,     0,     6,     0,     6,     0,
       5,     0,     5,     0,     4,     0,     0,     0,    11,     0,
       7,     0,     5,     0,     4,     0,     5,     0,     3,     3,
       1,     3,     1,     0,     4,     0,     0,     7,     0,     0,
       7,     0,     0,     0,     9,     0,     0,     6,     0,     0,
       6,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     4,     0,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     3,     3,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     4,     0,     2,     1,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     0,     2,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       6,   193,    26,    37,    40,    45,    51,     0,     0,    91,
     208,   212,   209,   211,   210,   213,    22,     0,     3,   131,
     163,     0,     6,     0,     7,     8,     9,    10,    11,    12,
     195,    13,    14,    15,     0,     0,     0,     0,     0,     0,
       0,   194,     0,     0,     0,     0,     0,     0,    18,    19,
       0,    21,     0,     0,   193,     0,     6,     0,     0,     0,
       1,     2,    17,   145,   147,   149,   151,   153,   155,   137,
     139,   141,   143,    16,   157,   159,   161,    65,     0,     0,
      96,    99,   135,     0,     0,     0,    41,     0,     0,     0,
     196,   206,   204,   202,   198,   200,    23,    25,   165,     0,
     132,     0,   164,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    80,    82,    74,     0,     0,
     136,     0,     0,     0,     6,     0,     0,     0,    92,   197,
     207,   205,   203,   199,   201,     4,   133,   192,   102,   146,
       0,   105,   148,     0,   108,   150,     0,   111,   152,     0,
     114,   154,     0,   117,   156,     0,   129,   138,     0,   126,
     140,     0,   123,   142,     0,   120,   144,     0,   158,     0,
     160,     0,   162,     0,     0,     0,    84,    86,    89,    72,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    83,
       0,     0,     6,   103,     0,   106,     0,   109,     0,   112,
       0,   115,     0,   118,     0,   130,     0,   127,     0,   124,
       0,   121,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    79,    81,    97,   100,    27,    31,    38,    42,     0,
      52,    93,     5,   175,   177,   179,   181,   183,   185,   167,
     169,   171,   173,   187,   189,   191,     0,    75,     0,     0,
       0,     6,     6,     6,     0,    46,     0,     0,    66,     0,
      78,    70,    87,    90,     0,     0,     0,    43,     0,    57,
      63,     0,     0,     6,     0,    28,    32,    39,     0,    47,
       0,     0,     0,     0,     0,    53,    94,     0,    76,    29,
       0,     0,     0,     0,     0,     0,     0,     6,    54,    67,
      33,     0,     0,     6,     6,     6,     6,    64,    68,     0,
       0,     0,     0,     0,    60,    62,    34,    44,    48,    56,
      58,     6,     6,     0,     0,    35,    49,    36,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    56,   222,    22,    23,    51,    52,    53,    24,
      42,   281,   319,    43,   282,   320,   339,   351,   357,    25,
      44,   283,    26,    45,   154,   284,   308,    27,    46,   298,
     322,   352,   358,    28,    47,   286,   328,   301,   310,   311,
     312,   313,   314,    29,   139,   303,   338,   140,    30,    36,
      37,   246,   289,   290,   144,    31,   141,   142,   249,   143,
     250,    32,    50,   221,   287,    33,    38,   148,    39,   149,
      34,   103,   223,   106,   225,   109,   227,   112,   229,   115,
     231,   118,   233,   130,   241,   127,   239,   124,   237,   121,
     235,    57,   166,    40,   150,   122,   125,   128,   131,   104,
     107,   110,   113,   116,   119,   133,   135,   137,    59,   123,
     126,   129,   132,   105,   108,   111,   114,   117,   120,   134,
     136,   138,    41,   146,   159,   163,   164,   162,   161,   160,
      35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -268
static const yytype_int16 yypact[] =
{
     100,    53,  -268,  -268,  -268,  -268,  -268,   -12,    -8,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,     1,     0,  -268,  -268,
     -38,    30,   100,    -6,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,   192,    38,     9,    20,    32,    41,
      34,  -268,    43,    44,    46,    45,    49,    50,  -268,  -268,
     167,  -268,   240,     0,   -13,   235,   100,    90,     0,   240,
    -268,  -268,  -268,    -5,    -1,    12,    15,    17,    18,    19,
      23,    25,    26,  -268,    56,    58,    64,   -23,     6,    65,
    -268,  -268,  -268,     0,     0,     0,  -268,   167,     0,   102,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,   810,  -268,    66,
    -268,   285,  -268,   103,   240,    71,   112,   240,    88,   124,
     240,    92,   125,   240,    94,   130,   240,    96,   132,   240,
      98,   136,   240,   104,   138,   240,   105,   141,   240,   108,
     144,   240,   111,   240,   113,   240,   115,   240,   116,   118,
     119,   120,   126,   128,   127,   171,   143,  -268,   240,     0,
    -268,   306,   327,   348,   100,     0,   165,   369,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
       0,  -268,  -268,     0,  -268,  -268,     0,  -268,  -268,     0,
    -268,  -268,     0,  -268,  -268,     0,  -268,  -268,     0,  -268,
    -268,     0,  -268,  -268,     0,  -268,  -268,     0,  -268,     0,
    -268,     0,  -268,     0,   167,   167,  -268,  -268,  -268,  -268,
       6,     6,   129,   390,   134,   135,   137,   131,   411,   145,
     140,   147,   100,  -268,   432,  -268,   453,  -268,   474,  -268,
     495,  -268,   516,  -268,   537,  -268,   558,  -268,   579,  -268,
     600,  -268,   621,   642,   663,   684,   155,   166,   156,   240,
       0,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,   193,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,   168,   170,   169,   172,
     705,   100,   100,   100,   198,  -268,    -2,   240,  -268,   205,
    -268,  -268,  -268,  -268,   175,   188,   189,  -268,   194,    14,
    -268,   196,   191,   100,   167,  -268,  -268,  -268,   197,  -268,
       0,   240,     0,   240,   200,  -268,  -268,   206,  -268,  -268,
     239,     0,     0,   726,   207,   747,   209,   100,  -268,  -268,
    -268,   768,   789,   100,   100,   100,   100,  -268,  -268,   213,
     212,   215,    -2,    -2,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,   100,   100,   208,   219,  -268,  -268,  -268,  -268
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -268,   -22,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -267,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -201,  -268,  -268,  -132,   177,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
     -15,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,  -268,
    -268,  -268,  -268,   -33,  -268,  -268,  -268,  -268,  -268,  -268,
     -42
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -191
static const yytype_int16 yytable[] =
{
      61,  -101,    55,    58,   248,  -104,    54,   -24,    89,    90,
      91,    92,    54,    93,    94,    95,   299,   -85,  -107,    96,
     -55,  -110,   -83,  -113,  -116,  -128,   102,   300,   -71,  -125,
      60,  -122,  -119,    48,    99,  -134,  -174,    49,    97,    62,
    -176,    17,   -24,   101,    77,   156,   -20,    17,    19,   -24,
      78,    20,   -24,  -178,    19,   -55,  -180,    20,  -182,  -184,
    -166,    79,   -55,   145,  -168,   -55,  -170,  -172,   151,   152,
     153,   169,    80,   157,   172,   349,   350,   175,   251,   252,
     178,    81,    82,   181,    83,    84,   184,    85,    86,   187,
      87,    88,   190,   -95,   -71,   193,   100,  -186,   196,  -188,
     198,  -134,   200,   318,   202,  -190,     1,   147,   158,   168,
     165,     2,   170,     3,     4,   212,     5,     6,   171,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   173,
     174,   177,   217,   176,   213,   179,   180,   182,   183,   185,
     218,    17,   186,    18,   189,   188,   191,   192,    19,   194,
     195,    20,   197,   211,   199,   224,   201,   203,   226,   204,
     205,   228,   247,   247,   230,   206,   207,   232,   208,   209,
     234,   219,   277,   236,   253,   258,   238,   255,   256,   240,
     257,   210,   242,   260,   243,   -85,   244,   261,   245,    10,
      11,    12,    13,    14,    15,   145,   145,   276,   278,   285,
     262,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,   288,   -77,   297,   291,   304,   279,   292,    74,   305,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,   306,   307,   309,   280,   316,    73,   321,    74,
     315,    75,    76,    90,    91,    92,   327,    93,    94,    95,
     329,   330,   355,   334,   302,   336,   346,   347,   348,   294,
     295,   296,   247,   356,   155,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,    98,   324,     0,
     326,   317,    74,     0,    75,    76,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   323,     0,   325,     0,     0,
       0,     0,     0,     0,     0,   337,   331,   332,     0,     0,
       0,   342,   343,   344,   345,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,   167,     0,   353,
     354,     0,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,   214,     0,
       0,     0,     0,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,   215,
       0,     0,     0,     0,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     216,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,   220,     0,     0,     0,     0,    74,     0,    75,    76,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,   254,     0,    74,     0,    75,
      76,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,     0,     0,     0,   259,     0,    74,     0,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,   263,     0,     0,     0,     0,    74,
       0,    75,    76,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,   264,     0,     0,     0,     0,
      74,     0,    75,    76,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,   265,     0,     0,     0,
       0,    74,     0,    75,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,   266,     0,     0,
       0,     0,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,   267,     0,
       0,     0,     0,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,   268,
       0,     0,     0,     0,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     269,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,   270,     0,     0,     0,     0,    74,     0,    75,    76,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,   271,     0,     0,     0,     0,    74,     0,    75,
      76,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,   272,     0,     0,     0,     0,    74,     0,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,   273,     0,     0,     0,     0,    74,
       0,    75,    76,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,   274,     0,     0,     0,     0,
      74,     0,    75,    76,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,   275,     0,     0,     0,
       0,    74,     0,    75,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
     293,     0,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,   333,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,     0,
       0,     0,     0,   335,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     340,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,   341,     0,     0,     0,     0,    74,     0,    75,    76,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,     0,     0,    74,     0,    75,
      76
};

static const yytype_int16 yycheck[] =
{
      22,     6,    17,    41,   205,     6,     6,     6,    50,     3,
       4,     5,     6,     7,     8,     9,    18,    40,     6,    52,
       6,     6,    45,     6,     6,     6,    59,    29,    41,     6,
       0,     6,     6,    45,    56,    48,    41,    45,    53,    45,
      41,    41,    41,    58,     6,    87,    45,    41,    48,    48,
      41,    51,    51,    41,    48,    41,    41,    51,    41,    41,
      41,    41,    48,    78,    41,    51,    41,    41,    83,    84,
      85,   104,    40,    88,   107,   342,   343,   110,   210,   211,
     113,    40,    48,   116,    41,    41,   119,    41,    43,   122,
      41,    41,   125,    40,    41,   128,     6,    41,   131,    41,
     133,    48,   135,   304,   137,    41,     6,    42,     6,     6,
      44,    11,    41,    13,    14,   148,    16,    17,     6,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    41,
       6,     6,   154,    41,   149,    41,     6,    41,     6,    41,
     155,    41,     6,    43,     6,    41,    41,     6,    48,    41,
       6,    51,    41,    10,    41,   170,    41,    41,   173,    41,
      41,   176,   204,   205,   179,    45,    40,   182,    40,    42,
     185,     6,     6,   188,    45,    44,   191,    43,    43,   194,
      43,    10,   197,    43,   199,    40,   201,    40,   203,    22,
      23,    24,    25,    26,    27,   210,   211,    42,    42,     6,
     222,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    43,    42,    15,    45,    10,   249,    45,    47,    44,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    44,    44,    40,   250,    45,    45,    41,    47,
      44,    49,    50,     3,     4,     5,    46,     7,     8,     9,
      44,    12,    44,    46,   287,    46,    43,    45,    43,   281,
     282,   283,   304,    44,    87,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,   311,    -1,
     313,   303,    47,    -1,    49,    50,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   310,    -1,   312,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   327,   321,   322,    -1,    -1,
      -1,   333,   334,   335,   336,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,   351,
     352,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,
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
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    -1,    46,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    14,    16,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    43,    48,
      51,    54,    57,    58,    62,    72,    75,    80,    86,    96,
     101,   108,   114,   118,   123,   183,   102,   103,   119,   121,
     146,   175,    63,    66,    73,    76,    81,    87,    45,    45,
     115,    59,    60,    61,     6,   123,    55,   144,    41,   161,
       0,    54,    45,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    45,    47,    49,    50,     6,    41,    41,
      40,    40,    48,    41,    41,    41,    43,    41,    41,   183,
       3,     4,     5,     7,     8,     9,   176,   123,    42,    54,
       6,   123,   176,   124,   152,   166,   126,   153,   167,   128,
     154,   168,   130,   155,   169,   132,   156,   170,   134,   157,
     171,   142,   148,   162,   140,   149,   163,   138,   150,   164,
     136,   151,   165,   158,   172,   159,   173,   160,   174,    97,
     100,   109,   110,   112,   107,   123,   176,    42,   120,   122,
     147,   123,   123,   123,    77,   108,   183,   123,     6,   177,
     182,   181,   180,   178,   179,    44,   145,    42,     6,   176,
      41,     6,   176,    41,     6,   176,    41,     6,   176,    41,
       6,   176,    41,     6,   176,    41,     6,   176,    41,     6,
     176,    41,     6,   176,    41,     6,   176,    41,   176,    41,
     176,    41,   176,    41,    41,    41,    45,    40,    40,    42,
      10,    10,   176,   123,    42,    42,    42,    54,   123,     6,
      42,   116,    56,   125,   123,   127,   123,   129,   123,   131,
     123,   133,   123,   135,   123,   143,   123,   141,   123,   139,
     123,   137,   123,   123,   123,   123,   104,   183,   104,   111,
     113,   107,   107,    45,    45,    43,    43,    43,    44,    45,
      43,    40,    54,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,     6,    42,   176,
     123,    64,    67,    74,    78,     6,    88,   117,    43,   105,
     106,    45,    45,    45,    54,    54,    54,    15,    82,    18,
      29,    90,   176,    98,    10,    44,    44,    44,    79,    40,
      91,    92,    93,    94,    95,    44,    45,    54,   104,    65,
      68,    41,    83,   123,   176,   123,   176,    46,    89,    44,
      12,   123,   123,    46,    46,    46,    46,    54,    99,    69,
      42,    42,    54,    54,    54,    54,    43,    45,    43,    90,
      90,    70,    84,    54,    54,    44,    44,    71,    85
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
#line 93 "parser.y"
    {printf("stmt_list\n");}
    break;

  case 3:
#line 94 "parser.y"
    {add("S");}
    break;

  case 4:
#line 94 "parser.y"
    {add("S");}
    break;

  case 5:
#line 94 "parser.y"
    {printf("{stmt_list}\n");}
    break;

  case 6:
#line 95 "parser.y"
    {printf("stmt epsilon\n");}
    break;

  case 7:
#line 103 "parser.y"
    {printf("if statement\n");}
    break;

  case 8:
#line 104 "parser.y"
    {printf("while statement\n");}
    break;

  case 9:
#line 105 "parser.y"
    {printf("repeat statement\n");}
    break;

  case 10:
#line 106 "parser.y"
    {printf("for statement\n");}
    break;

  case 11:
#line 107 "parser.y"
    {printf("switch statement\n");}
    break;

  case 12:
#line 108 "parser.y"
    {printf("function declaration\n");}
    break;

  case 13:
#line 110 "parser.y"
    {printf("variable declaration\n");}
    break;

  case 14:
#line 111 "parser.y"
    {printf("constant declaration\n");}
    break;

  case 15:
#line 112 "parser.y"
    {printf("assignment statement\n");}
    break;

  case 16:
#line 113 "parser.y"
    {printf("expression\n");}
    break;

  case 17:
#line 114 "parser.y"
    {printf("return statement\n");}
    break;

  case 18:
#line 115 "parser.y"
    {printf("break statement\n"); add("K");}
    break;

  case 19:
#line 116 "parser.y"
    {printf("continue statement\n"); add("K");}
    break;

  case 20:
#line 119 "parser.y"
    {add("K");}
    break;

  case 21:
#line 119 "parser.y"
    {printf("return\n");}
    break;

  case 22:
#line 120 "parser.y"
    {add("K");}
    break;

  case 23:
#line 120 "parser.y"
    {printf("return term\n");}
    break;

  case 24:
#line 121 "parser.y"
    {add("K");}
    break;

  case 25:
#line 121 "parser.y"
    {printf("return expr\n");}
    break;

  case 26:
#line 129 "parser.y"
    {add("K");}
    break;

  case 27:
#line 129 "parser.y"
    {add("S");}
    break;

  case 28:
#line 129 "parser.y"
    {add("S");}
    break;

  case 29:
#line 129 "parser.y"
    {printf("if (expr) {stmt_list}\n");}
    break;

  case 30:
#line 130 "parser.y"
    {add("K");}
    break;

  case 31:
#line 130 "parser.y"
    {add("S");}
    break;

  case 32:
#line 130 "parser.y"
    {add("S");}
    break;

  case 33:
#line 130 "parser.y"
    {add("K");}
    break;

  case 34:
#line 130 "parser.y"
    {add("S");}
    break;

  case 35:
#line 130 "parser.y"
    {add("S");}
    break;

  case 36:
#line 130 "parser.y"
    {printf("if (expr) {stmt_list} else {stmt_list}\n");}
    break;

  case 37:
#line 133 "parser.y"
    { add("K"); }
    break;

  case 38:
#line 133 "parser.y"
    { add("S"); }
    break;

  case 39:
#line 133 "parser.y"
    {add("S"); printf("while (expr) {stmt_list}\n");}
    break;

  case 40:
#line 136 "parser.y"
    { add("K"); }
    break;

  case 41:
#line 136 "parser.y"
    { add("S"); }
    break;

  case 42:
#line 136 "parser.y"
    { add("S"); }
    break;

  case 43:
#line 136 "parser.y"
    { add("K"); }
    break;

  case 44:
#line 136 "parser.y"
    {printf("repeat {stmt_list} until (expr)\n");}
    break;

  case 45:
#line 139 "parser.y"
    { add("K"); }
    break;

  case 46:
#line 139 "parser.y"
    { add("V"); }
    break;

  case 47:
#line 139 "parser.y"
    { add("O");}
    break;

  case 48:
#line 139 "parser.y"
    {add("S");}
    break;

  case 49:
#line 139 "parser.y"
    {add("S");}
    break;

  case 50:
#line 139 "parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n");}
    break;

  case 51:
#line 142 "parser.y"
    {add("K");}
    break;

  case 52:
#line 142 "parser.y"
    {add("S");}
    break;

  case 53:
#line 142 "parser.y"
    { add("S");}
    break;

  case 54:
#line 142 "parser.y"
    {printf("switch (expr) {case_list}\n");}
    break;

  case 55:
#line 145 "parser.y"
    { add("K");}
    break;

  case 56:
#line 145 "parser.y"
    {printf("case expr: stmt_list case_list\n");}
    break;

  case 57:
#line 146 "parser.y"
    { add("K");}
    break;

  case 58:
#line 146 "parser.y"
    {printf("case term: stmt_list case_list\n");}
    break;

  case 59:
#line 147 "parser.y"
    { add("K");}
    break;

  case 60:
#line 147 "parser.y"
    {printf("case expr: stmt_list\n");}
    break;

  case 61:
#line 148 "parser.y"
    { add("K");}
    break;

  case 62:
#line 148 "parser.y"
    {printf("case term: stmt_list\n");}
    break;

  case 63:
#line 149 "parser.y"
    { add("K");}
    break;

  case 64:
#line 149 "parser.y"
    {printf("default: stmt_list\n");}
    break;

  case 65:
#line 152 "parser.y"
    {add("F");}
    break;

  case 66:
#line 152 "parser.y"
    { add("S");}
    break;

  case 67:
#line 152 "parser.y"
    {add("S");}
    break;

  case 68:
#line 152 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");}
    break;

  case 69:
#line 153 "parser.y"
    {add("F");}
    break;

  case 70:
#line 153 "parser.y"
    {printf("data_type identifier () {stmt_list}\n");}
    break;

  case 71:
#line 156 "parser.y"
    {add("F");}
    break;

  case 72:
#line 156 "parser.y"
    {printf("identifier (call_param_list) ;\n");}
    break;

  case 73:
#line 157 "parser.y"
    {add("F");}
    break;

  case 74:
#line 157 "parser.y"
    {printf("identifier () ;\n");}
    break;

  case 75:
#line 165 "parser.y"
    {add("V");}
    break;

  case 76:
#line 165 "parser.y"
    {printf("data_type identifier , dec_param_list\n");}
    break;

  case 77:
#line 166 "parser.y"
    {add("V");}
    break;

  case 78:
#line 166 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 79:
#line 169 "parser.y"
    {printf("identifier , call_param_list\n");}
    break;

  case 80:
#line 170 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 81:
#line 171 "parser.y"
    {printf("term , call_param_list\n");}
    break;

  case 82:
#line 172 "parser.y"
    {printf("term\n");}
    break;

  case 83:
#line 179 "parser.y"
    {add("V");}
    break;

  case 84:
#line 179 "parser.y"
    {printf("data_type identifier; \n");}
    break;

  case 85:
#line 180 "parser.y"
    {add("V");}
    break;

  case 86:
#line 180 "parser.y"
    {add("O");}
    break;

  case 87:
#line 180 "parser.y"
    {printf("data_type identifier = term ;\n");}
    break;

  case 88:
#line 181 "parser.y"
    {add("V");}
    break;

  case 89:
#line 181 "parser.y"
    {add("O");}
    break;

  case 90:
#line 181 "parser.y"
    {printf("data_type identifier = expr ;\n");}
    break;

  case 91:
#line 188 "parser.y"
    { add("K");}
    break;

  case 92:
#line 188 "parser.y"
    { add("V");}
    break;

  case 93:
#line 188 "parser.y"
    { add("O");}
    break;

  case 94:
#line 188 "parser.y"
    {printf("const data_type identifier = term ;\n");}
    break;

  case 95:
#line 195 "parser.y"
    {add("V");}
    break;

  case 96:
#line 195 "parser.y"
    { add("O");}
    break;

  case 97:
#line 195 "parser.y"
    {printf("identifier = term ;\n");}
    break;

  case 98:
#line 196 "parser.y"
    {add("V");}
    break;

  case 99:
#line 196 "parser.y"
    { add("O");}
    break;

  case 100:
#line 196 "parser.y"
    {printf("identifier = expr ;\n");}
    break;

  case 101:
#line 204 "parser.y"
    {add("O");}
    break;

  case 102:
#line 204 "parser.y"
    {add("V");}
    break;

  case 103:
#line 204 "parser.y"
    {printf("expr == identifer\n");}
    break;

  case 104:
#line 205 "parser.y"
    {add("O");}
    break;

  case 105:
#line 205 "parser.y"
    {add("V");}
    break;

  case 106:
#line 205 "parser.y"
    {printf("expr != identifer\n");}
    break;

  case 107:
#line 206 "parser.y"
    {add("O");}
    break;

  case 108:
#line 206 "parser.y"
    {add("V");}
    break;

  case 109:
#line 206 "parser.y"
    {printf("expr < identifer\n");}
    break;

  case 110:
#line 207 "parser.y"
    {add("O");}
    break;

  case 111:
#line 207 "parser.y"
    {add("V");}
    break;

  case 112:
#line 207 "parser.y"
    {printf("expr > identifer\n");}
    break;

  case 113:
#line 208 "parser.y"
    {add("O");}
    break;

  case 114:
#line 208 "parser.y"
    {add("V");}
    break;

  case 115:
#line 208 "parser.y"
    {printf("expr <= identifer\n");}
    break;

  case 116:
#line 209 "parser.y"
    {add("O");}
    break;

  case 117:
#line 209 "parser.y"
    {add("V");}
    break;

  case 118:
#line 209 "parser.y"
    {printf("expr >= identifer\n");}
    break;

  case 119:
#line 210 "parser.y"
    {add("O");}
    break;

  case 120:
#line 210 "parser.y"
    {add("V");}
    break;

  case 121:
#line 210 "parser.y"
    {printf("expr / identifer\n");}
    break;

  case 122:
#line 211 "parser.y"
    {add("O");}
    break;

  case 123:
#line 211 "parser.y"
    {add("V");}
    break;

  case 124:
#line 211 "parser.y"
    {printf("expr * identifer\n");}
    break;

  case 125:
#line 212 "parser.y"
    {add("O");}
    break;

  case 126:
#line 212 "parser.y"
    {add("V");}
    break;

  case 127:
#line 212 "parser.y"
    {printf("expr - identifer\n");}
    break;

  case 128:
#line 213 "parser.y"
    {add("O");}
    break;

  case 129:
#line 213 "parser.y"
    {add("V");}
    break;

  case 130:
#line 213 "parser.y"
    {printf("expr + identifer\n");}
    break;

  case 131:
#line 214 "parser.y"
    {add("O");}
    break;

  case 132:
#line 214 "parser.y"
    {add("V");}
    break;

  case 133:
#line 214 "parser.y"
    {printf("unary expr\n");}
    break;

  case 134:
#line 215 "parser.y"
    {add("V");}
    break;

  case 135:
#line 215 "parser.y"
    {add("O");}
    break;

  case 136:
#line 215 "parser.y"
    {printf("identifer unary\n");}
    break;

  case 137:
#line 220 "parser.y"
    {add("O");}
    break;

  case 138:
#line 220 "parser.y"
    {printf("expr + term\n");}
    break;

  case 139:
#line 221 "parser.y"
    {add("O");}
    break;

  case 140:
#line 221 "parser.y"
    {printf("expr - term\n");}
    break;

  case 141:
#line 222 "parser.y"
    {add("O");}
    break;

  case 142:
#line 222 "parser.y"
    {printf("expr * term\n");}
    break;

  case 143:
#line 223 "parser.y"
    {add("O");}
    break;

  case 144:
#line 223 "parser.y"
    {printf("expr / term\n");}
    break;

  case 145:
#line 224 "parser.y"
    {add("O");}
    break;

  case 146:
#line 224 "parser.y"
    {printf("expr == term\n");}
    break;

  case 147:
#line 225 "parser.y"
    {add("O");}
    break;

  case 148:
#line 225 "parser.y"
    {printf("expr != term\n");}
    break;

  case 149:
#line 226 "parser.y"
    {add("O");}
    break;

  case 150:
#line 226 "parser.y"
    {printf("expr < term\n");}
    break;

  case 151:
#line 227 "parser.y"
    {add("O");}
    break;

  case 152:
#line 227 "parser.y"
    {printf("expr > term\n");}
    break;

  case 153:
#line 228 "parser.y"
    {add("O");}
    break;

  case 154:
#line 228 "parser.y"
    {printf("expr <= term\n");}
    break;

  case 155:
#line 229 "parser.y"
    {add("O");}
    break;

  case 156:
#line 229 "parser.y"
    {printf("expr >= term\n");}
    break;

  case 157:
#line 230 "parser.y"
    {add("O");}
    break;

  case 158:
#line 230 "parser.y"
    {printf("expr ^ term\n");}
    break;

  case 159:
#line 231 "parser.y"
    {add("O");}
    break;

  case 160:
#line 231 "parser.y"
    {printf("expr && term\n");}
    break;

  case 161:
#line 232 "parser.y"
    {add("O");}
    break;

  case 162:
#line 232 "parser.y"
    {printf("expr || term\n");}
    break;

  case 163:
#line 233 "parser.y"
    {add("O");}
    break;

  case 164:
#line 233 "parser.y"
    {printf("!term\n");}
    break;

  case 165:
#line 234 "parser.y"
    {printf("(expr)\n");}
    break;

  case 166:
#line 235 "parser.y"
    {add("O");}
    break;

  case 167:
#line 235 "parser.y"
    {printf("expr + (expr)\n");}
    break;

  case 168:
#line 236 "parser.y"
    {add("O");}
    break;

  case 169:
#line 236 "parser.y"
    {printf("expr - (expr)\n");}
    break;

  case 170:
#line 237 "parser.y"
    {add("O");}
    break;

  case 171:
#line 237 "parser.y"
    {printf("expr * (expr)\n");}
    break;

  case 172:
#line 238 "parser.y"
    {add("O");}
    break;

  case 173:
#line 238 "parser.y"
    {printf("expr / (expr)\n");}
    break;

  case 174:
#line 239 "parser.y"
    {add("O");}
    break;

  case 175:
#line 239 "parser.y"
    {printf("expr == (expr)\n");}
    break;

  case 176:
#line 240 "parser.y"
    {add("O");}
    break;

  case 177:
#line 240 "parser.y"
    {printf("expr != (expr)\n");}
    break;

  case 178:
#line 241 "parser.y"
    {add("O");}
    break;

  case 179:
#line 241 "parser.y"
    {printf("expr < (expr)\n");}
    break;

  case 180:
#line 242 "parser.y"
    {add("O");}
    break;

  case 181:
#line 242 "parser.y"
    {printf("expr > (expr)\n");}
    break;

  case 182:
#line 243 "parser.y"
    {add("O");}
    break;

  case 183:
#line 243 "parser.y"
    {printf("expr <= (expr)\n");}
    break;

  case 184:
#line 244 "parser.y"
    {add("O");}
    break;

  case 185:
#line 244 "parser.y"
    {printf("expr >= (expr)\n");}
    break;

  case 186:
#line 245 "parser.y"
    {add("O");}
    break;

  case 187:
#line 245 "parser.y"
    {printf("expr ^ (expr)\n");}
    break;

  case 188:
#line 246 "parser.y"
    {add("O");}
    break;

  case 189:
#line 246 "parser.y"
    {printf("expr && (expr)\n");}
    break;

  case 190:
#line 247 "parser.y"
    {add("O");}
    break;

  case 191:
#line 247 "parser.y"
    {printf("expr || (expr)\n");}
    break;

  case 192:
#line 248 "parser.y"
    {printf("! (expr)\n");}
    break;

  case 193:
#line 249 "parser.y"
    {add("V");}
    break;

  case 194:
#line 249 "parser.y"
    {printf("identifier\n");}
    break;

  case 195:
#line 250 "parser.y"
    {printf("function call\n");}
    break;

  case 196:
#line 262 "parser.y"
    {add("C");}
    break;

  case 197:
#line 262 "parser.y"
    {printf("number\n");}
    break;

  case 198:
#line 263 "parser.y"
    {add("C");}
    break;

  case 199:
#line 263 "parser.y"
    {printf("true\n");}
    break;

  case 200:
#line 264 "parser.y"
    {add("C");}
    break;

  case 201:
#line 264 "parser.y"
    {printf("false\n");}
    break;

  case 202:
#line 265 "parser.y"
    {add("C");}
    break;

  case 203:
#line 265 "parser.y"
    {printf("char\n");}
    break;

  case 204:
#line 266 "parser.y"
    {add("C");}
    break;

  case 205:
#line 266 "parser.y"
    {printf("string\n");}
    break;

  case 206:
#line 267 "parser.y"
    {add("C");}
    break;

  case 207:
#line 267 "parser.y"
    {printf("float\n");}
    break;

  case 208:
#line 272 "parser.y"
    {add("K");}
    break;

  case 209:
#line 273 "parser.y"
    {add("K");}
    break;

  case 210:
#line 274 "parser.y"
    {add("K");}
    break;

  case 211:
#line 275 "parser.y"
    {add("K");}
    break;

  case 212:
#line 276 "parser.y"
    {add("K");}
    break;

  case 213:
#line 277 "parser.y"
    {add("K");}
    break;


/* Line 1267 of yacc.c.  */
#line 2984 "y.tab.c"
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


#line 278 "parser.y"




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

