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
  MINUS expression_arithmetique_f
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
      $$ = new_expr_arithm(temp, add_quad($2->code,q));
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
