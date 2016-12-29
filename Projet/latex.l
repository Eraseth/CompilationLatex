%option noyywrap
%{
  #include <stdlib.h>
  #include <stdio.h>
  #include <string.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #include "include/expression_arithm.h"
  #include "include/expression_bool.h"
  #include "include/structure_controle.h"
  #include "y.tab.h"

%}

%s texsci

begin            "\\begin{texsci}"
end              "\\end{texsci}"
blankline        "\\BlankLine"
mbox             "\\mbox"
id               [a-zA-Z_][a-zA-Z0-9_]*
string           \"(\\.|[^"])*\"
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
constFloat       [-+]?[0-9]*\.?[0-9]+([-+]?[0-9]+)?
constBool        "\\true"|"\\false"
eoi              "\\;"
%%

{begin}             { BEGIN(texsci); printf("BEGIN{texsci} ");   // Start TexSci scanning mode
                      return TEXSCI_BEGIN;
                    }
<texsci>{end}       { BEGIN(INITIAL); printf("END "); // Reset to default scanning mode
                      return TEXSCI_END;
		                }
<texsci>{blankline}       { printf("BLANKLINE "); return BLANKLINE; }
<texsci>{leftarrow}       { printf("LEFTARROW "); return LEFTARROW; }
<texsci>{in}              { printf("IN "); return IN; }
<texsci>{integer}         { printf("INTEGER "); return INTEGER; }
<texsci>{commentaire}     { printf("COMMENTAIRE "); }
<texsci>{boolean}         { printf("BOOLEAN "); return BOOLEAN; }
<texsci>{eoi}             { printf("EOI (End of instruction) "); return EOI; }
<texsci>{real}            { printf("REAL "); return REAL; }
<texsci>{emptyset}        { printf("EMPTYSET "); return EMPTYSET; }
<texsci>{while}           { printf("WHILE "); return WHILE; }
<texsci>{for}             { printf("FOR "); return FOR; }
<texsci>{KwTo}            { printf("KWTO "); return KWTO; }
<texsci>{if}              { printf("IF "); return IF; }
<texsci>{elseif}          { printf("ELSEIF "); return ELSEIF; }
<texsci>{declareConstant} { printf("DELCARECONSTANT "); return DECLARECONSTANT; }
<texsci>{declareInput}    { printf("DECLAREINPUT "); return DECLAREINPUT; }
<texsci>{declareOutput}   { printf("DECLAREOUTPUT "); return DECLAREOUTPUT; }
<texsci>{declareGlobal}   { printf("DECLAREGLOBAL "); return DECLAREGLOBAL; }
<texsci>{declareLocal}    { printf("DECLARELOCAL "); return DECLARELOCAL; }
<texsci>{div}             { printf("DIV "); return DIV; }
<texsci>{mult}            { printf("MULT "); return MULT; }
<texsci>{minus}           { printf("MINUS "); return MINUS; }
<texsci>{plus}            { printf("PLUS "); return PLUS; }
<texsci>{no}              { printf("NO "); return NO; }
<texsci>{et}              { printf("ET "); return ET; }
<texsci>{ou}              { printf("OU "); return OU; }
<texsci>{egal}            { printf("EGAL "); return EGAL; }
<texsci>{sup}             { printf("SUP "); return SUP; }
<texsci>{inf}             { printf("INF "); return INF; }
<texsci>{infegal}         { printf("INFEGAL "); return INFEGAL; }
<texsci>{supegal}         { printf("SUPEGAL "); return SUPEGAL; }
<texsci>{printInt}        { printf("PRINTINT "); return PRINTINT; }
<texsci>{printText}       { printf("PRINTTEXT "); return PRINTTEXT; }
<texsci>{printReal}       { printf("PRINTREAL "); return PRINTREAL; }
<texsci>{mbox}            { printf("MBOX "); return MBOX; }
<texsci>{constInt}        {
                            printf("CONSTINT ");
                            yylval.value = atoi(yytext);
                            return CONSTINT;
                          }

<texsci>{constFloat}      {
                            printf("CONSTFLOAT ");
                            yylval.dvalue = atof(yytext);
                            return CONSTFLOAT;
                          }
<texsci>{constBool}       {
                            printf("CONSTBOOL ");
                            if(strcmp(yytext, "\\true") == 0){
                              yylval.value = 1;
                            } else {
                              yylval.value = 0;
                            }
                            return CONSTBOOL;
                          }
<texsci>[{}()$,^]         { printf("%c ", yytext[0]);return yytext[0]; }
<texsci>[\n]              { printf("\n"); return yytext[0];}

<texsci>{string}    {
                      yylval.name = strdup(yytext);
                      printf("String --> %s", yytext);
                      return STRING;
                    }

<texsci>{id}        {
                      yylval.name = strdup(yytext);
                      printf("ID --> %s", yytext);
                      return ID;
                    }



.                   { ; }

%%

void texcc_lexer_free() {
  yy_delete_buffer(YY_CURRENT_BUFFER);
  free(yy_buffer_stack);
}

/*int main(int argc, char* argv[])
{
	yyin = fopen(argv[1], "r");
	yylex();
	fclose(yyin);
	return 0;
}*/
