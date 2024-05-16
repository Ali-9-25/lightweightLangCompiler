
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
<<<<<<< HEAD
#line 1 "parser.y"
=======
#line 1 "./parser.y"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "node.h"
#define MAX_SYMBOLS 1000
/* Symbol table structure */
struct symbol {
    char * name;
    char * data_type; // 0 for int, 1 for float
    char * type;  // keyword, constant, variable
    int line_no; // line number too check if the variable is initialized or if the closest scope control token
};

nodeType *opr(int oper, int nops, ...);
nodeType *id(int i);
nodeType *con(int value);
//TODO: Add unary operators such as ++, --, !, ~, etc.
struct symbol symbol_table[MAX_SYMBOLS];
int symbol_count = 0;
// int count = 0;
extern FILE *yyin;
void yyerror(const char *s);
int yylex();
int lookup_symbol(char *name);
void add(char c, char * name, char * type);
char * charToString(char c);
extern int countn; // line count


/* Line 189 of yacc.c  */
#line 105 "parser.tab.c"

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
<<<<<<< HEAD
#line 32 "parser.y"
=======
#line 32 "./parser.y"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

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
<<<<<<< HEAD

=======
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    struct var_name {
        char name[100];
        struct node* nd;
    } nd_obj;



/* Line 214 of yacc.c  */
<<<<<<< HEAD
#line 218 "parser.tab.c"
=======
#line 217 "parser.tab.c"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
<<<<<<< HEAD
#line 230 "parser.tab.c"
=======
#line 229 "parser.tab.c"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

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
<<<<<<< HEAD
#define YYFINAL  61
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   924
=======
#define YYFINAL  62
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   931
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
<<<<<<< HEAD
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNRULES -- Number of states.  */
#define YYNSTATES  230
=======
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNRULES -- Number of states.  */
#define YYNSTATES  231
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

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
<<<<<<< HEAD
       0,     0,     3,     6,    11,    12,    14,    16,    18,    20,
      22,    24,    26,    28,    30,    33,    36,    39,    42,    44,
      47,    50,    58,    70,    78,    88,   101,   109,   115,   121,
     126,   131,   135,   144,   151,   156,   160,   165,   168,   172,
     174,   178,   180,   184,   190,   196,   203,   208,   213,   217,
     221,   225,   229,   233,   237,   241,   245,   249,   253,   256,
     259,   263,   267,   271,   275,   279,   283,   287,   291,   295,
     299,   303,   307,   311,   314,   318,   324,   330,   336,   342,
     348,   354,   360,   366,   372,   378,   384,   390,   396,   401,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
     423,   425,   427
=======
       0,     0,     3,     6,     8,     9,    14,    16,    18,    20,
      22,    24,    26,    28,    30,    32,    35,    38,    41,    44,
      46,    49,    52,    60,    72,    80,    90,   103,   111,   117,
     123,   128,   133,   137,   146,   153,   158,   162,   167,   170,
     174,   176,   180,   182,   186,   192,   198,   205,   210,   215,
     219,   223,   227,   231,   235,   239,   243,   247,   251,   255,
     258,   261,   265,   269,   273,   277,   281,   285,   289,   293,
     297,   301,   305,   309,   313,   316,   320,   326,   332,   338,
     344,   350,   356,   362,   368,   374,   380,   386,   392,   398,
     403,   405,   407,   409,   411,   413,   415,   417,   419,   421,
     423,   425,   427,   429
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
<<<<<<< HEAD
      54,     0,    -1,    55,    54,    -1,    43,    54,    44,    54,
      -1,    -1,    57,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    63,    -1,    67,    -1,    68,    -1,    69,    -1,
      70,    45,    -1,    56,    45,    -1,    19,    45,    -1,    20,
      45,    -1,    28,    -1,    28,    71,    -1,    28,    70,    -1,
      11,    41,    70,    42,    43,    54,    44,    -1,    11,    41,
      70,    42,    43,    54,    44,    12,    43,    54,    44,    -1,
      13,    41,    70,    42,    43,    54,    44,    -1,    14,    43,
      54,    44,    15,    41,    70,    42,    45,    -1,    16,    41,
      67,    70,    45,     6,    40,    70,    42,    43,    54,    44,
      -1,    17,    41,    70,    42,    43,    62,    44,    -1,    18,
      70,    46,    54,    62,    -1,    18,    71,    46,    54,    62,
      -1,    18,    70,    46,    54,    -1,    18,    71,    46,    54,
      -1,    29,    46,    54,    -1,    72,     6,    41,    65,    42,
      43,    54,    44,    -1,    72,     6,    41,    65,    42,    45,
      -1,     6,    41,    66,    42,    -1,     6,    41,    42,    -1,
      72,     6,    10,    65,    -1,    72,     6,    -1,    70,    10,
      66,    -1,    70,    -1,    71,    10,    66,    -1,    71,    -1,
      72,     6,    45,    -1,    72,     6,    40,    71,    45,    -1,
      72,     6,    40,    70,    45,    -1,    21,    72,     6,    40,
      71,    45,    -1,     6,    40,    71,    45,    -1,     6,    40,
      70,    45,    -1,    70,    30,     6,    -1,    70,    31,     6,
      -1,    70,    32,     6,    -1,    70,    33,     6,    -1,    70,
      34,     6,    -1,    70,    35,     6,    -1,    70,    39,     6,
      -1,    70,    38,     6,    -1,    70,    37,     6,    -1,    70,
      36,     6,    -1,    48,     6,    -1,     6,    48,    -1,    70,
      36,    71,    -1,    70,    37,    71,    -1,    70,    38,    71,
      -1,    70,    39,    71,    -1,    70,    30,    71,    -1,    70,
      31,    71,    -1,    70,    32,    71,    -1,    70,    33,    71,
      -1,    70,    34,    71,    -1,    70,    35,    71,    -1,    70,
      47,    71,    -1,    70,    49,    71,    -1,    70,    50,    71,
      -1,    51,    71,    -1,    41,    70,    42,    -1,    70,    36,
      41,    70,    42,    -1,    70,    37,    41,    70,    42,    -1,
      70,    38,    41,    70,    42,    -1,    70,    39,    41,    70,
      42,    -1,    70,    30,    41,    70,    42,    -1,    70,    31,
      41,    70,    42,    -1,    70,    32,    41,    70,    42,    -1,
      70,    33,    41,    70,    42,    -1,    70,    34,    41,    70,
      42,    -1,    70,    35,    41,    70,    42,    -1,    70,    47,
      41,    70,    42,    -1,    70,    49,    41,    70,    42,    -1,
      70,    50,    41,    70,    42,    -1,    51,    41,    70,    42,
      -1,     6,    -1,    64,    -1,     3,    -1,     8,    -1,     9,
      -1,     7,    -1,     5,    -1,     4,    -1,    22,    -1,    24,
      -1,    26,    -1,    25,    -1,    23,    -1,    27,    -1
