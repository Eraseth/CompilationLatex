/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

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

/* Line 268 of yacc.c  */
#line 1 "latex.y"

  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #include "include/expression_arithm.h"
  #include "include/gen_assembleur.h"
  #include "y.tab.h"

  #define TEXCC_ERROR_GENERAL 4

  //Notre liste chaînée TDS
  tableSymbole tableS = NULL;
  quad_list code = NULL;
  //Compteur pour la création de variable temporaire
  int compteurTemporaire = 0;

  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;

  void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
    exit(EXIT_FAILURE);
  }

  char * conversion_int_string()
  {
    char * str = malloc(sizeof(char)*64);
    sprintf(str,"%d",compteurTemporaire);
    return str;
  }

  char * generate_temp_name(){
    char * str = malloc(sizeof(char)*64);
    char * str2 = conversion_int_string(compteurTemporaire);
    strcat(str, "temp");
    strcat(str,str2);
    free(str2);
    compteurTemporaire++;
    return str;
  }



/* Line 268 of yacc.c  */
#line 120 "y.tab.c"

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
     TEXSCI_BEGIN = 258,
     TEXSCI_END = 259,
     BLANKLINE = 260,
     LEFTARROW = 261,
     IN = 262,
     MBOX = 263,
     INTEGER = 264,
     COMMENTAIRE = 265,
     BOOLEAN = 266,
     REAL = 267,
     EMPTYSET = 268,
     WHILE = 269,
     FOR = 270,
     KWTO = 271,
     IF = 272,
     ELSEIF = 273,
     DECLARECONSTANT = 274,
     DECLAREINPUT = 275,
     DECLAREOUTPUT = 276,
     DECLAREGLOBAL = 277,
     DECLARELOCAL = 278,
     NO = 279,
     ET = 280,
     OU = 281,
     EGAL = 282,
     SUP = 283,
     INF = 284,
     INFEGAL = 285,
     SUPEGAL = 286,
     PRINTINT = 287,
     PRINTTEXT = 288,
     PRINTREAL = 289,
     CONSTINT = 290,
     CONSTBOOL = 291,
     DIV = 292,
     CONSTFLOAT = 293,
     MULT = 294,
     MINUS = 295,
     PLUS = 296,
     EOI = 297,
     ID = 298
   };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define LEFTARROW 261
#define IN 262
#define MBOX 263
#define INTEGER 264
#define COMMENTAIRE 265
#define BOOLEAN 266
#define REAL 267
#define EMPTYSET 268
#define WHILE 269
#define FOR 270
#define KWTO 271
#define IF 272
#define ELSEIF 273
#define DECLARECONSTANT 274
#define DECLAREINPUT 275
#define DECLAREOUTPUT 276
#define DECLAREGLOBAL 277
#define DECLARELOCAL 278
#define NO 279
#define ET 280
#define OU 281
#define EGAL 282
#define SUP 283
#define INF 284
#define INFEGAL 285
#define SUPEGAL 286
#define PRINTINT 287
#define PRINTTEXT 288
#define PRINTREAL 289
#define CONSTINT 290
#define CONSTBOOL 291
#define DIV 292
#define CONSTFLOAT 293
#define MULT 294
#define MINUS 295
#define PLUS 296
#define EOI 297
#define ID 298




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 49 "latex.y"

  char* name;
  int value;
  float dvalue;
  struct {
      union {
        int valInt;
        float valFloat;
      } valUnion;
      int type;
    } valeurSt;
    expr_arithm expr_arithm;



/* Line 293 of yacc.c  */
#line 258 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 270 "y.tab.c"

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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
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

