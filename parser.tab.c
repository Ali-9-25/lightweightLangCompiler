
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "parser.y"

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


/* Line 189 of yacc.c  */
#line 102 "parser.tab.c"

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



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 29 "parser.y"

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



/* Line 214 of yacc.c  */
#line 207 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 219 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  58
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   498

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  87
/* YYNRULES -- Number of states.  */
#define YYNSTATES  184

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
       0,     0,     3,     6,     7,     9,    11,    13,    15,    17,
      19,    21,    23,    25,    28,    31,    34,    37,    39,    42,
      45,    53,    65,    73,    83,    96,   104,   110,   116,   121,
     126,   130,   139,   146,   151,   155,   160,   163,   167,   169,
     173,   175,   179,   185,   191,   198,   203,   208,   212,   216,
     220,   224,   228,   232,   236,   240,   244,   248,   251,   254,
     258,   262,   266,   270,   274,   278,   282,   286,   290,   294,
     298,   302,   306,   309,   313,   315,   317,   319,   321,   323,
     325,   327,   329,   331,   333,   335,   337,   339
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      54,     0,    -1,    55,    54,    -1,    -1,    57,    -1,    58,
      -1,    59,    -1,    60,    -1,    61,    -1,    63,    -1,    67,
      -1,    68,    -1,    69,    -1,    70,    45,    -1,    56,    45,
      -1,    19,    45,    -1,    20,    45,    -1,    28,    -1,    28,
      71,    -1,    28,    70,    -1,    11,    41,    70,    42,    43,
      54,    44,    -1,    11,    41,    70,    42,    43,    54,    44,
      12,    43,    54,    44,    -1,    13,    41,    70,    42,    43,
      54,    44,    -1,    14,    43,    54,    44,    15,    41,    70,
      42,    45,    -1,    16,    41,    67,    70,    45,     6,    40,
      70,    42,    43,    54,    44,    -1,    17,    41,    70,    42,
      43,    62,    44,    -1,    18,    70,    46,    54,    62,    -1,
      18,    71,    46,    54,    62,    -1,    18,    70,    46,    54,
      -1,    18,    71,    46,    54,    -1,    29,    46,    54,    -1,
      72,     6,    41,    65,    42,    43,    54,    44,    -1,    72,
       6,    41,    65,    42,    45,    -1,     6,    41,    66,    42,
      -1,     6,    41,    42,    -1,    72,     6,    10,    65,    -1,
      72,     6,    -1,    70,    10,    66,    -1,    70,    -1,    71,
      10,    66,    -1,    71,    -1,    72,     6,    45,    -1,    72,
       6,    40,    71,    45,    -1,    72,     6,    40,    70,    45,
      -1,    21,    72,     6,    40,    71,    45,    -1,     6,    40,
      71,    45,    -1,     6,    40,    70,    45,    -1,    70,    30,
       6,    -1,    70,    31,     6,    -1,    70,    32,     6,    -1,
      70,    33,     6,    -1,    70,    34,     6,    -1,    70,    35,
       6,    -1,    70,    39,     6,    -1,    70,    38,     6,    -1,
      70,    37,     6,    -1,    70,    36,     6,    -1,    48,     6,
      -1,     6,    48,    -1,    70,    36,    71,    -1,    70,    37,
      71,    -1,    70,    38,    71,    -1,    70,    39,    71,    -1,
      70,    30,    71,    -1,    70,    31,    71,    -1,    70,    32,
      71,    -1,    70,    33,    71,    -1,    70,    34,    71,    -1,
      70,    35,    71,    -1,    70,    47,    71,    -1,    70,    49,
      71,    -1,    70,    50,    71,    -1,    51,    71,    -1,    41,
      70,    42,    -1,     6,    -1,    64,    -1,     3,    -1,     8,
      -1,     9,    -1,     7,    -1,     5,    -1,     4,    -1,    22,
      -1,    24,    -1,    26,    -1,    25,    -1,    23,    -1,    27,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    78,    78,    79,    87,    88,    89,    90,    91,    92,
      94,    95,    96,    97,    98,    99,   100,   103,   104,   105,
     113,   114,   117,   120,   123,   126,   129,   130,   131,   132,
     133,   136,   137,   140,   141,   149,   150,   153,   154,   155,
     156,   163,   164,   165,   172,   179,   180,   188,   189,   190,
     191,   192,   193,   194,   195,   196,   197,   198,   199,   204,
     205,   206,   207,   208,   209,   210,   211,   212,   213,   214,
     215,   216,   217,   218,   219,   220,   232,   233,   234,   235,
     236,   237,   242,   243,   244,   245,   246,   247
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
  "NOT", "UMINUS", "$accept", "stmt_list", "stmt", "return_stmt",
  "if_stmt", "while_stmt", "repeat_stmt", "for_stmt", "switch_stmt",
  "case_list", "func_decl", "func_call", "dec_param_list",
  "call_param_list", "var_decl", "const_decl", "assignment_stmt", "expr",
  "TERM", "DATATYPE", 0
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
       0,    53,    54,    54,    55,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    56,    56,    56,
      57,    57,    58,    59,    60,    61,    62,    62,    62,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    67,    67,    67,    68,    69,    69,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     2,     1,     2,     2,
       7,    11,     7,     9,    12,     7,     5,     5,     4,     4,
       3,     8,     6,     4,     3,     4,     2,     3,     1,     3,
       1,     3,     5,     5,     6,     4,     4,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,    74,     0,     0,     0,     0,     0,     0,     0,     0,
      82,    86,    83,    85,    84,    87,    17,     0,     0,     0,
       0,     3,     0,     4,     5,     6,     7,     8,     9,    75,
      10,    11,    12,     0,     0,     0,     0,    58,     0,     0,
       3,     0,     0,    15,    16,     0,    76,    81,    80,    74,
      79,    77,    78,    19,    18,     0,    57,    72,     1,     2,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,     0,     0,     0,     0,     0,     0,    34,     0,
      38,    40,     0,     0,     0,     0,     0,     0,     0,    73,
      47,    63,    48,    64,    49,    65,    50,    66,    51,    67,
      52,    68,    56,    59,    55,    60,    54,    61,    53,    62,
      69,    70,    71,     0,     0,    41,    46,    45,    33,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    37,    39,     3,     3,     0,     0,     0,     0,
      43,    42,     0,    36,     0,     0,     0,     0,     0,     0,
       0,    44,     3,    32,     0,    20,    22,     0,     0,     0,
       0,     3,    25,     0,    35,     0,     0,     0,     3,     3,
      30,    31,     3,    23,     0,    28,    29,     0,     3,    26,
      27,    21,     0,    24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    20,    21,    22,    23,    24,    25,    26,    27,   150,
      28,    29,   130,    79,    30,    31,    32,    33,    81,    34
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -140
static const yytype_int16 yypact[] =
{
     139,   -33,   -39,   -11,     5,     8,     9,    21,    22,   159,
    -140,  -140,  -140,  -140,  -140,  -140,    85,    20,    59,    13,
      69,   139,    25,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,   182,    66,    85,    36,  -140,    20,    20,
     139,   159,    20,  -140,  -140,    67,  -140,  -140,  -140,   -37,
    -140,  -140,  -140,   413,  -140,   203,  -140,  -140,  -140,  -140,
    -140,    92,   115,   169,   198,   450,   461,   468,   475,   482,
     489,  -140,    13,    13,    13,   -17,   224,    29,  -140,    33,
     161,    70,   245,   266,    32,    20,    73,   287,    42,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -140,
    -140,  -140,  -140,    85,   159,  -140,  -140,  -140,  -140,    85,
      85,    40,    43,    87,   308,   -35,    61,    13,   329,    60,
      65,    79,  -140,  -140,   139,   139,    71,   102,   -15,    80,
    -140,  -140,   -16,   100,    83,    84,    20,    89,    85,    86,
      90,  -140,   139,  -140,   159,    99,  -140,   350,    20,   371,
      91,   139,  -140,    95,  -140,    98,   104,   392,   139,   139,
    -140,  -140,   139,  -140,   125,   -15,   -15,   126,   139,  -140,
    -140,  -140,   135,  -140
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,   -21,  -140,  -140,  -140,  -140,  -140,  -140,  -140,  -139,
    -140,  -140,   -24,   -73,    94,  -140,  -140,    -4,   -10,    -8
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      59,    45,    38,   148,    36,   113,    54,    35,    36,    57,
     115,    37,    53,    55,   149,    37,    46,    47,    48,    84,
      50,    51,    52,   113,   114,    77,    49,   152,   115,   153,
      39,    76,    80,    86,    82,    83,   179,   180,    87,    46,
      47,    48,    49,    50,    51,    52,   132,   133,    40,    41,
      42,    91,    93,    95,    97,    99,   101,   103,   105,   107,
     109,    17,   110,   111,   112,    56,    43,    44,    18,    58,
      60,    19,    75,    88,   117,   118,   123,    17,    78,   125,
     120,   124,   127,   134,    18,   143,   135,    19,    46,    47,
      48,    49,    50,    51,    52,    46,    47,    48,    90,    50,
      51,    52,   136,   129,   138,   141,   131,   142,   147,   128,
     154,   165,   146,   144,   145,    80,    80,   139,    46,    47,
      48,    92,    50,    51,    52,   151,    17,   155,   156,   158,
     164,   163,   161,    18,   162,    85,    19,   169,   160,   171,
     170,   172,   157,     0,   159,     1,   131,   175,   176,   173,
       2,   177,     3,     4,   167,     5,     6,   182,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,   178,     0,
     181,   119,    46,    47,    48,    94,    50,    51,    52,   183,
      17,    10,    11,    12,    13,    14,    15,    18,     0,     0,
      19,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    46,    47,    48,    96,    50,    51,    52,    72,     0,
      73,    74,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,     0,     0,     0,    71,     0,    72,
       0,    73,    74,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,     0,     0,    89,     0,     0,     0,     0,
      72,     0,    73,    74,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,     0,     0,     0,     0,     0,   116,
       0,    72,     0,    73,    74,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,     0,     0,   121,     0,     0,
       0,     0,    72,     0,    73,    74,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,     0,     0,   122,     0,
       0,     0,     0,    72,     0,    73,    74,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,     0,     0,   126,
       0,     0,     0,     0,    72,     0,    73,    74,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,     0,     0,
       0,     0,     0,   137,     0,    72,     0,    73,    74,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,     0,
       0,     0,     0,     0,   140,     0,    72,     0,    73,    74,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
       0,     0,   166,     0,     0,     0,     0,    72,     0,    73,
      74,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,     0,     0,     0,     0,     0,     0,   168,    72,     0,
      73,    74,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,     0,     0,   174,     0,     0,     0,     0,    72,
       0,    73,    74,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    46,    47,    48,    98,    50,    51,    52,
      72,     0,    73,    74,    46,    47,    48,   100,    50,    51,
      52,    46,    47,    48,   102,    50,    51,    52,    46,    47,
      48,   104,    50,    51,    52,    46,    47,    48,   106,    50,
      51,    52,    46,    47,    48,   108,    50,    51,    52
};

