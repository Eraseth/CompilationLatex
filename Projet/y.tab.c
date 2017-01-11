/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "latex.y" /* yacc.c:339  */

  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #include "include/expression_arithm.h"
  #include "include/expression_bool.h"
  #include "include/gen_assembleur.h"
  #include "include/statement.h"
  #include "y.tab.h"
  #define TEXCC_ERROR_GENERAL 4
  #define VAR_BOOL_FALSE "var_bool_false"
  //Notre liste chaînée TDS
  tableSymbole tableS = NULL;
  quad_list code = NULL;
  //Compteur pour la création de variable temporaire
  int compteurTemporaire = 0;
  //Compteur pour le prochain quad (marqueur)
  int compteur_quad = 0;
  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;
  void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
    exit(EXIT_FAILURE);
  }
  char * generate_temp_name(){
    char * str = malloc(sizeof(char)*64*2);
    char * str2 = conversion_int_string(compteurTemporaire);
    strcat(str, "temp");
    strcat(str,str2);
    free(str2);
    compteurTemporaire++;
    return str;
  }

#line 106 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TEXSCI_BEGIN = 258,
    TEXSCI_END = 259,
    BLANKLINE = 260,
    LEFTARROW = 261,
    IN = 262,
    MBOX = 263,
    STRING = 264,
    INTEGER = 265,
    COMMENTAIRE = 266,
    BOOLEAN = 267,
    REAL = 268,
    EMPTYSET = 269,
    WHILE = 270,
    FOR = 271,
    KWTO = 272,
    IF = 273,
    ELSEIF = 274,
    DECLARECONSTANT = 275,
    DECLAREINPUT = 276,
    DECLAREOUTPUT = 277,
    DECLAREGLOBAL = 278,
    DECLARELOCAL = 279,
    NO = 280,
    ET = 281,
    OU = 282,
    EGAL = 283,
    SUP = 284,
    NOEGAL = 285,
    INF = 286,
    INFEGAL = 287,
    SUPEGAL = 288,
    PRINTINT = 289,
    PRINTTEXT = 290,
    PRINTREAL = 291,
    CONSTINT = 292,
    CONSTBOOL = 293,
    DIV = 294,
    CONSTFLOAT = 295,
    MULT = 296,
    MINUS = 297,
    PLUS = 298,
    EOI = 299,
    ID = 300
  };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define LEFTARROW 261
#define IN 262
#define MBOX 263
#define STRING 264
#define INTEGER 265
#define COMMENTAIRE 266
#define BOOLEAN 267
#define REAL 268
#define EMPTYSET 269
#define WHILE 270
#define FOR 271
#define KWTO 272
#define IF 273
#define ELSEIF 274
#define DECLARECONSTANT 275
#define DECLAREINPUT 276
#define DECLAREOUTPUT 277
#define DECLAREGLOBAL 278
#define DECLARELOCAL 279
#define NO 280
#define ET 281
#define OU 282
#define EGAL 283
#define SUP 284
#define NOEGAL 285
#define INF 286
#define INFEGAL 287
#define SUPEGAL 288
#define PRINTINT 289
#define PRINTTEXT 290
#define PRINTREAL 291
#define CONSTINT 292
#define CONSTBOOL 293
#define DIV 294
#define CONSTFLOAT 295
#define MULT 296
#define MINUS 297
#define PLUS 298
#define EOI 299
#define ID 300

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "latex.y" /* yacc.c:355  */

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
    expr_bool expr_bool;
    statement statement;
    variable var;

#line 253 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 270 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   213

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  53
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  201

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   300

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,    51,     2,     2,     2,
      47,    48,     2,     2,    52,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    46,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    84,    84,    85,    91,   100,   109,   112,   127,   137,
     143,   149,   156,   185,   192,   199,   209,   215,   231,   237,
     256,   278,   301,   349,   383,   415,   421,   459,   465,   470,
     494,   517,   528,   533,   538,   543,   548,   554,   568,   582,
     588,   595,   614,   631,   636,   641,   646,   651,   656,   662,
     669,   676,   680,   683,   687,   690,   694,   697,   701,   704,
     708,   711,   716,   720,   724,   727,   732,   736,   740,   743,
     765,   787,   792,   797,   804,   808,   812
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TEXSCI_BEGIN", "TEXSCI_END",
  "BLANKLINE", "LEFTARROW", "IN", "MBOX", "STRING", "INTEGER",
  "COMMENTAIRE", "BOOLEAN", "REAL", "EMPTYSET", "WHILE", "FOR", "KWTO",
  "IF", "ELSEIF", "DECLARECONSTANT", "DECLAREINPUT", "DECLAREOUTPUT",
  "DECLAREGLOBAL", "DECLARELOCAL", "NO", "ET", "OU", "EGAL", "SUP",
  "NOEGAL", "INF", "INFEGAL", "SUPEGAL", "PRINTINT", "PRINTTEXT",
  "PRINTREAL", "CONSTINT", "CONSTBOOL", "DIV", "CONSTFLOAT", "MULT",
  "MINUS", "PLUS", "EOI", "ID", "'='", "'('", "')'", "'{'", "'}'", "'$'",
  "','", "$accept", "algorithm_list", "algorithm", "zone_instructions",
  "list_instructions", "instruction", "instruction_affectation",
  "instruction_fonction", "argument_entier", "argument_real",
  "structure_controle", "expression_arithmetique",
  "expression_arithmetique_t", "expression_arithmetique_f", "operateur_f",
  "operateur_m", "operateur_affectation", "expr_boolean", "relop",
  "marqueur", "zone_declarations", "zone_declaration_constante",
  "zone_declaration_input", "zone_declaration_output",
  "zone_declaration_global", "zone_declaration_local",
  "suite_declarations_constante", "suite_declarations_variable",
  "declaration_constante", "declaration_variable", "valeur", "type", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,    61,    40,    41,   123,
     125,    36,    44
};
# endif

