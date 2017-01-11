#if !defined( EXPR_H )

#define EXPR_H
#include <stdio.h>
#include <stdlib.h>
#include "quad_list.h"
#include "variable.h"

enum type {BOOL, ARITHM, IDT, CONST};
//Structure pour notre code 3 adresses
typedef struct expr_struct
{
  quad_list code;
  variable resultat;
  quad_list true_list;
  quad_list false_list;
  enum type type_ex;
}*expr;



expr new_expr(quad_list code, variable resultat, quad_list true_list, quad_list false_list, enum type ty);
void print_expr(expr ex);
void free_expr(expr ex);
#endif
