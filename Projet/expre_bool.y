expr_boolean:
  expr_boolean OU marqueur expr_boolean_t
  {
    ;
  }
  |
  expr_boolean_t {
    ;
  }
  ;
expr_boolean_t:
  expr_boolean_t ET marqueur expr_boolean_f
  {
    ;
  }
  |
  expr_boolean_f
  {
    ;
  }
  ;
expr_boolean_f:
  '(' expr_boolean ')'
  {
    ;
  }
  |
  ID
  {
      ;
  }
  |
  CONSTBOOL
  {
    ;
  }
  |
  NO expr_boolean_f
  {
    ;
  }
  |
  expression_arithmetique relop expression_arithmetique
  {
    ;
  }
  ;

  expr_boolean:
  expr_boolean OU marqueur expr_boolean
  {
    printf("expr_boolean : expr_boolean OU marqueur expr_boolean\n");
    $$ = new_expr_bool(new_quad_list(),new_quad_list(), new_quad_list());
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
  expr_boolean ET marqueur expr_boolean
  {
    printf("expr_boolean : expr_boolean ET marqueur expr_boolean\n");
    $$ = new_expr_bool(new_quad_list(),new_quad_list(), new_quad_list());
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
  '(' expr_boolean ')'
  {
    printf("'(' expr_boolean ')'\n");
    $$ = new_expr_bool($2->code, $2->true_list, $2->false_list);
  }
  |
  NO expr_boolean
  {
    printf("expr_boolean : NO expr_boolean\n");
    //Pour effectuer le NO on inverse la False List et la True List
    $$ = new_expr_bool($2->code, $2->false_list, $2->true_list);
  }
  |
  expression_arithmetique relop expression_arithmetique
  {
    printf("expr_boolean : expression_arithmetique relop expression_arithmetique\n");
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
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  |CONSTBOOL
  {
    //En fonction de la valeur de const bool jump soit à la false list, soit à la true list
    $$ = new_expr_bool(new_quad_list(), new_quad_list(), new_quad_list());
    if(yylval.value){
      quad trueL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
      $$->true_list = add_quad($$->true_list, trueL);
      $$->code = add_quad($$->code, trueL);
    } else {
      quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
      $$->false_list = add_quad($$->false_list, falseL);
      $$->code = add_quad($$->code, falseL);
    }
  }
  |ID
  {
    $$ = new_expr_bool(new_quad_list(), new_quad_list(), new_quad_list());
    variable var = lookup_tds(tableS,$1);
    variable var_bool_false = lookup_tds(tableS,VAR_BOOL_FALSE);
    if(var == NULL){
      printf("ERROR : Variable %s non définie.\n", $1);
      exit(EXIT_FAILURE);
    };
    quad trueL = new_quad(NOEGAL, var, var_bool_false, NULL);
    quad falseL = new_quad(QUAD_GOTO, NULL, NULL, NULL);
    //Génération des true et false lists
    $$->true_list = add_quad($$->true_list, trueL);
    $$->false_list = add_quad($$->false_list, falseL);
    /* On ajoute la True List et la False List dans notre code (on les compléteras par
    référence au fur et a mesure qu'on remonte dans notre grammaire) */
    $$->code = add_quad($$->code, trueL);
    $$->code = add_quad($$->code, falseL);
  }
  ;
