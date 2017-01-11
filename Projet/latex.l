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
  #include "include/expression.h"
  #include "include/statement.h"
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
noegal           "\\neq"
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
<texsci>{blankline}       { return BLANKLINE; }
<texsci>{leftarrow}       { return LEFTARROW; }
<texsci>{in}              { return IN; }
<texsci>{integer}         { return INTEGER; }
<texsci>{commentaire}     { }
<texsci>{boolean}         { return BOOLEAN; }
<texsci>{eoi}             { return EOI; }
<texsci>{real}            { return REAL; }
<texsci>{emptyset}        { return EMPTYSET; }
<texsci>{while}           { return WHILE; }
<texsci>{for}             { return FOR; }
<texsci>{KwTo}            { return KWTO; }
<texsci>{if}              { return IF; }
<texsci>{elseif}          { return ELSEIF; }
<texsci>{declareConstant} { return DECLARECONSTANT; }
<texsci>{declareInput}    { return DECLAREINPUT; }
<texsci>{declareOutput}   { return DECLAREOUTPUT; }
<texsci>{declareGlobal}   { return DECLAREGLOBAL; }
<texsci>{declareLocal}    { return DECLARELOCAL; }
<texsci>{div}             { return DIV; }
<texsci>{mult}            { return MULT; }
<texsci>{minus}           { return MINUS; }
<texsci>{plus}            { return PLUS; }
<texsci>{no}              { return NO; }
<texsci>{et}              { return ET; }
<texsci>{ou}              { return OU; }
<texsci>{egal}            { return EGAL; }
<texsci>{noegal}          { return NOEGAL; }
<texsci>{sup}             { return SUP; }
<texsci>{inf}             { return INF; }
<texsci>{infegal}         { return INFEGAL; }
<texsci>{supegal}         { return SUPEGAL; }
<texsci>{printInt}        { return PRINTINT; }
<texsci>{printText}       { return PRINTTEXT; }
<texsci>{printReal}       { return PRINTREAL; }
<texsci>{mbox}            { return MBOX; }
<texsci>{constInt}        {

                            yylval.value = atoi(yytext);
                            return CONSTINT;
                          }

<texsci>{constFloat}      {

                            yylval.dvalue = atof(yytext);
                            return CONSTFLOAT;
                          }
<texsci>{constBool}       {

                            if(strcmp(yytext, "\\true") == 0){
                              yylval.value = 1;
                            } else {
                              yylval.value = 0;
                            }
                            return CONSTBOOL;
                          }
<texsci>[{}()$,^]         { return yytext[0]; }
<texsci>[\n]              { }

<texsci>{string}    {
                      yylval.name = strdup(yytext);
                      return STRING;
                    }

<texsci>{id}        {
                      yylval.name = strdup(yytext);
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
