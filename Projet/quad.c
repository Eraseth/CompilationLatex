#include "include/quad.h"


quad new_quad(int operateur, variable arg1, variable arg2, variable res){
  quad new_quad = malloc(sizeof(struct quad_struct));
  new_quad->operateur = operateur;
  new_quad->arg1 = arg1;
  new_quad->arg2 = arg2;
  new_quad->res = res;
  return new_quad;
}

void print_quad(quad q){
  printf("%d\n", q->operateur);
  print_variable(q->arg1);
  print_variable(q->arg2);
  print_variable(q->res);
}

void free_quad(quad q){
  if (q != NULL) {
    free(q);
  }
}
