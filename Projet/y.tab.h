/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison interface for Yacc-like parsers in C
   
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
     INTEGER = 263,
     COMMENTAIRE = 264,
     BOOLEAN = 265,
     REAL = 266,
     EMPTYSET = 267,
     WHILE = 268,
     FOR = 269,
     KWTO = 270,
     IF = 271,
     ELSEIF = 272,
     DECLARECONSTANT = 273,
     DECLAREINPUT = 274,
     DECLAREOUTPUT = 275,
     DECLAREGLOBAL = 276,
     DECLARELOCAL = 277,
     NO = 278,
     ET = 279,
     OU = 280,
     EGAL = 281,
     SUP = 282,
     INF = 283,
     INFEGAL = 284,
     SUPEGAL = 285,
     PRINTINT = 286,
     PRINTTEXT = 287,
     PRINTREAL = 288,
     CONSTINT = 289,
     CONSTBOOL = 290,
     DIV = 291,
     CONSTFLOAT = 292,
     MULT = 293,
     MINUS = 294,
     PLUS = 295,
     EOI = 296,
     ID = 297
   };
#endif
/* Tokens.  */
#define TEXSCI_BEGIN 258
#define TEXSCI_END 259
#define BLANKLINE 260
#define LEFTARROW 261
#define IN 262
#define INTEGER 263
#define COMMENTAIRE 264
#define BOOLEAN 265
#define REAL 266
#define EMPTYSET 267
#define WHILE 268
#define FOR 269
#define KWTO 270
#define IF 271
#define ELSEIF 272
#define DECLARECONSTANT 273
#define DECLAREINPUT 274
#define DECLAREOUTPUT 275
#define DECLAREGLOBAL 276
#define DECLARELOCAL 277
#define NO 278
#define ET 279
#define OU 280
#define EGAL 281
#define SUP 282
#define INF 283
#define INFEGAL 284
#define SUPEGAL 285
#define PRINTINT 286
#define PRINTTEXT 287
#define PRINTREAL 288
#define CONSTINT 289
#define CONSTBOOL 290
#define DIV 291
#define CONSTFLOAT 292
#define MULT 293
#define MINUS 294
#define PLUS 295
#define EOI 296
#define ID 297




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 2068 of yacc.c  */
#line 45 "latex.y"

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



/* Line 2068 of yacc.c  */
#line 150 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


