#if !defined( GEN_ASSEMBLEUR_H )

#define GEN_ASSEMBLEUR_H
#include <stdio.h>
#include <stdlib.h>
#include "tableSymbole.h"
#include "quad_list.h"

void generate_data(FILE *assembleur_file, tableSymbole table_symbole);
void generate_text(FILE *assembleur_file, quad_list code);
void generate_function(FILE *assembleur_file); //TODO --> Nouvelle structure pour gérer les fonctions


#endif
