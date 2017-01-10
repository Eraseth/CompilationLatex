/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

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
#line 48 "latex.y" /* yacc.c:1909  */

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


#line 162 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
