%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #define TEXCC_ERROR_GENERAL 4

  //Notre liste chaînée TDS
  tableSymbole tableS = NULL;
  //Compteur pour la création de variable temporaire
  int compteurTemporaire = 0;

  // Functions and global variables provided by Lex.
  int yylex();
  void texcc_lexer_free();
  extern FILE* yyin;

  void yyerror (char const *s) {
    fprintf (stderr, "%s\n", s);
  }

  char * conversion_int_string(int compteurTemporaire)
  {
    char * str = malloc(sizeof(char)*64);
    sprintf(str,"%d",compteurTemporaire);
    return str;
  }

  char * generate_temp_name(int compteurTemporaire){
    char * str = malloc(sizeof(char)*64);
    char * str2 = conversion_int_string(compteurTemporaire);
    strcat(str, "temp");
    strcat(str,str2);
    free(str2);
    return str;
  }

%}

%union {
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
  variable v;
}

%token <value> TEXSCI_BEGIN TEXSCI_END BLANKLINE LEFTARROW IN
%token <value> INTEGER COMMENTAIRE BOOLEAN REAL EMPTYSET
%token <value> WHILE FOR KWTO IF ELSEIF
%token <value> DECLARECONSTANT DECLAREINPUT DECLAREOUTPUT DECLAREGLOBAL DECLARELOCAL
%token <value> NO ET OU EGAL SUP
%token <value> INF INFEGAL SUPEGAL PRINTINT PRINTTEXT
%token <value> PRINTREAL CONSTINT CONSTBOOL DIV
%token <dvalue> CONSTFLOAT
%token <value> MULT MINUS PLUS EOI
%token <name> ID

%type <value> type
%type <valeurSt> valeur
%type <quadExpr> expression_arithmetique expression_arithmetique_t expression_arithmetique_f

%right '=' LEFTARROW
%left '+' '-'
%left '*' '/'

%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  {
    printf("Do nothing");
  }
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}' '\n' zone_declarations zone_instructions TEXSCI_END
    {
      //fprintf(stderr, "[texcc] info: algorithm \"%s\" parsed\n", $3);
      //free($3);
      printf("ALGORITHM\n");
    }
  ;

/* ----------------Zone des instructions---------------- */
zone_instructions:
  list_instructions
  {
    printf("Liste d'instructions\n");
  }
  ;
list_instructions:
  instruction  list_instructions
  {
    printf("list_instructions");
  }
  |
  instruction EOI '\n'
  {
    printf("list_instructions");
  }
  |
  { ; }
  ;
instruction:
  instruction_affectation
  {
    printf("Do nothing");
  }
  ;
instruction_affectation:
  '$' ID LEFTARROW expression_arithmetique '$'
  {
    quad new_quad();
  }
  ;
expression_arithmetique:
  expression_arithmetique PLUS expression_arithmetique_t
  {

  }
  |
  expression_arithmetique_t
  {

  }
  ;
expression_arithmetique_t:
  expression_arithmetique_t MULT expression_arithmetique_f
  {

  }
  |
  expression_arithmetique_f
  {

  }
  ;
expression_arithmetique_f:
  '(' expression_arithmetique ')'
  {

  }
  |
  valeur
  {
    variable var;

  }
  ;
/* ----------------Zone de déclarations (ordre obligatoire ici)---------------- */
zone_declarations:
    zone_declaration_constante zone_declaration_input zone_declaration_output
    zone_declaration_global zone_declaration_local BLANKLINE '\n'
    {
      printf("\nzone déclaration\n");
    }
    | BLANKLINE '\n'
    {
      printf("\nzone déclaration vide\n");
    }
  ;
zone_declaration_constante:
    DECLARECONSTANT '{' '$' suite_declarations_constante '$' '}' '\n'
    {
      printf("\nzone déclaration DECLARECONSTANT\n");
    }
    //Ici decale/reduce
    /*| { ; }*/
  ;
zone_declaration_input:
    DECLAREINPUT '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREINPUT\n");
    }
    | { ; }
  ;
zone_declaration_output:
    DECLAREOUTPUT '{' '$' declaration_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREOUTPUT\n");
    }
    | { ; }
  ;
zone_declaration_global:
    DECLAREGLOBAL '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration DECLAREGLOBAL\n");
    }
    | { ; }
  ;
zone_declaration_local:
    DECLARELOCAL '{' '$' suite_declarations_variable '$' '}' '\n'
    {
      printf("\nzone déclaration local\n");
    }
    | { ; }
  ;
suite_declarations_constante:
    declaration_constante ',' suite_declarations_constante
    {
      printf("\nsuite déclaration constante\n");
    }
    |
    declaration_constante
    {
      printf("\ndéclaration constante\n");
    }
    | EMPTYSET
    {
      ;
    }
    | { ; }
  ;
suite_declarations_variable:
    declaration_variable ',' suite_declarations_variable
    {
      printf("\nsuite déclaration var\n");
    }
    |
    declaration_variable
    {
      printf("\ndéclaration var\n");
    }
    | EMPTYSET
    {
      ;
    }
    | { ; }
  ;
declaration_constante:
    ID EGAL valeur IN type
    {
      variable var;
      switch ($5) {
        case INTEGER:
          var = new_variable_int($1, $3.valUnion.valInt);
          break;
        case BOOLEAN:
          var = new_variable_bool($1, $3.valUnion.valInt);
          break;
        case REAL:
          var = new_variable_float($1, $3.valUnion.valFloat);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_constante)\n", $5);
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
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
          var = new_variable_float($1, 0.0);
          break;
        default:
          printf("\nError : Type non reconnu %d(declaration_variable)\n", $3);
          exit(EXIT_FAILURE);
          break;
      }
      tableS = add_variable(tableS, var);
    }
  ;
valeur:
    CONSTINT
    {
      $$.valUnion.valInt = yylval.value;
      $$.type = TYPE_INT;
    }
    | CONSTFLOAT
    {
      $$.valUnion.valFloat = yylval.dvalue;
      $$.type = TYPE_FLOAT;
    }
    | CONSTBOOL
    {
      $$.valUnion.valInt = yylval.value;
      $$.type = TYPE_BOOL;
    }
  ;
type:
    INTEGER
    {
      $$ = INTEGER;
    }
    | BOOLEAN
    {
      $$ = BOOLEAN;
    }
    | REAL
    {
      $$ = REAL;
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
  print_tds(tableS);
  free_tds(tableS);
  return EXIT_SUCCESS;

}
