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
  if (q == NULL) {
    printf("ERROR : Affichage quad NULL\n");
    exit(EXIT_FAILURE);
  }
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

  /*
  ====================================
  Gestion des opérations arithmétiques
  ====================================
  */
  if (result->type == 0 || result->type == 2) {
    /* Cas entier et boolean (instructions assembleur différentes) */
    switch (q->operateur) {
      case PLUS:
        fprintf(assembleur_file, "# Addition d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "add $t0,$t0,$t1\n");
        fprintf(assembleur_file, "sw $t0,var_%s\n", result->id);
        break;
      case MINUS:
        fprintf(assembleur_file, "# Soustraction d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "sub $t0,$t0,$t1\n");
        fprintf(assembleur_file, "sw $t0,var_%s\n", result->id);
        break;
      case MULT:
        fprintf(assembleur_file, "# Multiplication d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "mul $t0,$t0,$t1\n");
        fprintf(assembleur_file, "sw $t0,var_%s\n", result->id);
        break;
      case DIV:
        fprintf(assembleur_file, "# Division d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "div $t0,$t0,$t1\n");
        fprintf(assembleur_file, "sw $t0,var_%s\n", result->id);
        break;
      case LEFTARROW:
      /* Ajout de EGAL (ou pas) */
        fprintf(assembleur_file, "# Assignation d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "sw $t0,var_%s\n", result->id);
        break;
      }
  } else if (result->type == 1) {
    /* Cas float (instructions assembleur différentes) */
    switch (q->operateur) {
      case PLUS:
        fprintf(assembleur_file, "# Addition d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "l.s $f1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "add.s $f0,$f0,$f1\n");
        fprintf(assembleur_file, "s.s $f0,var_%s\n", result->id);
        break;
      case MINUS:
        fprintf(assembleur_file, "# Soustraction d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "l.s $f1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "sub.s $f0,$f0,$f1\n");
        fprintf(assembleur_file, "s.s $f0,var_%s\n", result->id);
        break;
      case MULT:
        fprintf(assembleur_file, "# Multiplication d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "l.s $f1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "mul.s $f0,$f0,$f1\n");
        fprintf(assembleur_file, "s.s $f0,var_%s\n", result->id);
        break;
      case DIV:
        fprintf(assembleur_file, "# Division d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "l.s $f1,var_%s\n", arg2->id);
        fprintf(assembleur_file, "div.s $f0,$f0,$f1\n");
        fprintf(assembleur_file, "s.s $f0,var_%s\n", result->id);
        break;
      case LEFTARROW:
      /* Ajout de EGAL (ou pas) */
        fprintf(assembleur_file, "# Assignation d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "s.s $f0,var_%s\n", result->id);
        break;
      }
  }

  /*
  ====================================
  Gestion de la conversion (int to flaot et float to int)
  ====================================
  */
  switch (q->operateur) {
    case CONVERSION_INT_FLOAT:
      fprintf(assembleur_file, "# Conversion d'un entier en réel et assignation\n");
      fprintf(assembleur_file, "lw $t2,var_%s\n", arg1->id);
      fprintf(assembleur_file, "mtc1 $t2, $f12\n");
      fprintf(assembleur_file, "cvt.s.w $f1,$f12\n");
      fprintf(assembleur_file, "s.s $f1,var_%s\n", result->id);
      break;
    case CONVERSION_FLOAT_INT:
      fprintf(assembleur_file, "# Conversion d'un réel en entier et assignation\n");
      fprintf(assembleur_file, "l.s $f2,var_%s\n", arg1->id);
      fprintf(assembleur_file, "cvt.w.s $f1,$f2\n");
      fprintf(assembleur_file, "mfc1 $t1, $f1\n");
      fprintf(assembleur_file, "sw $t1,var_%s\n", result->id);
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
      printf("-->")
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
    case CONVERSION_INT_FLOAT:
      printf("int to float")
      ;
      break;
    case CONVERSION_FLOAT_INT:
      printf("float to int")
      ;
      break;
    default:
      printf("Operateur non reconnu\n");
      break;
  }
}
