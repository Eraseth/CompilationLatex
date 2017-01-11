%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "include/tableSymbole.h"
  #include "include/quad_list.h"
  #include "include/quad.h"
  #include "include/variable.h"
  #include "include/expression_arithm.h"
  #include "include/expression_bool.h"
  #include "include/expression.h"
  #include "include/gen_assembleur.h"
  #include "include/statement.h"
  #include "y.tab.h"
  #define TEXCC_ERROR_GENERAL 4
  #define VAR_BOOL_FALSE "var_bool_false"
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
%token <name> ID
%type <value> type marqueur operateur_affectation
%type <valeurSt> valeur
%type <expr> expression
%type <var> argument_real argument_entier
%type <statement> structure_controle list_instructions instruction instruction_affectation
%type <statement> instruction_fonction

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
    quad qNext = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(qNext,compteur_quad);
    $1->code = add_quad($1->code,qNext);
    code = $1->code;
  }
  |
  { ; }
  ;
list_instructions:
  instruction marqueur list_instructions
  {
    printf("list_instructions : instruction marqueur list_instructions --> Marqueur : %d\n", $2);
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
    printf("list_instructions : instruction\n");
    $$ = new_statement(new_quad_list(),new_quad_list());
    //$1->next_list = complete($1->next_list,compteur_quad);
    $$->next_list = add_quad_list($$->next_list,$1->next_list);
    $$->code = add_quad_list($$->code,$1->code);
  }
  ;
