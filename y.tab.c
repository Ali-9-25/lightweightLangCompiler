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
#define YYLAST   839

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  119
/* YYNRULES -- Number of rules.  */
#define YYNRULES  201
/* YYNRULES -- Number of states.  */
#define YYNSTATES  347

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
       0,     0,     3,     6,    11,    12,    14,    16,    18,    20,
      22,    24,    26,    28,    30,    33,    36,    39,    42,    43,
      46,    47,    51,    52,    56,    57,    66,    67,    68,    82,
      83,    84,    94,    95,    96,    97,    98,   112,   113,   114,
     115,   131,   132,   133,   143,   144,   151,   152,   159,   160,
     166,   167,   173,   174,   179,   180,   181,   192,   193,   201,
     202,   208,   209,   214,   215,   221,   222,   226,   230,   232,
     236,   238,   239,   244,   245,   246,   254,   255,   256,   264,
     265,   266,   267,   277,   278,   279,   286,   287,   288,   295,
     296,   297,   303,   304,   305,   311,   312,   313,   319,   320,
     321,   327,   328,   329,   335,   336,   337,   343,   344,   345,
     351,   352,   353,   359,   360,   361,   367,   368,   369,   375,
     376,   377,   382,   383,   384,   389,   390,   395,   396,   401,
     402,   407,   408,   413,   414,   419,   420,   425,   426,   431,
     432,   437,   438,   443,   444,   449,   450,   455,   456,   461,
     462,   467,   468,   472,   476,   477,   484,   485,   492,   493,
     500,   501,   508,   509,   516,   517,   524,   525,   532,   533,
     540,   541,   548,   549,   556,   557,   564,   565,   572,   573,
     580,   585,   586,   589,   591,   592,   595,   596,   599,   600,
     603,   604,   607,   608,   611,   612,   615,   617,   619,   621,
     623,   625
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      54,     0,    -1,    55,    54,    -1,    43,    54,    44,    54,
      -1,    -1,    60,    -1,    64,    -1,    67,    -1,    72,    -1,
      76,    -1,    85,    -1,    96,    -1,   102,    -1,   106,    -1,
     111,    45,    -1,    56,    45,    -1,    19,    45,    -1,    20,
      45,    -1,    -1,    28,    57,    -1,    -1,    28,    58,   164,
      -1,    -1,    28,    59,   111,    -1,    -1,    11,    61,    41,
     111,    42,    43,    54,    44,    -1,    -1,    -1,    11,    62,
      41,   111,    42,    43,    54,    44,    12,    63,    43,    54,
      44,    -1,    -1,    -1,    13,    65,    41,   111,    42,    43,
      66,    54,    44,    -1,    -1,    -1,    -1,    -1,    14,    68,
      43,    69,    54,    44,    70,    15,    71,    41,   111,    42,
      45,    -1,    -1,    -1,    -1,    16,    73,    41,    96,   111,
      45,     6,    74,    40,    75,   111,    42,    43,    54,    44,
      -1,    -1,    -1,    17,    77,    41,   111,    42,    43,    79,
      44,    78,    -1,    -1,    18,    80,   111,    46,    54,    79,
      -1,    -1,    18,    81,   164,    46,    54,    79,    -1,    -1,
      18,    82,   111,    46,    54,    -1,    -1,    18,    83,   164,
      46,    54,    -1,    -1,    29,    84,    46,    54,    -1,    -1,
      -1,   171,     6,    86,    41,    92,    42,    43,    87,    54,
      44,    -1,    -1,   171,     6,    88,    41,    92,    42,    45,
      -1,    -1,     6,    90,    41,    95,    42,    -1,    -1,     6,
      91,    41,    42,    -1,    -1,   171,     6,    93,    10,    92,
      -1,    -1,   171,     6,    94,    -1,   111,    10,    95,    -1,
     111,    -1,   164,    10,    95,    -1,   164,    -1,    -1,   171,
       6,    97,    45,    -1,    -1,    -1,   171,     6,    98,    40,
      99,   164,    45,    -1,    -1,    -1,   171,     6,   100,    40,
     101,   111,    45,    -1,    -1,    -1,    -1,    21,   103,   171,
       6,   104,    40,   105,   164,    45,    -1,    -1,    -1,     6,
     107,    40,   108,   164,    45,    -1,    -1,    -1,     6,   109,
      40,   110,   111,    45,    -1,    -1,    -1,   111,    30,   112,
       6,   113,    -1,    -1,    -1,   111,    31,   114,     6,   115,
      -1,    -1,    -1,   111,    32,   116,     6,   117,    -1,    -1,
      -1,   111,    33,   118,     6,   119,    -1,    -1,    -1,   111,
      34,   120,     6,   121,    -1,    -1,    -1,   111,    35,   122,
       6,   123,    -1,    -1,    -1,   111,    39,   124,     6,   125,
      -1,    -1,    -1,   111,    38,   126,     6,   127,    -1,    -1,
      -1,   111,    37,   128,     6,   129,    -1,    -1,    -1,   111,
      36,   130,     6,   131,    -1,    -1,    -1,    48,   132,     6,
     133,    -1,    -1,    -1,     6,   134,    48,   135,    -1,    -1,
     111,    36,   136,   164,    -1,    -1,   111,    37,   137,   164,
      -1,    -1,   111,    38,   138,   164,    -1,    -1,   111,    39,
     139,   164,    -1,    -1,   111,    30,   140,   164,    -1,    -1,
     111,    31,   141,   164,    -1,    -1,   111,    32,   142,   164,
      -1,    -1,   111,    33,   143,   164,    -1,    -1,   111,    34,
     144,   164,    -1,    -1,   111,    35,   145,   164,    -1,    -1,
     111,    47,   146,   164,    -1,    -1,   111,    49,   147,   164,
      -1,    -1,   111,    50,   148,   164,    -1,    -1,    51,   149,
     164,    -1,    41,   111,    42,    -1,    -1,   111,    36,   150,
      41,   111,    42,    -1,    -1,   111,    37,   151,    41,   111,
      42,    -1,    -1,   111,    38,   152,    41,   111,    42,    -1,
      -1,   111,    39,   153,    41,   111,    42,    -1,    -1,   111,
      30,   154,    41,   111,    42,    -1,    -1,   111,    31,   155,
      41,   111,    42,    -1,    -1,   111,    32,   156,    41,   111,
      42,    -1,    -1,   111,    33,   157,    41,   111,    42,    -1,
      -1,   111,    34,   158,    41,   111,    42,    -1,    -1,   111,
      35,   159,    41,   111,    42,    -1,    -1,   111,    47,   160,
      41,   111,    42,    -1,    -1,   111,    49,   161,    41,   111,
      42,    -1,    -1,   111,    50,   162,    41,   111,    42,    -1,
      51,    41,   111,    42,    -1,    -1,     6,   163,    -1,    89,
      -1,    -1,     3,   165,    -1,    -1,     8,   166,    -1,    -1,
       9,   167,    -1,    -1,     7,   168,    -1,    -1,     5,   169,
      -1,    -1,     4,   170,    -1,    22,    -1,    24,    -1,    26,
      -1,    25,    -1,    23,    -1,    27,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    93,    93,    94,    95,   103,   104,   105,   106,   107,
     108,   110,   111,   112,   113,   114,   115,   116,   119,   119,
     120,   120,   121,   121,   129,   129,   130,   130,   130,   133,
     133,   133,   136,   136,   136,   136,   136,   139,   139,   139,
     139,   142,   142,   142,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   149,   152,   152,   152,   153,   153,   156,
     156,   157,   157,   165,   165,   166,   166,   169,   170,   171,
     172,   179,   179,   180,   180,   180,   181,   181,   181,   188,
     188,   188,   188,   195,   195,   195,   196,   196,   196,   204,
     204,   204,   205,   205,   205,   206,   206,   206,   207,   207,
     207,   208,   208,   208,   209,   209,   209,   210,   210,   210,
     211,   211,   211,   212,   212,   212,   213,   213,   213,   214,
     214,   214,   215,   215,   215,   220,   220,   221,   221,   222,
     222,   223,   223,   224,   224,   225,   225,   226,   226,   227,
     227,   228,   228,   229,   229,   230,   230,   231,   231,   232,
     232,   233,   233,   234,   235,   235,   236,   236,   237,   237,
     238,   238,   239,   239,   240,   240,   241,   241,   242,   242,
     243,   243,   244,   244,   245,   245,   246,   246,   247,   247,
     248,   249,   249,   250,   262,   262,   263,   263,   264,   264,
     265,   265,   266,   266,   267,   267,   272,   273,   274,   275,
     276,   277
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
  "NOT", "UMINUS", "$accept", "stmt_list", "stmt", "return_stmt", "@1",
  "@2", "@3", "if_stmt", "@4", "@5", "@6", "while_stmt", "@7", "@8",
  "repeat_stmt", "@9", "@10", "@11", "@12", "for_stmt", "@13", "@14",
  "@15", "switch_stmt", "@16", "@17", "case_list", "@18", "@19", "@20",
  "@21", "@22", "func_decl", "@23", "@24", "@25", "func_call", "@26",
  "@27", "dec_param_list", "@28", "@29", "call_param_list", "var_decl",
  "@30", "@31", "@32", "@33", "@34", "const_decl", "@35", "@36", "@37",
  "assignment_stmt", "@38", "@39", "@40", "@41", "expr", "@42", "@43",
  "@44", "@45", "@46", "@47", "@48", "@49", "@50", "@51", "@52", "@53",
  "@54", "@55", "@56", "@57", "@58", "@59", "@60", "@61", "@62", "@63",
  "@64", "@65", "@66", "@67", "@68", "@69", "@70", "@71", "@72", "@73",
  "@74", "@75", "@76", "@77", "@78", "@79", "@80", "@81", "@82", "@83",
  "@84", "@85", "@86", "@87", "@88", "@89", "@90", "@91", "@92", "@93",
  "TERM", "@94", "@95", "@96", "@97", "@98", "@99", "DATATYPE", 0
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
       0,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    57,    56,
      58,    56,    59,    56,    61,    60,    62,    63,    60,    65,
      66,    64,    68,    69,    70,    71,    67,    73,    74,    75,
      72,    77,    78,    76,    80,    79,    81,    79,    82,    79,
      83,    79,    84,    79,    86,    87,    85,    88,    85,    90,
      89,    91,    89,    93,    92,    94,    92,    95,    95,    95,
      95,    97,    96,    98,    99,    96,   100,   101,    96,   103,
     104,   105,   102,   107,   108,   106,   109,   110,   106,   112,
     113,   111,   114,   115,   111,   116,   117,   111,   118,   119,
     111,   120,   121,   111,   122,   123,   111,   124,   125,   111,
     126,   127,   111,   128,   129,   111,   130,   131,   111,   132,
     133,   111,   134,   135,   111,   136,   111,   137,   111,   138,
     111,   139,   111,   140,   111,   141,   111,   142,   111,   143,
     111,   144,   111,   145,   111,   146,   111,   147,   111,   148,
     111,   149,   111,   111,   150,   111,   151,   111,   152,   111,
     153,   111,   154,   111,   155,   111,   156,   111,   157,   111,
     158,   111,   159,   111,   160,   111,   161,   111,   162,   111,
     111,   163,   111,   111,   165,   164,   166,   164,   167,   164,
     168,   164,   169,   164,   170,   164,   171,   171,   171,   171,
     171,   171
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     4,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     0,     2,
       0,     3,     0,     3,     0,     8,     0,     0,    13,     0,
       0,     9,     0,     0,     0,     0,    13,     0,     0,     0,
      15,     0,     0,     9,     0,     6,     0,     6,     0,     5,
       0,     5,     0,     4,     0,     0,    10,     0,     7,     0,
       5,     0,     4,     0,     5,     0,     3,     3,     1,     3,
       1,     0,     4,     0,     0,     7,     0,     0,     7,     0,
       0,     0,     9,     0,     0,     6,     0,     0,     6,     0,
       0,     5,     0,     0,     5,     0,     0,     5,     0,     0,
       5,     0,     0,     5,     0,     0,     5,     0,     0,     5,
       0,     0,     5,     0,     0,     5,     0,     0,     5,     0,
       0,     4,     0,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     4,     0,     4,     0,     4,     0,     4,     0,
       4,     0,     3,     3,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       4,     0,     2,     1,     0,     2,     0,     2,     0,     2,
       0,     2,     0,     2,     0,     2,     1,     1,     1,     1,
       1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,   181,    24,    29,    32,    37,    41,     0,     0,    79,
     196,   200,   197,   199,   198,   201,    20,     0,     4,   119,
     151,     0,     4,     0,     5,     6,     7,     8,     9,    10,
     183,    11,    12,    13,     0,     0,     0,     0,     0,     0,
       0,   182,     0,     0,     0,     0,     0,     0,    16,    17,
       0,    19,     0,     0,   181,     0,     0,     0,     0,     0,
       1,     2,    15,   133,   135,   137,   139,   141,   143,   125,
     127,   129,   131,    14,   145,   147,   149,    54,     0,     0,
      84,    87,   123,     0,     0,     0,    33,     0,     0,     0,
     184,   194,   192,   190,   186,   188,    21,    23,   153,     4,
     120,     0,   152,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    68,    70,    62,     0,     0,
     124,     0,     0,     0,     4,     0,     0,     0,    80,   185,
     195,   193,   191,   187,   189,     3,   121,   180,    90,   134,
       0,    93,   136,     0,    96,   138,     0,    99,   140,     0,
     102,   142,     0,   105,   144,     0,   117,   126,     0,   114,
     128,     0,   111,   130,     0,   108,   132,     0,   146,     0,
     148,     0,   150,     0,     0,     0,    72,    74,    77,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    71,
       0,     0,    91,     0,    94,     0,    97,     0,   100,     0,
     103,     0,   106,     0,   118,     0,   115,     0,   112,     0,
     109,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,    69,    85,    88,     4,     4,    30,    34,     0,     0,
      81,   163,   165,   167,   169,   171,   173,   155,   157,   159,
     161,   175,   177,   179,     0,    63,     0,     0,     0,     0,
       0,     4,     0,    38,    46,    52,     0,     0,    55,     0,
      66,    58,    75,    78,    25,     0,     0,    35,     0,     0,
       0,     0,     0,     0,    42,     0,     4,     0,    27,    31,
       0,    39,     0,     0,     0,     0,     4,    43,    82,     0,
      64,     0,     0,     0,     4,     4,     4,     4,    53,    56,
       4,     0,     0,     0,     0,    49,    51,     0,     0,     0,
      45,    47,    28,    36,     4,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    21,    22,    23,    51,    52,    53,    24,    42,    43,
     321,    25,    44,   281,    26,    45,   154,   282,   310,    27,
      46,   298,   323,    28,    47,   317,   286,   299,   300,   301,
     302,   303,    29,   139,   306,   140,    30,    36,    37,   245,
     289,   290,   144,    31,   141,   142,   248,   143,   249,    32,
      50,   221,   287,    33,    38,   148,    39,   149,    34,   103,
     222,   106,   224,   109,   226,   112,   228,   115,   230,   118,
     232,   130,   240,   127,   238,   124,   236,   121,   234,    57,
     166,    40,   150,   122,   125,   128,   131,   104,   107,   110,
     113,   116,   119,   133,   135,   137,    59,   123,   126,   129,
     132,   105,   108,   111,   114,   117,   120,   134,   136,   138,
      41,   146,   159,   163,   164,   162,   161,   160,    35
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -301
static const yytype_int16 yypact[] =
{
     106,    -5,  -301,  -301,  -301,  -301,  -301,   -23,   -17,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,     0,    11,   106,  -301,
       5,    39,   106,    27,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,   194,    44,    29,    32,    42,    45,
      36,  -301,    46,    47,    49,    48,    52,    53,  -301,  -301,
     191,  -301,   134,    11,    30,   215,    55,    90,    11,   134,
    -301,  -301,  -301,    -4,    -1,     1,    14,    15,    17,    20,
      23,    24,    25,  -301,    56,    59,    61,   -21,     6,    65,
    -301,  -301,  -301,    11,    11,    11,  -301,   191,    11,    97,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,   789,  -301,   106,
    -301,   247,  -301,   103,   134,    70,   107,   134,    73,   109,
     134,    75,   112,   134,    83,   129,   134,   104,   138,   134,
     110,   142,   134,   111,   144,   134,   117,   147,   134,   118,
     154,   134,   121,   134,   122,   134,   124,   134,   125,   127,
     128,   126,   132,   135,   136,   173,   164,  -301,   134,    11,
    -301,   285,   306,   327,   106,    11,   171,   348,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
      11,  -301,  -301,    11,  -301,  -301,    11,  -301,  -301,    11,
    -301,  -301,    11,  -301,  -301,    11,  -301,  -301,    11,  -301,
    -301,    11,  -301,  -301,    11,  -301,  -301,    11,  -301,    11,
    -301,    11,  -301,    11,   191,   191,  -301,  -301,  -301,  -301,
       6,     6,   139,   369,   137,   143,   146,   149,   390,   141,
     148,   155,  -301,   411,  -301,   432,  -301,   453,  -301,   474,
    -301,   495,  -301,   516,  -301,   537,  -301,   558,  -301,   579,
    -301,   600,   621,   642,   663,   145,   190,   156,   134,    11,
    -301,  -301,  -301,  -301,   106,   106,  -301,  -301,   193,    -2,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,   157,   177,   152,   189,   684,   198,
     211,   106,   220,  -301,    12,  -301,   212,   134,  -301,   228,
    -301,  -301,  -301,  -301,  -301,   249,   222,  -301,   219,    11,
     134,    11,   134,   221,  -301,   223,   106,   191,  -301,  -301,
     229,  -301,   705,   225,   726,   226,   106,  -301,  -301,   230,
    -301,   233,    11,    11,   106,   106,   106,   106,  -301,  -301,
     106,   747,   768,    -2,    -2,  -301,  -301,   243,   224,   248,
    -301,  -301,  -301,  -301,   106,   251,  -301
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -301,   -18,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -300,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -202,
    -301,  -301,  -143,   206,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,    -9,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,  -301,
    -301,   -27,  -301,  -301,  -301,  -301,  -301,  -301,   -49
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -179
static const yytype_int16 yytable[] =
{
      56,    89,   -89,   247,    61,   -92,   -22,   -95,    55,    90,
      91,    92,    54,    93,    94,    95,   284,    54,   -44,   -73,
     -98,  -101,    48,  -104,   -71,    96,  -116,   285,    49,  -113,
    -110,  -107,   102,   340,   341,   -83,   -59,  -162,   156,    60,
    -164,   -22,  -166,  -122,    97,   -18,    58,    17,   -22,   101,
      77,   -22,    17,   -44,    19,  -168,  -170,    20,  -172,    19,
     -44,  -154,    20,   -44,  -156,  -158,  -160,   250,   251,   145,
      78,   -59,    62,    79,   151,   152,   153,   169,  -122,   157,
     172,   165,    80,   175,    82,    81,   178,    83,    84,   181,
      85,    86,   184,    87,    88,   187,   100,  -174,   190,    99,
    -176,   193,  -178,   158,   196,   320,   198,   147,   200,   168,
     202,   170,     1,   171,   173,   174,   176,     2,   177,     3,
       4,   212,     5,     6,   179,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,   180,   217,    90,    91,    92,
     213,    93,    94,    95,   183,   182,   218,    17,   186,    18,
     189,   185,   188,   192,    19,   246,   246,    20,   191,   194,
     195,   223,   197,   199,   225,   201,   203,   227,   204,   205,
     229,   206,   207,   231,   211,   208,   233,   219,   209,   235,
     254,   -73,   237,   210,   252,   239,   255,   274,   241,   256,
     242,   259,   243,   257,   244,   260,   275,   291,   276,   283,
     288,   145,   145,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    10,    11,    12,    13,    14,    15,   -65,
      74,   277,    75,    76,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,   292,   297,   279,   280,   307,    73,
     278,    74,   294,    75,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,   295,   304,    98,   246,   311,
     305,   308,    74,   296,    75,    76,   309,   316,   318,   343,
     322,   325,   327,   313,   329,   315,   330,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,   342,   319,   167,
     312,   344,   314,   155,    74,   346,    75,    76,   328,     0,
       0,     0,     0,     0,     0,     0,   333,   334,   335,   336,
       0,     0,   337,   331,   332,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,   345,   214,     0,     0,
       0,     0,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,   215,     0,
       0,     0,     0,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,   216,
       0,     0,     0,     0,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     220,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,     0,     0,     0,   253,     0,    74,     0,    75,    76,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,     0,     0,     0,   258,     0,    74,     0,    75,
      76,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,   261,     0,     0,     0,     0,    74,     0,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,   262,     0,     0,     0,     0,    74,
       0,    75,    76,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,   263,     0,     0,     0,     0,
      74,     0,    75,    76,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,   264,     0,     0,     0,
       0,    74,     0,    75,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,   265,     0,     0,
       0,     0,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,   266,     0,
       0,     0,     0,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,   267,
       0,     0,     0,     0,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     268,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,   269,     0,     0,     0,     0,    74,     0,    75,    76,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
       0,     0,   270,     0,     0,     0,     0,    74,     0,    75,
      76,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,     0,     0,   271,     0,     0,     0,     0,    74,     0,
      75,    76,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,     0,     0,   272,     0,     0,     0,     0,    74,
       0,    75,    76,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,     0,     0,   273,     0,     0,     0,     0,
      74,     0,    75,    76,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,     0,     0,     0,     0,     0,   293,
       0,    74,     0,    75,    76,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,     0,     0,     0,     0,     0,
       0,   324,    74,     0,    75,    76,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,     0,     0,     0,     0,
       0,     0,   326,    74,     0,    75,    76,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,     0,     0,   338,
       0,     0,     0,     0,    74,     0,    75,    76,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,     0,     0,
     339,     0,     0,     0,     0,    74,     0,    75,    76,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,     0,
       0,     0,     0,     0,     0,     0,    74,     0,    75,    76
};

static const yytype_int16 yycheck[] =
{
      18,    50,     6,   205,    22,     6,     6,     6,    17,     3,
       4,     5,     6,     7,     8,     9,    18,     6,     6,    40,
       6,     6,    45,     6,    45,    52,     6,    29,    45,     6,
       6,     6,    59,   333,   334,    40,    41,    41,    87,     0,
      41,    41,    41,    48,    53,    45,    41,    41,    48,    58,
       6,    51,    41,    41,    48,    41,    41,    51,    41,    48,
      48,    41,    51,    51,    41,    41,    41,   210,   211,    78,
      41,    41,    45,    41,    83,    84,    85,   104,    48,    88,
     107,    99,    40,   110,    48,    40,   113,    41,    41,   116,
      41,    43,   119,    41,    41,   122,     6,    41,   125,    44,
      41,   128,    41,     6,   131,   307,   133,    42,   135,     6,
     137,    41,     6,     6,    41,     6,    41,    11,     6,    13,
      14,   148,    16,    17,    41,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,     6,   154,     3,     4,     5,
     149,     7,     8,     9,     6,    41,   155,    41,     6,    43,
       6,    41,    41,     6,    48,   204,   205,    51,    41,    41,
       6,   170,    41,    41,   173,    41,    41,   176,    41,    41,
     179,    45,    40,   182,    10,    40,   185,     6,    42,   188,
      43,    40,   191,    10,    45,   194,    43,    42,   197,    43,
     199,    43,   201,    44,   203,    40,     6,    45,    42,     6,
      43,   210,   211,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    22,    23,    24,    25,    26,    27,    42,
      47,   248,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    45,    15,   254,   255,    10,    45,
     249,    47,    44,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    44,    44,    42,   307,    40,
     287,    12,    47,   281,    49,    50,    44,    46,    45,    45,
      41,    46,    46,   300,    44,   302,    43,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    44,   306,    42,
     299,    43,   301,    87,    47,    44,    49,    50,   316,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   324,   325,   326,   327,
      -1,    -1,   330,   322,   323,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,   344,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,
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
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,    49,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    14,    16,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    43,    48,
      51,    54,    55,    56,    60,    64,    67,    72,    76,    85,
      89,    96,   102,   106,   111,   171,    90,    91,   107,   109,
     134,   163,    61,    62,    65,    68,    73,    77,    45,    45,
     103,    57,    58,    59,     6,   111,    54,   132,    41,   149,
       0,    54,    45,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    45,    47,    49,    50,     6,    41,    41,
      40,    40,    48,    41,    41,    41,    43,    41,    41,   171,
       3,     4,     5,     7,     8,     9,   164,   111,    42,    44,
       6,   111,   164,   112,   140,   154,   114,   141,   155,   116,
     142,   156,   118,   143,   157,   120,   144,   158,   122,   145,
     159,   130,   136,   150,   128,   137,   151,   126,   138,   152,
     124,   139,   153,   146,   160,   147,   161,   148,   162,    86,
      88,    97,    98,   100,    95,   111,   164,    42,   108,   110,
     135,   111,   111,   111,    69,    96,   171,   111,     6,   165,
     170,   169,   168,   166,   167,    54,   133,    42,     6,   164,
      41,     6,   164,    41,     6,   164,    41,     6,   164,    41,
       6,   164,    41,     6,   164,    41,     6,   164,    41,     6,
     164,    41,     6,   164,    41,     6,   164,    41,   164,    41,
     164,    41,   164,    41,    41,    41,    45,    40,    40,    42,
      10,    10,   164,   111,    42,    42,    42,    54,   111,     6,
      42,   104,   113,   111,   115,   111,   117,   111,   119,   111,
     121,   111,   123,   111,   131,   111,   129,   111,   127,   111,
     125,   111,   111,   111,   111,    92,   171,    92,    99,   101,
      95,    95,    45,    45,    43,    43,    43,    44,    45,    43,
      40,    42,    42,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,     6,    42,   164,   111,    54,
      54,    66,    70,     6,    18,    29,    79,   105,    43,    93,
      94,    45,    45,    45,    44,    44,    54,    15,    74,    80,
      81,    82,    83,    84,    44,   164,    87,    10,    12,    44,
      71,    40,   111,   164,   111,   164,    46,    78,    45,    54,
      92,    63,    41,    75,    46,    46,    46,    46,    54,    44,
      43,   111,   111,    54,    54,    54,    54,    54,    42,    42,
      79,    79,    44,    45,    43,    54,    44
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
    {printf("{stmt_list}\n");}
    break;

  case 4:
#line 95 "parser.y"
    {printf("stmt epsilon\n");}
    break;

  case 5:
#line 103 "parser.y"
    {printf("if statement\n");}
    break;

  case 6:
#line 104 "parser.y"
    {printf("while statement\n");}
    break;

  case 7:
#line 105 "parser.y"
    {printf("repeat statement\n");}
    break;

  case 8:
#line 106 "parser.y"
    {printf("for statement\n");}
    break;

  case 9:
#line 107 "parser.y"
    {printf("switch statement\n");}
    break;

  case 10:
#line 108 "parser.y"
    {printf("function declaration\n");}
    break;

  case 11:
#line 110 "parser.y"
    {printf("variable declaration\n");}
    break;

  case 12:
#line 111 "parser.y"
    {printf("constant declaration\n");}
    break;

  case 13:
#line 112 "parser.y"
    {printf("assignment statement\n");}
    break;

  case 14:
#line 113 "parser.y"
    {printf("expression\n");}
    break;

  case 15:
#line 114 "parser.y"
    {printf("return statement\n");}
    break;

  case 16:
#line 115 "parser.y"
    {printf("break statement\n"); add("K");}
    break;

  case 17:
#line 116 "parser.y"
    {printf("continue statement\n"); add("K");}
    break;

  case 18:
#line 119 "parser.y"
    {add("K");}
    break;

  case 19:
#line 119 "parser.y"
    {printf("return\n");}
    break;

  case 20:
#line 120 "parser.y"
    {add("K");}
    break;

  case 21:
#line 120 "parser.y"
    {printf("return term\n");}
    break;

  case 22:
#line 121 "parser.y"
    {add("K");}
    break;

  case 23:
#line 121 "parser.y"
    {printf("return expr\n");}
    break;

  case 24:
#line 129 "parser.y"
    { add("K");}
    break;

  case 25:
#line 129 "parser.y"
    {printf("if (expr) {stmt_list}\n");}
    break;

  case 26:
#line 130 "parser.y"
    {add("K");}
    break;

  case 27:
#line 130 "parser.y"
    {add("K");}
    break;

  case 28:
#line 130 "parser.y"
    {printf("if (expr) {stmt_list} else {stmt_list}\n");}
    break;

  case 29:
#line 133 "parser.y"
    { add("K"); }
    break;

  case 30:
#line 133 "parser.y"
    { add("S"); }
    break;

  case 31:
#line 133 "parser.y"
    {add("S"); printf("while (expr) {stmt_list}\n");}
    break;

  case 32:
#line 136 "parser.y"
    { add("K"); }
    break;

  case 33:
#line 136 "parser.y"
    { add("S"); }
    break;

  case 34:
#line 136 "parser.y"
    { add("S"); }
    break;

  case 35:
#line 136 "parser.y"
    { add("K"); }
    break;

  case 36:
#line 136 "parser.y"
    {printf("repeat {stmt_list} until (expr)\n");}
    break;

  case 37:
#line 139 "parser.y"
    { add("K"); }
    break;

  case 38:
#line 139 "parser.y"
    { add("V"); }
    break;

  case 39:
#line 139 "parser.y"
    { add("O");}
    break;

  case 40:
#line 139 "parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n");}
    break;

  case 41:
#line 142 "parser.y"
    {add("K");}
    break;

  case 42:
#line 142 "parser.y"
    { add("S");}
    break;

  case 43:
#line 142 "parser.y"
    {printf("switch (expr) {case_list}\n");}
    break;

  case 44:
#line 145 "parser.y"
    { add("K");}
    break;

  case 45:
#line 145 "parser.y"
    {printf("case expr: stmt_list case_list\n");}
    break;

  case 46:
#line 146 "parser.y"
    { add("K");}
    break;

  case 47:
#line 146 "parser.y"
    {printf("case term: stmt_list case_list\n");}
    break;

  case 48:
#line 147 "parser.y"
    { add("K");}
    break;

  case 49:
#line 147 "parser.y"
    {printf("case expr: stmt_list\n");}
    break;

  case 50:
#line 148 "parser.y"
    { add("K");}
    break;

  case 51:
#line 148 "parser.y"
    {printf("case term: stmt_list\n");}
    break;

  case 52:
#line 149 "parser.y"
    { add("K");}
    break;

  case 53:
#line 149 "parser.y"
    {printf("default: stmt_list\n");}
    break;

  case 54:
#line 152 "parser.y"
    {add("F");}
    break;

  case 55:
#line 152 "parser.y"
    { add("S");}
    break;

  case 56:
#line 152 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");}
    break;

  case 57:
#line 153 "parser.y"
    {add("F");}
    break;

  case 58:
#line 153 "parser.y"
    {printf("data_type identifier () {stmt_list}\n");}
    break;

  case 59:
#line 156 "parser.y"
    {add("F");}
    break;

  case 60:
#line 156 "parser.y"
    {printf("identifier (call_param_list) ;\n");}
    break;

  case 61:
#line 157 "parser.y"
    {add("F");}
    break;

  case 62:
#line 157 "parser.y"
    {printf("identifier () ;\n");}
    break;

  case 63:
#line 165 "parser.y"
    {add("V");}
    break;

  case 64:
#line 165 "parser.y"
    {printf("data_type identifier , dec_param_list\n");}
    break;

  case 65:
#line 166 "parser.y"
    {add("V");}
    break;

  case 66:
#line 166 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 67:
#line 169 "parser.y"
    {printf("identifier , call_param_list\n");}
    break;

  case 68:
#line 170 "parser.y"
    {printf("data_type identifier\n");}
    break;

  case 69:
#line 171 "parser.y"
    {printf("term , call_param_list\n");}
    break;

  case 70:
#line 172 "parser.y"
    {printf("term\n");}
    break;

  case 71:
#line 179 "parser.y"
    {add("V");}
    break;

  case 72:
#line 179 "parser.y"
    {printf("data_type identifier; \n");}
    break;

  case 73:
#line 180 "parser.y"
    {add("V");}
    break;

  case 74:
#line 180 "parser.y"
    {add("O");}
    break;

  case 75:
#line 180 "parser.y"
    {printf("data_type identifier = term ;\n");}
    break;

  case 76:
#line 181 "parser.y"
    {add("V");}
    break;

  case 77:
#line 181 "parser.y"
    {add("O");}
    break;

  case 78:
#line 181 "parser.y"
    {printf("data_type identifier = expr ;\n");}
    break;

  case 79:
#line 188 "parser.y"
    { add("K");}
    break;

  case 80:
#line 188 "parser.y"
    { add("V");}
    break;

  case 81:
#line 188 "parser.y"
    { add("O");}
    break;

  case 82:
#line 188 "parser.y"
    {printf("const data_type identifier = term ;\n");}
    break;

  case 83:
#line 195 "parser.y"
    {add("V");}
    break;

  case 84:
#line 195 "parser.y"
    { add("O");}
    break;

  case 85:
#line 195 "parser.y"
    {printf("identifier = term ;\n");}
    break;

  case 86:
#line 196 "parser.y"
    {add("V");}
    break;

  case 87:
#line 196 "parser.y"
    { add("O");}
    break;

  case 88:
#line 196 "parser.y"
    {printf("identifier = expr ;\n");}
    break;

  case 89:
#line 204 "parser.y"
    {add("O");}
    break;

  case 90:
#line 204 "parser.y"
    {add("V");}
    break;

  case 91:
#line 204 "parser.y"
    {printf("expr == identifer\n");}
    break;

  case 92:
#line 205 "parser.y"
    {add("O");}
    break;

  case 93:
#line 205 "parser.y"
    {add("V");}
    break;

  case 94:
#line 205 "parser.y"
    {printf("expr != identifer\n");}
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
    {printf("expr < identifer\n");}
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
    {printf("expr > identifer\n");}
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
    {printf("expr <= identifer\n");}
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
    {printf("expr >= identifer\n");}
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
    {printf("expr / identifer\n");}
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
    {printf("expr * identifer\n");}
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
    {printf("expr - identifer\n");}
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
    {printf("expr + identifer\n");}
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
    {printf("unary expr\n");}
    break;

  case 122:
#line 215 "parser.y"
    {add("V");}
    break;

  case 123:
#line 215 "parser.y"
    {add("O");}
    break;

  case 124:
#line 215 "parser.y"
    {printf("identifer unary\n");}
    break;

  case 125:
#line 220 "parser.y"
    {add("O");}
    break;

  case 126:
#line 220 "parser.y"
    {printf("expr + term\n");}
    break;

  case 127:
#line 221 "parser.y"
    {add("O");}
    break;

  case 128:
#line 221 "parser.y"
    {printf("expr - term\n");}
    break;

  case 129:
#line 222 "parser.y"
    {add("O");}
    break;

  case 130:
#line 222 "parser.y"
    {printf("expr * term\n");}
    break;

  case 131:
#line 223 "parser.y"
    {add("O");}
    break;

  case 132:
#line 223 "parser.y"
    {printf("expr / term\n");}
    break;

  case 133:
#line 224 "parser.y"
    {add("O");}
    break;

  case 134:
#line 224 "parser.y"
    {printf("expr == term\n");}
    break;

  case 135:
#line 225 "parser.y"
    {add("O");}
    break;

  case 136:
#line 225 "parser.y"
    {printf("expr != term\n");}
    break;

  case 137:
#line 226 "parser.y"
    {add("O");}
    break;

  case 138:
#line 226 "parser.y"
    {printf("expr < term\n");}
    break;

  case 139:
#line 227 "parser.y"
    {add("O");}
    break;

  case 140:
#line 227 "parser.y"
    {printf("expr > term\n");}
    break;

  case 141:
#line 228 "parser.y"
    {add("O");}
    break;

  case 142:
#line 228 "parser.y"
    {printf("expr <= term\n");}
    break;

  case 143:
#line 229 "parser.y"
    {add("O");}
    break;

  case 144:
#line 229 "parser.y"
    {printf("expr >= term\n");}
    break;

  case 145:
#line 230 "parser.y"
    {add("O");}
    break;

  case 146:
#line 230 "parser.y"
    {printf("expr ^ term\n");}
    break;

  case 147:
#line 231 "parser.y"
    {add("O");}
    break;

  case 148:
#line 231 "parser.y"
    {printf("expr && term\n");}
    break;

  case 149:
#line 232 "parser.y"
    {add("O");}
    break;

  case 150:
#line 232 "parser.y"
    {printf("expr || term\n");}
    break;

  case 151:
#line 233 "parser.y"
    {add("O");}
    break;

  case 152:
#line 233 "parser.y"
    {printf("!term\n");}
    break;

  case 153:
#line 234 "parser.y"
    {printf("(expr)\n");}
    break;

  case 154:
#line 235 "parser.y"
    {add("O");}
    break;

  case 155:
#line 235 "parser.y"
    {printf("expr + (expr)\n");}
    break;

  case 156:
#line 236 "parser.y"
    {add("O");}
    break;

  case 157:
#line 236 "parser.y"
    {printf("expr - (expr)\n");}
    break;

  case 158:
#line 237 "parser.y"
    {add("O");}
    break;

  case 159:
#line 237 "parser.y"
    {printf("expr * (expr)\n");}
    break;

  case 160:
#line 238 "parser.y"
    {add("O");}
    break;

  case 161:
#line 238 "parser.y"
    {printf("expr / (expr)\n");}
    break;

  case 162:
#line 239 "parser.y"
    {add("O");}
    break;

  case 163:
#line 239 "parser.y"
    {printf("expr == (expr)\n");}
    break;

  case 164:
#line 240 "parser.y"
    {add("O");}
    break;

  case 165:
#line 240 "parser.y"
    {printf("expr != (expr)\n");}
    break;

  case 166:
#line 241 "parser.y"
    {add("O");}
    break;

  case 167:
#line 241 "parser.y"
    {printf("expr < (expr)\n");}
    break;

  case 168:
#line 242 "parser.y"
    {add("O");}
    break;

  case 169:
#line 242 "parser.y"
    {printf("expr > (expr)\n");}
    break;

  case 170:
#line 243 "parser.y"
    {add("O");}
    break;

  case 171:
#line 243 "parser.y"
    {printf("expr <= (expr)\n");}
    break;

  case 172:
#line 244 "parser.y"
    {add("O");}
    break;

  case 173:
#line 244 "parser.y"
    {printf("expr >= (expr)\n");}
    break;

  case 174:
#line 245 "parser.y"
    {add("O");}
    break;

  case 175:
#line 245 "parser.y"
    {printf("expr ^ (expr)\n");}
    break;

  case 176:
#line 246 "parser.y"
    {add("O");}
    break;

  case 177:
#line 246 "parser.y"
    {printf("expr && (expr)\n");}
    break;

  case 178:
#line 247 "parser.y"
    {add("O");}
    break;

  case 179:
#line 247 "parser.y"
    {printf("expr || (expr)\n");}
    break;

  case 180:
#line 248 "parser.y"
    {printf("! (expr)\n");}
    break;

  case 181:
#line 249 "parser.y"
    {add("V");}
    break;

  case 182:
#line 249 "parser.y"
    {printf("identifier\n");}
    break;

  case 183:
#line 250 "parser.y"
    {printf("function call\n");}
    break;

  case 184:
#line 262 "parser.y"
    {add("C");}
    break;

  case 185:
#line 262 "parser.y"
    {printf("number\n");}
    break;

  case 186:
#line 263 "parser.y"
    {add("C");}
    break;

  case 187:
#line 263 "parser.y"
    {printf("true\n");}
    break;

  case 188:
#line 264 "parser.y"
    {add("C");}
    break;

  case 189:
#line 264 "parser.y"
    {printf("false\n");}
    break;

  case 190:
#line 265 "parser.y"
    {add("C");}
    break;

  case 191:
#line 265 "parser.y"
    {printf("char\n");}
    break;

  case 192:
#line 266 "parser.y"
    {add("C");}
    break;

  case 193:
#line 266 "parser.y"
    {printf("string\n");}
    break;

  case 194:
#line 267 "parser.y"
    {add("C");}
    break;

  case 195:
#line 267 "parser.y"
    {printf("float\n");}
    break;

  case 196:
#line 272 "parser.y"
    {add("K");}
    break;

  case 197:
#line 273 "parser.y"
    {add("K");}
    break;

  case 198:
#line 274 "parser.y"
    {add("K");}
    break;

  case 199:
#line 275 "parser.y"
    {add("K");}
    break;

  case 200:
#line 276 "parser.y"
    {add("K");}
    break;

  case 201:
#line 277 "parser.y"
    {add("K");}
    break;


/* Line 1267 of yacc.c.  */
#line 2902 "y.tab.c"
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