=======
      54,     0,    -1,    56,    54,    -1,    55,    -1,    -1,    43,
      54,    44,    54,    -1,    58,    -1,    59,    -1,    60,    -1,
      61,    -1,    62,    -1,    64,    -1,    68,    -1,    69,    -1,
      70,    -1,    71,    45,    -1,    57,    45,    -1,    19,    45,
      -1,    20,    45,    -1,    28,    -1,    28,    72,    -1,    28,
      71,    -1,    11,    41,    71,    42,    43,    54,    44,    -1,
      11,    41,    71,    42,    43,    54,    44,    12,    43,    54,
      44,    -1,    13,    41,    71,    42,    43,    54,    44,    -1,
      14,    43,    54,    44,    15,    41,    71,    42,    45,    -1,
      16,    41,    68,    71,    45,     6,    40,    71,    42,    43,
      54,    44,    -1,    17,    41,    71,    42,    43,    63,    44,
      -1,    18,    71,    46,    54,    63,    -1,    18,    72,    46,
      54,    63,    -1,    18,    71,    46,    54,    -1,    18,    72,
      46,    54,    -1,    29,    46,    54,    -1,    73,     6,    41,
      66,    42,    43,    54,    44,    -1,    73,     6,    41,    66,
      42,    45,    -1,     6,    41,    67,    42,    -1,     6,    41,
      42,    -1,    73,     6,    10,    66,    -1,    73,     6,    -1,
      71,    10,    67,    -1,    71,    -1,    72,    10,    67,    -1,
      72,    -1,    73,     6,    45,    -1,    73,     6,    40,    72,
      45,    -1,    73,     6,    40,    71,    45,    -1,    21,    73,
       6,    40,    72,    45,    -1,     6,    40,    72,    45,    -1,
       6,    40,    71,    45,    -1,    71,    30,     6,    -1,    71,
      31,     6,    -1,    71,    32,     6,    -1,    71,    33,     6,
      -1,    71,    34,     6,    -1,    71,    35,     6,    -1,    71,
      39,     6,    -1,    71,    38,     6,    -1,    71,    37,     6,
      -1,    71,    36,     6,    -1,    48,     6,    -1,     6,    48,
      -1,    71,    36,    72,    -1,    71,    37,    72,    -1,    71,
      38,    72,    -1,    71,    39,    72,    -1,    71,    30,    72,
      -1,    71,    31,    72,    -1,    71,    32,    72,    -1,    71,
      33,    72,    -1,    71,    34,    72,    -1,    71,    35,    72,
      -1,    71,    47,    72,    -1,    71,    49,    72,    -1,    71,
      50,    72,    -1,    51,    72,    -1,    41,    71,    42,    -1,
      71,    36,    41,    71,    42,    -1,    71,    37,    41,    71,
      42,    -1,    71,    38,    41,    71,    42,    -1,    71,    39,
      41,    71,    42,    -1,    71,    30,    41,    71,    42,    -1,
      71,    31,    41,    71,    42,    -1,    71,    32,    41,    71,
      42,    -1,    71,    33,    41,    71,    42,    -1,    71,    34,
      41,    71,    42,    -1,    71,    35,    41,    71,    42,    -1,
      71,    47,    41,    71,    42,    -1,    71,    49,    41,    71,
      42,    -1,    71,    50,    41,    71,    42,    -1,    51,    41,
      71,    42,    -1,     6,    -1,    65,    -1,     3,    -1,     8,
      -1,     9,    -1,     7,    -1,     5,    -1,     4,    -1,    22,
      -1,    24,    -1,    26,    -1,    25,    -1,    23,    -1,    27,
      -1
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
<<<<<<< HEAD
       0,    88,    88,    89,    90,    98,    99,   100,   101,   102,
     103,   105,   106,   107,   108,   109,   110,   111,   114,   115,
     116,   124,   125,   128,   131,   134,   137,   140,   141,   142,
     143,   144,   147,   148,   151,   152,   160,   161,   164,   165,
     166,   167,   174,   175,   176,   183,   190,   191,   199,   200,
     201,   202,   203,   204,   205,   206,   207,   208,   209,   210,
     211,   212,   213,   214,   215,   216,   217,   218,   219,   220,
     221,   222,   223,   224,   225,   226,   227,   228,   229,   230,
     231,   232,   233,   234,   235,   236,   237,   238,   239,   240,
     241,   253,   254,   255,   256,   257,   258,   263,   264,   265,
     266,   267,   268
=======
       0,    87,    87,    88,    89,    93,   106,   107,   108,   109,
     110,   111,   113,   114,   115,   116,   117,   118,   119,   122,
     123,   124,   132,   133,   136,   139,   142,   145,   148,   149,
     150,   151,   152,   155,   156,   159,   160,   168,   169,   172,
     173,   174,   175,   182,   183,   184,   191,   199,   200,   208,
     209,   210,   211,   212,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,   250,   262,   263,   264,   265,   266,   267,   272,   273,
     274,   275,   276,   277
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
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
<<<<<<< HEAD
  "NOT", "UMINUS", "$accept", "stmt_list", "stmt", "return_stmt",
=======
  "NOT", "UMINUS", "$accept", "stmt_list", "scope", "stmt", "return_stmt",
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
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
<<<<<<< HEAD
       0,    53,    54,    54,    54,    55,    55,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    56,    56,
      56,    57,    57,    58,    59,    60,    61,    62,    62,    62,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    67,    68,    69,    69,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71,    71,    72,    72,    72,
      72,    72,    72
=======
       0,    53,    54,    54,    54,    55,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    57,
      57,    57,    58,    58,    59,    60,    61,    62,    63,    63,
      63,    63,    63,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    68,    69,    70,    70,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    72,    72,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    73
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
<<<<<<< HEAD
       0,     2,     2,     4,     0,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     2,     1,     2,
       2,     7,    11,     7,     9,    12,     7,     5,     5,     4,
       4,     3,     8,     6,     4,     3,     4,     2,     3,     1,
       3,     1,     3,     5,     5,     6,     4,     4,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     3,     5,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     4,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
=======
       0,     2,     2,     1,     0,     4,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     1,
       2,     2,     7,    11,     7,     9,    12,     7,     5,     5,
       4,     4,     3,     8,     6,     4,     3,     4,     2,     3,
       1,     3,     1,     3,     5,     5,     6,     4,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     5,     5,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,     4,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
       4,    89,     0,     0,     0,     0,     0,     0,     0,     0,
      97,   101,    98,   100,    99,   102,    18,     0,     4,     0,
       0,     0,     4,     0,     5,     6,     7,     8,     9,    10,
      90,    11,    12,    13,     0,     0,     0,     0,    59,     0,
       0,     4,     0,     0,    16,    17,     0,    91,    96,    95,
      89,    94,    92,    93,    20,    19,     0,     0,    58,     0,
      73,     1,     2,    15,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,    35,     0,    39,    41,     0,     0,     0,     0,     0,
       0,     0,    74,     4,     0,    48,     0,    64,    49,     0,
      65,    50,     0,    66,    51,     0,    67,    52,     0,    68,
      53,     0,    69,    57,     0,    60,    56,     0,    61,    55,
       0,    62,    54,     0,    63,     0,    70,     0,    71,     0,
      72,     0,     0,    42,    47,    46,    34,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     3,    88,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,    40,     4,     4,     0,
       0,     0,     0,    79,    80,    81,    82,    83,    84,    75,
      76,    77,    78,    85,    86,    87,    44,    43,     0,    37,
       0,     0,     0,     0,     0,     0,     0,    45,     4,    33,
       0,    21,    23,     0,     0,     0,     0,     4,    26,     0,
      36,     0,     0,     0,     4,     4,    31,    32,     4,    24,
       0,    29,    30,     0,     4,    27,    28,    22,     0,    25
