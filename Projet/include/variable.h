#if !defined( VARIABLE_H )
#define VARIABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_BOOL 2

//Structure pour nos variables
typedef struct variable_struct
{
  char *id;
	int type;  /*0 --> int 1 --> float/float2 --> bool (iValue = 0 || 1)*/
  union Value {
  float dValue;
  int iValue;
} val;

}*variable;

/* Fonctions sur la structure variable */
variable new_variable_int(char *id, int val);

variable new_variable_float(char *id, float val);

variable new_variable_bool(char *id, int val);

void update_variable_int(variable var, int val);

void update_variable_float(variable var, float val);

void update_variable_bool(variable var, int val);

void print_variable(variable var);

void free_variable(variable var);


#endif
