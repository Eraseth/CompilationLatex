#if !defined( EXPR_ARITHM_H )

#define EXPR_ARITHM_H
#include <stdio.h>
#include <stdlib.h>
#include "quad_list.h"
#include "variable.h"

//Structure pour notre code 3 adresses
typedef struct expr_arithm_struct
{
  variable resultat;
  quad_list code;
}*expr_arithm;



expr_arithm new_expr_arithm(variable,quad_list);
void print_expr_arithm(expr_arithm e);
void free_expr_arithm(expr_arithm e);
#endif
