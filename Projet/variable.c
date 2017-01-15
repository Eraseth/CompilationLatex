#include "include/variable.h"

variable new_variable_string(char *id, char * val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_STRING;
  res->id = strdup(id);
  res->val.sValue = strdup(val);
  res->init_bool = 0;
  return res;
}
variable new_variable_int(char *id, int val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_INT;
  res->id = strdup(id);
  res->val.iValue = val;
  res->init_bool = 0;
  return res;
}

variable new_variable_float(char *id, float val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_FLOAT;
  res->id = strdup(id);
  res->val.dValue = val;
  res->init_bool = 0;
  return res;
}

variable new_variable_goto(int val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_JUMP;
  res->id = NULL;
  res->val.iValue = val;
  res->init_bool = 0;
  return res;
}

variable new_variable_bool(char *id, int val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_BOOL;
  res->id = strdup(id);
  res->val.iValue = val;
  res->init_bool = 0;
  return res;
}


void print_variable(variable var){
  if (var == NULL) {
    printf("Variable : NULL\n");
    return ;
  }
  switch (var->type) {
    case TYPE_INT:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d init : %d\n", var->id, "int", var->val.iValue,var->init_bool);
      break;
    case TYPE_FLOAT:
      printf("Variable : Nom : %s, Type : %s, Valeur : %lf init : %d\n", var->id, "float", var->val.dValue,var->init_bool);
      break;
    case TYPE_BOOL:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d init : %d\n", var->id, "boolean", var->val.iValue,var->init_bool);
      break;
    case TYPE_STRING:
      printf("Variable : Nom : %s, Type : %s, Valeur : %s init : %d\n", var->id, "string", var->val.sValue,var->init_bool);
      break;
    case TYPE_JUMP:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d init : %d\n", var->id, "jump", var->val.iValue,var->init_bool);
      break;
  }
}

void set_init_bool_true(variable var)
{
  var->init_bool = 1;
}

void free_variable(variable var){

  if (var != NULL) {
    free(var->id);
    free(var);
  }
}
