#if !defined( STR_CTRL_H )

#define STR_CTRL_H
#include <stdio.h>
#include <stdlib.h>
#include "quad_list.h"
#include "variable.h"

//Structure pour notre code 3 adresses
typedef struct struct_ctrl_struct
{
  quad_list code;
  quad_list next_list;
}*struct_ctrl;

struct_ctrl new_struct_ctrl(quad_list code, quad_list next_list);
void print_struct_ctrl(struct_ctrl str_ctrl);
void free_struct_ctrl(struct_ctrl str_ctrl);
#endif
