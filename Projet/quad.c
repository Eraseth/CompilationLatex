#include "include/quad.h"
#include "include/expression_arithm.h"
#include "include/expression_bool.h"
#include "include/expression.h"
#include "include/statement.h"
#include "y.tab.h"


quad new_quad(int operateur, variable arg1, variable arg2, variable res){
  quad new_quad = malloc(sizeof(struct quad_struct));
  new_quad->operateur = operateur;
  new_quad->arg1 = arg1;
  new_quad->arg2 = arg2;
  new_quad->res = res;
  new_quad->label = -1;
  return new_quad;
}

void set_label(quad q, int label){
  q->label = label;
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
  // printf("Label : %d\n", q);
}

void assembleur_quad(FILE *assembleur_file, quad q){
  variable arg1 = q->arg1;
  variable arg2 = q->arg2;
  variable result = q->res;

  if (q->label > -1) {
    fprintf(assembleur_file, "%s:\n", parse_label(q->label));
  }
  if(arg1 == NULL && arg2 == NULL && result == NULL && q->operateur == QUAD_LABEL)
  {
    return ;//Ce quad sert uniquement à générer un label
  }
  /*
  ====================================
  Gestion des opérations arithmétiques
  ====================================
  */
  if (result == NULL) {
    printf("ERREUR, quad contenant un résultat inconnu.\n");
    print_quad(q);
    exit(EXIT_FAILURE);
  }
  else if (result->type == 0 || result->type == 2) {
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
      case NEGATE:
        fprintf(assembleur_file, "# Negation d'un entier\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "neg $t0,$t0\n");
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
      case QUAD_INCR:
        fprintf(assembleur_file, "# Incrémentation de un d'une variable\n");
        fprintf(assembleur_file, "lw $t0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "li $t1,1\n");
        fprintf(assembleur_file, "add $t0,$t0,$t1\n");
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
      case NEGATE:
        fprintf(assembleur_file, "# Negation d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "neg.s $f0,$f0\n");
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
      case QUAD_INCR:
        fprintf(assembleur_file, "# Incrémentation d'un réel\n");
        fprintf(assembleur_file, "l.s $f0,var_%s\n", arg1->id);
        fprintf(assembleur_file, "li $f1,1.0\n");
        fprintf(assembleur_file, "add.s $f0,$f0,$f1\n");
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
  ========================================================
  Gestion de la conversion (int to flaot et float to int),
  de l'affichage des valeurs en fonction de leur type,
  des opérateurs de comparaison
  ========================================================
  */
  switch (q->operateur) {
    /*
    -------------------------------------------------------
    Gestion de la conversion (int to flaot et float to int)
    -------------------------------------------------------
    */
    case CONVERSION_INT_FLOAT:
      fprintf(assembleur_file, "# Conversion d'un entier en réel et assignation\n");
      char registreDestFloat[3] = "$f1";
      convertIntToFloat(assembleur_file, arg1, "$t1", registreDestFloat);
      fprintf(assembleur_file, "s.s %s,var_%s\n", registreDestFloat, result->id);
      break;
    case CONVERSION_FLOAT_INT:
      fprintf(assembleur_file, "# Conversion d'un réel en entier et assignation\n");
      char registreDestInt[3] = "$t1";
      convertFloatToInt(assembleur_file, arg1, "$f2", "$f1", registreDestInt);
      fprintf(assembleur_file, "sw %s,var_%s\n", registreDestInt, result->id);
      break;
    /*
    -------------------------------------------------------
    Gestion de l'affichage' (int to flaot et float to int)
    -------------------------------------------------------
    */
    case PRINT_INT:
      fprintf(assembleur_file, "# Affichage d'un entier\n");
      fprintf(assembleur_file, "li $v0,1\n");
      fprintf(assembleur_file, "lw $a0,var_%s\n", arg1->id);
      fprintf(assembleur_file, "syscall\n");
      break;
    case PRINT_FLOAT:
      fprintf(assembleur_file, "# Affichage d'un float\n");
      fprintf(assembleur_file, "li $v0,2\n");
      fprintf(assembleur_file, "l.s $f12,var_%s\n", arg1->id);
      fprintf(assembleur_file, "syscall\n");
      break;
    case PRINT_STRING:
      fprintf(assembleur_file, "# Affichage d'un string\n");
      fprintf(assembleur_file, "li $v0,4\n");
      fprintf(assembleur_file, "la $a0,var_%s\n", arg1->id);
      fprintf(assembleur_file, "syscall\n");
      break;
    /*
    -------------------------------------------------------
    Gestion des opérateurs de comparaison (<, ==, !=, ...)
    -------------------------------------------------------
    */
    case EGAL:
      fprintf(assembleur_file, "# Jump conditionel (==)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
        fprintf(assembleur_file, "# Type int ou bool\n");
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
        fprintf(assembleur_file, "beq $t1, $t2, %s\n", parse_label(result->val.iValue));

          break;
        case TYPE_FLOAT:
        fprintf(assembleur_file, "# Type float\n");
        //TODO Générer l'assembleur pour la comparaison de float
          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }

      break;
    case NOEGAL:
      fprintf(assembleur_file, "# Jump conditionel (!=)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
        fprintf(assembleur_file, "# Type int ou bool\n");
        fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
        fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
        fprintf(assembleur_file, "bne $t1, $t2, %s\n", parse_label(result->val.iValue));

          break;
        case TYPE_FLOAT:
        fprintf(assembleur_file, "# Type float\n");
        //TODO Générer l'assembleur pour la comparaison de float
          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }

      break;
    case SUP:
      fprintf(assembleur_file, "# Jump conditionel (>)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
          fprintf(assembleur_file, "# Type int ou bool\n");
          fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
          fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
          fprintf(assembleur_file, "bgt $t1, $t2, %s\n", parse_label(result->val.iValue));
        break;
          break;
        case TYPE_FLOAT:

          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }
      break;
    case INF:
      fprintf(assembleur_file, "# Jump conditionel (<)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
          fprintf(assembleur_file, "# Type int ou bool\n");
          fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
          fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
          fprintf(assembleur_file, "blt $t1, $t2, %s\n", parse_label(result->val.iValue));
          break;
        case TYPE_FLOAT:

          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }
      break;
    case INFEGAL:
      fprintf(assembleur_file, "# Jump conditionel (<=)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
            fprintf(assembleur_file, "# Type int ou bool\n");
            fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
            fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
            fprintf(assembleur_file, "ble $t1, $t2, %s\n", parse_label(result->val.iValue));
          break;
        case TYPE_FLOAT:

          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }

      break;
    case SUPEGAL:
      fprintf(assembleur_file, "# Jump conditionel (>=)\n");
      switch (testTypeVariables(arg1, arg2)) {
        case TYPE_INT: case TYPE_BOOL:
          fprintf(assembleur_file, "# Type int ou bool\n");
          fprintf(assembleur_file, "lw $t1,var_%s\n", arg1->id);
          fprintf(assembleur_file, "lw $t2,var_%s\n", arg2->id);
          fprintf(assembleur_file, "bge $t1, $t2, %s\n", parse_label(result->val.iValue));
          break;
        case TYPE_FLOAT:

          break;
        case -1:
          /* Conversion en float */
          // if (arg1->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          // if(arg2->type != TYPE_FLOAT) {
          //   convertIntToFloat(assembleur_file, arg1, "$t2", "$f1");
          // }
          break;
      }
      break;
      case QUAD_GOTO:
        fprintf(assembleur_file, "# Jump\n");
        fprintf(assembleur_file, "j %s\n", parse_label(result->val.iValue));
        break;
  }
  fprintf(assembleur_file, "\n");
}


void convertIntToFloat(FILE *assembleur_file, variable arg, char * registerSrc, char * registerDest){
  //fprintf(assembleur_file, "lw $t2,var_%s\n", arg1->id);
  fprintf(assembleur_file, "lw %s,var_%s\n", registerSrc, arg->id);
  //fprintf(assembleur_file, "mtc1 $t2, $f12\n");
  fprintf(assembleur_file, "mtc1 %s, $f12\n", registerSrc);
  //fprintf(assembleur_file, "cvt.s.w $f1,$f12\n");
  fprintf(assembleur_file, "cvt.s.w %s,$f12\n", registerDest);
}

void convertFloatToInt(FILE *assembleur_file, variable arg, char * registerSrc, char * registerTemp, char * registerDest){
  //fprintf(assembleur_file, "l.s $f2,var_%s\n", arg1->id);
  fprintf(assembleur_file, "l.s %s,var_%s\n", registerSrc, arg->id);
  //fprintf(assembleur_file, "cvt.w.s $f1,$f2\n");
  fprintf(assembleur_file, "cvt.w.s %s,%s\n", registerTemp, registerSrc);
  //fprintf(assembleur_file, "mfc1 $t1, $f1\n");
  fprintf(assembleur_file, "mfc1 %s, %s\n", registerDest, registerTemp);
}

/* Renvoi le type en cas d'égalité, sinon -1 */
int testTypeVariables(variable var1, variable var2){
  if (var1->type == var2->type) {
    return var1->type;
  }
  return -1;
}

char * conversion_int_string(int val)
{
  char * str = malloc(sizeof(char)*64);
  sprintf(str,"%d",val);
  return str;
}

char * parse_label(int label){
  char * str = malloc(sizeof(char)*64*2);
  char * str2 = conversion_int_string(label);
  strcat(str, "label");
  strcat(str,str2);
  free(str2);
  return str;
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
    case NOEGAL:
      printf("!=")
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
    case PRINT_INT:
      printf("print int")
      ;
      break;
    case PRINT_FLOAT:
      printf("print float")
      ;
      break;
    case PRINT_STRING:
      printf("print string")
      ;
      break;
    case QUAD_GOTO:
      printf("GOTO")
      ;
      break;
    case QUAD_LABEL:
      printf("LABEL")
      ;
      break;
    default:
      printf("Operateur non reconnu : %d\n", operator);
      break;
  }
}