static const yytype_int16 yycheck[] =
{
      21,     9,    41,    18,    41,    40,    16,    40,    41,    19,
      45,    48,    16,    17,    29,    48,     3,     4,     5,    40,
       7,     8,     9,    40,    41,    35,     6,    43,    45,    45,
      41,    35,    36,    41,    38,    39,   175,   176,    42,     3,
       4,     5,     6,     7,     8,     9,   119,   120,    43,    41,
      41,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    41,    72,    73,    74,     6,    45,    45,    48,     0,
      45,    51,     6,     6,    45,    42,    44,    41,    42,     6,
      10,    85,    40,    43,    48,     6,    43,    51,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,    15,   113,    43,    45,   114,    42,     6,   113,
      10,    12,    41,   134,   135,   119,   120,   127,     3,     4,
       5,     6,     7,     8,     9,    45,    41,    44,    44,    40,
     154,   152,    46,    48,    44,    41,    51,    46,   148,    44,
     161,    43,   146,    -1,   148,     6,   154,   168,   169,    45,
      11,   172,    13,    14,   158,    16,    17,   178,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    43,    -1,
      44,    10,     3,     4,     5,     6,     7,     8,     9,    44,
      41,    22,    23,    24,    25,    26,    27,    48,    -1,    -1,
      51,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,     3,     4,     5,     6,     7,     8,     9,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,     3,     4,     5,     6,     7,     8,     9,
      47,    -1,    49,    50,     3,     4,     5,     6,     7,     8,
       9,     3,     4,     5,     6,     7,     8,     9,     3,     4,
       5,     6,     7,     8,     9,     3,     4,     5,     6,     7,
       8,     9,     3,     4,     5,     6,     7,     8,     9
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    14,    16,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    48,    51,
      54,    55,    56,    57,    58,    59,    60,    61,    63,    64,
      67,    68,    69,    70,    72,    40,    41,    48,    41,    41,
      43,    41,    41,    45,    45,    72,     3,     4,     5,     6,
       7,     8,     9,    70,    71,    70,     6,    71,     0,    54,
      45,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    45,    47,    49,    50,     6,    70,    71,    42,    66,
      70,    71,    70,    70,    54,    67,    72,    70,     6,    42,
       6,    71,     6,    71,     6,    71,     6,    71,     6,    71,
       6,    71,     6,    71,     6,    71,     6,    71,     6,    71,
      71,    71,    71,    40,    41,    45,    45,    45,    42,    10,
      10,    42,    42,    44,    70,     6,    42,    40,    70,    71,
      65,    72,    66,    66,    43,    43,    15,    45,    43,    71,
      45,    45,    42,     6,    54,    54,    41,     6,    18,    29,
      62,    45,    43,    45,    10,    44,    44,    70,    40,    70,
      71,    46,    44,    54,    65,    12,    42,    70,    46,    46,
      54,    44,    43,    45,    42,    54,    54,    54,    43,    62,
      62,    44,    54,    44
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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

/* Line 1455 of yacc.c  */
#line 78 "parser.y"
    {printf("stmt_list\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 79 "parser.y"
    {printf("stmt epsilon\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 87 "parser.y"
    {printf("if statement\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
#line 88 "parser.y"
    {printf("while statement\n");;}
    break;

  case 6:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {printf("repeat statement\n");;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
    {printf("for statement\n");;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 91 "parser.y"
    {printf("switch statement\n");;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 92 "parser.y"
    {printf("function declaration\n");;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 94 "parser.y"
    {printf("variable declaration\n");;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 95 "parser.y"
    {printf("constant declaration\n");;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 96 "parser.y"
    {printf("assignment statement\n");;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 97 "parser.y"
    {printf("expression\n");;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 98 "parser.y"
    {printf("return statement\n");;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 99 "parser.y"
    {printf("break statement\n");;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 100 "parser.y"
    {printf("continue statement\n");;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 103 "parser.y"
    {printf("return\n");;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 104 "parser.y"
    {printf("return term\n");;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {printf("return expr\n");;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 113 "parser.y"
    {printf("if (expr) {stmt_list}\n");;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 114 "parser.y"
    {printf("if (expr) {stmt_list} else {stmt_list}\n");;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 117 "parser.y"
    {printf("while (expr) {stmt_list}\n");;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 120 "parser.y"
    {printf("repeat {stmt_list} until (expr)\n");;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 123 "parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n");;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 126 "parser.y"
    {printf("switch (expr) {case_list}\n");;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 129 "parser.y"
    {printf("case expr: stmt_list case_list\n");;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 130 "parser.y"
    {printf("case term: stmt_list case_list\n");;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 131 "parser.y"
    {printf("case expr: stmt_list\n");;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 132 "parser.y"
    {printf("case term: stmt_list\n");;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 133 "parser.y"
    {printf("default: stmt_list\n");;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 136 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 137 "parser.y"
    {printf("data_type identifier () {stmt_list}\n");;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 140 "parser.y"
    {printf("identifier (call_param_list) ;\n");;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 141 "parser.y"
    {printf("identifier () ;\n");;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 149 "parser.y"
    {printf("data_type identifier , dec_param_list\n");;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 150 "parser.y"
    {printf("data_type identifier\n");;}
    break;

  case 37:

/* Line 1455 of yacc.c  */
#line 153 "parser.y"
    {printf("identifier , call_param_list\n");;}
    break;

  case 38:

/* Line 1455 of yacc.c  */
#line 154 "parser.y"
    {printf("data_type identifier\n");;}
    break;

  case 39:

/* Line 1455 of yacc.c  */
#line 155 "parser.y"
    {printf("term , call_param_list\n");;}
    break;

  case 40:

/* Line 1455 of yacc.c  */
#line 156 "parser.y"
    {printf("term\n");;}
    break;

  case 41:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    {printf("data_type identifier; \n");;}
    break;

  case 42:

/* Line 1455 of yacc.c  */
#line 164 "parser.y"
    {printf("data_type identifier = term ;\n");;}
    break;

  case 43:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    {printf("data_type identifier = expr ;\n");;}
    break;

  case 44:

/* Line 1455 of yacc.c  */
#line 172 "parser.y"
    {printf("const data_type identifier = term ;\n");;}
    break;

  case 45:

/* Line 1455 of yacc.c  */
#line 179 "parser.y"
    {printf("identifier = term ;\n");;}
    break;

  case 46:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {printf("identifier = expr ;\n");;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 188 "parser.y"
    {printf("expr == identifer\n");;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 189 "parser.y"
    {printf("expr != identifer\n");;}
    break;

  case 49:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    {printf("expr < identifer\n");;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 191 "parser.y"
    {printf("expr > identifer\n");;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    {printf("expr <= identifer\n");;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 193 "parser.y"
    {printf("expr >= identifer\n");;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 194 "parser.y"
    {printf("expr / identifer\n");;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 195 "parser.y"
    {printf("expr * identifer\n");;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 196 "parser.y"
    {printf("expr - identifer\n");;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 197 "parser.y"
    {printf("expr + identifer\n");;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {printf("unary expr\n");;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 199 "parser.y"
    {printf("identifer unary\n");;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 204 "parser.y"
    {printf("expr + term\n");;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 205 "parser.y"
    {printf("expr - term\n");;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 206 "parser.y"
    {printf("expr * term\n");;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 207 "parser.y"
    {printf("expr / term\n");;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {printf("expr == term\n");;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 209 "parser.y"
    {printf("expr != term\n");;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 210 "parser.y"
    {printf("expr < term\n");;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 211 "parser.y"
    {printf("expr > term\n");;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 212 "parser.y"
    {printf("expr <= term\n");;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {printf("expr >= term\n");;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 214 "parser.y"
    {printf("expr ^ term\n");;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 215 "parser.y"
    {printf("expr && term\n");;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 216 "parser.y"
    {printf("expr || term\n");;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 217 "parser.y"
    {printf("!term\n");;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {printf("(expr)\n");;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 219 "parser.y"
    {printf("identifier\n");;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 220 "parser.y"
    {printf("function call\n");;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 232 "parser.y"
    {printf("number\n");;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 233 "parser.y"
    {printf("true\n");;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 234 "parser.y"
    {printf("false\n");;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 235 "parser.y"
    {printf("char\n");;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 236 "parser.y"
    {printf("string\n");;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 237 "parser.y"
    {printf("float\n");;}
    break;



/* Line 1455 of yacc.c  */
#line 2196 "parser.tab.c"
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
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
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



/* Line 1675 of yacc.c  */
#line 248 "parser.y"


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
    return 0;
}

