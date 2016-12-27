#include "include/tableSymbole.h"

/* Fonctions sur la TDS */
tableSymbole new_tds(){
  return NULL;
}

tableSymbole add_variable(tableSymbole table, variable var){
  if (lookup_tds(table, var->id) != NULL) {
    fprintf(stderr, "\n: La variable %s est déjà défini dans la Table des Symboles", var->id);
    exit(EXIT_FAILURE);
  }
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

variable lookup_tds(tableSymbole table, char *id){
  tableSymbole temp = table;

  while(temp!=NULL && strcmp(temp->var->id, id) != 0)
	{
    temp = temp->next;
  }
  if (temp == NULL) {
    return NULL;
  }
  return temp->var;

}

void gen_assembleur_data(FILE *assembleur_file, tableSymbole table_symbole){
  tableSymbole temp = table_symbole;

  while(temp!=NULL)
	{
    variable var = temp->var;
    switch (var->type) {
      case TYPE_INT:
        fprintf(assembleur_file, "var_%s: %s %d\n", var->id, ".word", var->val.iValue);
        break;
      case TYPE_FLOAT:
        fprintf(assembleur_file, "var_%s: %s %f\n", var->id, ".float", var->val.dValue);
        break;
      case TYPE_BOOL:
        fprintf(assembleur_file, "var_%s: %s %d\n", var->id, ".word", var->val.iValue);
        break;
      default:
        printf("\nERROR, génération de code assembleur. Type non reconnu\n");
        break;
    }
    temp = temp->next;
  }
  if (temp == NULL) {
    return ;
  }
}

// void main(){
//   variable v1 = new_variable_int("name", 45);
//   variable v2 = new_variable_float("name", 45.2);
//   tableSymbole tds = new_tds();
//   tds = add_variable(tds, v1);
//   tds = add_variable(tds, v2);
//   print_tds(tds);
//   print_variable(lookup_tds(tds, "name"));
//   if (lookup_tds(tds, "namefqsfqd") == NULL) {
//     printf("NULL\n");
//   }
//   print_variable(lookup_tds(tds, "name1"));
// }
