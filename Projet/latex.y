%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #include "include/expression.h"
  #include "include/gen_assembleur.h"
  #include "include/statement.h"
  #include "y.tab.h"
  #define TEXCC_ERROR_GENERAL 4
  #define VAR_BOOL_FALSE "bool_false"

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
  extern int yylineno;

  int COMPTEUR_ERROR_FOR = 0;
  char *TAB_ID_FOR[1024] = {NULL};

  void yyerror(char *s) {
      fprintf(stderr, "ERROR : Line %d --> %s\n", yylineno, s);
      exit(SYNTAX_ERROR);
  }

  char * generate_temp_name(){
    char * str = malloc(sizeof(char)*64);
    char * str2 = conversion_int_string(compteurTemporaire);
    strcpy(str, "temp");
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
    expr expr;
    statement statement;
    variable var;
}
%token <value> TEXSCI_BEGIN TEXSCI_END BLANKLINE LEFTARROW IN MBOX STRING
%token <value> INTEGER COMMENTAIRE BOOLEAN REAL EMPTYSET
%token <value> WHILE FOR KWTO IF ELSEIF
%token <value> DECLARECONSTANT DECLAREINPUT DECLAREOUTPUT DECLAREGLOBAL DECLARELOCAL
%token <value> NO ET OU EGAL SUP NOEGAL
%token <value> INF INFEGAL SUPEGAL PRINTINT PRINTTEXT
%token <value> PRINTREAL CONSTINT CONSTBOOL DIV
%token <dvalue> CONSTFLOAT
%token <value> MULT MINUS PLUS EOI
%type <value> type marqueur operateur_affectation
%type <valeurSt> valeur
%token <name> ID
%type <expr> expression
%type <statement> structure_controle list_instructions instruction instruction_affectation
%type <statement> instruction_fonction
%type <name> declaration_variable

%right LEFTARROW
%left OU
%left ET
%left EGAL NOEGAL
%left INF INFEGAL SUP SUPEGAL
%left PLUS MINUS
%left MULT DIV
%right NOR


%%
algorithm_list:
    algorithm_list algorithm
  | algorithm
  {
    printf("Success !\n");
  }
  ;
algorithm:
    TEXSCI_BEGIN '{' ID '}'  zone_declarations BLANKLINE zone_instructions TEXSCI_END
    {
      ;
    }
  ;
/* ----------------Zone des instructions---------------- */
zone_instructions:
  list_instructions marqueur
  {
    int nbErr;
    for(nbErr = 0; nbErr < 1024; nbErr++){
      if(TAB_ID_FOR[nbErr] != NULL){
        printf("\nERROR : Variable %s non initialisée.\n", TAB_ID_FOR[nbErr]);
        exit(SEMANTIC_ERROR);
      }
    }
    quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(qNext,$2);
    $1->next_list = complete($1->next_list,$2);
    $1->code = add_quad($1->code,qNext);
    code = $1->code;
  }
  |
  { ; }
  ;
list_instructions:
  instruction marqueur list_instructions
  {
    $1->next_list = complete($1->next_list,$2);
    $$ = new_statement(new_quad_list(),new_quad_list());
    $$->code = add_quad_list($$->code,$1->code);
    $$->next_list = add_quad_list($$->next_list,$3->next_list);
    if ($1->next_list != NULL){
      quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
      set_label(qNext,$2);
      $$->code = add_quad($$->code,qNext);
    }
    $$->code = add_quad_list($$->code,$3->code);
  }
  |
  instruction
  {
    $$ = new_statement(new_quad_list(),new_quad_list());
    //$1->next_list = complete($1->next_list,compteur_quad);
    $$->next_list = add_quad_list($$->next_list,$1->next_list);
    $$->code = add_quad_list($$->code,$1->code);
  }
  ;
