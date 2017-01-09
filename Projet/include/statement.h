#if !defined( STATEMENT_H )

#define STATEMENT_H
#include <stdio.h>
#include <stdlib.h>
#include "quad_list.h"
#include "variable.h"

//Structure pour notre code 3 adresses
typedef struct statement_struct
{
  quad_list code;
  quad_list next_list;
}*statement;



statement new_statement(quad_list code, quad_list next_list);
void print_statement(statement st);
void free_statement(statement st);
#endif