#define YYPACT_NINF -104

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-104)))

#define YYTABLE_NINF -9

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      66,   -42,    76,  -104,    37,  -104,  -104,    47,    68,    50,
      -7,    80,    51,  -104,    55,    60,    61,    -2,   107,  -104,
       0,  -104,    63,    91,    -4,    65,    67,    69,    70,    73,
     111,    74,    75,  -104,    -7,    78,    79,    96,  -104,    95,
      81,    82,    86,    88,    14,    14,    72,  -104,    58,    83,
      94,  -104,     1,    89,    90,   100,   -14,    93,    -4,    14,
     111,    14,  -104,  -104,  -104,    58,  -104,    14,    42,    19,
    -104,   -13,  -104,     2,    97,    98,    99,    58,    -6,  -104,
    -104,  -104,   134,   101,   102,   103,   104,   108,   142,   143,
    -104,  -104,     4,    58,  -104,  -104,    35,  -104,  -104,  -104,
    -104,  -104,  -104,  -104,  -104,  -104,    58,    58,  -104,  -104,
      58,  -104,  -104,   106,   109,   112,   114,   116,    38,    77,
     110,     1,   117,     1,   118,  -104,    77,   120,   -26,  -104,
      19,    -6,  -104,    14,    14,  -104,  -104,    12,   140,    -5,
    -104,  -104,  -104,  -104,  -104,  -104,   121,   123,     1,  -104,
    -104,   136,  -104,   125,   113,   126,  -104,  -104,   127,   128,
    -104,  -104,   129,  -104,   122,   130,   133,   132,    -7,    -7,
     137,   138,   139,  -104,   141,    -7,    58,   144,   145,   146,
     147,   148,  -104,   149,    -9,  -104,  -104,  -104,  -104,  -104,
    -104,   150,   135,  -104,    -7,   152,   153,    -7,  -104,   154,
    -104
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,    52,     0,
       6,    54,     0,    49,     0,     0,     0,     0,     0,     5,
      49,    11,     0,    56,    64,     0,     0,     0,     0,     0,
       0,     0,     0,     4,     0,     0,     0,    58,    63,     0,
       0,    62,     0,     0,     0,     0,     0,    36,     0,     0,
       0,     7,    68,     0,     0,    60,     0,     0,    64,     0,
       0,     0,    71,    73,    72,     0,    31,     0,    42,    25,
      27,     0,    30,     0,     0,     0,     0,     0,    12,     9,
      10,    67,     0,     0,    66,     0,     0,     0,     0,     0,
      51,    61,     0,     0,    40,    29,    42,    39,    43,    45,
      44,    46,    47,    48,    35,    34,     0,     0,    32,    33,
       0,    49,    49,     0,     0,     0,     0,     0,     0,     0,
       0,    68,     0,    68,     0,    50,     0,     0,     0,    28,
      24,    41,    26,     0,     0,    49,    49,     0,     0,     0,
      74,    75,    76,    70,    53,    65,     0,     0,    68,    69,
      49,     0,    38,    37,     0,     0,    16,    17,     0,     0,
      18,    19,     0,    55,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    57,     0,     0,     0,     0,     0,     0,
       0,     0,    59,     0,     0,    21,    49,    13,    15,    14,
      20,     0,     0,    49,     0,     0,     0,     0,    23,     0,
      22
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -104,  -104,   156,  -104,   -33,  -104,  -104,  -104,  -104,  -104,
    -104,   -45,    71,   -63,  -104,  -104,   151,   -40,  -104,   -20,
    -104,  -104,  -104,  -104,  -104,  -104,   131,  -103,  -104,   105,
     157,    62
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,    18,    19,    20,    31,    32,   158,   162,
      21,    68,    69,    70,   110,   106,    48,    71,   107,    25,
      10,    11,    23,    37,    55,    88,    40,    83,    41,    84,
      72,   143
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      34,    51,    95,    78,    -8,    73,    29,     4,    13,    14,
      38,    15,    16,   111,   112,    81,   104,   105,   145,    92,
     147,    94,    96,    62,    63,   151,    64,    97,   111,   112,
     111,   112,   118,   104,   105,   160,   104,   105,   113,    61,
     161,    39,   191,    30,    17,   165,    82,   132,   128,   156,
      -8,    62,    63,   114,    64,   127,    65,   157,   108,    66,
     109,    67,   131,    98,    99,   100,   101,   102,   103,     1,
      98,    99,   100,   101,   102,   103,     5,   104,   105,     1,
     104,   105,     7,   129,   104,   105,   129,   140,     9,   141,
     142,   133,   134,   152,   153,    62,    63,     8,    64,    12,
      65,    22,    24,    66,    26,    77,    74,    75,    76,    27,
      28,    33,    35,    36,    42,   154,   155,    47,    43,    54,
      44,    45,    46,    56,    87,    49,    50,    79,    53,    52,
     166,   184,    57,    60,    58,   177,   178,    59,    80,    86,
      85,   119,   183,    90,   115,   116,   117,   125,    82,   159,
     126,   111,   120,   167,   121,   123,   135,   124,     6,   136,
     144,   196,   168,   137,   199,   138,   192,   139,   146,   148,
     150,   163,   173,   195,   164,   169,     0,   130,   170,   171,
     172,   174,   175,   176,   194,   179,   180,   181,   149,    91,
     122,   182,     0,     0,   185,   186,   187,   188,   189,   190,
     193,   197,     0,   198,   200,     0,     0,     0,     0,     0,
       0,    93,     0,    89
};