instruction:
  '$' instruction_affectation '$' EOI
  {
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  '$' instruction_fonction '$' EOI
  {
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  structure_controle
  {
    $$ = new_statement($1->code,$1->next_list);
  }
  ;
instruction_affectation:
  ID operateur_affectation expression
  {

    if($3->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'assigner une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }
    variable var = lookup_tds(tableS, $1);

    if(var == NULL){
      printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $1);
      exit(OTHER_ERROR);
    }

    set_init_bool_true(var);
    //Ajout du code de l'expression
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), $3->code);

    //Convertit le type pour permettre l'Assignation
    q = new_quad($2,$3->resultat,NULL,var);
    //Ajout de notre nouveau quad (quad d'Assignation)
    ql = add_quad(ql,q);

    $$ = new_statement(ql,new_quad_list());
  }
  ;
instruction_fonction:
    MBOX '{' PRINTINT '('  '$' expression '$' ')' '}'
    {
      variable var = lookup_tds(tableS, $6->resultat->id);
      if(var == NULL){
        printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $6->resultat->id);
        exit(OTHER_ERROR);
      }

      if(var->type != TYPE_INT)
      {
        printf("\nERROR : Line %d --> PrintInt() demande un type entier.\n", yylineno);
        exit(SEMANTIC_ERROR);
      }

      quad q = new_quad(PRINT_INT, var, var, var);
      quad_list ql = add_quad($6->code,q);
      $$ = new_statement(ql,NULL);
    }
    |
    MBOX '{' PRINTREAL '('  '$' expression '$' ')' '}'
    {
      variable var = lookup_tds(tableS, $6->resultat->id);
      if(var == NULL){
        printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $6->resultat->id);
        exit(OTHER_ERROR);
      }

      if(var->type != TYPE_FLOAT)
      {
        printf("\nERROR : Line %d --> PrintReal() demande un type réel.\n", yylineno);
        exit(SEMANTIC_ERROR);
      }

      quad q = new_quad(PRINT_FLOAT, var, var, var);
      quad_list ql = add_quad($6->code,q);
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
  /*
  Structure de contrôle
  */
