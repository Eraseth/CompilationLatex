#include "include/expression_arithm.h"

expr_arithm new_expr_arithm(variable var,quad_list ql)
{
  expr_arithm new = malloc(sizeof(struct expr_arithm_struct));
  new->resultat = var;
  new->code = ql;
  return new;
}
void print_expr_arithm(expr_arithm e)
{
  printf("Expression arithmetique \n resultat :");
  print_variable(e->resultat);
  printf("\n code :");
  print_quad_list(e->code);
}
void free_expr_arithm(expr_arithm e)
{
  ;
}
