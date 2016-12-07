#if !defined( QUAD_LIST_H )

#define QUAD_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include "quad.h"

//Structure pour notre TDS (chained list)
typedef struct quad_list_struct
{
	quad quad;
	struct quad_list_struct *next;
}*quad_list;

quad_list new_quad_list();
quad_list add_quad(quad_list quad_l, quad quad);
void print_quad_list(quad_list quad_l);
void free_quad_list(quad_list quad_l);
quad_list add_quad_list(quad_list q1 , quad_list q2);

#endif
