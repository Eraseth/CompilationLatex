%{
  #include <stdio.h>
  #include <stdlib.h>
  #define TEXCC_ERROR_GENERAL 4

  void yyerror(char*);

  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;
%}

%union {
  char* name;
  int value;
  double dvalue;
}

%token <value> TEXSCI_BEGIN TEXSCI_END BLANKLINE LEFTARROW IN
%token <value> INTEGER COMMENTAIRE BOOLEAN REAL EMPTYSET
%token <value> WHILE FOR KWTO IF ELSEIF
%token <value> DECLARECONSTANT DECLAREINPUT DECLAREOUTPUT DECLAREGLOBAL DECLARELOCAL
%token <value> NO ET OU EGAL SUP
%token <value> INF INFEGAL SUPEGAL PRINTINT PRINTTEXT
%token <value> PRINTREAL CONSTINT CONSTBOOL DIV
%token <dvalue> CONSTFLOAT
%token <value> MULT MINUS PLUS
%token <name> ID

%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' '\n' zone_declarations '\n' TEXSCI_END
    {
      fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      free($3);
    }
  ;

/* Zone de déclarations (ordre obligatoire ici) */
zone_declarations:
    declaration_constante '\n' declaration_input '\n' declaration_output '\n'
    declaration_global '\n' declaration_local '\n' BLANKLINE '\n'
    {
      fprintf(stderr, "zone déclaration");
    }
  ;
declaration_constante:
    DECLARECONSTANT '{' '$' suite_declarations_constante '$' '}'
    {

    }
    | { ; }
  ;
declaration_input:
    DECLAREINPUT '{' '$' suite_declarations_variable '$' '}'
    {

    }
    | { ; }
  ;
declaration_output:
    DECLAREOUTPUT '{' '$' declaration_variable '$' '}'
    {

    }
    | { ; }
  ;
declaration_global:
    DECLAREGLOBAL '{' '$' suite_declarations_variable '$' '}'
    {

    }
    | { ; }
  ;
declaration_local:
    DECLARELOCAL '{' '$' suite_declarations_variable '$' '}'
    {

    }
    | { ; }
  ;
suite_declarations_constante:
    suite_declarations_constante declaration_constante ','
    {

    }
    | EMPTYSET
    {

    }
    | { ; }
  ;
suite_declarations_variable:
    suite_declarations_variable declaration_variable ','
    {

    }
    | EMPTYSET
    {

    }
    | { ; }
  ;
declaration_constante:
    ID EGAL valeur IN type_scalaire
    {

    }
  ;
declaration_variable:
    ID IN type
    {

    }
  ;
valeur:
    CONSTINT
    {

    }
    | CONSTFLOAT
    {

    }
    | CONSTBOOL
    {

    }
  ;
type_scalaire:
    INTEGER
    {

    }
    | BOOLEAN
    {

    }
    | REAL
    {

    }
  ;
type:
    type_scalaire '^' '{' CONSTINT '}'
    {

    }
  ;
%%

int main(int argc, char* argv[]) {
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
  fclose(yyin);
  texcc_lexer_free();
  return EXIT_SUCCESS;
}