instruction:
  '$' instruction_affectation '$' EOI
  {
    printf("instruction : '$' instruction_affectation '$' EOI");
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  '$' instruction_fonction '$' EOI
  {
    printf("instruction : '$' instruction_fonction '$' EOI");
    $$ = new_statement($2->code,$2->next_list);
  }
  |
  structure_controle
  {
    printf("instruction : structure_controle");
    $$ = new_statement($1->code,$1->next_list);
  }
  ;
instruction_affectation:
  ID operateur_affectation expression
  {
    variable var = lookup_tds(tableS, $1);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    }
    //Ajout du code de l'expression
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), $3->code);
    //Convertit le type pour permettre l'Assignation
    if((var->type == TYPE_INT || var->type == TYPE_BOOL) && $3->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, $3->resultat, NULL, var);
      ql = add_quad(ql,q);
    } else if(($3->resultat->type == TYPE_INT || $3->resultat->type == TYPE_BOOL) && var->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, $3->resultat, NULL, var);
      ql = add_quad(ql,q);
    } else {
      q = new_quad($2,$3->resultat,NULL,var);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(ql,q);
    }
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
  WHILE marqueur '{' '$' expression '$' '}' marqueur '{' list_instructions '}'
  {
    printf("structure_controle : WHILE marqueur '{' '$' expression '$' '}' marqueur '{' list_instructions '}' --> Marqueur1 : %d --> Marqueur1 : %d\n", $2, $8);
    $5->true_list = complete($5->true_list, $8); //La true liste pointe sur le marqueur
    $10->next_list = complete($10->next_list, $2); //La next list pointe sur le marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    $$->next_list = add_quad_list($$->next_list, $5->false_list);
    print_quad_list($$->next_list);
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
    print_quad_list($$->code);
  }
  |
  IF '{' '$' expression '$' '}' marqueur '{' list_instructions '}'
  {
    printf("structure_controle : IF '{' '$' expression '$' '}' marqueur '{' list_instructions '}' --> Marqueur : %d\n", $7);
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
    print_quad_list($$->code);
  }
  |
  FOR '{' '$' ID operateur_affectation expression '$' KWTO '$' expression '$' '}' marqueur '{' list_instructions '}'
  {
    printf("structure_controle : FOR marqueur '{' '$' instruction_affectation '$' KWTO '$' expression '$' '}' '{' list_instructions '}'\n");
    $15->next_list = complete($15->next_list, $13); //La next list pointe sur le marqueur
    $$= new_statement(new_quad_list(), new_quad_list());
    variable var_id = lookup_tds(tableS,$4);
    if(var_id == NULL){
      printf("ERROR : Variable %s non définie.\n", $4);
      exit(EXIT_FAILURE);
    }
    //Ajout du code de l'expression arithmétiques
    quad_list ql;
    quad q;
    ql = add_quad_list(new_quad_list(), $6->code);
    //Convertit le type pour permettre l'Assignation
    if((var_id->type == TYPE_INT || var_id->type == TYPE_BOOL) && $6->resultat->type == TYPE_FLOAT){
      //Float to Int
      q = new_quad(CONVERSION_FLOAT_INT, $6->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else if(($6->resultat->type == TYPE_INT || $6->resultat->type == TYPE_BOOL) && var_id->type == TYPE_FLOAT){
      //Int to Float
      q = new_quad(CONVERSION_INT_FLOAT, $6->resultat, NULL, var_id);
      ql = add_quad(ql,q);
    } else {
      q = new_quad($5,$6->resultat,NULL,var_id);
      //Ajout de notre nouveau quad (quad d'Assignation)
      ql = add_quad(ql,q);
    }
    $$->code = add_quad_list($$->code, ql);
    //Ensuite le label
    quad q_label = new_quad(QUAD_LABEL, NULL, NULL, NULL);
    set_label(q_label,$13);
    $$->code = add_quad($$->code, q_label);
    //Ajout du test (EGAL)
    quad test = new_quad(SUPEGAL, var_id, $10->resultat, NULL);
    $$->next_list = add_quad($$->next_list, test);
    $$->code = add_quad($$->code, test);
    //Suivi du code de notre list d'instructions
    $$->code = add_quad_list($$->code, $15->code);
    //Incrémentation de la variable
    quad incr_indice = new_quad(QUAD_INCR, var_id, NULL, var_id);
    $$->code = add_quad($$->code, incr_indice);
    //Et le goto vers le test
    variable m = new_variable_goto($13);
    quad goto_for = new_quad(QUAD_GOTO, NULL, NULL, m);
    $$->code = add_quad($$->code, goto_for);
  }
  |
  ELSEIF '{' '$' expression '$' '}' marqueur '{' list_instructions '}' marqueur '{' list_instructions '}'
  {
    printf("structure_controle : ELSEIF '{' '$' expression '$' '}' marqueur '{' list_instructions '}' marqueur '{' list_instructions '}'\n");
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
    if (($1->resultat->type) != ($3->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,$1->resultat->id,$3->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr nex_expr;
    switch($1->resultat->type){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
    case TYPE_FLOAT:
      var = new_variable_float(generate_temp_name(), 0.0);
      break;
    case TYPE_BOOL:
      var = new_variable_bool(generate_temp_name(), 0);
      break;
    default:
      printf("\nError : Type non reconnu %d (valeur)_n", $1->resultat->type);
      exit(EXIT_FAILURE);
      break;
    }
    tableS = add_variable(tableS, var);
    quad q = new_quad(DIV,$1->resultat,$3->resultat,var);
    $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression MULT expression
  {
    if (($1->resultat->type) != ($3->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,$1->resultat->id,$3->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr nex_expr;
    switch($1->resultat->type){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      default:
        printf("\nError : Type non reconnu %d (valeur)_n", $1->resultat->type);
        exit(EXIT_FAILURE);
        break;
      }
      tableS = add_variable(tableS, var);
      quad q = new_quad(MULT,$1->resultat,$3->resultat,var);
      $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression PLUS expression
  {
    if (($1->resultat->type) != ($3->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,$1->resultat->id,$3->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr nex_expr;
    switch($1->resultat->type){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
    case TYPE_FLOAT:
      var = new_variable_float(generate_temp_name(), 0.0);
      break;
    case TYPE_BOOL:
      var = new_variable_bool(generate_temp_name(), 0);
      break;
    default:
      printf("\nError : Type non reconnu %d (valeur)_n", $1->resultat->type);
      exit(EXIT_FAILURE);
      break;
    }
    tableS = add_variable(tableS, var);
    quad q = new_quad(PLUS,$1->resultat,$3->resultat,var);
    $$ = new_expr(add_quad(add_quad_list($1->code,$3->code),q), var, NULL, NULL, ARITHM);
  }
  |
 expression MINUS expression
  {
    if (($1->resultat->type) != ($3->resultat->type))
    {
      fprintf(stderr, "\n: Les variables %s et %s ne sont pas du mêmes types"
      ,$1->resultat->id,$3->resultat->id);
      exit(EXIT_FAILURE);
    }
    variable var;
    expr nex_expr;
    switch($1->resultat->type){
      case TYPE_INT:
        var = new_variable_int(generate_temp_name(), 0);
        break;
      case TYPE_FLOAT:
        var = new_variable_float(generate_temp_name(), 0.0);
        break;
      case TYPE_BOOL:
        var = new_variable_bool(generate_temp_name(), 0);
        break;
      default:
        printf("\nError : Type non reconnu %d (valeur)_n", $1->resultat->type);
        exit(EXIT_FAILURE);
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
        printf("\nError : Impossible d'inverser la valeur d'un Boolean (utilisation de la syntaxe suivante : \"\\neg\")\n");
        exit(EXIT_FAILURE);
        break;
      default:
        printf("\nError : Type non reconnu %d(valeur)\n",$2->resultat->type);
        exit(EXIT_FAILURE);
        break;
      }
      tableS = add_variable(tableS, temp);
      quad q = new_quad(NEGATE,$2->resultat,NULL,temp);
      $$ = new_expr(add_quad($2->code,q), temp, NULL, NULL, ARITHM);
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
    printf("expr_boolean : NO expr_boolean\n");
    //Pour effectuer le NO on inverse la False List et la True List
    $$ = new_expr($2->code, NULL, $2->false_list, $2->true_list, BOOL);
  }
  |
  //Les valeurs
  ID
  {
    $$ =  new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), IDT);
    variable var = lookup_tds(tableS,$1);
    variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    }

    //Utile dans le cas l'id est directement testé dans un une expr boolean
    quad trueL = new_quad(NOEGAL, var, var_bool_false, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
    $$->resultat = var;
  }
  |
  valeur
  {
    $$ =  new_expr(new_quad_list(), NULL, new_quad_list(), new_quad_list(), CONST);
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
            if($1.valUnion.valInt){
              quad trueL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
              $$->true_list = add_quad($$->true_list, trueL);
              $$->code = add_quad($$->code, trueL);
            } else {
              quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
              $$->false_list = add_quad($$->false_list, falseL);
              $$->code = add_quad($$->code, falseL);
            }
            break;
          default:
            printf("\nError : Type non reconnu %d(valeur)\n",$1.type);
            exit(EXIT_FAILURE);
            break;
          }
    tableS = add_variable(tableS, var);
    $$->resultat = var;
  }
  |
  '(' expression ')'
  {
    $$ =  $2;
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
  /* Ajoute une variable dans la table des symboles pour comparer les boolean
  Ex : if(true) générera une comparaison entre la variable CONSTBOOL et VAR_BOOL_FALSE */
  variable var_bool_false = new_variable_int(VAR_BOOL_FALSE, 0);
  tableS = add_variable(tableS, var_bool_false);
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
