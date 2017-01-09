%{
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
    expr_arithm expr_arithm;
    expr_bool expr_bool;
    statement statement;
    variable var;

}

%token <value> TEXSCI_BEGIN TEXSCI_END BLANKLINE LEFTARROW IN MBOX STRING
%token <value> INTEGER COMMENTAIRE BOOLEAN REAL EMPTYSET
%token <value> WHILE FOR KWTO IF ELSEIF
%token <value> DECLARECONSTANT DECLAREINPUT DECLAREOUTPUT DECLAREGLOBAL DECLARELOCAL
%token <value> NO ET OU EGAL SUP
%token <value> INF INFEGAL SUPEGAL PRINTINT PRINTTEXT
%token <value> PRINTREAL CONSTINT CONSTBOOL DIV
%token <dvalue> CONSTFLOAT
%token <value> MULT MINUS PLUS EOI
%token <name> ID

%type <value> type operateur_f operateur_m operateur_affectation marqueur relop
%type <valeurSt> valeur
%type <expr_arithm> expression_arithmetique expression_arithmetique_t expression_arithmetique_f
%type <expr_bool> expr_boolean
%type <var> argument_real argument_entier
%type <statement> structure_controle list_instructions instruction instruction_affectation
%type <statement> instruction_fonction


%right '=' LEFTARROW
%left OU
%left ET
%left '(' ')'
%left EGAL SUP INF INFEGAL SUPEGAL
%left NO
%left PLUS MINUS
%left MULT DIV


%%

algorithm_list:
    algorithm_list algorithm
  | algorithm
  {
    printf("Algorithm Found !");
  }
  ;

algorithm:
    TEXSCI_BEGIN '{' ID '}'  zone_declarations zone_instructions TEXSCI_END
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
    code = $1->code;
  }
  |
  { ; }
  ;
list_instructions:
  instruction marqueur list_instructions
  {
    printf("list_instructions");
    $1->next_list = complete($1->next_list,$2);
    $$ = new_statement(new_quad_list(),new_quad_list());
    $$->code = add_quad_list($$->code,$1->code);

    $$->next_list = add_quad_list($$->next_list,$1->next_list);
    $$->next_list = add_quad_list($$->next_list,$3->next_list);

    if ($1->next_list != NULL){
      quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
      set_label(qNext,compteur_quad);compteur_quad++;
      $$->code = add_quad($$->code,qNext);
    }
    $$->code = add_quad_list($$->code,$3->code);

  }
  |
  instruction
  {
    $1->next_list = complete($1->next_list,compteur_quad);
    $$ = new_statement(new_quad_list(),new_quad_list());
    $$->next_list = add_quad_list($$->next_list,$1->next_list);
    $$->code = add_quad_list($$->code,$1->code);
    printf("list_instructions");
  }
  ;
instruction:
  '$' instruction_affectation '$' EOI
  {
    printf("Instruction Affectation");
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  '$' instruction_fonction '$' EOI
  {
    printf("Instruction Fonction");
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  structure_controle
  {
    $$ = new_statement($1->code,$1->next_list);
  }
  ;
instruction_affectation:
  ID operateur_affectation expression_arithmetique
  {
    variable var = lookup_tds(tableS, $1);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    }

    //Ajout du code de l'expression arithmétiques
    quad_list ql;
    quad q;
    //Convertit le type pour permettre l'Assignation
    if((var->type == TYPE_INT || var->type == TYPE_BOOL) && $3->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, $3->resultat, NULL, var);
      ql = add_quad(NULL,q);
    } else if(($3->resultat->type == TYPE_INT || $3->resultat->type == TYPE_BOOL) && var->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, $3->resultat, NULL, var);
      ql = add_quad(NULL,q);
    } else {
      q = new_quad($2,$3->resultat,NULL,var);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(NULL,q);
    }

    print_quad_list(ql);
    $$ = new_statement(ql,new_quad_list());
  }
  ;