structure_controle:
  WHILE marqueur '{' '$' expression '$' '}' marqueur '{' list_instructions '}'
  {

    if($5->type_ex != BOOL){
      variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
      //Utile dans le cas ou l'expression test n'est pas de type Boolean (sans false list ni true list)
      quad trueL = new_quad(NOEGAL, $5->resultat, var_bool_false, NULL);
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);

      $5->true_list = add_quad($5->true_list, trueL);
      $5->code = add_quad($5->code, trueL);

      $5->false_list = add_quad($5->false_list, falseL);
      $5->code = add_quad($5->code, falseL);
    }

    $5->true_list = complete($5->true_list, $8); //La true liste pointe sur le marqueur
    $10->next_list = complete($10->next_list, $2); //La next list pointe sur le marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    $$->next_list = add_quad_list($$->next_list, $5->false_list);
    quad q = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q,$8);
    quad q_while = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_while,$2);
    $$->code = add_quad($$->code, q_while);
    $$->code = add_quad_list($$->code, $5->code);
    $$->code = add_quad($$->code, q);
    $$->code = add_quad_list($$->code, $10->code);
    variable m = new_variable_goto($2);
    quad goto_while = new_quad(QUAD_GOTO, NULL, NULL, m);
    $$->code = add_quad($$->code, goto_while);
  }
  |
  IF '{' '$' expression '$' '}' marqueur '{' list_instructions '}'
  {
    if($4->type_ex != BOOL){
      variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
      //Utile dans le cas ou l'expression test n'est pas de type Boolean (sans false list ni true list)
      quad trueL = new_quad(NOEGAL, $4->resultat, var_bool_false, NULL);
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);

      $4->true_list = add_quad($4->true_list, trueL);
      $4->code = add_quad($4->code, trueL);

      $4->false_list = add_quad($4->false_list, falseL);
      $4->code = add_quad($4->code, falseL);
    }

    $4->true_list = complete($4->true_list, $7); //La true liste pointe sur le marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    $$->next_list = add_quad_list($$->next_list, $4->false_list);
    $$->next_list = add_quad_list($$->next_list, $9->next_list);
    /* L'instruction ci-dessus va faire pointer la sortie du "if imbriqué" vers la même sortie
    que le if parent.
    Exemple :
    \If{$4 = 4$}{
      $\mbox{printText($"Test"$)}$\;
      \If{$3 = 4$}{$\mbox{printText($"Test1"$)}$\;}
    }
    La sortie du second if va pointer sur la même que le premier */
    quad q = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q,$7);
    $$->code = add_quad_list($$->code, $4->code);
    $$->code = add_quad($$->code, q);
    $$->code = add_quad_list($$->code, $9->code);
  }
  |
  FOR '{' '$' error_for ID operateur_affectation expression '$' KWTO '$' expression '$' '}' marqueur '{' list_instructions '}'
  {

    int nbErr;
    for(nbErr = 0; nbErr < 1024; nbErr++){
      if(TAB_ID_FOR[nbErr] != NULL && strcmp(TAB_ID_FOR[nbErr], $5) == 0){
        TAB_ID_FOR[nbErr] = NULL;
      }
    }
    COMPTEUR_ERROR_FOR--;

    if($11->type_ex != BOOL){
      variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
      //Utile dans le cas ou l'expression test n'est pas de type Boolean (sans false list ni true list)
      quad trueL = new_quad(NOEGAL, $11->resultat, var_bool_false, NULL);
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);

      $11->true_list = add_quad($11->true_list, trueL);
      $11->code = add_quad($11->code, trueL);

      $11->false_list = add_quad($11->false_list, falseL);
      $11->code = add_quad($11->code, falseL);
    }

    $16->next_list = complete($16->next_list, $14); //La next list pointe sur le marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    variable var_id = lookup_tds(tableS,$5);

    if(var_id == NULL){
      printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $5);
      exit(OTHER_ERROR);
    }
    set_init_bool_true(var_id);
    //Ajout du code de l'expression arithmétiques
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), $7->code);
    //Convertit le type pour permettre l'Assignation
    if((var_id->type == TYPE_INT || var_id->type == TYPE_BOOL) && $7->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, $7->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else if(($7->resultat->type == TYPE_INT || $7->resultat->type == TYPE_BOOL) && var_id->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, $7->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else {
      q = new_quad($6,$7->resultat,NULL,var_id);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(ql,q);
    }
    $$->code = add_quad_list($$->code, ql);
    //Ensuite le label
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,$14);
    $$->code = add_quad($$->code, q_label);
    //Ajout du test (EGAL)
    quad test = new_quad(SUP, var_id, $11->resultat, NULL);
    $$->next_list = add_quad($$->next_list, test);
    $$->code = add_quad($$->code, test);
    //Suivi du code de notre list d'instructions
    $$->code = add_quad_list($$->code, $16->code);
    //Incrémentation de la variable
    quad incr_indice = new_quad(QUAD_INCR, var_id, NULL, var_id);
    $$->code = add_quad($$->code, incr_indice);
    //Et le goto vers le test
    variable m = new_variable_goto($14);
    quad goto_for = new_quad(QUAD_GOTO, NULL, NULL, m);
    $$->code = add_quad($$->code, goto_for);
  }
  |
  ELSEIF '{' '$' expression '$' '}' marqueur '{' list_instructions '}' marqueur '{' list_instructions '}'
  {

    if($4->type_ex != BOOL){
      variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
      //Utile dans le cas ou l'expression test n'est pas de type Boolean (sans false list ni true list)
      quad trueL = new_quad(NOEGAL, $4->resultat, var_bool_false, NULL);
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);

      $4->true_list = add_quad($4->true_list, trueL);
      $4->code = add_quad($4->code, trueL);

      $4->false_list = add_quad($4->false_list, falseL);
      $4->code = add_quad($4->code, falseL);
    }

    $4->true_list = complete($4->true_list, $7); //La true liste pointe sur le marqueur
    $4->false_list = complete($4->false_list, $11); //La false liste pointe sur le second marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    /* L'instruction ci-dessus va faire pointer la sortie du "if imbriqué" vers la même sortie
    que le if parent.
    Exemple :
    \If{$4 = 4$}{
      $\mbox{printText($"Test"$)}$\;
      \If{$3 = 4$}{$\mbox{printText($"Test1"$)}$\;}
    }
    La sortie du second if va pointer sur la même que le premier */
    quad q_label_marqueur1 = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label_marqueur1, $7);
    quad q_label_marqueur2 = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label_marqueur2, $11);
    $$->code = add_quad_list($$->code, $4->code);
    $$->code = add_quad($$->code, q_label_marqueur1);
    $$->next_list = add_quad_list($$->next_list, $9->next_list);
    $$->code = add_quad_list($$->code, $9->code);
    quad goto_else_if1 = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    $$->next_list = add_quad($$->next_list, goto_else_if1);
    $$->code = add_quad($$->code, goto_else_if1);
    $$->code = add_quad($$->code, q_label_marqueur2);
    $$->next_list = add_quad_list($$->next_list, $13->next_list);
    $$->code = add_quad_list($$->code, $13->code);
    quad goto_else_if2 = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    $$->next_list = add_quad($$->next_list, goto_else_if2);
    $$->code = add_quad($$->code, goto_else_if2);
  }
  ;

