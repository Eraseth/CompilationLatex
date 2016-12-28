#if !defined( QUAD_H )

#define QUAD_H
#include <stdio.h>
#include <stdlib.h>
#include "variable.h"

//Définition de types de quads supplémentaires
#define CONVERSION_INT_FLOAT -2
#define CONVERSION_FLOAT_INT -3
#define PRINT_INT -4
#define PRINT_FLOAT -5
#define PRINT_STRING -6
//Structure pour notre code 3 adresses
typedef struct quad_struct
{
  int operateur;
  variable arg1;
  variable arg2;
  variable res;
  int label;
}*quad;



quad new_quad(int operateur, variable arg1, variable arg2, variable res);
void print_quad(quad q);
void free_quad(quad q);
void print_op(int operator);
void assembleur_quad(FILE *assembleur_file, quad q);
#endif
