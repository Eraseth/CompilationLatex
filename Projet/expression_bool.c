#include "include/expression_bool.h"

expr_bool new_expr_bool(quad_list code, quad_list true_list, quad_list false_list)
{
  expr_bool new = malloc(sizeof(struct expr_bool_struct));
  new->code = code;
  new->true_list = true_list;
  new->false_list = false_list;
  return new;
}

void print_expr_bool(expr_bool eb)
{
  printf("Expression boolean\n");
  printf("\n Code :");
  print_quad_list(eb->code);
  printf("\n True List :");
  print_quad_list(eb->true_list);
  printf("\n False List :");
  print_quad_list(eb->false_list);
}

void free_expr_bool(expr_bool eb)
{
  ;
}
