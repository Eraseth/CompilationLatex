#include "include/tableSymbole.h"

/* Fonctions sur la TDS */
tableSymbole new_tds(){
  return NULL;
}

tableSymbole add_variable(tableSymbole table, variable var){
	tableSymbole ajout = malloc(sizeof(struct tds_struct));
	ajout->var = var;
	ajout->next = NULL;

	if (table==NULL)
	{
		return ajout;
	}
	else
	{
		tableSymbole temp = table;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ajout;
		return table;
	}
}

void print_tds(tableSymbole table){

  printf("Table des symboles :\n");
  if (table==NULL)
  {
    ;
  }
  else
  {
    tableSymbole temp = table;
    while(temp->next!=NULL)
    {
      print_variable(temp->var);
      temp = temp->next;
    }
    print_variable(temp->var);
    printf("\n");
  }
}

void free_tds(tableSymbole table){
  tableSymbole temp = table;
	tableSymbole tempNext;

	while(temp!=NULL)
	{
  	tempNext = temp->next;
  	free_variable(temp->var);
  	free(temp);
  	temp = tempNext;
  }
}
int main(){

  variable v = new_variable_int("id", 0);
  variable v2 = new_variable_double("id2", 1.0);
  tableSymbole t = new_tds();
  t = add_variable(t,v);
  t = add_variable(t,v2);
  print_tds(t);
  return EXIT_SUCCESS;
}
