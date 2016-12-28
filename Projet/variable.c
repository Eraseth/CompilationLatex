#include "include/variable.h"

variable new_variable_string(char *id, char * val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_STRING;
  res->id = strdup(id);
  res->val.sValue = strdup(val);
  return res;
}
variable new_variable_int(char *id, int val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_INT;
  res->id = strdup(id);
  res->val.iValue = val;
  return res;
}

variable new_variable_float(char *id, float val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_FLOAT;
  res->id = strdup(id);
  res->val.dValue = val;
  return res;
}

variable new_variable_bool(char *id, int val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = TYPE_BOOL;
  res->id = strdup(id);
  res->val.iValue = val;
  return res;
}

void update_variable_int(variable var, int val){
  if(var->type!=TYPE_INT)
  {
    perror("Error dans update_variable_int : La variable n'est pas de type entier");
    exit(-1);
  }
  var->val.iValue = val;
}

void update_variable_float(variable var, float val){
  if(var->type!=TYPE_FLOAT)
  {
    perror("Error dans update_variable_int : La variable n'est pas de type float");
    exit(-1);
  }
  var->val.dValue = val;
}


void update_variable_bool(variable var, int val){
  if(var->type!=TYPE_BOOL)
  {
    perror("Error dans update_variable_int : La variable n'est pas de type bool");
    exit(-1);
  }
  var->val.iValue = val;
}


void print_variable(variable var){
  if (var == NULL) {
    printf("Variable : NULL\n");
    return ;
  }
  switch (var->type) {
    case TYPE_INT:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d\n", var->id, "int", var->val.iValue);
      break;
    case TYPE_FLOAT:
      printf("Variable : Nom : %s, Type : %s, Valeur : %lf\n", var->id, "float", var->val.dValue);
      break;
    case TYPE_BOOL:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d\n", var->id, "boolean", var->val.iValue);
      break;
    case TYPE_STRING:
      printf("Variable : Nom : %s, Type : %s, Valeur : %s\n", var->id, "string", var->val.sValue);
      break;
  }
}

void free_variable(variable var){

  if (var != NULL) {
    free(var->id);
    free(var);
  }
}
/*
int main(){

  variable v = new_variable_int("id", 0);
  variable v2 = new_variable_float("id2", 1.0);
  print_variable(v);
  print_variable(v2);
  return EXIT_SUCCESS;
}
*/