expression:
//Expression arithmétique
 expression DIV expression
  {
    if($1->type_ex == BOOL || $3->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'éffectuer un calcul sur une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }

    variable var;
    expr nex_expr;
    switch(testTypeVariables($1->resultat, $3->resultat)){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT: case -1:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      }
    tableS = add_variable(tableS, var);
    quad q = new_quad(DIV,$1->resultat,$3->resultat,var);
    $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression MULT expression
  {
    if($1->type_ex == BOOL || $3->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'éffectuer un calcul sur une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }

    variable var;
    expr nex_expr;
    switch(testTypeVariables($1->resultat, $3->resultat)){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT: case -1:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      }
      tableS = add_variable(tableS, var);
      quad q = new_quad(MULT,$1->resultat,$3->resultat,var);
      $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression PLUS expression
  {
    if($1->type_ex == BOOL || $3->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'éffectuer un calcul sur une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }

    variable var;
    expr nex_expr;
    switch(testTypeVariables($1->resultat, $3->resultat)){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT: case -1:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      }
    tableS = add_variable(tableS, var);
    quad q = new_quad(PLUS,$1->resultat,$3->resultat,var);
    $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression MINUS expression
  {
    if($1->type_ex == BOOL || $3->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'éffectuer un calcul sur une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }

    variable var;
    expr nex_expr;
    switch(testTypeVariables($1->resultat, $3->resultat)){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT: case -1:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      }
    tableS = add_variable(tableS, var);
    quad q = new_quad(MINUS, $1->resultat,$3->resultat,var);
    $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 MINUS expression %prec NOR
  {
    variable temp;
    switch($2->resultat->type){
      case TYPE_INT:
        temp = new_variable_int(generate_temp_name(),0);
        break;
      case TYPE_FLOAT:
        temp = new_variable_float(generate_temp_name(),0);
        break;
      case TYPE_BOOL:
        printf("\nERROR : Line %d --> Impossible d'inverser la valeur d'un Boolean (utilisation de la syntaxe suivante : \"\\neg\")\n", yylineno);
        exit(SEMANTIC_ERROR);
        break;
      default:
        printf("\nERROR : Line %d --> Type non reconnu %d (valeur)\n", yylineno,$2->resultat->type);
        exit(OTHER_ERROR);
        break;
      }
      tableS = add_variable(tableS, temp);
      quad q = new_quad(NEGATE,$2->resultat,NULL,temp);
      $$ = new_expr(add_quad($2->code,q), temp, NULL, NULL, ARITHM);
  }
  |
 PLUS expression %prec NOR
  {
    if($2->type_ex == BOOL){
      printf("\nERROR : Line %d --> Il n'est pas possible d'éffectuer un calcul sur une expression booléènne.\n", yylineno);
      exit(SEMANTIC_ERROR);
    }

    $$ = new_expr($2->code,$2->resultat,$2->true_list,$2->false_list,$2->type_ex);
  }
  |
  //Expression boolean (relop)
  expression OU marqueur expression
  {
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    $1->false_list = complete($1->false_list, $3);
    $$->true_list = add_quad_list($1->true_list, $4->true_list);
    $$->false_list = add_quad_list($$->false_list, $4->false_list);
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,$3);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad($$->code, q_label);
    $$->code = add_quad_list($$->code, $4->code);
  }
  |
  expression ET marqueur expression
  {
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    $1->true_list = complete($1->true_list, $3);
    $$->false_list = add_quad_list($1->false_list, $4->false_list);
    $$->true_list = add_quad_list($$->true_list, $4->true_list);
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,$3);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad($$->code, q_label);
    $$->code = add_quad_list($$->code, $4->code);
  }
  |
  expression EGAL expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(EGAL, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  expression NOEGAL expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(NOEGAL, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  expression SUP expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(SUP, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  expression INF expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(INF, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  expression INFEGAL expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(INFEGAL, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  expression SUPEGAL expression
  {
    variable res1 = $1->resultat; //Récupère la valeur de l'expr arithm
    variable res2 = $3->resultat;
    $$ = new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), BOOL);
    //NULL pour indiquer le label inconnu
    quad trueL = new_quad(SUPEGAL, res1, res2, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    $$->code = add_quad_list($$->code, $1->code);
    $$->code = add_quad_list($$->code, $3->code);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |
  NO expression %prec NOR
  {
    if($2->type_ex != BOOL){
      variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
      //Utile dans le cas ou l'expression test n'est pas de type Boolean (sans false list ni true list)
      quad trueL = new_quad(NOEGAL, $2->resultat, var_bool_false, NULL);
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);

      $2->true_list = add_quad($2->true_list, trueL);
      $2->code = add_quad($2->code, trueL);

      $2->false_list = add_quad($2->false_list, falseL);
      $2->code = add_quad($2->code, falseL);
    }

    $$ = new_expr($2->code, NULL, $2->false_list, $2->true_list, BOOL);
  }
  |
  //Les valeurs
  ID
  {
    variable var = lookup_tds(tableS,$1);
    if(var == NULL){
      printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $1);
      exit(OTHER_ERROR);
    }

    if (var->init_bool==0)
    {
      if(COMPTEUR_ERROR_FOR > 0){
        TAB_ID_FOR[COMPTEUR_ERROR_FOR-1] = strdup($1);
      } else {
        printf("\nERROR : Line %d --> Variable %s non initialisée.\n", yylineno, $1);
        exit(SEMANTIC_ERROR);
      }
    }

    $$ =  new_expr(new_quad_list(), var, new_quad_list(), new_quad_list(), IDT);
  }
  |
  valeur
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
            printf("\nERROR : Line %d --> Type non reconnu %d (valeur)\n", yylineno, $1.type);
            exit(OTHER_ERROR);
            break;
          }
    tableS = add_variable(tableS, var);
    $$ =  new_expr(new_quad_list(), var, new_quad_list(), new_quad_list(), CONST);
  }
  |
  '(' expression ')'
  {
    $$ = new_expr($2->code,$2->resultat,$2->true_list,$2->false_list,$2->type_ex);
  }
  ;

operateur_affectation:
  LEFTARROW
  {
    $$ = LEFTARROW;
  };

marqueur:
  {
      $$ = compteur_quad;
      compteur_quad++;
  }
  ;

error_for:
  {
      COMPTEUR_ERROR_FOR++;
  }
  ;

/* ----------------Zone de déclarations (ordre obligatoire ici)---------------- */
zone_declarations:
    zone_declarations declaration
    {
      ;
    }
    | { ; }
  ;
declaration:
  zone_declaration_constante { ; }
  |
  zone_declaration_input { ; }
  |
  zone_declaration_output { ; }
  |
  zone_declaration_global { ; }
  |
  zone_declaration_local { ; }
  ;
zone_declaration_constante:
    DECLARECONSTANT '{' '$' suite_declarations_constante '$' '}'
    {
      ;
    }
  ;
zone_declaration_input:
    DECLAREINPUT '{' '$' suite_declarations_variable '$' '}'
    {
      ;
    }
  ;
zone_declaration_output:
    DECLAREOUTPUT '{' '$' declaration_variable '$' '}'
    {
      ;
    }
  ;
zone_declaration_global:
    DECLAREGLOBAL '{' '$' suite_declarations_variable_global '$' '}'
    {
      ;
    }
  ;
zone_declaration_local:
    DECLARELOCAL '{' '$' suite_declarations_variable '$' '}'
    {
      ;
    }
  ;
suite_declarations_constante:
    suite_declarations_constante_aux
    {
      ;
    }
    | EMPTYSET
    {
      ;
    }
    | { ; }
  ;

suite_declarations_constante_aux:
  declaration_constante ',' suite_declarations_constante_aux
  {
    ;
  }
  |
  declaration_constante
  {
    ;
  }

suite_declarations_variable_global:
  suite_declarations_variable_global_aux
  {
    ;
  }
  | EMPTYSET
  {
    ;
  }
  | { ; }
  ;
suite_declarations_variable_global_aux:
declaration_variable ',' suite_declarations_variable_global_aux
{
  variable var = lookup_tds(tableS,$1);
  if(var == NULL){
    printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $1);
    exit(OTHER_ERROR);
  }
  set_init_bool_true(var);
}
|
declaration_variable
{
  variable var = lookup_tds(tableS,$1);
  if(var == NULL){
    printf("\nERROR : Line %d --> Variable %s non définie.\n", yylineno, $1);
    exit(OTHER_ERROR);
  }
  set_init_bool_true(var);
}
;
suite_declarations_variable:
    suite_declarations_variable_aux
    {
      ;
    }
    | EMPTYSET
    {
      ;
    }
    | { ; }
  ;
  suite_declarations_variable_aux:
      declaration_variable ',' suite_declarations_variable
      {
        ;
      }
      |
      declaration_variable
      {
        ;
      }
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
          printf("\n\nERROR : Line %d --> Type non reconnu %d(declaration_constante)\n", yylineno, $5);
          exit(OTHER_ERROR);
          break;
      }
      set_init_bool_true(var);
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
        printf("\n\nERROR : Line %d --> Type non reconnu %d(declaration_variable)\n", yylineno, $3);
        exit(OTHER_ERROR);
        break;
      }
      tableS = add_variable(tableS, var);
      $$ = strdup($1);
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
  FILE *fd = fopen("output.s", "w+");
  if (argc == 2) {
    if ((yyin = fopen(argv[1], "r")) == NULL) {
      fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
      exit(OTHER_ERROR);
    }
  } else {
    fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
    exit(OTHER_ERROR);
  }
  // Ajoute une variable dans la table des symboles pour comparer les boolean
  //Ex : if(true) générera une comparaison entre la variable CONSTBOOL et VAR_BOOL_FALSE
  variable var_bool_false = new_variable_int(VAR_BOOL_FALSE, 0);
  tableS = add_variable(tableS, var_bool_false);
  yyparse();
  generate_text(fd, code);
  printf("\n------------------Code (quads)------------------\n");
  print_quad_list(code);
  generate_data(fd, tableS);
  fclose(yyin);
  fclose(fd);
  texcc_lexer_free();
  printf("------------------Table des symboles------------------\n");
  print_tds(tableS);
  free_tds(tableS);
  free_quad_list(code);
  return EXIT_SUCCESS;
}
