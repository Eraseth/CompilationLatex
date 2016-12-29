#if !defined( EXPR_BOOL_H )

#define EXPR_BOOL_H
#include <stdio.h>
#include <stdlib.h>
#include "quad_list.h"
#include "variable.h"

//Structure pour notre code 3 adresses
typedef struct expr_bool_struct
{
  quad_list code;
  quad_list true_list;
  quad_list false_list;
}*expr_bool;



expr_bool new_expr_bool(quad_list code, quad_list true_list, quad_list false_list);
void print_expr_bool(expr_bool eb);
void free_expr_bool(expr_bool eb);
#endif
