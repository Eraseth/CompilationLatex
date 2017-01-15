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

void gen_assembleur_text(FILE *assembleur_file, quad_list code)
{
  quad_list temp = code;

  while(temp!=NULL)
  {
    assembleur_quad(assembleur_file, temp->quad);
    temp = temp->next;
  }
  if (temp == NULL) {
    return ;
  }
}

quad_list complete(quad_list ql, int label){
  quad_list temp = ql;

  while(temp!=NULL)
  {
    if (temp->quad->res != NULL) {
      printf("\nERROR, complete d'un quad possédant un resultat\n");
      exit(OTHER_ERROR);
    } else {
      temp->quad->res = new_variable_goto(label);
    }
    temp = temp->next;
  }

  return ql;
}