static const yytype_int16 yycheck[] =
{
      20,    34,    65,    48,     4,    45,     8,    49,    15,    16,
      14,    18,    19,    26,    27,    14,    42,    43,   121,    59,
     123,    61,    67,    37,    38,    51,    40,    67,    26,    27,
      26,    27,    77,    42,    43,    40,    42,    43,    51,    25,
      45,    45,    51,    45,    51,   148,    45,   110,    93,    37,
      50,    37,    38,    51,    40,    51,    42,    45,    39,    45,
      41,    47,   107,    28,    29,    30,    31,    32,    33,     3,
      28,    29,    30,    31,    32,    33,     0,    42,    43,     3,
      42,    43,    45,    48,    42,    43,    48,    10,    20,    12,
      13,   111,   112,   133,   134,    37,    38,    50,    40,    49,
      42,    21,    51,    45,    49,    47,    34,    35,    36,    49,
      49,     4,    49,    22,    49,   135,   136,     6,    51,    23,
      51,    51,    49,    28,    24,    51,    51,    44,    49,    51,
     150,   176,    51,    45,    52,   168,   169,    51,    44,    49,
      51,     7,   175,    50,    47,    47,    47,     5,    45,     9,
       7,    26,    51,    17,    52,    51,    50,    49,     2,    50,
      50,   194,    49,    51,   197,    51,   186,    51,    51,    51,
      50,    50,    50,   193,    51,    49,    -1,   106,    51,    51,
      51,    51,    49,    51,    49,    48,    48,    48,   126,    58,
      85,    50,    -1,    -1,    50,    50,    50,    50,    50,    50,
      50,    49,    -1,    50,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    60,    -1,    56
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    54,    55,    49,     0,    55,    45,    50,    20,
      73,    74,    49,    15,    16,    18,    19,    51,    56,    57,
      58,    63,    21,    75,    51,    72,    49,    49,    49,     8,
      45,    59,    60,     4,    72,    49,    22,    76,    14,    45,
      79,    81,    49,    51,    51,    51,    49,     6,    69,    51,
      51,    57,    51,    49,    23,    77,    28,    51,    52,    51,
      45,    25,    37,    38,    40,    42,    45,    47,    64,    65,
      66,    70,    83,    70,    34,    35,    36,    47,    64,    44,
      44,    14,    45,    80,    82,    51,    49,    24,    78,    83,
      50,    79,    70,    69,    70,    66,    64,    70,    28,    29,
      30,    31,    32,    33,    42,    43,    68,    71,    39,    41,
      67,    26,    27,    51,    51,    47,    47,    47,    64,     7,
      51,    52,    82,    51,    49,     5,     7,    51,    64,    48,
      65,    64,    66,    72,    72,    50,    50,    51,    51,    51,
      10,    12,    13,    84,    50,    80,    51,    80,    51,    84,
      50,    51,    70,    70,    72,    72,    37,    45,    61,     9,
      40,    45,    62,    50,    51,    80,    72,    17,    49,    49,
      51,    51,    51,    50,    51,    49,    51,    57,    57,    48,
      48,    48,    50,    57,    64,    50,    50,    50,    50,    50,
      50,    51,    72,    50,    49,    72,    57,    49,    50,    57,
      50
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    53,    54,    54,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    60,    60,    60,    61,    61,    62,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    66,    67,    67,    68,    68,    69,    70,    70,    70,
      70,    70,    70,    71,    71,    71,    71,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    78,
      78,    79,    79,    79,    79,    80,    80,    80,    80,    81,
      82,    83,    83,    83,    84,    84,    84
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     7,     1,     0,     3,     1,     4,
       4,     1,     3,     9,     9,     9,     1,     1,     1,     1,
      11,    10,    16,    14,     3,     1,     3,     1,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     4,     4,     2,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       6,     6,     0,     6,     0,     6,     0,     6,     0,     6,
       0,     3,     1,     1,     0,     3,     1,     1,     0,     5,
       3,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
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
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
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

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

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

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
      yychar = yylex ();
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 86 "latex.y" /* yacc.c:1646  */
    {
    printf("Algorithm Found !");
  }
#line 1493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 92 "latex.y" /* yacc.c:1646  */
    {
      //fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      //free($3);
      printf("ALGORITHM\n");
    }
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 101 "latex.y" /* yacc.c:1646  */
    {
    printf("Liste d'instructions\n");
    quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(qNext,compteur_quad);
    (yyvsp[0].statement)->code = add_quad((yyvsp[0].statement)->code,qNext);
    code = (yyvsp[0].statement)->code;
  }
#line 1515 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 109 "latex.y" /* yacc.c:1646  */
    { ; }
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 113 "latex.y" /* yacc.c:1646  */
    {
    printf("list_instructions : instruction marqueur list_instructions --> Marqueur : %d\n", (yyvsp[-1].value));
    (yyvsp[-2].statement)->next_list = complete((yyvsp[-2].statement)->next_list,(yyvsp[-1].value));
    (yyval.statement) = new_statement(new_quad_list(),new_quad_list());
    (yyval.statement)->code = add_quad_list((yyval.statement)->code,(yyvsp[-2].statement)->code);
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list,(yyvsp[0].statement)->next_list);
    if ((yyvsp[-2].statement)->next_list != NULL){
      quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
      set_label(qNext,(yyvsp[-1].value));
      (yyval.statement)->code = add_quad((yyval.statement)->code,qNext);
    }
    (yyval.statement)->code = add_quad_list((yyval.statement)->code,(yyvsp[0].statement)->code);
  }
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 128 "latex.y" /* yacc.c:1646  */
    {
    printf("list_instructions : instruction\n");
    (yyval.statement) = new_statement(new_quad_list(),new_quad_list());
    //$1->next_list = complete($1->next_list,compteur_quad);
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list,(yyvsp[0].statement)->next_list);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code,(yyvsp[0].statement)->code);
  }
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 138 "latex.y" /* yacc.c:1646  */
    {
    printf("instruction : '$' instruction_affectation '$' EOI");
    (yyval.statement) = new_statement((yyvsp[-2].statement)->code,(yyvsp[-2].statement)->next_list);
  }