# define YYCOPY_NEEDED 1

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

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
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
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   125

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  56
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  56
/* YYNRULES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   298

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      51,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    52,     2,     2,     2,
      53,    54,    47,    45,    55,    46,     2,    48,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    44,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    49,     2,    50,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    17,    19,    20,    27,    33,
      35,    37,    41,    51,    61,    63,    65,    67,    69,    73,
      75,    79,    81,    85,    87,    89,    91,    93,    95,    97,
      99,   107,   115,   116,   124,   125,   133,   134,   142,   143,
     151,   152,   156,   158,   160,   161,   165,   167,   169,   170,
     176,   180,   182,   184,   186,   188,   190
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      57,     0,    -1,    57,    58,    -1,    58,    -1,     3,    49,
      43,    50,    51,    72,    59,     4,    -1,    60,    -1,    -1,
      52,    61,    52,    42,    51,    60,    -1,    52,    61,    52,
      42,    51,    -1,    62,    -1,    63,    -1,    43,    71,    66,
      -1,     8,    49,    32,    53,    52,    64,    52,    54,    50,
      -1,     8,    49,    34,    53,    52,    65,    52,    54,    50,
      -1,    35,    -1,    43,    -1,    38,    -1,    43,    -1,    66,
      70,    67,    -1,    67,    -1,    67,    69,    68,    -1,    68,
      -1,    53,    66,    54,    -1,    82,    -1,    43,    -1,    37,
      -1,    39,    -1,    41,    -1,    40,    -1,     6,    -1,    73,
      74,    75,    76,    77,     5,    51,    -1,    19,    49,    52,
      78,    52,    50,    51,    -1,    -1,    20,    49,    52,    79,
      52,    50,    51,    -1,    -1,    21,    49,    52,    81,    52,
      50,    51,    -1,    -1,    22,    49,    52,    79,    52,    50,
      51,    -1,    -1,    23,    49,    52,    79,    52,    50,    51,
      -1,    -1,    80,    55,    78,    -1,    80,    -1,    13,    -1,
      -1,    81,    55,    79,    -1,    81,    -1,    13,    -1,    -1,
      43,    27,    82,     7,    83,    -1,    43,     7,    83,    -1,
      35,    -1,    38,    -1,    36,    -1,     9,    -1,    11,    -1,
      12,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    86,    93,   103,   108,   111,   116,   122,
     127,   133,   165,   177,   183,   187,   204,   208,   214,   246,
     252,   284,   290,   295,   318,   330,   335,   341,   346,   352,
     358,   365,   369,   372,   376,   379,   383,   386,   390,   393,
     397,   400,   405,   409,   413,   416,   421,   425,   429,   432,
     454,   476,   481,   486,   493,   497,   501
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXSCI_BEGIN", "TEXSCI_END",
  "BLANKLINE", "LEFTARROW", "IN", "MBOX", "INTEGER", "COMMENTAIRE",
  "BOOLEAN", "REAL", "EMPTYSET", "WHILE", "FOR", "KWTO", "IF", "ELSEIF",
  "DECLARECONSTANT", "DECLAREINPUT", "DECLAREOUTPUT", "DECLAREGLOBAL",
  "DECLARELOCAL", "NO", "ET", "OU", "EGAL", "SUP", "INF", "INFEGAL",
  "SUPEGAL", "PRINTINT", "PRINTTEXT", "PRINTREAL", "CONSTINT", "CONSTBOOL",
  "DIV", "CONSTFLOAT", "MULT", "MINUS", "PLUS", "EOI", "ID", "'='", "'+'",
  "'-'", "'*'", "'/'", "'{'", "'}'", "'\\n'", "'$'", "'('", "')'", "','",
  "$accept", "algorithm_list", "algorithm", "zone_instructions",
  "list_instructions", "instruction", "instruction_affectation",
  "instruction_fonction", "argument_entier", "argument_real",
  "expression_arithmetique", "expression_arithmetique_t",
  "expression_arithmetique_f", "operateur_f", "operateur_m",
  "operateur_affectation", "zone_declarations",
  "zone_declaration_constante", "zone_declaration_input",
  "zone_declaration_output", "zone_declaration_global",
  "zone_declaration_local", "suite_declarations_constante",
  "suite_declarations_variable", "declaration_constante",
  "declaration_variable", "valeur", "type", 0
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
     295,   296,   297,   298,    61,    43,    45,    42,    47,   123,
     125,    10,    36,    40,    41,    44
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    56,    57,    57,    58,    59,    59,    60,    60,    61,
      61,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      67,    67,    68,    68,    68,    69,    69,    70,    70,    71,
      72,    73,    73,    74,    74,    75,    75,    76,    76,    77,
      77,    78,    78,    78,    78,    79,    79,    79,    79,    80,
      81,    82,    82,    82,    83,    83,    83
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     8,     1,     0,     6,     5,     1,
       1,     3,     9,     9,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       7,     7,     0,     7,     0,     7,     0,     7,     0,     7,
       0,     3,     1,     1,     0,     3,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     0,    32,
       0,     6,    34,     0,     0,     0,     5,     0,    36,    44,
       0,     0,     0,     9,    10,     4,     0,     0,    38,    43,
       0,     0,    42,     0,    29,     0,     0,    48,     0,     0,
      40,     0,     0,    44,     0,     0,    51,    53,    52,    24,
       0,    11,    19,    21,    23,     0,    47,     0,     0,    46,
       0,     0,     0,     0,     0,     0,    41,     0,     0,     0,
      28,    27,     0,    25,    26,     0,     8,     0,     0,    48,
       0,    48,     0,     0,     0,    31,     0,     0,    22,    18,
      20,     7,    54,    55,    56,    50,     0,    45,     0,     0,
      48,    30,    49,    14,    15,     0,    16,    17,     0,    33,
       0,     0,     0,     0,     0,    35,     0,     0,     0,     0,
      37,     0,    12,    13,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,    15,    16,    22,    23,    24,   105,   108,
      51,    52,    53,    75,    72,    35,    11,    12,    18,    28,
      40,    63,    31,    58,    32,    59,    54,    95
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -77
static const yytype_int8 yypact[] =
{
       6,   -20,    23,   -77,   -21,   -77,   -77,   -17,   -14,    21,
      -7,    -9,    24,    -6,    -8,    37,   -77,    -1,    26,   -12,
       0,    39,     1,   -77,   -77,   -77,     2,     3,    28,   -77,
      29,     5,     4,    -4,   -77,   -28,    13,   -11,     8,    12,
      35,   -19,    14,   -12,    10,    15,   -77,   -77,   -77,   -77,
     -28,    -2,    -3,   -77,   -77,    11,   -77,    44,    17,    16,
      22,    18,    25,    61,    60,    27,   -77,    20,    30,   -27,
     -77,   -77,   -28,   -77,   -77,   -28,    -9,     9,    31,   -11,
      32,   -11,    33,    36,     9,   -77,   -31,   -32,   -77,    -3,
     -77,   -77,   -77,   -77,   -77,   -77,    38,   -77,    40,    34,
     -11,   -77,   -77,   -77,   -77,    41,   -77,   -77,    42,   -77,
      45,    47,    43,    19,    46,   -77,    48,    51,    52,    53,
     -77,    54,   -77,   -77,   -77
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -77,   -77,    73,   -77,     7,   -77,   -77,   -77,   -77,   -77,
      56,    49,    50,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     -77,   -77,    55,   -76,   -77,    57,    63,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -1
static const yytype_uint8 yytable[] =
{
      20,    29,    56,    97,   103,    99,   106,    46,    47,     1,
      48,   107,   104,    70,    71,    49,    46,    47,    92,    48,
      93,    94,     7,     5,   112,    50,     1,    88,    44,     4,
      45,    30,    57,     8,    73,    21,    74,     9,    70,    71,
      10,    25,    13,    14,    17,    34,    19,    27,    26,    33,
      39,    77,    38,    36,    37,    55,    41,    42,    62,    43,
      60,    61,    76,    67,    65,    57,    83,    84,    68,    78,
      81,    79,    86,   118,    82,     6,     0,     0,    85,   102,
       0,    96,    87,    91,    98,   100,   111,   101,     0,   109,
     110,     0,     0,   113,   114,   117,   115,   116,    66,   120,
     119,   121,   122,   123,    64,   124,    69,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    80,     0,     0,
       0,    89,     0,     0,     0,    90
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-77))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int8 yycheck[] =
{
       8,    13,    13,    79,    35,    81,    38,    35,    36,     3,
      38,    43,    43,    40,    41,    43,    35,    36,     9,    38,
      11,    12,    43,     0,   100,    53,     3,    54,    32,    49,
      34,    43,    43,    50,    37,    43,    39,    51,    40,    41,
      19,     4,    49,    52,    20,     6,    52,    21,    49,    49,
      22,     7,    49,    52,    52,    42,    27,    52,    23,    55,
      52,    49,    51,    53,    50,    43,     5,     7,    53,    52,
      52,    55,    52,    54,    49,     2,    -1,    -1,    51,    84,
      -1,    50,    52,    76,    52,    52,    52,    51,    -1,    51,
      50,    -1,    -1,    52,    52,    52,    51,    50,    43,    51,
      54,    50,    50,    50,    41,    51,    50,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    60,    -1,    -1,
      -1,    72,    -1,    -1,    -1,    75
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    57,    58,    49,     0,    58,    43,    50,    51,
      19,    72,    73,    49,    52,    59,    60,    20,    74,    52,
       8,    43,    61,    62,    63,     4,    49,    21,    75,    13,
      43,    78,    80,    49,     6,    71,    52,    52,    49,    22,
      76,    27,    52,    55,    32,    34,    35,    36,    38,    43,
      53,    66,    67,    68,    82,    42,    13,    43,    79,    81,
      52,    49,    23,    77,    82,    50,    78,    53,    53,    66,
      40,    41,    70,    37,    39,    69,    51,     7,    52,    55,
      81,    52,    49,     5,     7,    51,    52,    52,    54,    67,
      68,    60,     9,    11,    12,    83,    50,    79,    52,    79,
      52,    51,    83,    35,    43,    64,    38,    43,    65,    51,
      50,    52,    79,    52,    52,    51,    50,    52,    54,    54,
      51,    50,    50,    50,    51
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
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
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


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
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
  if (yypact_value_is_default (yyn))
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
      if (yytable_value_is_error (yyn))
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
        case 3:

/* Line 1806 of yacc.c  */
#line 87 "latex.y"
    {
    printf("Algorithm Found !");
  }
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 94 "latex.y"
    {
      //fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      //free($3);
      printf("ALGORITHM\n");
    }
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 104 "latex.y"
    {
    printf("Liste d'instructions\n");
  }
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 108 "latex.y"
    { ; }
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 112 "latex.y"
    {
    printf("list_instructions");
  }
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 117 "latex.y"
    {
    printf("list_instructions");
  }
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 123 "latex.y"
    {
    printf("Instruction Affectation");
  }
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 128 "latex.y"
    {
    printf("Instruction Fonction");
  }
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 134 "latex.y"
    {
    variable var = lookup_tds(tableS, (yyvsp[(1) - (3)].name));
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[(1) - (3)].name));
      exit(EXIT_FAILURE);
    }

    //Ajout du code de l'expression arithmétiques
    code = add_quad_list(code,(yyvsp[(3) - (3)].expr_arithm)->code);
    quad_list ql;
    quad q;
    //Convertit le type pour permettre l'Assignation
    if((var->type == TYPE_INT || var->type == TYPE_BOOL) && (yyvsp[(3) - (3)].expr_arithm)->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, (yyvsp[(3) - (3)].expr_arithm)->resultat, NULL, var);
      ql = add_quad(NULL,q);
    } else if(((yyvsp[(3) - (3)].expr_arithm)->resultat->type == TYPE_INT || (yyvsp[(3) - (3)].expr_arithm)->resultat->type == TYPE_BOOL) && var->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, (yyvsp[(3) - (3)].expr_arithm)->resultat, NULL, var);
      ql = add_quad(NULL,q);
    } else {
      q = new_quad((yyvsp[(2) - (3)].value),(yyvsp[(3) - (3)].expr_arithm)->resultat,NULL,var);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(NULL,q);
    }

    print_quad_list(ql);
    code = add_quad_list(code,ql);
  }
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 166 "latex.y"
    {

      variable var = new_variable_int(generate_temp_name(compteurTemporaire),(yyvsp[(6) - (9)].value));
      tableS = add_variable(tableS, var);
      quad q = new_quad(PRINT_INT, var, var, var);

      quad_list ql = add_quad(NULL,q);
      code = add_quad_list(code,ql);

    }
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 178 "latex.y"
    {
      ;
    }
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 184 "latex.y"
    {
    (yyval.value) = yylval.value;
  }
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 188 "latex.y"
    {
    variable var = lookup_tds(tableS, (yyvsp[(1) - (1)].name));
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[(1) - (1)].name));
      exit(EXIT_FAILURE);
    }
    if(var->type != TYPE_INT)
    {
      printf("ERROR : printInt demande un type entier en argumet.\n");
      exit(EXIT_FAILURE);
    }
    (yyval.value) = var->val.iValue;
  }
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 205 "latex.y"
    {
  ;
}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 209 "latex.y"
    {
  ;//Vérifier le type de ID
}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 215 "latex.y"
    {
    if (((yyvsp[(1) - (3)].expr_arithm)->resultat->type) != ((yyvsp[(3) - (3)].expr_arithm)->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,(yyvsp[(1) - (3)].expr_arithm)->resultat->id,(yyvsp[(3) - (3)].expr_arithm)->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr_arithm expr_arithm;
    switch((yyvsp[(1) - (3)].expr_arithm)->resultat->type){
              case TYPE_INT:
              var = new_variable_int(generate_temp_name(compteurTemporaire),0);
              break;
              case TYPE_FLOAT:
              var = new_variable_float(generate_temp_name(compteurTemporaire),0);
              break;
              case TYPE_BOOL:
              var = new_variable_bool(generate_temp_name(compteurTemporaire),0);
              break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[(1) - (3)].expr_arithm)->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad((yyvsp[(2) - (3)].value),(yyvsp[(1) - (3)].expr_arithm)->resultat,(yyvsp[(3) - (3)].expr_arithm)->resultat,var);
      quad_list ql = add_quad(NULL,q);
      (yyval.expr_arithm) = new_expr_arithm(var,add_quad_list(add_quad_list((yyvsp[(1) - (3)].expr_arithm)->code,(yyvsp[(3) - (3)].expr_arithm)->code),ql));
      print_expr_arithm((yyval.expr_arithm));
  }
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 247 "latex.y"
    {
    (yyval.expr_arithm) = (yyvsp[(1) - (1)].expr_arithm);
  }
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 253 "latex.y"
    {
    if (((yyvsp[(1) - (3)].expr_arithm)->resultat->type) != ((yyvsp[(3) - (3)].expr_arithm)->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,(yyvsp[(1) - (3)].expr_arithm)->resultat->id,(yyvsp[(3) - (3)].expr_arithm)->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr_arithm expr_arithm;
    switch((yyvsp[(1) - (3)].expr_arithm)->resultat->type){
              case TYPE_INT:
              var = new_variable_int(generate_temp_name(compteurTemporaire),0);
              break;
              case TYPE_FLOAT:
              var = new_variable_float(generate_temp_name(compteurTemporaire),0);
              break;
              case TYPE_BOOL:
              var = new_variable_bool(generate_temp_name(compteurTemporaire),0);
              break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[(1) - (3)].expr_arithm)->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad((yyvsp[(2) - (3)].value),(yyvsp[(1) - (3)].expr_arithm)->resultat,(yyvsp[(3) - (3)].expr_arithm)->resultat,var);
      quad_list ql = add_quad(NULL,q);
      (yyval.expr_arithm) = new_expr_arithm(var,add_quad_list(add_quad_list((yyvsp[(1) - (3)].expr_arithm)->code,(yyvsp[(3) - (3)].expr_arithm)->code),ql));
      print_expr_arithm((yyval.expr_arithm));
  }
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 285 "latex.y"
    {
    (yyval.expr_arithm) =  (yyvsp[(1) - (1)].expr_arithm);
  }
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 291 "latex.y"
    {
    (yyval.expr_arithm) =  (yyvsp[(2) - (3)].expr_arithm);
  }
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 297 "latex.y"
    {
    variable var;
    switch((yyvsp[(1) - (1)].valeurSt).type){
              case TYPE_INT:
              var = new_variable_int(generate_temp_name(compteurTemporaire),(yyvsp[(1) - (1)].valeurSt).valUnion.valInt);
              break;
              case TYPE_FLOAT:
              var = new_variable_float(generate_temp_name(compteurTemporaire),(yyvsp[(1) - (1)].valeurSt).valUnion.valFloat);
              break;
              case TYPE_BOOL:
              var = new_variable_bool(generate_temp_name(compteurTemporaire),(yyvsp[(1) - (1)].valeurSt).valUnion.valInt);
              break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[(1) - (1)].valeurSt).type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      (yyval.expr_arithm) =  new_expr_arithm(var,NULL);
    }
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 319 "latex.y"
    {
      variable var = lookup_tds(tableS,(yyvsp[(1) - (1)].name));
      if(var == NULL){
        printf("ERROR : Variable %s non définie.\n", (yyvsp[(1) - (1)].name));
        exit(EXIT_FAILURE);
      }
      (yyval.expr_arithm) =  new_expr_arithm(var,NULL);
    }
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 331 "latex.y"
    {
    (yyval.value) = DIV;
  }
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 336 "latex.y"
    {
    (yyval.value) = MULT;
  }
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 342 "latex.y"
    {
    (yyval.value) = PLUS;
  }
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 347 "latex.y"
    {
    (yyval.value) = MINUS;
  }
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 353 "latex.y"
    {
    (yyval.value) = LEFTARROW;
  }
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 360 "latex.y"
    {
      printf("\nzone déclaration\n");
    }
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 366 "latex.y"
    {
      printf("\nzone déclaration DECLARECONSTANT\n");
    }
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 369 "latex.y"
    { ; }
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 373 "latex.y"
    {
      printf("\nzone déclaration DECLAREINPUT\n");
    }
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 376 "latex.y"
    { ; }
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 380 "latex.y"
    {
      printf("\nzone déclaration DECLAREOUTPUT\n");
    }
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 383 "latex.y"
    { ; }
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 387 "latex.y"
    {
      printf("\nzone déclaration DECLAREGLOBAL\n");
    }
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 390 "latex.y"
    { ; }
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 394 "latex.y"
    {
      printf("\nzone déclaration local\n");
    }
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 397 "latex.y"
    { ; }
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 401 "latex.y"
    {
      printf("\nsuite déclaration constante\n");
    }
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 406 "latex.y"
    {
      printf("\ndéclaration constante\n");
    }
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 410 "latex.y"
    {
      ;
    }
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 413 "latex.y"
    { ; }
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 417 "latex.y"
    {
      printf("\nsuite déclaration var\n");
    }
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 422 "latex.y"
    {
      printf("\ndéclaration var\n");
    }
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 426 "latex.y"
    {
      ;
    }
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 429 "latex.y"
    { ; }
    break;

  case 49:

/* Line 1806 of yacc.c  */
#line 433 "latex.y"
    {
      variable var;
      switch ((yyvsp[(5) - (5)].value)) {
        case INTEGER:
          var = new_variable_int((yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].valeurSt).valUnion.valInt);
          break;
        case BOOLEAN:
          var = new_variable_bool((yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].valeurSt).valUnion.valInt);
          break;
        case REAL:
          var = new_variable_float((yyvsp[(1) - (5)].name), (yyvsp[(3) - (5)].valeurSt).valUnion.valFloat);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_constante)\n", (yyvsp[(5) - (5)].value));
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
    }
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 455 "latex.y"
    {
      variable var;
      switch ((yyvsp[(3) - (3)].value)) {
        case INTEGER:
          var = new_variable_int((yyvsp[(1) - (3)].name), 0);
          break;
        case BOOLEAN:
          var = new_variable_bool((yyvsp[(1) - (3)].name), 0);
          break;
        case REAL:
          var = new_variable_float((yyvsp[(1) - (3)].name), 0.0);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_variable)\n", (yyvsp[(3) - (3)].value));
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
    }
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 477 "latex.y"
    {
      (yyval.valeurSt).valUnion.valInt = yylval.value;
      (yyval.valeurSt).type = TYPE_INT;
    }
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 482 "latex.y"
    {
      (yyval.valeurSt).valUnion.valFloat = yylval.dvalue;
      (yyval.valeurSt).type = TYPE_FLOAT;
    }
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 487 "latex.y"
    {
      (yyval.valeurSt).valUnion.valInt = yylval.value;
      (yyval.valeurSt).type = TYPE_BOOL;
    }
    break;

  case 54:

/* Line 1806 of yacc.c  */
#line 494 "latex.y"
    {
      (yyval.value) = INTEGER;
    }
    break;

  case 55:

/* Line 1806 of yacc.c  */
#line 498 "latex.y"
    {
      (yyval.value) = BOOLEAN;
    }
    break;

  case 56:

/* Line 1806 of yacc.c  */
#line 502 "latex.y"
    {
      (yyval.value) = REAL;
    }
    break;



/* Line 1806 of yacc.c  */
#line 2234 "y.tab.c"
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
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
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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
      if (!yypact_value_is_default (yyn))
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
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



/* Line 2067 of yacc.c  */
#line 506 "latex.y"


int main(int argc, char* argv[]) {
  FILE *fd = fopen("assembleur.s", "w+");
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(TEXCC_ERROR_GENERAL);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(TEXCC_ERROR_GENERAL);
  }

  yyparse();
  generate_text(fd, code);
  generate_data(fd, tableS);
  fclose(yyin);
  fclose(fd);
  texcc_lexer_free();
  print_tds(tableS);
  free_tds(tableS);
  return EXIT_SUCCESS;

}

