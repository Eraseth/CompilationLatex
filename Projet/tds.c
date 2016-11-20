#include "tds.h"

/* Fonctions sur la structure variable */
variable new_variable(char *id, int type, union Value val){
  variable res = malloc(sizeof(struct variable_struct));
  res->type = type;
  res->id = strdup(id);
  res->val = val;
  return res;
}

void update_variable(variable var, union Value val){
  var->val = val;
}

void print_variable(variable var){
  switch (var->type) {
    case 0:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d\n", var->id, "int", var->val.iValue);
      break;
    case 1:
      printf("Variable : Nom : %s, Type : %s, Valeur : %lf\n", var->id, "double", var->val.dValue);
      break;
    case 2:
      printf("Variable : Nom : %s, Type : %s, Valeur : %d\n", var->id, "boolean", var->val.iValue);
      break;
  }
}

void free_variable(variable var){
  free(var->id);
  free(var);
}


/* Fonctions sur la TDS */
tds new_tds(){
  return NULL;
}

tds add_variable(tds table, variable var){
	tds ajout = malloc(sizeof(struct tds_struct));
	ajout->var = var;
	ajout->next = NULL;

	if (table==NULL)
	{
		return ajout;
	}
	else
	{
		tds temp = table;
		while(temp->next!=NULL)
		{
			temp = temp->next;
		}
		temp->next = ajout;
		return table;
	}
}

void print_tds(tds table){

  if (table==NULL)
  {
    ;
  }
  else
  {
    tds temp = table;
    while(temp->next!=NULL)
    {
      print_variable(temp->var);
      temp = temp->next;
    }
    print_variable(temp->var);
    printf("\n");
  }
}

void free_tds(tds table){
  tds temp = table;
	tds tempNext;

	while(temp!=NULL)
	{
  	tempNext = temp->next;
  	free_variable(temp->var);
  	free(temp);
  	temp = tempNext;
  }
}

int main(){
  union Value val;
  val.iValue = 3;

  union Value val2;
  val2.dValue = 3.48;

  variable v = new_variable("id", 0, val);
  variable v2 = new_variable("id2", 1, val2);

  tds table = new_tds();
  table = add_variable(table, v);
  table = add_variable(table, v2);

  print_tds(table);
  free_tds(table);

  return EXIT_SUCCESS;
}