#line 1560 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 144 "latex.y" /* yacc.c:1646  */
    {
    printf("instruction : '$' instruction_fonction '$' EOI");
    (yyval.statement) = new_statement((yyvsp[-2].statement)->code,(yyvsp[-2].statement)->next_list);
  }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 150 "latex.y" /* yacc.c:1646  */
    {
    printf("instruction : structure_controle");
    (yyval.statement) = new_statement((yyvsp[0].statement)->code,(yyvsp[0].statement)->next_list);
  }
#line 1578 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 157 "latex.y" /* yacc.c:1646  */
    {
    variable var = lookup_tds(tableS, (yyvsp[-2].name));
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[-2].name));
      exit(EXIT_FAILURE);
    }
    //Ajout du code de l'expression arithmétiques
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), (yyvsp[0].expr_arithm)->code);
    //Convertit le type pour permettre l'Assignation
    if((var->type == TYPE_INT || var->type == TYPE_BOOL) && (yyvsp[0].expr_arithm)->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, (yyvsp[0].expr_arithm)->resultat, NULL, var);
      ql = add_quad(ql,q);
    } else if(((yyvsp[0].expr_arithm)->resultat->type == TYPE_INT || (yyvsp[0].expr_arithm)->resultat->type == TYPE_BOOL) && var->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, (yyvsp[0].expr_arithm)->resultat, NULL, var);
      ql = add_quad(ql,q);
    } else {
      q = new_quad((yyvsp[-1].value),(yyvsp[0].expr_arithm)->resultat,NULL,var);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(ql,q);
    }
    (yyval.statement) = new_statement(ql,new_quad_list());
  }
#line 1609 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 186 "latex.y" /* yacc.c:1646  */
    {
      quad q = new_quad(PRINT_INT, (yyvsp[-3].var), (yyvsp[-3].var), (yyvsp[-3].var));
      quad_list ql = add_quad(NULL,q);
      (yyval.statement) = new_statement(ql,NULL);
    }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 193 "latex.y" /* yacc.c:1646  */
    {
      quad q = new_quad(PRINT_FLOAT, (yyvsp[-3].var), (yyvsp[-3].var), (yyvsp[-3].var));
      quad_list ql = add_quad(NULL,q);
      (yyval.statement) = new_statement(ql,NULL);
    }
#line 1629 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 200 "latex.y" /* yacc.c:1646  */
    {
      variable var = new_variable_string(generate_temp_name(),yylval.name);
      tableS = add_variable(tableS, var);
      quad q = new_quad(PRINT_STRING, var, var, var);
      quad_list ql = add_quad(NULL,q);
      (yyval.statement) = new_statement(ql,NULL);
    }
#line 1641 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 210 "latex.y" /* yacc.c:1646  */
    {
    variable var = new_variable_int(generate_temp_name(),yylval.value);
    tableS = add_variable(tableS, var);
    (yyval.var) = var;
  }
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 216 "latex.y" /* yacc.c:1646  */
    {
    variable var = lookup_tds(tableS, (yyvsp[0].name));
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[0].name));
      exit(EXIT_FAILURE);
    }
    if(var->type != TYPE_INT)
    {
      printf("ERROR : printInt demande un type entier en argument.\n");
      exit(EXIT_FAILURE);
    }
    (yyval.var) = var;
  }
#line 1669 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 232 "latex.y" /* yacc.c:1646  */
    {
    variable var = new_variable_float(generate_temp_name(),yylval.dvalue);
    tableS = add_variable(tableS, var);
    (yyval.var) = var;
  }
#line 1679 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 238 "latex.y" /* yacc.c:1646  */
    {
    variable var = lookup_tds(tableS, (yyvsp[0].name));
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[0].name));
      exit(EXIT_FAILURE);
    }
    if(var->type != TYPE_FLOAT)
    {
      printf("ERROR : printReal demande un type réel en argument.\n");
      exit(EXIT_FAILURE);
    }
    (yyval.var) = var;
  }
