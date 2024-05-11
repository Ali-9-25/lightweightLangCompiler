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
#define YYFINAL  59
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   955

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  127
/* YYNRULES -- Number of rules.  */
#define YYNRULES  207
/* YYNRULES -- Number of states.  */
#define YYNSTATES  343

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
     182,   187,   188,   189,   190,   202,   203,   209,   210,   211,
     217,   218,   222,   223,   227,   229,   233,   235,   236,   241,
     242,   243,   251,   252,   253,   261,   262,   263,   264,   274,
     275,   276,   283,   284,   285,   292,   293,   294,   300,   301,
     302,   308,   309,   310,   316,   317,   318,   324,   325,   326,
     332,   333,   334,   340,   341,   342,   348,   349,   350,   356,
     357,   358,   364,   365,   366,   372,   373,   374,   379,   380,
     381,   386,   387,   392,   393,   398,   399,   404,   405,   410,
     411,   416,   417,   422,   423,   428,   429,   434,   435,   440,
     441,   446,   447,   452,   453,   458,   459,   464,   465,   469,
     473,   474,   481,   482,   489,   490,   497,   498,   505,   506,
     513,   514,   521,   522,   529,   530,   537,   538,   545,   546,
     553,   554,   561,   562,   569,   570,   577,   582,   583,   586,
     588,   589,   592,   593,   596,   597,   600,   601,   604,   605,
     608,   609,   612,   614,   616,   618,   620,   622
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    57,    54,    -1,    -1,    -1,    43,    55,
      54,    44,    56,    54,    -1,    -1,    62,    -1,    72,    -1,
      75,    -1,    80,    -1,    86,    -1,    94,    -1,   104,    -1,
     110,    -1,   114,    -1,   119,    45,    -1,    58,    45,    -1,
      19,    45,    -1,    20,    45,    -1,    -1,    28,    59,    -1,
      -1,    28,    60,   172,    -1,    -1,    28,    61,   119,    -1,
      -1,    -1,    -1,    11,    63,    41,   119,    42,    43,    64,
      54,    44,    65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      11,    66,    41,   119,    42,    43,    67,    54,    44,    68,
      12,    69,    43,    70,    54,    44,    71,    -1,    -1,    -1,
      13,    73,    41,   119,    42,    43,    74,    54,    44,    -1,
      -1,    -1,    -1,    -1,    14,    76,    43,    77,    54,    44,
      78,    15,    79,    41,   119,    42,    45,    -1,    -1,    -1,
      -1,    -1,    -1,    16,    81,    41,   104,   119,    45,     6,
      82,    40,    83,   119,    42,    43,    84,    54,    44,    85,
      -1,    -1,    -1,    -1,    17,    87,    41,   119,    42,    43,
      88,    90,    44,    89,    -1,    -1,    18,    91,   119,    46,
      54,    90,    -1,    -1,    18,    92,   172,    46,    54,    90,
      -1,    -1,    29,    93,    46,    54,    -1,    -1,    -1,    -1,
     179,     6,    95,    41,   100,    42,    43,    96,    54,    44,
      97,    -1,    -1,     6,    99,    41,   103,    42,    -1,    -1,
      -1,   179,     6,   101,    10,   100,    -1,    -1,   179,     6,
     102,    -1,    -1,   119,    10,   103,    -1,   119,    -1,   172,
      10,   103,    -1,   172,    -1,    -1,   179,     6,   105,    45,
      -1,    -1,    -1,   179,     6,   106,    40,   107,   172,    45,
      -1,    -1,    -1,   179,     6,   108,    40,   109,   119,    45,
      -1,    -1,    -1,    -1,    21,   111,   179,     6,   112,    40,
     113,   172,    45,    -1,    -1,    -1,     6,   115,    40,   116,
     172,    45,    -1,    -1,    -1,     6,   117,    40,   118,   119,
      45,    -1,    -1,    -1,   119,    30,   120,     6,   121,    -1,
      -1,    -1,   119,    31,   122,     6,   123,    -1,    -1,    -1,
     119,    32,   124,     6,   125,    -1,    -1,    -1,   119,    33,
     126,     6,   127,    -1,    -1,    -1,   119,    34,   128,     6,
     129,    -1,    -1,    -1,   119,    35,   130,     6,   131,    -1,
      -1,    -1,   119,    39,   132,     6,   133,    -1,    -1,    -1,
     119,    38,   134,     6,   135,    -1,    -1,    -1,   119,    37,
     136,     6,   137,    -1,    -1,    -1,   119,    36,   138,     6,
     139,    -1,    -1,    -1,    48,   140,     6,   141,    -1,    -1,
      -1,     6,   142,    48,   143,    -1,    -1,   119,    36,   144,
     172,    -1,    -1,   119,    37,   145,   172,    -1,    -1,   119,
      38,   146,   172,    -1,    -1,   119,    39,   147,   172,    -1,
      -1,   119,    30,   148,   172,    -1,    -1,   119,    31,   149,
     172,    -1,    -1,   119,    32,   150,   172,    -1,    -1,   119,
      33,   151,   172,    -1,    -1,   119,    34,   152,   172,    -1,
      -1,   119,    35,   153,   172,    -1,    -1,   119,    47,   154,
     172,    -1,    -1,   119,    49,   155,   172,    -1,    -1,   119,
      50,   156,   172,    -1,    -1,    51,   157,   172,    -1,    41,
     119,    42,    -1,    -1,   119,    36,   158,    41,   119,    42,
      -1,    -1,   119,    37,   159,    41,   119,    42,    -1,    -1,
     119,    38,   160,    41,   119,    42,    -1,    -1,   119,    39,
     161,    41,   119,    42,    -1,    -1,   119,    30,   162,    41,
     119,    42,    -1,    -1,   119,    31,   163,    41,   119,    42,
      -1,    -1,   119,    32,   164,    41,   119,    42,    -1,    -1,
     119,    33,   165,    41,   119,    42,    -1,    -1,   119,    34,
     166,    41,   119,    42,    -1,    -1,   119,    35,   167,    41,
     119,    42,    -1,    -1,   119,    47,   168,    41,   119,    42,
      -1,    -1,   119,    49,   169,    41,   119,    42,    -1,    -1,
     119,    50,   170,    41,   119,    42,    -1,    51,    41,   119,
      42,    -1,    -1,     6,   171,    -1,    98,    -1,    -1,     3,
     173,    -1,    -1,     8,   174,    -1,    -1,     9,   175,    -1,
      -1,     7,   176,    -1,    -1,     5,   177,    -1,    -1,     4,
     178,    -1,    22,    -1,    24,    -1,    26,    -1,    25,    -1,
      23,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    94,    94,    95,   103,   104,   105,
     106,   107,   108,   110,   111,   112,   113,   114,   115,   116,
     119,   119,   120,   120,   121,   121,   129,   129,   129,   129,
     130,   130,   130,   130,   130,   130,   130,   133,   133,   133,
     136,   136,   136,   136,   136,   139,   139,   139,   139,   139,
     139,   142,   142,   142,   142,   145,   145,   146,   146,   149,
     149,   152,   152,   152,   152,   156,   156,   158,   166,   166,
     167,   167,   168,   171,   172,   173,   174,   181,   181,   182,
     182,   182,   183,   183,   183,   190,   190,   190,   190,   197,
     197,   197,   198,   198,   198,   206,   206,   206,   207,   207,
     207,   208,   208,   208,   209,   209,   209,   210,   210,   210,
     211,   211,   211,   212,   212,   212,   213,   213,   213,   214,
     214,   214,   215,   215,   215,   216,   216,   216,   217,   217,
     217,   222,   222,   223,   223,   224,   224,   225,   225,   226,
     226,   227,   227,   228,   228,   229,   229,   230,   230,   231,
     231,   232,   232,   233,   233,   234,   234,   235,   235,   236,
     237,   237,   238,   238,   239,   239,   240,   240,   241,   241,
     242,   242,   243,   243,   244,   244,   245,   245,   246,   246,
     247,   247,   248,   248,   249,   249,   250,   251,   251,   252,
     264,   264,   265,   265,   266,   266,   267,   267,   268,   268,
     269,   269,   274,   275,   276,   277,   278,   279
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
  "@29", "@30", "@31", "func_decl", "@32", "@33", "@34", "func_call",
  "@35", "dec_param_list", "@36", "@37", "call_param_list", "var_decl",
  "@38", "@39", "@40", "@41", "@42", "const_decl", "@43", "@44", "@45",
  "assignment_stmt", "@46", "@47", "@48", "@49", "expr", "@50", "@51",
  "@52", "@53", "@54", "@55", "@56", "@57", "@58", "@59", "@60", "@61",
  "@62", "@63", "@64", "@65", "@66", "@67", "@68", "@69", "@70", "@71",
  "@72", "@73", "@74", "@75", "@76", "@77", "@78", "@79", "@80", "@81",
  "@82", "@83", "@84", "@85", "@86", "@87", "@88", "@89", "@90", "@91",
  "@92", "@93", "@94", "@95", "@96", "@97", "@98", "@99", "@100", "@101",
  "TERM", "@102", "@103", "@104", "@105", "@106", "@107", "DATATYPE", 0
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
      90,    95,    96,    97,    94,    99,    98,    98,   101,   100,
     102,   100,   100,   103,   103,   103,   103,   105,   104,   106,
     107,   104,   108,   109,   104,   111,   112,   113,   110,   115,
     116,   114,   117,   118,   114,   120,   121,   119,   122,   123,
     119,   124,   125,   119,   126,   127,   119,   128,   129,   119,
     130,   131,   119,   132,   133,   119,   134,   135,   119,   136,
     137,   119,   138,   139,   119,   140,   141,   119,   142,   143,
     119,   144,   119,   145,   119,   146,   119,   147,   119,   148,
     119,   149,   119,   150,   119,   151,   119,   152,   119,   153,
     119,   154,   119,   155,   119,   156,   119,   157,   119,   119,
     158,   119,   159,   119,   160,   119,   161,   119,   162,   119,
     163,   119,   164,   119,   165,   119,   166,   119,   167,   119,
     168,   119,   169,   119,   170,   119,   119,   171,   119,   119,
     173,   172,   174,   172,   175,   172,   176,   172,   177,   172,
     178,   172,   179,   179,   179,   179,   179,   179
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
       4,     0,     0,     0,    11,     0,     5,     0,     0,     5,
       0,     3,     0,     3,     1,     3,     1,     0,     4,     0,
       0,     7,     0,     0,     7,     0,     0,     0,     9,     0,
       0,     6,     0,     0,     6,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     5,     0,     0,     5,     0,     0,     4,     0,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     3,     3,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     4,     0,     2,     1,
       0,     2,     0,     2,     0,     2,     0,     2,     0,     2,
       0,     2,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      67,   187,    26,    37,    40,    45,    51,     0,     0,    85,
     202,   206,   203,   205,   204,   207,    24,    67,     3,   125,
     157,     0,    67,     0,     7,     8,     9,    10,    11,    12,
     189,    13,    14,    15,     0,     0,     0,     0,     0,     0,
     188,     0,     0,     0,     0,     0,     0,    18,    19,     0,
      21,     0,    67,   187,     0,    67,     0,    67,     0,     1,
       2,    17,   139,   141,   143,   145,   147,   149,   131,   133,
     135,   137,    16,   151,   153,   155,    61,    67,    90,    93,
     129,    67,    67,    67,    41,     0,    67,     0,   190,   200,
     198,   196,   192,   194,    23,    25,   159,     0,   126,     0,
     158,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    74,    76,     0,    67,   130,     0,     0,     0,
      67,    67,     0,     0,    86,   191,   201,   199,   197,   193,
     195,     4,   127,   186,    96,   140,    67,    99,   142,    67,
     102,   144,    67,   105,   146,    67,   108,   148,    67,   111,
     150,    67,   123,   132,    67,   120,   134,    67,   117,   136,
      67,   114,   138,    67,   152,    67,   154,    67,   156,    67,
      72,    78,    80,    83,    66,    67,    67,     0,     0,     0,
       0,     0,     0,     0,    77,     0,     0,    67,    97,     0,
     100,     0,   103,     0,   106,     0,   109,     0,   112,     0,
     124,     0,   121,     0,   118,     0,   115,     0,     0,     0,
       0,     0,     0,     0,    67,    73,    75,    91,    94,    27,
      31,    38,    42,     0,    52,    87,     5,   169,   171,   173,
     175,   177,   179,   161,   163,   165,   167,   181,   183,   185,
       0,    68,     0,     0,    67,    67,    67,     0,    46,     0,
       0,    62,     0,    71,    81,    84,     0,     0,     0,    43,
       0,    55,    59,     0,     0,    67,    72,    28,    32,    39,
       0,    47,    67,     0,     0,    53,    88,     0,    69,    29,
       0,    67,    67,     0,     0,    67,    54,    63,    33,     0,
       0,    67,    67,    60,    64,     0,     0,     0,     0,     0,
      34,    44,    48,    56,    58,    67,    67,     0,     0,    35,
      49,    36,    50
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    55,   217,    22,    23,    50,    51,    52,    24,
      41,   274,   309,    42,   275,   310,   325,   335,   341,    25,
      43,   276,    26,    44,   150,   277,   300,    27,    45,   290,
     312,   336,   342,    28,    46,   279,   316,   293,   302,   303,
     304,    29,   137,   295,   324,    30,    36,   241,   282,   283,
     141,    31,   138,   139,   243,   140,   244,    32,    49,   216,
     280,    33,    37,   144,    38,   145,    34,   101,   218,   104,
     220,   107,   222,   110,   224,   113,   226,   116,   228,   128,
     236,   125,   234,   122,   232,   119,   230,    56,   162,    39,
     146,   120,   123,   126,   129,   102,   105,   108,   111,   114,
     117,   131,   133,   135,    58,   121,   124,   127,   130,   103,
     106,   109,   112,   115,   118,   132,   134,   136,    40,   143,
     155,   159,   160,   158,   157,   156,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -276
