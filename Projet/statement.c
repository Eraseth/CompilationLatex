#include "include/statement.h"

statement new_statement(quad_list code, quad_list next_list)
{
  statement new = malloc(sizeof(struct statement_struct));
  new->code = code;
  new->next_list = next_list;
  return new;
}

void print_statement(statement st)
{
  printf("statement\n");
  printf("\n Code :");
  print_quad_list(st->code);
  printf("\n Next List :");
  print_quad_list(st->next_list);
}

void free_statement(statement st)
{
  ;
}