#line 1697 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 257 "latex.y" /* yacc.c:1646  */
    {
    printf("structure_controle : WHILE marqueur '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}' --> Marqueur1 : %d --> Marqueur1 : %d\n", (yyvsp[-9].value), (yyvsp[-3].value));
    (yyvsp[-6].expr_bool)->true_list = complete((yyvsp[-6].expr_bool)->true_list, (yyvsp[-3].value)); //La true liste pointe sur le marqueur
    (yyvsp[-1].statement)->next_list = complete((yyvsp[-1].statement)->next_list, (yyvsp[-9].value)); //La next list pointe sur le marqueur
    (yyval.statement)= new_statement(new_quad_list(), new_quad_list());
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list, (yyvsp[-6].expr_bool)->false_list);
    print_quad_list((yyval.statement)->next_list);
    quad q = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q,(yyvsp[-3].value));
    quad q_while = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_while,(yyvsp[-9].value));
    (yyval.statement)->code = add_quad((yyval.statement)->code, q_while);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-6].expr_bool)->code);
    (yyval.statement)->code = add_quad((yyval.statement)->code, q);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-1].statement)->code);
    variable m = new_variable_goto((yyvsp[-9].value));
    quad goto_while = new_quad(QUAD_GOTO, NULL, NULL, m);
    (yyval.statement)->code = add_quad((yyval.statement)->code, goto_while);
    print_quad_list((yyval.statement)->code);
  }
#line 1722 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 279 "latex.y" /* yacc.c:1646  */
    {
    printf("structure_controle : IF '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}' --> Marqueur : %d\n", (yyvsp[-3].value));
    (yyvsp[-6].expr_bool)->true_list = complete((yyvsp[-6].expr_bool)->true_list, (yyvsp[-3].value)); //La true liste pointe sur le marqueur
    (yyval.statement)= new_statement(new_quad_list(), new_quad_list());
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list, (yyvsp[-6].expr_bool)->false_list);
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list, (yyvsp[-1].statement)->next_list);
    /* L'instruction ci-dessus va faire pointer la sortie du "if imbriqué" vers la même sortie
    que le if parent.
    Exemple :
    \If{$4 = 4$}{
      $\mbox{printText($"Test"$)}$\;
      \If{$3 = 4$}{$\mbox{printText($"Test1"$)}$\;}
    }
    La sortie du second if va pointer sur la même que le premier */
    quad q = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q,(yyvsp[-3].value));
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-6].expr_bool)->code);
    (yyval.statement)->code = add_quad((yyval.statement)->code, q);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-1].statement)->code);
    print_quad_list((yyval.statement)->code);
  }
#line 1748 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 302 "latex.y" /* yacc.c:1646  */
    {
    printf("structure_controle : FOR marqueur '{' '$' instruction_affectation '$' KWTO '$' expression_arithmetique '$' '}' '{' list_instructions '}'\n");
    (yyvsp[-1].statement)->next_list = complete((yyvsp[-1].statement)->next_list, (yyvsp[-3].value)); //La next list pointe sur le marqueur
    (yyval.statement)= new_statement(new_quad_list(), new_quad_list());
    variable var_id = lookup_tds(tableS,(yyvsp[-12].name));
    if(var_id == NULL){
      printf("ERROR : Variable %s non définie.\n", (yyvsp[-12].name));
      exit(EXIT_FAILURE);
    }
    //Ajout du code de l'expression arithmétiques
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), (yyvsp[-10].expr_arithm)->code);
    //Convertit le type pour permettre l'Assignation
    if((var_id->type == TYPE_INT || var_id->type == TYPE_BOOL) && (yyvsp[-10].expr_arithm)->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, (yyvsp[-10].expr_arithm)->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else if(((yyvsp[-10].expr_arithm)->resultat->type == TYPE_INT || (yyvsp[-10].expr_arithm)->resultat->type == TYPE_BOOL) && var_id->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, (yyvsp[-10].expr_arithm)->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else {
      q = new_quad((yyvsp[-11].value),(yyvsp[-10].expr_arithm)->resultat,NULL,var_id);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(ql,q);
    }
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, ql);
    //Ensuite le label
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,(yyvsp[-3].value));
    (yyval.statement)->code = add_quad((yyval.statement)->code, q_label);
    //Ajout du test (EGAL)
    quad test = new_quad(SUPEGAL, var_id, (yyvsp[-6].expr_arithm)->resultat, NULL);
    (yyval.statement)->next_list = add_quad((yyval.statement)->next_list, test);
    (yyval.statement)->code = add_quad((yyval.statement)->code, test);
    //Suivi du code de notre list d'instructions
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-1].statement)->code);
    //Incrémentation de la variable
    quad incr_indice = new_quad(QUAD_INCR, var_id, NULL, var_id);
    (yyval.statement)->code = add_quad((yyval.statement)->code, incr_indice);
    //Et le goto vers le test
    variable m = new_variable_goto((yyvsp[-3].value));
    quad goto_for = new_quad(QUAD_GOTO, NULL, NULL, m);
    (yyval.statement)->code = add_quad((yyval.statement)->code, goto_for);
  }
