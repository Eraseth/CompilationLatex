%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #define TEXCC_ERROR_GENERAL 4


  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;

  void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
  }

  tableSymbole tableS = NULL;
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

%type <value> type
%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' '\n' zone_declarations '\n' TEXSCI_END
    {
      //fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      //free($3);
      printf("ALGORITHM\n");
    }
  ;

/* Zone de déclarations (ordre obligatoire ici) */
zone_declarations:
    declaration_constante declaration_input declaration_output
    declaration_global declaration_local BLANKLINE
    {
      printf("\nzone déclaration\n");
    }
  ;
declaration_constante:
    DECLARECONSTANT '{' '$' suite_declarations_constante '$' '}' '\n'
    {
      printf("\nzone déclaration DECLARECONSTANT\n");
    }
    | { ; }
  ;
declaration_input:
    DECLAREINPUT '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREINPUT\n");
    }
    | { ; }
  ;
declaration_output:
    DECLAREOUTPUT '{' '$' declaration_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREOUTPUT\n");
    }
    | { ; }
  ;
declaration_global:
    DECLAREGLOBAL '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREGLOBAL\n");
    }
    | { ; }
  ;
declaration_local:
    DECLARELOCAL '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration local\n");
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
      printf("\nsuite déclaration var\n");
    }
    |
    suite_declarations_variable declaration_variable
    {
      printf("\nsuite déclaration var (sans virgule)\n");
    }
    | EMPTYSET
    {

    }
    | { ; }
  ;
declaration_constante:
    ID EGAL valeur IN type
    {

    }
  ;
declaration_variable:
    ID IN type
    {
      variable var;
      switch ($3) {
        case INTEGER:
          var = new_variable_int($1, 0);
          break;
        case BOOLEAN:
          var = new_variable_bool($1, 0);
          break;
        case REAL:
          var = new_variable_double($1, 0.0);
          break;
        default:
          printf("\nERROR TYPE NON RECONNU %d(declaration_variable)\n", $3);
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
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
type:
    INTEGER
    {
      $$ = INTEGER;
    }
    | BOOLEAN
    {
      $$ = $1;
    }
    | REAL
    {
      $$ = $1;
    }
  ;
%%

// int main(int argc, char* argv[]) {
//   if (argc == 2) {
//     if ((yyin = fopen(argv[1], "r")) == NULL) {
//       fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
//       exit(TEXCC_ERROR_GENERAL);
//     }
//   } else {
//     fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
//     exit(TEXCC_ERROR_GENERAL);
//   }
//
//   yyparse();
//   fclose(yyin);
//   texcc_lexer_free();
//   print_tds(tableS);
//   free_tds(tableS);
//   return EXIT_SUCCESS;
// }