=======
       4,    90,     0,     0,     0,     0,     0,     0,     0,     0,
      98,   102,    99,   101,   100,   103,    19,     0,     4,     0,
       0,     0,     3,     4,     0,     6,     7,     8,     9,    10,
      11,    91,    12,    13,    14,     0,     0,     0,     0,    60,
       0,     0,     4,     0,     0,    17,    18,     0,    92,    97,
      96,    90,    95,    93,    94,    21,    20,     0,     0,    59,
       0,    74,     1,     2,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    15,     0,     0,     0,     0,
       0,     0,    36,     0,    40,    42,     0,     0,     0,     0,
       0,     0,     0,    75,     4,     0,    49,     0,    65,    50,
       0,    66,    51,     0,    67,    52,     0,    68,    53,     0,
      69,    54,     0,    70,    58,     0,    61,    57,     0,    62,
      56,     0,    63,    55,     0,    64,     0,    71,     0,    72,
       0,    73,     0,     0,    43,    48,    47,    35,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     5,    89,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    39,    41,     4,     4,
       0,     0,     0,     0,    80,    81,    82,    83,    84,    85,
      76,    77,    78,    79,    86,    87,    88,    45,    44,     0,
      38,     0,     0,     0,     0,     0,     0,     0,    46,     4,
      34,     0,    22,    24,     0,     0,     0,     0,     4,    27,
       0,    37,     0,     0,     0,     4,     4,    32,    33,     4,
      25,     0,    30,    31,     0,     4,    28,    29,    23,     0,
      26
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
      -1,    21,    22,    23,    24,    25,    26,    27,    28,   196,
      29,    30,   163,    82,    31,    32,    33,    34,    84,    35
