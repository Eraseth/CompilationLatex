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

/* Line 2068 of yacc.c  */
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



/* Line 2068 of yacc.c  */
#line 152 "y.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