instruction_fonction:
    MBOX '{' PRINTINT '('  '$' argument_entier '$' ')' '}'
    {

      quad q = new_quad(PRINT_INT, $6, $6, $6);

      quad_list ql = add_quad(NULL,q);
      $$ = new_statement(ql,NULL);
    }
    |
    MBOX '{' PRINTREAL '('  '$' argument_real '$' ')' '}'
    {

      quad q = new_quad(PRINT_FLOAT, $6, $6, $6);

      quad_list ql = add_quad(NULL,q);
      $$ = new_statement(ql,NULL);
    }
    |
    MBOX '{' PRINTTEXT '('  '$' STRING '$' ')' '}'
    {
      variable var = new_variable_string(generate_temp_name(),yylval.name);
      tableS = add_variable(tableS, var);
      quad q = new_quad(PRINT_STRING, var, var, var);
      quad_list ql = add_quad(NULL,q);
      $$ = new_statement(ql,NULL);
    }
    ;
argument_entier:
  CONSTINT
  {
    variable var = new_variable_int(generate_temp_name(),yylval.value);
    tableS = add_variable(tableS, var);
    $$ = var;
  }
  |ID
  {
    variable var = lookup_tds(tableS, $1);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    }
    if(var->type != TYPE_INT)
    {
      printf("ERROR : printInt demande un type entier en argument.\n");
      exit(EXIT_FAILURE);
    }
    $$ = var;
  }
  ;

argument_real:
  CONSTFLOAT
  {
    variable var = new_variable_float(generate_temp_name(),yylval.dvalue);
    tableS = add_variable(tableS, var);
    $$ = var;
  }
  |ID
  {
    variable var = lookup_tds(tableS, $1);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    }
    if(var->type != TYPE_FLOAT)
    {
      printf("ERROR : printReal demande un type réel en argument.\n");
      exit(EXIT_FAILURE);
    }
    $$ = var;
  }
  ;
  /*
  Structure de contrôle
  */
structure_controle:
  WHILE marqueur '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}'
  {
    ;
  }
  |
  IF '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}'
  {

    $4->true_list = complete($4->true_list, $7);

    $$= new_statement(new_quad_list(), new_quad_list());
    $$->next_list = add_quad_list($$->next_list, $4->false_list);
    print_quad_list($$->next_list);
    quad q = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q,compteur_quad);compteur_quad++;
    $$->code = add_quad_list($$->code, $4->code);
    $$->code = add_quad($$->code, q);
    $$->code = add_quad_list($$->code, $9->code);
    print_quad_list($$->code);
  }
  |
  FOR marqueur '{' '$' instruction_affectation '$' KWTO '$' expression_arithmetique '$' '}' '{' list_instructions '}'
  {
    ;
  }
  |
  ELSEIF '{' '$' expr_boolean '$' '}' marqueur '{' list_instructions '}' marqueur '{' list_instructions '}'
  {
    ;
  }
  ;