#line 1799 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 350 "latex.y" /* yacc.c:1646  */
    {
    printf("structure_controle : ELSEIF '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}' marqueur '{' list_instructions '}'\n");
    (yyvsp[-10].expr_bool)->true_list = complete((yyvsp[-10].expr_bool)->true_list, (yyvsp[-7].value)); //La true liste pointe sur le marqueur
    (yyvsp[-10].expr_bool)->false_list = complete((yyvsp[-10].expr_bool)->false_list, (yyvsp[-3].value)); //La false liste pointe sur le second marqueur
    (yyval.statement)= new_statement(new_quad_list(), new_quad_list());
    /* L'instruction ci-dessus va faire pointer la sortie du "if imbriqué" vers la même sortie
    que le if parent.
    Exemple :
    \If{$4 = 4$}{
      $\mbox{printText($"Test"$)}$\;
      \If{$3 = 4$}{$\mbox{printText($"Test1"$)}$\;}
    }
    La sortie du second if va pointer sur la même que le premier */
    quad q_label_marqueur1 = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label_marqueur1, (yyvsp[-7].value));
    quad q_label_marqueur2 = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label_marqueur2, (yyvsp[-3].value));
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-10].expr_bool)->code);
    (yyval.statement)->code = add_quad((yyval.statement)->code, q_label_marqueur1);
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list, (yyvsp[-5].statement)->next_list);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-5].statement)->code);
    quad goto_else_if1 = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    (yyval.statement)->next_list = add_quad((yyval.statement)->next_list, goto_else_if1);
    (yyval.statement)->code = add_quad((yyval.statement)->code, goto_else_if1);
    (yyval.statement)->code = add_quad((yyval.statement)->code, q_label_marqueur2);
    (yyval.statement)->next_list = add_quad_list((yyval.statement)->next_list, (yyvsp[-1].statement)->next_list);
    (yyval.statement)->code = add_quad_list((yyval.statement)->code, (yyvsp[-1].statement)->code);
    quad goto_else_if2 = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    (yyval.statement)->next_list = add_quad((yyval.statement)->next_list, goto_else_if2);
    (yyval.statement)->code = add_quad((yyval.statement)->code, goto_else_if2);
  }
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 384 "latex.y" /* yacc.c:1646  */
    {
    if (((yyvsp[-2].expr_arithm)->resultat->type) != ((yyvsp[0].expr_arithm)->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,(yyvsp[-2].expr_arithm)->resultat->id,(yyvsp[0].expr_arithm)->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr_arithm expr_arithm;
    switch((yyvsp[-2].expr_arithm)->resultat->type){
              case TYPE_INT:
              var = new_variable_int(generate_temp_name(),0);
              break;
              case TYPE_FLOAT:
              var = new_variable_float(generate_temp_name(),0);
              break;
              case TYPE_BOOL:
              var = new_variable_bool(generate_temp_name(),0);
              break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[-2].expr_arithm)->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad((yyvsp[-1].value),(yyvsp[-2].expr_arithm)->resultat,(yyvsp[0].expr_arithm)->resultat,var);
      quad_list ql = add_quad(NULL,q);
      (yyval.expr_arithm) = new_expr_arithm(var,add_quad_list(add_quad_list((yyvsp[-2].expr_arithm)->code,(yyvsp[0].expr_arithm)->code),ql));
      print_expr_arithm((yyval.expr_arithm));
  }
#line 1870 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 416 "latex.y" /* yacc.c:1646  */
    {
    (yyval.expr_arithm) = (yyvsp[0].expr_arithm);
  }
#line 1878 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 422 "latex.y" /* yacc.c:1646  */
    {
    if (((yyvsp[-2].expr_arithm)->resultat->type) != ((yyvsp[0].expr_arithm)->resultat->type))
    {
      if (((yyvsp[-2].expr_arithm)->resultat->type) == TYPE_INT && ((yyvsp[0].expr_arithm)->resultat->type) == TYPE_BOOL || ((yyvsp[-2].expr_arithm)->resultat->type) == TYPE_BOOL && ((yyvsp[0].expr_arithm)->resultat->type) == TYPE_INT)
      {
        ;
      }
      else {
        fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
        ,(yyvsp[-2].expr_arithm)->resultat->id,(yyvsp[0].expr_arithm)->resultat->id);
        exit(EXIT_FAILURE);
      }
    }
    variable var;
    expr_arithm expr_arithm;
    switch((yyvsp[-2].expr_arithm)->resultat->type){
              case TYPE_INT:
              var = new_variable_int(generate_temp_name(),0);
              break;
              case TYPE_FLOAT:
              var = new_variable_float(generate_temp_name(),0);
              break;
              case TYPE_BOOL:
              var = new_variable_bool(generate_temp_name(),0);
              break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[-2].expr_arithm)->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad((yyvsp[-1].value),(yyvsp[-2].expr_arithm)->resultat,(yyvsp[0].expr_arithm)->resultat,var);
      quad_list ql = add_quad(NULL,q);
      (yyval.expr_arithm) = new_expr_arithm(var,add_quad_list(add_quad_list((yyvsp[-2].expr_arithm)->code,(yyvsp[0].expr_arithm)->code),ql));
      print_expr_arithm((yyval.expr_arithm));
  }
#line 1919 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 460 "latex.y" /* yacc.c:1646  */
    {
    (yyval.expr_arithm) =  (yyvsp[0].expr_arithm);
  }
#line 1927 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 466 "latex.y" /* yacc.c:1646  */
    {
    (yyval.expr_arithm) =  (yyvsp[-1].expr_arithm);
  }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 471 "latex.y" /* yacc.c:1646  */
    {
    variable temp;
    switch((yyvsp[0].expr_arithm)->resultat->type){
      case TYPE_INT:
        temp = new_variable_int(generate_temp_name(),0);
        break;
      case TYPE_FLOAT:
        temp = new_variable_float(generate_temp_name(),0);
        break;
      case TYPE_BOOL:
        printf("\nError : Impossible d'inverser la valeur d'un Boolean (utilisation de la syntaxe suivante : \"\\neg\")\n");
        exit(EXIT_FAILURE);
        break;
      default:
        printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[0].expr_arithm)->resultat->type);
        exit(EXIT_FAILURE);
        break;
      }
      tableS = add_variable(tableS, temp);
      quad q = new_quad(NEGATE,(yyvsp[0].expr_arithm)->resultat,NULL,temp);
      (yyval.expr_arithm) = new_expr_arithm(temp, add_quad((yyvsp[0].expr_arithm)->code,q));
  }