=======
      -1,    21,    22,    23,    24,    25,    26,    27,    28,    29,
     197,    30,    31,   164,    83,    32,    33,    34,    35,    85,
      36
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
<<<<<<< HEAD
#define YYPACT_NINF -202
static const yytype_int16 yypact[] =
{
     188,   -38,   -32,   -29,   -13,     8,    13,    20,    24,   145,
    -202,  -202,  -202,  -202,  -202,  -202,   125,     2,   188,    64,
     295,    78,   188,    34,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,   349,    75,   125,    32,  -202,     2,
       2,   188,   145,     2,  -202,  -202,    76,  -202,  -202,  -202,
     -17,  -202,  -202,  -202,   874,  -202,   370,    40,  -202,     2,
    -202,  -202,  -202,  -202,    10,   214,   237,   244,   253,   260,
     267,   283,   306,   313,  -202,   322,   330,   337,    31,   391,
      41,  -202,    45,   107,    79,   412,   433,    46,     2,    86,
     454,    53,  -202,   188,   475,  -202,     2,  -202,  -202,     2,
    -202,  -202,     2,  -202,  -202,     2,  -202,  -202,     2,  -202,
    -202,     2,  -202,  -202,     2,  -202,  -202,     2,  -202,  -202,
       2,  -202,  -202,     2,  -202,     2,  -202,     2,  -202,     2,
    -202,   125,   145,  -202,  -202,  -202,  -202,   125,   125,    52,
      55,    81,   496,     7,    56,   155,  -202,  -202,   517,   538,
     559,   580,   601,   622,   643,   664,   685,   706,   727,   748,
     769,   790,    57,    59,    98,  -202,  -202,   188,   188,    66,
      99,     4,    63,  -202,  -202,  -202,  -202,  -202,  -202,  -202,
    -202,  -202,  -202,  -202,  -202,  -202,  -202,  -202,    -1,   100,
      67,    69,     2,    83,   125,    73,    71,  -202,   188,  -202,
     145,   109,  -202,   811,     2,   832,    89,   188,  -202,   103,
    -202,    82,   106,   853,   188,   188,  -202,  -202,   188,  -202,
     105,     4,     4,   108,   188,  -202,  -202,  -202,   111,  -202
=======
#define YYPACT_NINF -150
static const yytype_int16 yypact[] =
{
     204,   -15,   -39,    -9,   -20,    -4,    14,    15,    20,    17,
    -150,  -150,  -150,  -150,  -150,  -150,    13,    -3,   204,    56,
     288,    75,  -150,   204,    38,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,   356,    82,    13,     5,  -150,
      -3,    -3,   204,    17,    -3,  -150,  -150,    83,  -150,  -150,
    -150,   -12,  -150,  -150,  -150,   881,  -150,   377,    47,  -150,
      -3,  -150,  -150,  -150,  -150,    63,   136,   231,   253,   260,
     270,   280,   299,   309,   319,  -150,   327,   334,   344,    18,
     398,    49,  -150,    50,   137,    85,   419,   440,    53,    -3,
      92,   461,    60,  -150,   204,   482,  -150,    -3,  -150,  -150,
      -3,  -150,  -150,    -3,  -150,  -150,    -3,  -150,  -150,    -3,
    -150,  -150,    -3,  -150,  -150,    -3,  -150,  -150,    -3,  -150,
    -150,    -3,  -150,  -150,    -3,  -150,    -3,  -150,    -3,  -150,
      -3,  -150,    13,    17,  -150,  -150,  -150,  -150,    13,    13,
      58,    66,    91,   503,    12,    67,    77,  -150,  -150,   524,
     545,   566,   587,   608,   629,   650,   671,   692,   713,   734,
     755,   776,   797,    68,    70,   109,  -150,  -150,   204,   204,
      76,   113,   -14,    78,  -150,  -150,  -150,  -150,  -150,  -150,
    -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,     6,
     111,    86,    88,    -3,    93,    13,    80,    90,  -150,   204,
    -150,    17,   115,  -150,   818,    -3,   839,    89,   204,  -150,
      94,  -150,   103,   104,   860,   204,   204,  -150,  -150,   204,
    -150,   105,   -14,   -14,   118,   204,  -150,  -150,  -150,   122,
    -150
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
    -202,   -18,  -202,  -202,  -202,  -202,  -202,  -202,  -202,  -201,
    -202,  -202,   -47,   -92,   119,  -202,  -202,   -11,    -9,    -8
=======
    -150,   -18,  -150,  -150,  -150,  -150,  -150,  -150,  -150,  -150,
    -149,  -150,  -150,   -70,   -61,   135,  -150,  -150,   -10,    87,
      -8
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
<<<<<<< HEAD
      57,    46,    36,    37,    62,    54,    56,    55,    50,    39,
      38,    60,    40,    47,    48,    49,    95,    51,    52,    53,
     225,   226,   194,    87,    37,    79,    83,    80,    85,    86,
      41,    38,    90,   195,    89,    47,    48,    49,    50,    51,
      52,    53,   198,    17,   199,   165,   166,   131,    94,    42,
      19,    96,   133,    20,    43,    97,   100,   103,   106,   109,
     112,   115,   118,   121,   124,    44,   126,   128,   130,    45,
      58,   131,   132,    17,    81,   146,   133,   142,    61,    63,
      19,    78,    91,    20,    93,   148,   135,   136,   149,   138,
     141,   150,   143,   145,   151,   167,   169,   152,   168,   171,
     153,   188,   187,   154,   189,   193,   155,   192,   197,   156,
     200,   201,   157,   202,   158,   208,   159,   137,   160,   207,
     161,   211,   162,   204,   164,   218,    83,    83,    47,    48,
      49,    50,    51,    52,    53,   215,   172,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,   217,   224,   190,
     191,   219,   227,   210,    75,   229,    76,    77,    47,    48,
      49,    88,    51,    52,    53,     0,    17,    10,    11,    12,
      13,    14,    15,    19,     0,     0,    20,     0,     0,     0,
     209,   203,     0,   205,     0,   206,     0,     0,     0,   216,
       0,     0,   164,   213,     1,     0,   221,   222,     0,     2,
     223,     3,     4,     0,     5,     6,   228,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    47,    48,    49,
      98,    51,    52,    53,     0,     0,     0,     0,     0,    17,
       0,    18,     0,     0,     0,     0,    19,     0,     0,    20,
      47,    48,    49,   101,    51,    52,    53,    47,    48,    49,
     104,    51,    52,    53,     0,    99,    47,    48,    49,   107,
      51,    52,    53,    47,    48,    49,   110,    51,    52,    53,
      47,    48,    49,   113,    51,    52,    53,     0,   102,     0,
       0,     0,     0,     0,     0,   105,    47,    48,    49,   116,
      51,    52,    53,     0,   108,     0,     0,     0,    47,    48,
      49,   111,    51,    52,    53,     0,     0,     0,   114,    47,
      48,    49,   119,    51,    52,    53,    47,    48,    49,   122,
      51,    52,    53,     0,   117,    47,    48,    49,     0,    51,
      52,    53,     0,    47,    48,    49,    59,    51,    52,    53,
      47,    48,    49,     0,    51,    52,    53,   120,     0,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,     0,   125,     0,     0,     0,     0,     0,     0,
       0,   127,     0,     0,     0,     0,     0,     0,   129,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,    74,     0,    75,     0,    76,    77,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,    92,     0,     0,     0,     0,    75,     0,    76,
      77,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,   134,     0,    75,     0,
      76,    77,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,   139,     0,     0,     0,     0,    75,
       0,    76,    77,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,   140,     0,     0,     0,     0,
      75,     0,    76,    77,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,   144,     0,     0,     0,
       0,    75,     0,    76,    77,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,   147,     0,     0,
       0,     0,    75,     0,    76,    77,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,     0,     0,
       0,   170,     0,    75,     0,    76,    77,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,   173,
       0,     0,     0,     0,    75,     0,    76,    77,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
     174,     0,     0,     0,     0,    75,     0,    76,    77,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,   175,     0,     0,     0,     0,    75,     0,    76,    77,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,   176,     0,     0,     0,     0,    75,     0,    76,
      77,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,   177,     0,     0,     0,     0,    75,     0,
      76,    77,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,   178,     0,     0,     0,     0,    75,
       0,    76,    77,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,   179,     0,     0,     0,     0,
      75,     0,    76,    77,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,   180,     0,     0,     0,
       0,    75,     0,    76,    77,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,   181,     0,     0,
       0,     0,    75,     0,    76,    77,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,     0,     0,   182,     0,
       0,     0,     0,    75,     0,    76,    77,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,     0,     0,   183,
       0,     0,     0,     0,    75,     0,    76,    77,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
     184,     0,     0,     0,     0,    75,     0,    76,    77,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,   185,     0,     0,     0,     0,    75,     0,    76,    77,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
       0,     0,     0,     0,     0,   186,     0,    75,     0,    76,
      77,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,   212,     0,     0,     0,     0,    75,     0,
      76,    77,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     0,     0,     0,     0,     0,     0,   214,    75,
       0,    76,    77,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,     0,     0,   220,     0,     0,     0,     0,
      75,     0,    76,    77,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     0,     0,     0,     0,     0,
       0,    75,     0,    76,    77
=======
      58,    47,    40,    51,   195,    63,    55,    57,    48,    49,
      50,    51,    52,    53,    54,   196,    48,    49,    50,    51,
      52,    53,    54,    42,    88,    37,    38,    80,    84,    38,
      86,    87,    41,    39,    91,    90,    39,    43,    17,    10,
      11,    12,    13,    14,    15,    19,    17,    82,    20,   199,
      95,   200,   132,    19,    17,    44,    20,   134,   132,   133,
      45,    19,    59,   134,    20,    46,    48,    49,    50,    96,
      52,    53,    54,   226,   227,    62,   147,   166,   167,   143,
      48,    49,    50,    64,    52,    53,    54,   149,    79,    92,
     150,    94,   137,   151,   136,   139,   152,   142,   144,   153,
     146,   168,   154,    56,    97,   155,   170,    61,   156,   169,
     172,   157,   189,   188,   158,   190,   159,   193,   160,   194,
     161,   201,   162,   198,    81,   165,   208,   212,    84,    84,
     202,   211,   203,   205,   209,   216,     0,     0,   218,    48,
      49,    50,    99,    52,    53,    54,   219,   138,   225,   220,
     191,   192,    98,   101,   104,   107,   110,   113,   116,   119,
     122,   125,   228,   127,   129,   131,   230,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   100,    89,     0,
       0,   210,     0,   204,    76,   206,    77,    78,     0,     0,
     217,     0,     0,   165,     0,   214,     0,   222,   223,     0,
       0,   224,     0,     0,     0,     0,     0,   229,     0,     0,
       1,     0,     0,     0,     0,     2,     0,     3,     4,   163,
       5,     6,     0,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,   173,    48,    49,    50,   102,    52,    53,
      54,     0,     0,     0,     0,    17,     0,    18,     0,     0,
       0,     0,    19,     0,     0,    20,    48,    49,    50,   105,
      52,    53,    54,    48,    49,    50,   108,    52,    53,    54,
       0,     0,   103,    48,    49,    50,   111,    52,    53,    54,
       0,     0,   207,    48,    49,    50,   114,    52,    53,    54,
       0,    48,    49,    50,   106,    52,    53,    54,     0,     0,
       0,   109,    48,    49,    50,   117,    52,    53,    54,     0,
       0,   112,    48,    49,    50,   120,    52,    53,    54,     0,
       0,   115,    48,    49,    50,   123,    52,    53,    54,    60,
      48,    49,    50,     0,    52,    53,    54,    48,    49,    50,
     118,    52,    53,    54,     0,     0,     0,    48,    49,    50,
     121,    52,    53,    54,     0,     0,     0,     0,     0,     0,
     124,     0,     0,     0,     0,     0,     0,     0,   126,     0,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   130,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,     0,     0,
       0,    75,     0,    76,     0,    77,    78,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,    93,
       0,     0,     0,     0,    76,     0,    77,    78,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
       0,     0,     0,   135,     0,    76,     0,    77,    78,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,   140,     0,     0,     0,     0,    76,     0,    77,    78,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,   141,     0,     0,     0,     0,    76,     0,    77,
      78,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,   145,     0,     0,     0,     0,    76,     0,
      77,    78,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,   148,     0,     0,     0,     0,    76,
       0,    77,    78,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,     0,     0,     0,   171,     0,
      76,     0,    77,    78,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,   174,     0,     0,     0,
       0,    76,     0,    77,    78,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,   175,     0,     0,
       0,     0,    76,     0,    77,    78,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,   176,     0,
       0,     0,     0,    76,     0,    77,    78,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,   177,
       0,     0,     0,     0,    76,     0,    77,    78,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
     178,     0,     0,     0,     0,    76,     0,    77,    78,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,   179,     0,     0,     0,     0,    76,     0,    77,    78,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,   180,     0,     0,     0,     0,    76,     0,    77,
      78,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,   181,     0,     0,     0,     0,    76,     0,
      77,    78,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,     0,     0,   182,     0,     0,     0,     0,    76,
       0,    77,    78,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,     0,     0,   183,     0,     0,     0,     0,
      76,     0,    77,    78,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,     0,     0,   184,     0,     0,     0,
       0,    76,     0,    77,    78,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,     0,     0,   185,     0,     0,
       0,     0,    76,     0,    77,    78,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,     0,     0,   186,     0,
       0,     0,     0,    76,     0,    77,    78,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,     0,     0,     0,
       0,     0,   187,     0,    76,     0,    77,    78,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,     0,     0,
     213,     0,     0,     0,     0,    76,     0,    77,    78,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,     0,
       0,     0,     0,     0,     0,   215,    76,     0,    77,    78,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
       0,     0,   221,     0,     0,     0,     0,    76,     0,    77,
      78,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,     0,     0,     0,     0,     0,     0,     0,    76,     0,
      77,    78
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
      18,     9,    40,    41,    22,    16,    17,    16,     6,    41,
      48,    20,    41,     3,     4,     5,     6,     7,     8,     9,
     221,   222,    18,    41,    41,    36,    37,    36,    39,    40,
      43,    48,    43,    29,    42,     3,     4,     5,     6,     7,
       8,     9,    43,    41,    45,   137,   138,    40,    59,    41,
      48,    41,    45,    51,    41,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    45,    75,    76,    77,    45,
       6,    40,    41,    41,    42,    93,    45,    88,     0,    45,
      48,     6,     6,    51,    44,    96,    45,    42,    99,    10,
      44,   102,     6,    40,   105,    43,    15,   108,    43,    43,
     111,    42,    45,   114,     6,     6,   117,    41,    45,   120,
      10,    44,   123,    44,   125,    44,   127,    10,   129,    46,
     131,    12,   131,    40,   132,    43,   137,   138,     3,     4,
       5,     6,     7,     8,     9,    46,   145,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    44,    43,   167,
     168,    45,    44,   200,    47,    44,    49,    50,     3,     4,
       5,    42,     7,     8,     9,    -1,    41,    22,    23,    24,
      25,    26,    27,    48,    -1,    -1,    51,    -1,    -1,    -1,
     198,   192,    -1,   194,    -1,   194,    -1,    -1,    -1,   207,
      -1,    -1,   200,   204,     6,    -1,   214,   215,    -1,    11,
     218,    13,    14,    -1,    16,    17,   224,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    41,
      -1,    43,    -1,    -1,    -1,    -1,    48,    -1,    -1,    51,
       3,     4,     5,     6,     7,     8,     9,     3,     4,     5,
       6,     7,     8,     9,    -1,    41,     3,     4,     5,     6,
       7,     8,     9,     3,     4,     5,     6,     7,     8,     9,
       3,     4,     5,     6,     7,     8,     9,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    41,     3,     4,     5,     6,
       7,     8,     9,    -1,    41,    -1,    -1,    -1,     3,     4,
       5,    41,     7,     8,     9,    -1,    -1,    -1,    41,     3,
       4,     5,     6,     7,     8,     9,     3,     4,     5,     6,
       7,     8,     9,    -1,    41,     3,     4,     5,    -1,     7,
       8,     9,    -1,     3,     4,     5,    41,     7,     8,     9,
       3,     4,     5,    -1,     7,     8,     9,    41,    -1,    -1,
      -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    41,    -1,    -1,    -1,    -1,    -1,    -1,    41,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
=======
      18,     9,    41,     6,    18,    23,    16,    17,     3,     4,
       5,     6,     7,     8,     9,    29,     3,     4,     5,     6,
       7,     8,     9,    43,    42,    40,    41,    37,    38,    41,
      40,    41,    41,    48,    44,    43,    48,    41,    41,    22,
      23,    24,    25,    26,    27,    48,    41,    42,    51,    43,
      60,    45,    40,    48,    41,    41,    51,    45,    40,    41,
      45,    48,     6,    45,    51,    45,     3,     4,     5,     6,
       7,     8,     9,   222,   223,     0,    94,   138,   139,    89,
       3,     4,     5,    45,     7,     8,     9,    97,     6,     6,
     100,    44,    42,   103,    45,    10,   106,    44,     6,   109,
      40,    43,   112,    16,    41,   115,    15,    20,   118,    43,
      43,   121,    42,    45,   124,     6,   126,    41,   128,     6,
     130,    10,   132,    45,    37,   133,    46,    12,   138,   139,
      44,   201,    44,    40,    44,    46,    -1,    -1,    44,     3,
       4,     5,     6,     7,     8,     9,    43,    10,    43,    45,
     168,   169,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    44,    76,    77,    78,    44,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    41,    43,    -1,
      -1,   199,    -1,   193,    47,   195,    49,    50,    -1,    -1,
     208,    -1,    -1,   201,    -1,   205,    -1,   215,   216,    -1,
      -1,   219,    -1,    -1,    -1,    -1,    -1,   225,    -1,    -1,
       6,    -1,    -1,    -1,    -1,    11,    -1,    13,    14,   132,
      16,    17,    -1,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,   146,     3,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    41,    -1,    43,    -1,    -1,
      -1,    -1,    48,    -1,    -1,    51,     3,     4,     5,     6,
       7,     8,     9,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    41,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,   195,     3,     4,     5,     6,     7,     8,     9,
      -1,     3,     4,     5,    41,     7,     8,     9,    -1,    -1,
      -1,    41,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    41,     3,     4,     5,     6,     7,     8,     9,    -1,
      -1,    41,     3,     4,     5,     6,     7,     8,     9,    41,
       3,     4,     5,    -1,     7,     8,     9,     3,     4,     5,
      41,     7,     8,     9,    -1,    -1,    -1,     3,     4,     5,
      41,     7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      41,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    41,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    41,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    -1,    49,    50,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    45,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
<<<<<<< HEAD
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    47,    -1,    49,    50,    30,    31,    32,
=======
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
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
      35,    36,    37,    38,    39,    -1,    -1,    42,    -1,    -1,
      -1,    -1,    47,    -1,    49,    50,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,    32,
<<<<<<< HEAD
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    47,
      -1,    49,    50,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    -1,    -1,    -1,    -1,
      47,    -1,    49,    50,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    47,    -1,    49,    50
=======
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    47,    -1,    49,    50,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    47,    -1,    49,    50,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    47,    -1,    49,    50,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    42,    -1,    -1,    -1,    -1,    47,    -1,    49,
      50,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      49,    50
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    11,    13,    14,    16,    17,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    41,    43,    48,
<<<<<<< HEAD
      51,    54,    55,    56,    57,    58,    59,    60,    61,    63,
      64,    67,    68,    69,    70,    72,    40,    41,    48,    41,
      41,    43,    41,    41,    45,    45,    72,     3,     4,     5,
       6,     7,     8,     9,    70,    71,    70,    54,     6,    41,
      71,     0,    54,    45,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    45,    47,    49,    50,     6,    70,
      71,    42,    66,    70,    71,    70,    70,    54,    67,    72,
      70,     6,    42,    44,    70,     6,    41,    71,     6,    41,
      71,     6,    41,    71,     6,    41,    71,     6,    41,    71,
       6,    41,    71,     6,    41,    71,     6,    41,    71,     6,
      41,    71,     6,    41,    71,    41,    71,    41,    71,    41,
      71,    40,    41,    45,    45,    45,    42,    10,    10,    42,
      42,    44,    70,     6,    42,    40,    54,    42,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    71,    65,    72,    66,    66,    43,    43,    15,
      45,    43,    71,    42,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    45,    45,    42,     6,
      54,    54,    41,     6,    18,    29,    62,    45,    43,    45,
      10,    44,    44,    70,    40,    70,    71,    46,    44,    54,
      65,    12,    42,    70,    46,    46,    54,    44,    43,    45,
      42,    54,    54,    54,    43,    62,    62,    44,    54,    44
=======
      51,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      64,    65,    68,    69,    70,    71,    73,    40,    41,    48,
      41,    41,    43,    41,    41,    45,    45,    73,     3,     4,
       5,     6,     7,     8,     9,    71,    72,    71,    54,     6,
      41,    72,     0,    54,    45,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    45,    47,    49,    50,     6,
      71,    72,    42,    67,    71,    72,    71,    71,    54,    68,
      73,    71,     6,    42,    44,    71,     6,    41,    72,     6,
      41,    72,     6,    41,    72,     6,    41,    72,     6,    41,
      72,     6,    41,    72,     6,    41,    72,     6,    41,    72,
       6,    41,    72,     6,    41,    72,    41,    72,    41,    72,
      41,    72,    40,    41,    45,    45,    45,    42,    10,    10,
      42,    42,    44,    71,     6,    42,    40,    54,    42,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    72,    66,    73,    67,    67,    43,    43,
      15,    45,    43,    72,    42,    42,    42,    42,    42,    42,
      42,    42,    42,    42,    42,    42,    42,    45,    45,    42,
       6,    54,    54,    41,     6,    18,    29,    63,    45,    43,
      45,    10,    44,    44,    71,    40,    71,    72,    46,    44,
      54,    66,    12,    42,    71,    46,    46,    54,    44,    43,
      45,    42,    54,    54,    54,    43,    63,    63,    44,    54,
      44
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
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
<<<<<<< HEAD
#line 88 "parser.y"
    {printf("stmt_list\n");;}
    break;

  case 3:

/* Line 1455 of yacc.c  */
#line 89 "parser.y"
    {printf("{stmt_list}\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 90 "parser.y"
=======
#line 87 "./parser.y"
    {printf("stmt_list\n");;}
    break;

  case 4:

/* Line 1455 of yacc.c  */
#line 89 "./parser.y"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    {printf("stmt epsilon\n");;}
    break;

  case 5:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 98 "parser.y"
    {printf("if statement\n");;}
=======
#line 93 "./parser.y"
    {printf("{scope}\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 6:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 99 "parser.y"
    {printf("while statement\n");;}
=======
#line 106 "./parser.y"
    {printf("if statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 7:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 100 "parser.y"
    {printf("repeat statement\n");;}
=======
#line 107 "./parser.y"
    {printf("while statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 8:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 101 "parser.y"
    {printf("for statement\n");;}
=======
#line 108 "./parser.y"
    {printf("repeat statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 9:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 102 "parser.y"
    {printf("switch statement\n");;}
=======
#line 109 "./parser.y"
    {printf("for statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 10:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 103 "parser.y"
    {printf("function declaration\n");;}
=======
#line 110 "./parser.y"
    {printf("switch statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 11:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 105 "parser.y"
    {printf("variable declaration\n");;}
=======
#line 111 "./parser.y"
    {printf("function declaration\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 12:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 106 "parser.y"
    {printf("constant declaration\n");;}
=======
#line 113 "./parser.y"
    {printf("variable declaration\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 13:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 107 "parser.y"
    {printf("assignment statement\n");;}
=======
#line 114 "./parser.y"
    {printf("constant declaration\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 14:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 108 "parser.y"
    {printf("expression\n");;}
=======
#line 115 "./parser.y"
    {printf("assignment statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 15:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 109 "parser.y"
    {printf("return statement\n");;}
=======
#line 116 "./parser.y"
    {printf("expression\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 16:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 110 "parser.y"
    {printf("break statement\n");;}
=======
#line 117 "./parser.y"
    {printf("return statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 17:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 111 "parser.y"
    {printf("continue statement\n");;}
=======
#line 118 "./parser.y"
    {printf("break statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 18:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 114 "parser.y"
    {printf("return\n");          ;}
=======
#line 119 "./parser.y"
    {printf("continue statement\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 19:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 115 "parser.y"
    {printf("return term\n"); ;}
=======
#line 122 "./parser.y"
    {printf("return\n");          ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 20:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 116 "parser.y"
    {printf("return expr\n"); ;}
=======
#line 123 "./parser.y"
    {printf("return term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 21:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 124 "parser.y"
    {printf("if (expr) {stmt_list}\n");;}
=======
#line 124 "./parser.y"
    {printf("return expr\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 22:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 125 "parser.y"
    {printf("if (expr) {stmt_list} else {stmt_list}\n");;}
=======
#line 132 "./parser.y"
    {printf("if (expr) {stmt_list}\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 23:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 128 "parser.y"
    {printf("while (expr) {stmt_list}\n");;}
=======
#line 133 "./parser.y"
    {printf("if (expr) {stmt_list} else {stmt_list}\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 24:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 131 "parser.y"
    {printf("repeat {stmt_list} until (expr)\n");;}
=======
#line 136 "./parser.y"
    {printf("while (expr) {stmt_list}\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 25:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 134 "parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n"); ;}
=======
#line 139 "./parser.y"
    {printf("repeat {stmt_list} until (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 26:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 137 "parser.y"
    {printf("switch (expr) {case_list}\n"); ;}
=======
#line 142 "./parser.y"
    {printf("for (assignment; expr; assignment) {stmt_list}\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 27:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 140 "parser.y"
    {printf("case expr: stmt_list case_list\n"); ;}
=======
#line 145 "./parser.y"
    {printf("switch (expr) {case_list}\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 28:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 141 "parser.y"
    {printf("case term: stmt_list case_list\n"); ;}
=======
#line 148 "./parser.y"
    {printf("case expr: stmt_list case_list\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 29:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 142 "parser.y"
    {printf("case expr: stmt_list\n");           ;}
=======
#line 149 "./parser.y"
    {printf("case term: stmt_list case_list\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 30:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 143 "parser.y"
    {printf("case term: stmt_list\n");           ;}
=======
#line 150 "./parser.y"
    {printf("case expr: stmt_list\n");           ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 31:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 144 "parser.y"
    {printf("default: stmt_list\n");             ;}
=======
#line 151 "./parser.y"
    {printf("case term: stmt_list\n");           ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 32:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 147 "parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");  add('F', (yyvsp[(2) - (8)].str), (yyvsp[(1) - (8)].str));;}
=======
#line 152 "./parser.y"
    {printf("default: stmt_list\n");             ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 33:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 148 "parser.y"
    {printf("data_type identifier () {stmt_list}\n");                add('F', (yyvsp[(2) - (6)].str), (yyvsp[(1) - (6)].str));;}
=======
#line 155 "./parser.y"
    {printf("data_type identifier (dec_param_list) {stmt_list}\n");  add('F', (yyvsp[(2) - (8)].str), (yyvsp[(1) - (8)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 34:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 151 "parser.y"
    {printf("identifier (call_param_list) ;\n"); add('F', (yyvsp[(1) - (4)].str), "N/A");;}
=======
#line 156 "./parser.y"
    {printf("data_type identifier () {stmt_list}\n");                add('F', (yyvsp[(2) - (6)].str), (yyvsp[(1) - (6)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 35:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 152 "parser.y"
    {printf("identifier () ;\n");                add('F', (yyvsp[(1) - (3)].str), "N/A");;}
=======
#line 159 "./parser.y"
    {printf("identifier (call_param_list) ;\n"); add('F', (yyvsp[(1) - (4)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 36:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 160 "parser.y"
    {printf("data_type identifier , dec_param_list\n");  add('V', (yyvsp[(2) - (4)].str), (yyvsp[(1) - (4)].str));;}
=======
#line 160 "./parser.y"
    {printf("identifier () ;\n");                add('F', (yyvsp[(1) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 37:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 161 "parser.y"
    {printf("data_type identifier\n");                   add('V', (yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].str));;}
=======
#line 168 "./parser.y"
    {printf("data_type identifier , dec_param_list\n");  add('V', (yyvsp[(2) - (4)].str), (yyvsp[(1) - (4)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 38:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 164 "parser.y"
    {printf("identifier , call_param_list\n");;}
=======
#line 169 "./parser.y"
    {printf("data_type identifier\n");                   add('V', (yyvsp[(2) - (2)].str), (yyvsp[(1) - (2)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 39:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 165 "parser.y"
    {printf("data_type identifier\n");;}
=======
#line 172 "./parser.y"
    {printf("identifier , call_param_list\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 40:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 166 "parser.y"
    {printf("term , call_param_list\n");;}
=======
#line 173 "./parser.y"
    {printf("data_type identifier\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 41:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 167 "parser.y"
    {printf("term\n");;}
=======
#line 174 "./parser.y"
    {printf("term , call_param_list\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 42:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 174 "parser.y"
    {printf("data_type identifier; \n");         add('V', (yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].str));;}
=======
#line 175 "./parser.y"
    {printf("term\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 43:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 175 "parser.y"
    {printf("%s %s %s Term;\n",(yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str));      add('V', (yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].str)); ;}
=======
#line 182 "./parser.y"
    {printf("data_type identifier; \n");         add('V', (yyvsp[(2) - (3)].str), (yyvsp[(1) - (3)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 44:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 176 "parser.y"
    {printf("data_type identifier = expr ;\n");  add('V', (yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].str)); ;}
=======
#line 183 "./parser.y"
    {printf("%s %s %s Term;\n",(yyvsp[(1) - (5)].str), (yyvsp[(2) - (5)].str), (yyvsp[(3) - (5)].str));      add('V', (yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].str)); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 45:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 183 "parser.y"
    {printf("const data_type identifier = term ;\n"); add('V', (yyvsp[(3) - (6)].str), (yyvsp[(2) - (6)].str));;}
=======
#line 184 "./parser.y"
    {printf("data_type identifier = expr ;\n");  add('V', (yyvsp[(2) - (5)].str), (yyvsp[(1) - (5)].str)); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 46:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 190 "parser.y"
    {printf("identifier = term ;\n");   add('V', (yyvsp[(1) - (4)].str), "N/A");;}
=======
#line 191 "./parser.y"
    {printf("const data_type identifier = term ;\n"); add('V', (yyvsp[(3) - (6)].str), (yyvsp[(2) - (6)].str));;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 47:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 191 "parser.y"
    {printf("identifier = expr ;\n");   add('V', (yyvsp[(1) - (4)].str), "N/A");;}
=======
#line 199 "./parser.y"
    {printf("identifier = term ;\n");   add('V', (yyvsp[(1) - (4)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 48:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 199 "parser.y"
    {printf("expr == identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 200 "./parser.y"
    {printf("identifier = expr ;\n");   add('V', (yyvsp[(1) - (4)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 49:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 200 "parser.y"
    {printf("expr != identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 208 "./parser.y"
    {printf("expr == identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 50:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 201 "parser.y"
    {printf("expr < identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 209 "./parser.y"
    {printf("expr != identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 51:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 202 "parser.y"
    {printf("expr > identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 210 "./parser.y"
    {printf("expr < identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 52:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 203 "parser.y"
    {printf("expr <= identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 211 "./parser.y"
    {printf("expr > identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 53:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 204 "parser.y"
    {printf("expr >= identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 212 "./parser.y"
    {printf("expr <= identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 54:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 205 "parser.y"
    {printf("expr / identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 213 "./parser.y"
    {printf("expr >= identifer\n");  add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 55:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 206 "parser.y"
    {printf("expr * identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 214 "./parser.y"
    {printf("expr / identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 56:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 207 "parser.y"
    {printf("expr - identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 215 "./parser.y"
    {printf("expr * identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 57:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 208 "parser.y"
    {printf("expr + identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
=======
#line 216 "./parser.y"
    {printf("expr - identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 58:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 209 "parser.y"
    {printf("unary expr\n");     add('V', (yyvsp[(2) - (2)].str), "N/A");;}
=======
#line 217 "./parser.y"
    {printf("expr + identifer\n");   add('V', (yyvsp[(3) - (3)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 59:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 210 "parser.y"
    {printf("identifer unary\n");add('V', (yyvsp[(1) - (2)].str), "N/A");;}
=======
#line 218 "./parser.y"
    {printf("unary expr\n");     add('V', (yyvsp[(2) - (2)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 60:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 211 "parser.y"
    {printf("expr + term\n");  ;}
=======
#line 219 "./parser.y"
    {printf("identifer unary\n");add('V', (yyvsp[(1) - (2)].str), "N/A");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 61:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 212 "parser.y"
    {printf("expr - term\n");  ;}
=======
#line 220 "./parser.y"
    {printf("expr + term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 62:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 213 "parser.y"
    {printf("expr * term\n");  ;}
=======
#line 221 "./parser.y"
    {printf("expr - term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 63:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 214 "parser.y"
    {printf("expr / term\n");  ;}
=======
#line 222 "./parser.y"
    {printf("expr * term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 64:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 215 "parser.y"
    {printf("expr == term\n"); ;}
=======
#line 223 "./parser.y"
    {printf("expr / term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 65:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 216 "parser.y"
    {printf("expr != term\n"); ;}
=======
#line 224 "./parser.y"
    {printf("expr == term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 66:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 217 "parser.y"
    {printf("expr < term\n");  ;}
=======
#line 225 "./parser.y"
    {printf("expr != term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 67:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 218 "parser.y"
    {printf("expr > term\n");  ;}
=======
#line 226 "./parser.y"
    {printf("expr < term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 68:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 219 "parser.y"
    {printf("expr <= term\n"); ;}
=======
#line 227 "./parser.y"
    {printf("expr > term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 69:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 220 "parser.y"
    {printf("expr >= term\n"); ;}
=======
#line 228 "./parser.y"
    {printf("expr <= term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 70:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 221 "parser.y"
    {printf("expr ^ term\n");  ;}
=======
#line 229 "./parser.y"
    {printf("expr >= term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 71:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 222 "parser.y"
    {printf("expr && term\n"); ;}
=======
#line 230 "./parser.y"
    {printf("expr ^ term\n");  ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 72:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 223 "parser.y"
    {printf("expr || term\n"); ;}
=======
#line 231 "./parser.y"
    {printf("expr && term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 73:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 224 "parser.y"
    {printf("!term\n");        ;}
=======
#line 232 "./parser.y"
    {printf("expr || term\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 74:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 225 "parser.y"
    {printf("(expr)\n");;}
=======
#line 233 "./parser.y"
    {printf("!term\n");        ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 75:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 226 "parser.y"
    {printf("expr + (expr)\n"); ;}
=======
#line 234 "./parser.y"
    {printf("(expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 76:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 227 "parser.y"
    {printf("expr - (expr)\n"); ;}
=======
#line 235 "./parser.y"
    {printf("expr + (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 77:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 228 "parser.y"
    {printf("expr * (expr)\n"); ;}
=======
#line 236 "./parser.y"
    {printf("expr - (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 78:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 229 "parser.y"
    {printf("expr / (expr)\n"); ;}
=======
#line 237 "./parser.y"
    {printf("expr * (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 79:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 230 "parser.y"
    {printf("expr == (expr)\n");;}
=======
#line 238 "./parser.y"
    {printf("expr / (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 80:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 231 "parser.y"
    {printf("expr != (expr)\n");;}
=======
#line 239 "./parser.y"
    {printf("expr == (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 81:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 232 "parser.y"
    {printf("expr < (expr)\n"); ;}
=======
#line 240 "./parser.y"
    {printf("expr != (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 82:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 233 "parser.y"
    {printf("expr > (expr)\n"); ;}
=======
#line 241 "./parser.y"
    {printf("expr < (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 83:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 234 "parser.y"
    {printf("expr <= (expr)\n");;}
=======
#line 242 "./parser.y"
    {printf("expr > (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 84:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 235 "parser.y"
    {printf("expr >= (expr)\n");;}
=======
#line 243 "./parser.y"
    {printf("expr <= (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 85:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 236 "parser.y"
    {printf("expr ^ (expr)\n"); ;}
=======
#line 244 "./parser.y"
    {printf("expr >= (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 86:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 237 "parser.y"
    {printf("expr && (expr)\n");;}
=======
#line 245 "./parser.y"
    {printf("expr ^ (expr)\n"); ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 87:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 238 "parser.y"
    {printf("expr || (expr)\n");;}
=======
#line 246 "./parser.y"
    {printf("expr && (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 88:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 239 "parser.y"
    {printf("! (expr)\n");      ;}
=======
#line 247 "./parser.y"
    {printf("expr || (expr)\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 89:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 240 "parser.y"
    {printf("identifier\n");    ;}
=======
#line 248 "./parser.y"
    {printf("! (expr)\n");      ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 90:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 241 "parser.y"
    {printf("function call\n");;}
=======
#line 249 "./parser.y"
    {printf("identifier\n");    ;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 91:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 253 "parser.y"
    {printf("number\n");;}
=======
#line 250 "./parser.y"
    {printf("function call\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 92:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 254 "parser.y"
    {printf("true\n");;}
=======
#line 262 "./parser.y"
    {printf("number\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 93:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 255 "parser.y"
    {printf("false\n");;}
=======
#line 263 "./parser.y"
    {printf("true\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 94:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 256 "parser.y"
    {printf("char\n");;}
=======
#line 264 "./parser.y"
    {printf("false\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 95:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 257 "parser.y"
    {printf("string\n");;}
=======
#line 265 "./parser.y"
    {printf("char\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 96:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 258 "parser.y"
    {printf("float\n");;}
=======
#line 266 "./parser.y"
    {printf("string\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 97:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 263 "parser.y"
    {printf("int\n");    (yyval.str) = (yyvsp[(1) - (1)].str);}
=======
#line 267 "./parser.y"
    {printf("float\n");;}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 98:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 264 "parser.y"
    {printf("bool\n");   (yyval.str) = (yyvsp[(1) - (1)].str);}
=======
#line 272 "./parser.y"
    {printf("int\n");    (yyval.str) = (yyvsp[(1) - (1)].str);}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 99:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 265 "parser.y"
    {printf("char\n");   (yyval.str) = (yyvsp[(1) - (1)].str);}
=======
#line 273 "./parser.y"
    {printf("bool\n");   (yyval.str) = (yyvsp[(1) - (1)].str);}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 100:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 266 "parser.y"
    {printf("string\n"); (yyval.str) = (yyvsp[(1) - (1)].str);}
=======
#line 274 "./parser.y"
    {printf("char\n");   (yyval.str) = (yyvsp[(1) - (1)].str);}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 101:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 267 "parser.y"
    {printf("float\n");  (yyval.str) = (yyvsp[(1) - (1)].str);}
=======
#line 275 "./parser.y"
    {printf("string\n"); (yyval.str) = (yyvsp[(1) - (1)].str);}
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    break;

  case 102:

/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 268 "parser.y"
=======
#line 276 "./parser.y"
    {printf("float\n");  (yyval.str) = (yyvsp[(1) - (1)].str);;}
    break;

  case 103:

/* Line 1455 of yacc.c  */
#line 277 "./parser.y"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
    {printf("void\n");   (yyval.str) = (yyvsp[(1) - (1)].str);}
    break;



/* Line 1455 of yacc.c  */
<<<<<<< HEAD
#line 2468 "parser.tab.c"
=======
#line 2475 "parser.tab.c"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad
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
<<<<<<< HEAD
#line 270 "parser.y"
=======
#line 279 "./parser.y"
>>>>>>> 59fc53211c0ff0b454cfae0354276dc86a9e1aad

char * charToString(char c) {
    static char str[2]; // Make sure it's large enough to hold the character and the null terminator
    str[0] = c;
    str[1] = '\0'; // Null-terminate the string
    return str;
}

nodeType *con(int value) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeCon;
    p->con.value = value;

    return p;
}

nodeType *id(int i) {
    nodeType *p;

    /* allocate node */
    if ((p = malloc(sizeof(nodeType))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeId;
    p->id.i = i;

    return p;
}

nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    int i;

    /* allocate node, extending op array */
    if ((p = malloc(sizeof(nodeType) + (nops-1) * sizeof(nodeType *))) == NULL)
        yyerror("out of memory");

    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}
void add(char c, char * name, char * type){
    if(c == 'V'){ //variable
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].data_type = type;
        symbol_table[symbol_count].type = "Variable";
        symbol_table[symbol_count].line_no = countn;
        symbol_count++;
    }
    else if(c == 'F'){
        symbol_table[symbol_count].name = name;
        symbol_table[symbol_count].data_type = type;
        symbol_table[symbol_count].type = "Function";
        symbol_table[symbol_count].line_no = countn;
        symbol_count++; 
    }
    printf("current symbol count = %d\n", symbol_count);
}
/*
yyerror: This function is called when there's a syntax error in the input.
It prints an error message and exits the program.
*/
void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
    /* exit(1); */
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
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUMBER \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<symbol_count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<symbol_count;i++) {
		free(symbol_table[i].name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
    return 0;
}

/* int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
} */