expression_arithmetique:
  expression_arithmetique operateur_m expression_arithmetique_t
  {
    if (($1->resultat->type) != ($3->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,$1->resultat->id,$3->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr_arithm expr_arithm;
    switch($1->resultat->type){
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
                printf("\nError : Type non reconnu %d(valeur)\n",$1->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad($2,$1->resultat,$3->resultat,var);
      quad_list ql = add_quad(NULL,q);
      $$ = new_expr_arithm(var,add_quad_list(add_quad_list($1->code,$3->code),ql));
      print_expr_arithm($$);
  }
  |
  expression_arithmetique_t
  {
    $$ = $1;
  }
  ;
expression_arithmetique_t:
  expression_arithmetique_t operateur_f expression_arithmetique_f
  {
    if (($1->resultat->type) != ($3->resultat->type))
    {
      if (($1->resultat->type) == TYPE_INT && ($3->resultat->type) == TYPE_BOOL || ($1->resultat->type) == TYPE_BOOL && ($3->resultat->type) == TYPE_INT)
      {
        ;
      }
      else {
        fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
        ,$1->resultat->id,$3->resultat->id);
        exit(EXIT_FAILURE);
      }
    }

    variable var;
    expr_arithm expr_arithm;
    switch($1->resultat->type){
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
                printf("\nError : Type non reconnu %d(valeur)\n",$1->resultat->type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      quad q = new_quad($2,$1->resultat,$3->resultat,var);
      quad_list ql = add_quad(NULL,q);
      $$ = new_expr_arithm(var,add_quad_list(add_quad_list($1->code,$3->code),ql));
      print_expr_arithm($$);
  }
  |
  expression_arithmetique_f
  {
    $$ =  $1;
  }
  ;
expression_arithmetique_f:
  '(' expression_arithmetique ')'
  {
    $$ =  $2;
  }
  |
  valeur
  //On a reconnu une valeur on doit donc ajouter un nouveau temporaire dans la table des symboles
  {
    variable var;
    switch($1.type){
              case TYPE_INT:
                var = new_variable_int(generate_temp_name(),$1.valUnion.valInt);
                break;
              case TYPE_FLOAT:
                var = new_variable_float(generate_temp_name(),$1.valUnion.valFloat);
                break;
              case TYPE_BOOL:
                var = new_variable_bool(generate_temp_name(),$1.valUnion.valInt);
                break;
              default:
                printf("\nError : Type non reconnu %d(valeur)\n",$1.type);
                exit(EXIT_FAILURE);
                break;
              }
      tableS = add_variable(tableS, var);
      $$ =  new_expr_arithm(var,NULL);
    }
    |
    ID
    {
      variable var = lookup_tds(tableS,$1);
      if(var == NULL){
        printf("ERROR : Variable %s non définie.\n", $1);
        exit(EXIT_FAILURE);
      }
      $$ =  new_expr_arithm(var,NULL);
    }
  ;
operateur_f:
  DIV
  {
    $$ = DIV;
  }
  |
  MULT
  {
    $$ = MULT;
  };

  operateur_m:
  PLUS
  {
    $$ = PLUS;
  }
  |
  MINUS
  {
    $$ = MINUS;
  };

  operateur_affectation:
  LEFTARROW
  {
    $$ = LEFTARROW;
  };

/* Expression Boolean */
expr_boolean:
  expr_boolean OU marqueur expr_boolean
  {
    ;
  }
  |
  expr_boolean ET marqueur expr_boolean
  {
    ;
  }
  |
  NO expr_boolean
  {
    ;
  }
  |
  expression_arithmetique relop expression_arithmetique
  {
    printf("EXPRE BOOLEAAN\n");
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr_bool(new_quad_list(), new_quad_list(), new_quad_list());

    //NULL pour indiquer le label inconnu
    quad trueL = new_quad($2, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);


    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);

  }
  |CONSTBOOL
  {
    ;
  }
  ;
  /* Operateur relationelle */
  relop:
    EGAL
    {
      $$ = EGAL;
    }
    |
    SUP
    {
      $$ = SUP;
    }
    |
    INF
    {
      $$ = INF;
    }
    |
    INFEGAL
    {
      $$ = INFEGAL;
    }
    |
    SUPEGAL
    {
      $$ = SUPEGAL;
    }
    ;
marqueur:
  {
      $$ = compteur_quad;
  }
  ;

/* ----------------Zone de déclarations (ordre obligatoire ici)---------------- */
zone_declarations:
    zone_declaration_constante zone_declaration_input zone_declaration_output
    zone_declaration_global zone_declaration_local BLANKLINE
    {
      printf("\nzone déclaration\n");
    }
  ;
zone_declaration_constante:
    DECLARECONSTANT '{' '$' suite_declarations_constante '$' '}'
    {
      printf("\nzone déclaration DECLARECONSTANT\n");
    }
    | { ; }
  ;
zone_declaration_input:
    DECLAREINPUT '{' '$' suite_declarations_variable '$' '}'
    {
      printf("\nzone déclaration DECLAREINPUT\n");
    }
    | { ; }
  ;
zone_declaration_output:
    DECLAREOUTPUT '{' '$' declaration_variable '$' '}'
    {
      printf("\nzone déclaration DECLAREOUTPUT\n");
    }
    | { ; }
  ;
zone_declaration_global:
    DECLAREGLOBAL '{' '$' suite_declarations_variable '$' '}'
    {
      printf("\nzone déclaration DECLAREGLOBAL\n");
    }
    | { ; }
  ;
zone_declaration_local:
    DECLARELOCAL '{' '$' suite_declarations_variable '$' '}'
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
