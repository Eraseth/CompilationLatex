%option nounput
%option noinput
%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
%}

%s texsci

begin            "\\begin{texsci}"
end              "\\end{texsci}"
blankline        "\\BlankLine"
id               [a-zA-Z_][a-zA-Z0-9_]*
leftarrow        "\\leftarrow"|"\\gets"
in               "\\in"
integer          "\\Integer"
commentaire      "\\tcc{".*"}"
boolean          "\\Boolean"
real             "\\Real"
emptyset         "\\emptyset"
while            "\\While"
for              "\\For"
KwTo             "\\KwTo"
if               "\\If"
elseif           "\\eIf"
declareConstant  "\\Constant"
declareInput     "\\Input"
declareOutput    "\\Output"
declareGlobal    "\\Global"
declareLocal     "\\Local"
div              "\\div"
mult             "\\times"|"\\ast"
minus            "-"
plus             "+"
no               "\\neg"
et               "\\wedge"
ou               "\\vee"
egal             "="
sup              ">"
inf              "<"
infegal          "\\leq"
supegal          "\\geq"
printInt         "printInt"
printText        "printText"
printReal        "printReal"
constInt         [-+]?[0-9]([0-9])*
constFloat       [-+]?[0-9]*\.?[0-9]+([-+]?[0-9]+)?$
constBool        "\\true"|"\\false"
%%

{begin}             { BEGIN(texsci); printf("BEGIN ");   // Start TexSci scanning mode
                      /*return TEXSCI_BEGIN;*/
                    }
<texsci>{end}       { BEGIN(INITIAL); printf("END "); // Reset to default scanning mode
                      /*return TEXSCI_END*/;
		                }
<texsci>{blankline}       { printf("BLANKLINE "); /*return BLANKLINE;*/ }
<texsci>{leftarrow}       { printf("LEFTARROW "); /*return LEFTARROW;*/ }
<texsci>{in}              { printf("IN "); /*return IN;*/ }
<texsci>{integer}         { printf("INTEGER "); /*return INTEGER;*/ }
<texsci>{commentaire}     { printf("COMMENTAIRE "); }
<texsci>{boolean}         { printf("BOOLEAN "); /*return BOOLEAN;*/ }
<texsci>{real}            { printf("REAL "); /*return REAL;*/ }
<texsci>{emptyset}        { printf("EMPTYSET "); /*return EMPTYSET;*/ }
<texsci>{while}           { printf("WHILE "); /*return WHILE;*/ }
<texsci>{for}             { printf("FOR "); /*return FOR;*/ }
<texsci>{KwTo}            { printf("KWTO "); /*return KWTO;*/ }
<texsci>{if}              { printf("IF "); /*return IF;*/ }
<texsci>{elseif}          { printf("ELSEIF "); /*return ELSEIF;*/ }
<texsci>{declareConstant} { printf("DELCARECONSTANT "); /*return DELCARECONSTANT;*/ }
<texsci>{declareInput}    { printf("DECLAREINPUT "); /*return DECLAREINPUT;*/ }
<texsci>{declareOutput}   { printf("DECLAREOUTPUT "); /*return DECLAREOUTPUT;*/ }
<texsci>{declareGlobal}   { printf("DECLAREGLOBAL "); /*return DECLAREGLOBAL;*/ }
<texsci>{declareLocal}    { printf("DECLARELOCAL "); /*return DECLARELOCAL;*/ }
<texsci>{div}             { printf("DIV "); /*return DIV;*/ }
<texsci>{mult}            { printf("MULT "); /*return MULT;*/ }
<texsci>{minus}           { printf("MINUS "); /*return MINUS;*/ }
<texsci>{plus}            { printf("PLUS "); /*return PLUS;*/ }
<texsci>{no}              { printf("NO "); /*return NO;*/ }
<texsci>{et}              { printf("ET "); /*return ET;*/ }
<texsci>{ou}              { printf("OU "); /*return OU;*/ }
<texsci>{egal}            { printf("EGAL "); /*return EGAL;*/ }
<texsci>{sup}             { printf("SUP "); /*return SUP;*/ }
<texsci>{inf}             { printf("INF "); /*return INF;*/ }
<texsci>{infegal}         { printf("INFEGAL "); /*return INFEGAL;*/ }
<texsci>{supegal}         { printf("SUPEGAL "); /*return SUPEGAL;*/ }
<texsci>{printInt}        { printf("PRINTINT "); /*return PRINTINT;*/ }
<texsci>{printText}       { printf("PRINTTEXT "); /*return PRINTTEXT;*/ }
<texsci>{printReal}       { printf("PRINTREAL "); /*return PRINTREAL;*/ }
<texsci>{constInt}        { printf("CONSTINT "); /*return CONSTINT;*/ }
<texsci>{constFloat}      { printf("CONSTFLOAT "); /*return CONSTFLOAT;*/ }
<texsci>{constBool}       { printf("CONSTBOOL "); /*return CONSTBOOL;*/ }
<texsci>[{}()$,^]         { printf("%c ", yytext[0]);/*return yytext[0];*/ }
[\n]                      { printf("\n"); /*return yytext[0];*/}
<texsci>{id}        {
                      /*yylval.name = strdup(yytext);
                      return ID;*/
                      printf("%s\n", yytext);
                    }
.                   { }

%%
/*
int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	return 0;
}
*/