static const yytype_int16 yypact[] =
{
     191,    65,  -276,  -276,  -276,  -276,  -276,   -33,   -15,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,    11,    -4,  -276,  -276,
      -6,    40,    98,     0,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,   359,    45,    14,    38,    39,    24,
    -276,    18,    41,    43,    42,    46,    47,  -276,  -276,   254,
    -276,   129,    -4,     2,   380,   337,    75,    -4,   129,  -276,
    -276,  -276,     5,     7,    16,    17,    19,    21,    22,    23,
      28,    32,  -276,    49,    50,    52,   -14,     1,  -276,  -276,
    -276,    -4,    -4,    -4,  -276,   254,    -4,    88,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,   905,  -276,    56,  -276,   401,
    -276,    90,   129,    61,    97,   129,    66,   102,   129,    89,
     125,   129,    99,   137,   129,   103,   139,   129,   106,   142,
     129,   110,   146,   129,   114,   151,   129,   117,   154,   129,
     120,   129,   122,   129,   123,   129,   126,   128,   121,   130,
     132,   131,   225,   165,   129,    -4,  -276,   422,   443,   464,
     337,    -4,   170,   485,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,    -4,  -276,  -276,    -4,
    -276,  -276,    -4,  -276,  -276,    -4,  -276,  -276,    -4,  -276,
    -276,    -4,  -276,  -276,    -4,  -276,  -276,    -4,  -276,  -276,
      -4,  -276,  -276,    -4,  -276,    -4,  -276,    -4,  -276,    -4,
     254,  -276,  -276,  -276,  -276,     1,     1,   133,   506,   141,
     143,   144,   136,   527,   145,   149,   148,    98,  -276,   548,
    -276,   569,  -276,   590,  -276,   611,  -276,   632,  -276,   653,
    -276,   674,  -276,   695,  -276,   716,  -276,   737,   758,   779,
     800,   140,   187,   129,    -4,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,   188,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
     153,   156,   155,   821,   337,   337,   337,   184,  -276,     3,
     129,  -276,   193,  -276,  -276,  -276,   157,   162,   179,  -276,
     189,   217,  -276,   183,   185,   337,   254,  -276,  -276,  -276,
     190,  -276,    -4,   129,   192,  -276,  -276,   196,  -276,  -276,
     221,    -4,    -4,   842,   195,   337,  -276,  -276,  -276,   863,
     884,   304,   304,  -276,  -276,   194,   198,   201,     3,     3,
    -276,  -276,  -276,  -276,  -276,   337,   337,   203,   204,  -276,
    -276,  -276,  -276
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -276,   -22,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -275,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,   -60,  -276,  -276,
    -130,   160,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,   -16,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,
    -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,  -276,   -34,
    -276,  -276,  -276,  -276,  -276,  -276,   -46
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -185
static const yytype_int16 yytable[] =
{
      60,    54,    53,    87,    88,    89,    90,    53,    91,    92,
      93,   -95,    47,   -98,   -22,   -22,   -22,    94,   -22,   -22,
     -22,   291,  -101,  -104,   100,  -107,   -79,  -110,  -122,  -119,
      48,   -77,   292,    97,  -116,    57,    95,    17,  -113,   152,
      59,    99,    17,   -65,    19,    61,  -168,    20,  -170,    19,
    -128,    76,    20,   333,   334,    77,   -20,  -172,  -174,    81,
    -176,   142,  -178,  -160,  -162,   147,   148,   149,   165,  -164,
     153,   168,    80,  -166,   171,   245,   246,   174,    78,    79,
     177,    98,    82,   180,    83,    84,   183,    85,    86,   186,
    -180,  -182,   189,  -184,   154,   192,   164,   194,    -6,   196,
     161,   198,   166,   167,     1,   -89,   -65,   169,   170,     2,
     207,     3,     4,  -128,     5,     6,    -6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    -6,   212,   208,
     172,   173,    88,    89,    90,   213,    91,    92,    93,    17,
     175,    18,    -6,   176,   178,   179,    19,   181,   182,    20,
     219,   184,   185,   221,   242,   187,   223,   188,   190,   225,
     191,   193,   227,   195,   197,   229,   201,   199,   231,   200,
     202,   233,   203,   204,   235,   206,   214,   237,   247,   238,
     252,   239,   270,   240,   249,   -79,   250,   251,   255,   142,
     142,    -6,   254,   271,   278,   256,   281,     1,   -70,   289,
     284,   297,     2,   296,     3,     4,   298,     5,     6,   272,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
     -57,   -57,   -57,   299,   -57,   -57,   -57,   305,   273,   301,
     306,   311,    17,   318,    18,   205,   308,   330,   315,    19,
     317,   322,    20,   331,   332,   151,   294,   339,   340,     0,
     242,     0,   286,   287,   288,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,     0,     0,   314,
       0,     0,    73,   307,    74,    75,    10,    11,    12,    13,
      14,    15,     0,     0,     0,     0,   313,     0,     0,     0,
       0,     0,     0,   323,     0,   319,   320,     0,     0,   328,
     329,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       1,     0,     0,   337,   338,     2,     0,     3,     4,     0,
       5,     6,    -6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    -6,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     1,     0,    17,     0,    18,     2,     0,
       3,     4,    19,     5,     6,    20,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,     0,
      18,    -6,     0,     0,     0,    19,     0,     0,    20,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,     0,     0,     0,    72,     0,    73,     0,    74,    75,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,    96,     0,     0,     0,     0,    73,     0,    74,
      75,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,   163,     0,     0,     0,     0,    73,     0,
      74,    75,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,   209,     0,     0,     0,     0,    73,
       0,    74,    75,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,   210,     0,     0,     0,     0,
      73,     0,    74,    75,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,   211,     0,     0,     0,
       0,    73,     0,    74,    75,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,   215,     0,     0,
       0,     0,    73,     0,    74,    75,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,   248,     0,    73,     0,    74,    75,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,     0,
       0,     0,   253,     0,    73,     0,    74,    75,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
     257,     0,     0,     0,     0,    73,     0,    74,    75,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,   258,     0,     0,     0,     0,    73,     0,    74,    75,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,   259,     0,     0,     0,     0,    73,     0,    74,
      75,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,   260,     0,     0,     0,     0,    73,     0,
      74,    75,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,   261,     0,     0,     0,     0,    73,
       0,    74,    75,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,   262,     0,     0,     0,     0,
      73,     0,    74,    75,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,   263,     0,     0,     0,
       0,    73,     0,    74,    75,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,   264,     0,     0,
       0,     0,    73,     0,    74,    75,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,     0,     0,   265,     0,
       0,     0,     0,    73,     0,    74,    75,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,     0,     0,   266,
       0,     0,     0,     0,    73,     0,    74,    75,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,     0,     0,
     267,     0,     0,     0,     0,    73,     0,    74,    75,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,     0,
       0,   268,     0,     0,     0,     0,    73,     0,    74,    75,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
       0,     0,   269,     0,     0,     0,     0,    73,     0,    74,
      75,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,     0,     0,     0,     0,     0,   285,     0,    73,     0,
      74,    75,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,   321,    73,
       0,    74,    75,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,     0,     0,   326,     0,     0,     0,     0,
      73,     0,    74,    75,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,     0,     0,   327,     0,     0,     0,
       0,    73,     0,    74,    75,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,    73,     0,    74,    75
};

static const yytype_int16 yycheck[] =
{
      22,    17,     6,    49,     3,     4,     5,     6,     7,     8,
       9,     6,    45,     6,     3,     4,     5,    51,     7,     8,
       9,    18,     6,     6,    58,     6,    40,     6,     6,     6,
      45,    45,    29,    55,     6,    41,    52,    41,     6,    85,
       0,    57,    41,    41,    48,    45,    41,    51,    41,    48,
      48,     6,    51,   328,   329,    41,    45,    41,    41,    41,
      41,    77,    41,    41,    41,    81,    82,    83,   102,    41,
      86,   105,    48,    41,   108,   205,   206,   111,    40,    40,
     114,     6,    41,   117,    41,    43,   120,    41,    41,   123,
      41,    41,   126,    41,     6,   129,     6,   131,     0,   133,
      44,   135,    41,     6,     6,    40,    41,    41,     6,    11,
     144,    13,    14,    48,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,   150,   145,
      41,     6,     3,     4,     5,   151,     7,     8,     9,    41,
      41,    43,    44,     6,    41,     6,    48,    41,     6,    51,
     166,    41,     6,   169,   200,    41,   172,     6,    41,   175,
       6,    41,   178,    41,    41,   181,    45,    41,   184,    41,
      40,   187,    40,    42,   190,    10,     6,   193,    45,   195,
      44,   197,    42,   199,    43,    40,    43,    43,    40,   205,
     206,     0,    43,     6,     6,   217,    43,     6,    42,    15,
      45,    44,    11,    10,    13,    14,    44,    16,    17,   243,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
       3,     4,     5,    44,     7,     8,     9,    44,   244,    40,
      45,    41,    41,    12,    43,    10,   296,    43,    46,    48,
      44,    46,    51,    45,    43,    85,   280,    44,    44,    -1,
     296,    -1,   274,   275,   276,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,   303,
      -1,    -1,    47,   295,    49,    50,    22,    23,    24,    25,
      26,    27,    -1,    -1,    -1,    -1,   302,    -1,    -1,    -1,
      -1,    -1,    -1,   315,    -1,   311,   312,    -1,    -1,   321,
     322,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       6,    -1,    -1,   335,   336,    11,    -1,    13,    14,    -1,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     6,    -1,    41,    -1,    43,    11,    -1,
      13,    14,    48,    16,    17,    51,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    51,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,
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
      51,    54,    57,    58,    62,    72,    75,    80,    86,    94,
      98,   104,   110,   114,   119,   179,    99,   115,   117,   142,
     171,    63,    66,    73,    76,    81,    87,    45,    45,   111,
      59,    60,    61,     6,   119,    55,   140,    41,   157,     0,
      54,    45,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    45,    47,    49,    50,     6,    41,    40,    40,
      48,    41,    41,    41,    43,    41,    41,   179,     3,     4,
       5,     7,     8,     9,   172,   119,    42,    54,     6,   119,
     172,   120,   148,   162,   122,   149,   163,   124,   150,   164,
     126,   151,   165,   128,   152,   166,   130,   153,   167,   138,
     144,   158,   136,   145,   159,   134,   146,   160,   132,   147,
     161,   154,   168,   155,   169,   156,   170,    95,   105,   106,
     108,   103,   119,   172,   116,   118,   143,   119,   119,   119,
      77,   104,   179,   119,     6,   173,   178,   177,   176,   174,
     175,    44,   141,    42,     6,   172,    41,     6,   172,    41,
       6,   172,    41,     6,   172,    41,     6,   172,    41,     6,
     172,    41,     6,   172,    41,     6,   172,    41,     6,   172,
      41,     6,   172,    41,   172,    41,   172,    41,   172,    41,
      41,    45,    40,    40,    42,    10,    10,   172,   119,    42,
      42,    42,    54,   119,     6,    42,   112,    56,   121,   119,
     123,   119,   125,   119,   127,   119,   129,   119,   131,   119,
     139,   119,   137,   119,   135,   119,   133,   119,   119,   119,
     119,   100,   179,   107,   109,   103,   103,    45,    45,    43,
      43,    43,    44,    45,    43,    40,    54,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,     6,   172,   119,    64,    67,    74,    78,     6,    88,
     113,    43,   101,   102,    45,    45,    54,    54,    54,    15,
      82,    18,    29,    90,   172,    96,    10,    44,    44,    44,
      79,    40,    91,    92,    93,    44,    45,    54,   100,    65,
      68,    41,    83,   119,   172,    46,    89,    44,    12,   119,
     119,    46,    46,    54,    97,    69,    42,    42,    54,    54,
      43,    45,    43,    90,    90,    70,    84,    54,    54,    44,
      44,    71,    85
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
#line 149 "parser.y"
    { add("K");}
    break;

  case 60:
#line 149 "parser.y"
    {printf("default: stmt_list\n");}
    break;

  case 61:
#line 152 "parser.y"
    {add("F");}
    break;

  case 62:
#line 152 "parser.y"
    { add("S");}
    break;

  case 63:
#line 152 "parser.y"
    {add("S");}
    break;

  case 64:
#line 152 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");}
    break;

  case 65:
#line 156 "parser.y"
    {add("F");}
    break;

  case 66:
#line 156 "parser.y"
    {printf("identifier (call_param_list) ;\n");}
    break;

  case 68:
#line 166 "parser.y"
    {add("V");}
    break;

  case 69:
#line 166 "parser.y"
    {printf("data_type identifier , dec_param_list\n");}
    break;

  case 70:
#line 167 "parser.y"
    {add("V");}
    break;

  case 71:
#line 167 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 73:
#line 171 "parser.y"
    {printf("identifier , call_param_list\n");}
    break;

  case 74:
#line 172 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 75:
#line 173 "parser.y"
    {printf("term , call_param_list\n");}
    break;

  case 76:
#line 174 "parser.y"
    {printf("term\n");}
    break;

  case 77:
#line 181 "parser.y"
    {add("V");}
    break;

  case 78:
#line 181 "parser.y"
    {printf("data_type identifier; \n");}
    break;

  case 79:
#line 182 "parser.y"
    {add("V");}
    break;

  case 80:
#line 182 "parser.y"
    {add("O");}
    break;

  case 81:
#line 182 "parser.y"
    {printf("data_type identifier = term ;\n");}
    break;

  case 82:
#line 183 "parser.y"
    {add("V");}
    break;

  case 83:
#line 183 "parser.y"
    {add("O");}
    break;

  case 84:
#line 183 "parser.y"
    {printf("data_type identifier = expr ;\n");}
    break;

  case 85:
#line 190 "parser.y"
    { add("K");}
    break;

  case 86:
#line 190 "parser.y"
    { add("V");}
    break;

  case 87:
#line 190 "parser.y"
    { add("O");}
    break;

  case 88:
#line 190 "parser.y"
    {printf("const data_type identifier = term ;\n");}
    break;

  case 89:
#line 197 "parser.y"
    {add("V");}
    break;

  case 90:
#line 197 "parser.y"
    { add("O");}
    break;

  case 91:
#line 197 "parser.y"
    {printf("identifier = term ;\n");}
    break;

  case 92:
#line 198 "parser.y"
    {add("V");}
    break;

  case 93:
#line 198 "parser.y"
    { add("O");}
    break;

  case 94:
#line 198 "parser.y"
    {printf("identifier = expr ;\n");}
    break;

  case 95:
#line 206 "parser.y"
    {add("O");}
    break;

  case 96:
#line 206 "parser.y"
    {add("V");}
    break;

  case 97:
#line 206 "parser.y"
    {printf("expr == identifer\n");}
    break;

  case 98:
#line 207 "parser.y"
    {add("O");}
    break;

  case 99:
#line 207 "parser.y"
    {add("V");}
    break;

  case 100:
#line 207 "parser.y"
    {printf("expr != identifer\n");}
    break;

  case 101:
#line 208 "parser.y"
    {add("O");}
    break;

  case 102:
#line 208 "parser.y"
    {add("V");}
    break;

  case 103:
#line 208 "parser.y"
    {printf("expr < identifer\n");}
    break;

  case 104:
#line 209 "parser.y"
    {add("O");}
    break;

  case 105:
#line 209 "parser.y"
    {add("V");}
    break;

  case 106:
#line 209 "parser.y"
    {printf("expr > identifer\n");}
    break;

  case 107:
#line 210 "parser.y"
    {add("O");}
    break;

  case 108:
#line 210 "parser.y"
    {add("V");}
    break;

  case 109:
#line 210 "parser.y"
    {printf("expr <= identifer\n");}
    break;

  case 110:
#line 211 "parser.y"
    {add("O");}
    break;

  case 111:
#line 211 "parser.y"
    {add("V");}
    break;

  case 112:
#line 211 "parser.y"
    {printf("expr >= identifer\n");}
    break;

  case 113:
#line 212 "parser.y"
    {add("O");}
    break;

  case 114:
#line 212 "parser.y"
    {add("V");}
    break;

  case 115:
#line 212 "parser.y"
    {printf("expr / identifer\n");}
    break;

  case 116:
#line 213 "parser.y"
    {add("O");}
    break;

  case 117:
#line 213 "parser.y"
    {add("V");}
    break;

  case 118:
#line 213 "parser.y"
    {printf("expr * identifer\n");}
    break;

  case 119:
#line 214 "parser.y"
    {add("O");}
    break;

  case 120:
#line 214 "parser.y"
    {add("V");}
    break;

  case 121:
#line 214 "parser.y"
    {printf("expr - identifer\n");}
    break;

  case 122:
#line 215 "parser.y"
    {add("O");}
    break;

  case 123:
#line 215 "parser.y"
    {add("V");}
    break;

  case 124:
#line 215 "parser.y"
    {printf("expr + identifer\n");}
    break;

  case 125:
#line 216 "parser.y"
    {add("O");}
    break;

  case 126:
#line 216 "parser.y"
    {add("V");}
    break;

  case 127:
#line 216 "parser.y"
    {printf("unary expr\n");}
    break;

  case 128:
#line 217 "parser.y"
    {add("V");}
    break;

  case 129:
#line 217 "parser.y"
    {add("O");}
    break;

  case 130:
#line 217 "parser.y"
    {printf("identifer unary\n");}
    break;

  case 131:
#line 222 "parser.y"
    {add("O");}
    break;

  case 132:
#line 222 "parser.y"
    {printf("expr + term\n");}
    break;

  case 133:
#line 223 "parser.y"
    {add("O");}
    break;

  case 134:
#line 223 "parser.y"
    {printf("expr - term\n");}
    break;

  case 135:
#line 224 "parser.y"
    {add("O");}
    break;

  case 136:
#line 224 "parser.y"
    {printf("expr * term\n");}
    break;

  case 137:
#line 225 "parser.y"
    {add("O");}
    break;

  case 138:
#line 225 "parser.y"
    {printf("expr / term\n");}
    break;

  case 139:
#line 226 "parser.y"
    {add("O");}
    break;

  case 140:
#line 226 "parser.y"
    {printf("expr == term\n");}
    break;

  case 141:
#line 227 "parser.y"
    {add("O");}
    break;

  case 142:
#line 227 "parser.y"
    {printf("expr != term\n");}
    break;

  case 143:
#line 228 "parser.y"
    {add("O");}
    break;

  case 144:
#line 228 "parser.y"
    {printf("expr < term\n");}
    break;

  case 145:
#line 229 "parser.y"
    {add("O");}
    break;

  case 146:
#line 229 "parser.y"
    {printf("expr > term\n");}
    break;

  case 147:
#line 230 "parser.y"
    {add("O");}
    break;

  case 148:
#line 230 "parser.y"
    {printf("expr <= term\n");}
    break;

  case 149:
#line 231 "parser.y"
    {add("O");}
    break;

  case 150:
#line 231 "parser.y"
    {printf("expr >= term\n");}
    break;

  case 151:
#line 232 "parser.y"
    {add("O");}
    break;

  case 152:
#line 232 "parser.y"
    {printf("expr ^ term\n");}
    break;

  case 153:
#line 233 "parser.y"
    {add("O");}
    break;

  case 154:
#line 233 "parser.y"
    {printf("expr && term\n");}
    break;

  case 155:
#line 234 "parser.y"
    {add("O");}
    break;

  case 156:
#line 234 "parser.y"
    {printf("expr || term\n");}
    break;

  case 157:
#line 235 "parser.y"
    {add("O");}
    break;

  case 158:
#line 235 "parser.y"
    {printf("!term\n");}
    break;

  case 159:
#line 236 "parser.y"
    {printf("(expr)\n");}
    break;

  case 160:
#line 237 "parser.y"
    {add("O");}
    break;

  case 161:
#line 237 "parser.y"
    {printf("expr + (expr)\n");}
    break;

  case 162:
#line 238 "parser.y"
    {add("O");}
    break;

  case 163:
#line 238 "parser.y"
    {printf("expr - (expr)\n");}
    break;

  case 164:
#line 239 "parser.y"
    {add("O");}
    break;

  case 165:
#line 239 "parser.y"
    {printf("expr * (expr)\n");}
    break;

  case 166:
#line 240 "parser.y"
    {add("O");}
    break;

  case 167:
#line 240 "parser.y"
    {printf("expr / (expr)\n");}
    break;

  case 168:
#line 241 "parser.y"
    {add("O");}
    break;

  case 169:
#line 241 "parser.y"
    {printf("expr == (expr)\n");}
    break;

  case 170:
#line 242 "parser.y"
    {add("O");}
    break;

  case 171:
#line 242 "parser.y"
    {printf("expr != (expr)\n");}
    break;

  case 172:
#line 243 "parser.y"
    {add("O");}
    break;

  case 173:
#line 243 "parser.y"
    {printf("expr < (expr)\n");}
    break;

  case 174:
#line 244 "parser.y"
    {add("O");}
    break;

  case 175:
#line 244 "parser.y"
    {printf("expr > (expr)\n");}
    break;

  case 176:
#line 245 "parser.y"
    {add("O");}
    break;

  case 177:
#line 245 "parser.y"
    {printf("expr <= (expr)\n");}
    break;

  case 178:
#line 246 "parser.y"
    {add("O");}
    break;

  case 179:
#line 246 "parser.y"
    {printf("expr >= (expr)\n");}
    break;

  case 180:
#line 247 "parser.y"
    {add("O");}
    break;

  case 181:
#line 247 "parser.y"
    {printf("expr ^ (expr)\n");}
    break;

  case 182:
#line 248 "parser.y"
    {add("O");}
    break;

  case 183:
#line 248 "parser.y"
    {printf("expr && (expr)\n");}
    break;

  case 184:
#line 249 "parser.y"
    {add("O");}
    break;

  case 185:
#line 249 "parser.y"
    {printf("expr || (expr)\n");}
    break;

  case 186:
#line 250 "parser.y"
    {printf("! (expr)\n");}
    break;

  case 187:
#line 251 "parser.y"
    {add("V");}
    break;

  case 188:
#line 251 "parser.y"
    {printf("identifier\n");}
    break;

  case 189:
#line 252 "parser.y"
    {printf("function call\n");}
    break;

  case 190:
#line 264 "parser.y"
    {add("C");}
    break;

  case 191:
#line 264 "parser.y"
    {printf("number\n");}
    break;

  case 192:
#line 265 "parser.y"
    {add("C");}
    break;

  case 193:
#line 265 "parser.y"
    {printf("true\n");}
    break;

  case 194:
#line 266 "parser.y"
    {add("C");}
    break;

  case 195:
#line 266 "parser.y"
    {printf("false\n");}
    break;

  case 196:
#line 267 "parser.y"
    {add("C");}
    break;

  case 197:
#line 267 "parser.y"
    {printf("char\n");}
    break;

  case 198:
#line 268 "parser.y"
    {add("C");}
    break;

  case 199:
#line 268 "parser.y"
    {printf("string\n");}
    break;

  case 200:
#line 269 "parser.y"
    {add("C");}
    break;

  case 201:
#line 269 "parser.y"
    {printf("float\n");}
    break;

  case 202:
#line 274 "parser.y"
    {add("K");}
    break;

  case 203:
#line 275 "parser.y"
    {add("K");}
    break;

  case 204:
#line 276 "parser.y"
    {add("K");}
    break;

  case 205:
#line 277 "parser.y"
    {add("K");}
    break;

  case 206:
#line 278 "parser.y"
    {add("K");}
    break;

  case 207:
#line 279 "parser.y"
    {add("K");}
    break;


/* Line 1267 of yacc.c.  */
#line 2949 "y.tab.c"
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


#line 280 "parser.y"




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

