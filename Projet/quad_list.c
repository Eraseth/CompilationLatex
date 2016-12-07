#include "include/quad_list.h"

/* Fonctions sur la TDS */
quad_list new_quad_list(){
  return NULL;
}

quad_list add_quad(quad_list quad_l, quad quad){
  quad_list ajout = malloc(sizeof(struct quad_list_struct));
	ajout->quad = quad;
	ajout->next = NULL;

	if (quad_l==NULL)
	{
		return ajout;
	}
	else
	{
		quad_list temp = quad_l;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ajout;
		return quad_l;
	}
}

void print_quad_list(quad_list quad_l){
  printf("Quad list :\n");
  if (quad_l==NULL)
  {
    ;
  }
  else
  {
    quad_list temp = quad_l;
    while(temp->next!=NULL)
    {
      print_quad(temp->quad);
      temp = temp->next;
    }
    print_quad(temp->quad);
    printf("\n");
  }
}

void free_quad_list(quad_list quad_l){
  quad_list temp = quad_l;
	quad_list tempNext;

	while(temp!=NULL)
	{
  	tempNext = temp->next;
  	free_quad(temp->quad);
  	free(temp);
  	temp = tempNext;
  }
}

quad_list add_quad_list(quad_list q1 , quad_list q2)
{
  if (q1 == NULL)
  {
    return q2;
  }
  else
  {
    quad_list temp = q1;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = q2;
		return q1;
  }
}
/* Pensez au doubles free */
/*
void main(){
  quad_list quadL = new_quad_list();
  quad_list quadL2 = new_quad_list();

  variable v1 = new_variable_int("abc", 1);
  variable v2 = new_variable_double("ab", 2.5);
  variable v3 = new_variable_bool("abcd", 1);

  quad q1 = new_quad('+', v1, v2, v3);
  quad q2 = new_quad('-', v1, v2, v3);
  quad q3 = new_quad('*', v1, v2, v3);

  quadL = add_quad(quadL, q1);
  quadL = add_quad(quadL, q2);
  quadL = add_quad(quadL, q3);

  quadL2 = add_quad(quadL2, q3);
  quadL = add_quad_list(quadL,quadL2);
  print_quad_list(quadL);
  free_quad_list(quadL);
}
*/
