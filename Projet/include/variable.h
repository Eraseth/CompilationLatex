#if !defined( VARIABLE_H )
#define VARIABLE_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TYPE_INT 0
#define TYPE_FLOAT 1
#define TYPE_BOOL 2
#define TYPE_STRING 3
#define TYPE_JUMP 4

#define LEX_ERROR 1
#define SYNTAX_ERROR 2
#define SEMANTIC_ERROR 3
#define OTHER_ERROR 4

//Structure pour nos variables
typedef struct variable_struct
{
  char *id;
	int type;  /*0 --> int 1 --> float/float 2 --> bool (iValue = 0 || 1) 3 --> string 4--> Jump*/
  union Value {
    float dValue;
    int iValue;
    char * sValue;
  } val;
  int init_bool;/* 0-> non initialisée , 1 -> initialisée*/
}*variable;

/* Fonctions sur la structure variable */
variable new_variable_int(char *id, int val);

variable new_variable_string(char *id, char * val);

variable new_variable_float(char *id, float val);

variable new_variable_bool(char *id, int val);

variable new_variable_goto(int val);

void set_init_bool_true(variable var);

void print_variable(variable var);

void free_variable(variable var);


#endif
