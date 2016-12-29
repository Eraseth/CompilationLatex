#include "include/structure_controle.h"

struct_ctrl new_struct_ctrl(quad_list code, quad_list next_list){
  struct_ctrl new = malloc(sizeof(struct struct_ctrl_struct));
  new->code = code;
  new->next_list = next_list;
  return new;
}

void print_struct_ctrl(struct_ctrl str_ctrl){
  printf("Structure de contrôle\n");
  printf("\n Code :");
  print_quad_list(str_ctrl->code);
  printf("\n Next list :");
  print_quad_list(str_ctrl->next_list);
}

void free_struct_ctrl(struct_ctrl str_ctrl){
  ;
}