#line 1962 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 496 "latex.y" /* yacc.c:1646  */
    {
    variable var;
    switch((yyvsp[0].valeurSt).type){
              case TYPE_INT:
                var = new_variable_int(generate_temp_name(),(yyvsp[0].valeurSt).valUnion.valInt);
                break;
              case TYPE_FLOAT:
                var = new_variable_float(generate_temp_name(),(yyvsp[0].valeurSt).valUnion.valFloat);
                break;
              case TYPE_BOOL:
                var = new_variable_bool(generate_temp_name(),(yyvsp[0].valeurSt).valUnion.valInt);
                break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",(yyvsp[0].valeurSt).type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      (yyval.expr_arithm) =  new_expr_arithm(var,NULL);
    }
#line 1987 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 518 "latex.y" /* yacc.c:1646  */
    {
      variable var = lookup_tds(tableS,(yyvsp[0].name));
      if(var == NULL){
        printf("ERROR : Variable %s non définie.\n", (yyvsp[0].name));
        exit(EXIT_FAILURE);
      }
      (yyval.expr_arithm) =  new_expr_arithm(var,NULL);
    }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 529 "latex.y" /* yacc.c:1646  */
    {
    (yyval.value) = DIV;
  }
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 534 "latex.y" /* yacc.c:1646  */
    {
    (yyval.value) = MULT;
  }
#line 2016 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 539 "latex.y" /* yacc.c:1646  */
    {
    (yyval.value) = PLUS;
  }
#line 2024 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 544 "latex.y" /* yacc.c:1646  */
    {
    (yyval.value) = MINUS;
  }
#line 2032 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 549 "latex.y" /* yacc.c:1646  */
    {
    (yyval.value) = LEFTARROW;
  }
#line 2040 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 555 "latex.y" /* yacc.c:1646  */
    {
    printf("expr_boolean : expr_boolean OU marqueur expr_boolean\n");
    (yyval.expr_bool) = new_expr_bool(new_quad_list(),new_quad_list(), new_quad_list());
    (yyvsp[-3].expr_bool)->false_list = complete((yyvsp[-3].expr_bool)->false_list, (yyvsp[-1].value));
    (yyval.expr_bool)->true_list = add_quad_list((yyvsp[-3].expr_bool)->true_list, (yyvsp[0].expr_bool)->true_list);
    (yyval.expr_bool)->false_list = add_quad_list((yyval.expr_bool)->false_list, (yyvsp[0].expr_bool)->false_list);
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,(yyvsp[-1].value));
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[-3].expr_bool)->code);
    (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, q_label);
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[0].expr_bool)->code);
  }
#line 2057 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 569 "latex.y" /* yacc.c:1646  */
    {
    printf("expr_boolean : expr_boolean ET marqueur expr_boolean\n");
    (yyval.expr_bool) = new_expr_bool(new_quad_list(),new_quad_list(), new_quad_list());
    (yyvsp[-3].expr_bool)->true_list = complete((yyvsp[-3].expr_bool)->true_list, (yyvsp[-1].value));
    (yyval.expr_bool)->false_list = add_quad_list((yyvsp[-3].expr_bool)->false_list, (yyvsp[0].expr_bool)->false_list);
    (yyval.expr_bool)->true_list = add_quad_list((yyval.expr_bool)->true_list, (yyvsp[0].expr_bool)->true_list);
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,(yyvsp[-1].value));
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[-3].expr_bool)->code);
    (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, q_label);
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[0].expr_bool)->code);
  }
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 583 "latex.y" /* yacc.c:1646  */
    {
    printf("'(' expr_boolean ')'\n");
    (yyval.expr_bool) = new_expr_bool((yyvsp[0].expr_bool)->code, (yyvsp[0].expr_bool)->true_list, (yyvsp[0].expr_bool)->false_list);
  }
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 589 "latex.y" /* yacc.c:1646  */
    {
    printf("expr_boolean : NO expr_boolean\n");
    //Pour effectuer le NO on inverse la False List et la True List
    (yyval.expr_bool) = new_expr_bool((yyvsp[0].expr_bool)->code, (yyvsp[0].expr_bool)->false_list, (yyvsp[0].expr_bool)->true_list);
  }
#line 2093 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 596 "latex.y" /* yacc.c:1646  */
    {
    printf("expr_boolean : expression_arithmetique relop expression_arithmetique\n");
    variable res1 = (yyvsp[-2].expr_arithm)->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = (yyvsp[0].expr_arithm)->resultat;
    (yyval.expr_bool) = new_expr_bool(new_quad_list(), new_quad_list(), new_quad_list());
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad((yyvsp[-1].value), res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    (yyval.expr_bool)->true_list = add_quad((yyval.expr_bool)->true_list, trueL);
    (yyval.expr_bool)->false_list = add_quad((yyval.expr_bool)->false_list, falseL);
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[-2].expr_arithm)->code);
    (yyval.expr_bool)->code = add_quad_list((yyval.expr_bool)->code, (yyvsp[0].expr_arithm)->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, trueL);
    (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, falseL);
  }
