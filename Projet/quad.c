#include "include/quad.h"
#include "include/expression_arithm.h"
#include "y.tab.h"


quad new_quad(int operateur, variable arg1, variable arg2, variable res){
  quad new_quad = malloc(sizeof(struct quad_struct));
  new_quad->operateur = operateur;
  new_quad->arg1 = arg1;
  new_quad->arg2 = arg2;
  new_quad->res = res;
  return new_quad;
}

void print_quad(quad q){
  print_op(q->operateur);
  printf("\n");
  print_variable(q->arg1);
  print_variable(q->arg2);
  print_variable(q->res);
}

void assembleur_quad(FILE *assembleur_file, quad q){
  variable arg1 = q->arg1;
  variable arg2 = q->arg2;
  variable result = q->res;
  switch (q->operateur) {
    case PLUS:
      fprintf(assembleur_file, "lw $t0, %s\n", arg1->id);
      fprintf(assembleur_file, "lw $t1, %s\n", arg2->id);
      fprintf(assembleur_file, "add $t1,$t0,$t1\n");
      fprintf(assembleur_file, "sw $t0, %s\n", result->id);
      break;
    case MINUS:
      fprintf(assembleur_file, "lw $t0, %s\n", arg1->id);
      fprintf(assembleur_file, "lw $t1, %s\n", arg2->id);
      fprintf(assembleur_file, "sub $t1,$t0,$t1\n");
      fprintf(assembleur_file, "sw $t0, %s\n", result->id);
      break;
    case MULT:
      fprintf(assembleur_file, "lw $t0, %s\n", arg1->id);
      fprintf(assembleur_file, "lw $t1, %s\n", arg2->id);
      fprintf(assembleur_file, "mul $t1,$t0,$t1\n");
      fprintf(assembleur_file, "sw $t0, %s\n", result->id);
      break;
  }
  fprintf(assembleur_file, "\n");
}

void free_quad(quad q){
  if (q != NULL) {
    free(q);
  }
}

void print_op(int operator)
{
  switch(operator){
    case LEFTARROW:
      printf("=")
      ;
      break;
    case DIV:
      printf("/")
      ;
      break;
    case MULT:
      printf("*")
      ;
      break;
    case MINUS:
      printf("-")
      ;
      break;
    case PLUS:
      printf("+")
      ;
      break;
    case NO:
      printf("!")
      ;
      break;
    case ET:
      printf("&&")
      ;
      break;
    case OU:
      printf("||")
      ;
      break;
    case EGAL:
      printf("==")
      ;
      break;
    case SUP:
      printf(">")
      ;
      break;
    case INF:
      printf("<")
      ;
      break;
    case INFEGAL:
      printf("<=")
      ;
      break;
    case SUPEGAL:
      printf(">=")
      ;
      break;
    default:
      printf("Operateur non reconnu\n");
      break;
  }
}
