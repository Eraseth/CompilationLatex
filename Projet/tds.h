#if !defined( TDS_H )

#define TDS_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union Value {
  double dValue;
  int iValue;
};

//Structure pour nos variables
typedef struct variable_struct
{
  char *id;
  /*
     0 --> int
     1 --> double/float
     2 --> bool (iValue = 0 || 1)
  */
	int type;
  union Value val;

}*variable;

//Structure pour notre TDS (chained list)
typedef struct tds_struct
{
	variable var;
	struct tds_struct *next;
}*tds;

/* Fonctions sur la structure variable */
variable new_variable(char *id, int type, union Value val);
void update_variable(variable var, union Value val);
void print_variable(variable var);
void free_variable(variable var);

/* Fonctions sur la TDS */
tds new_tds();
tds add_variable(tds table, variable var);
void print_tds(tds table);
void free_tds(tds table);

#endif