#line 2116 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 615 "latex.y" /* yacc.c:1646  */
    {
    //En fonction de la valeur de const bool jump soit à la false list, soit à la true list
    (yyval.expr_bool) = new_expr_bool(new_quad_list(), new_quad_list(), new_quad_list());
    if(yylval.value){
      quad trueL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
      (yyval.expr_bool)->true_list = add_quad((yyval.expr_bool)->true_list, trueL);
      (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, trueL);
    } else {
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
      (yyval.expr_bool)->false_list = add_quad((yyval.expr_bool)->false_list, falseL);
      (yyval.expr_bool)->code = add_quad((yyval.expr_bool)->code, falseL);
    }
  }
#line 2134 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 632 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = EGAL;
    }
#line 2142 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 637 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = NOEGAL;
    }
#line 2150 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 642 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = SUP;
    }
#line 2158 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 647 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = INF;
    }
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 652 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = INFEGAL;
    }
#line 2174 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 657 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = SUPEGAL;
    }
#line 2182 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 662 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = compteur_quad;
      compteur_quad++;
  }
#line 2191 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 671 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration\n");
    }
#line 2199 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 677 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration DECLARECONSTANT\n");
    }
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 680 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2213 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 684 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration DECLAREINPUT\n");
    }
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 687 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2227 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 691 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration DECLAREOUTPUT\n");
    }
#line 2235 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 694 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2241 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 698 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration DECLAREGLOBAL\n");
    }
#line 2249 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 701 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2255 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 705 "latex.y" /* yacc.c:1646  */
    {
      printf("\nzone déclaration local\n");
    }
#line 2263 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 708 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2269 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 712 "latex.y" /* yacc.c:1646  */
    {
      printf("\nsuite déclaration constante\n");
    }
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 717 "latex.y" /* yacc.c:1646  */
    {
      printf("\ndéclaration constante\n");
    }
#line 2285 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 721 "latex.y" /* yacc.c:1646  */
    {
      ;
    }
#line 2293 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 724 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2299 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 728 "latex.y" /* yacc.c:1646  */
    {
      printf("\nsuite déclaration var\n");
    }
#line 2307 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 733 "latex.y" /* yacc.c:1646  */
    {
      printf("\ndéclaration var\n");
    }
#line 2315 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 737 "latex.y" /* yacc.c:1646  */
    {
      ;
    }
#line 2323 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 740 "latex.y" /* yacc.c:1646  */
    { ; }
#line 2329 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 744 "latex.y" /* yacc.c:1646  */
    {
      variable var;
      switch ((yyvsp[0].value)) {
        case INTEGER:
          var = new_variable_int((yyvsp[-4].name), (yyvsp[-2].valeurSt).valUnion.valInt);
          break;
        case BOOLEAN:
          var = new_variable_bool((yyvsp[-4].name), (yyvsp[-2].valeurSt).valUnion.valInt);
          break;
        case REAL:
          var = new_variable_float((yyvsp[-4].name), (yyvsp[-2].valeurSt).valUnion.valFloat);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_constante)\n", (yyvsp[0].value));
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
    }
#line 2353 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 766 "latex.y" /* yacc.c:1646  */
    {
      variable var;
      switch ((yyvsp[0].value)) {
        case INTEGER:
          var = new_variable_int((yyvsp[-2].name), 0);
          break;
        case BOOLEAN:
          var = new_variable_bool((yyvsp[-2].name), 0);
          break;
        case REAL:
          var = new_variable_float((yyvsp[-2].name), 0.0);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_variable)\n", (yyvsp[0].value));
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
    }
#line 2377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 788 "latex.y" /* yacc.c:1646  */
    {
      (yyval.valeurSt).valUnion.valInt = yylval.value;
      (yyval.valeurSt).type = TYPE_INT;
    }
#line 2386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 793 "latex.y" /* yacc.c:1646  */
    {
      (yyval.valeurSt).valUnion.valFloat = yylval.dvalue;
      (yyval.valeurSt).type = TYPE_FLOAT;
    }
#line 2395 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 798 "latex.y" /* yacc.c:1646  */
    {
      (yyval.valeurSt).valUnion.valInt = yylval.value;
      (yyval.valeurSt).type = TYPE_BOOL;
    }
#line 2404 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 805 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = INTEGER;
    }
#line 2412 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 809 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = BOOLEAN;
    }
#line 2420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 813 "latex.y" /* yacc.c:1646  */
    {
      (yyval.value) = REAL;
    }
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2432 "y.tab.c" /* yacc.c:1646  */
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

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 817 "latex.y" /* yacc.c:1906  */

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
  /* Ajoute une variable dans la table des symboles pour comparer les boolean
  Ex : if(true) générera une comparaison entre la variable CONSTBOOL et VAR_BOOL_FALSE */
  variable var_bool_false = new_variable_int(VAR_BOOL_FALSE, 0);
  tableS = add_variable(tableS, var_bool_false);
  yyparse();
  /*variable v1 = new_variable_int("v1", 5);
  variable v2 = new_variable_int("v2", 5);
  variable v3 = new_variable_goto(5);
  quad q = new_quad(EGAL,v1,v2,v3);
  set_label(q, 5);
  quad_list ql = add_quad(NULL,q);
  code = add_quad_list(code,ql);*/
  generate_text(fd, code);
  print_quad_list(code);
  generate_data(fd, tableS);
  fclose(yyin);
  fclose(fd);
  texcc_lexer_free();
  print_tds(tableS);
  free_tds(tableS);
  return EXIT_SUCCESS;
}
