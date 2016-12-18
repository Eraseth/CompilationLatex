#include "include/gen_assembleur.h"


void generate_data(FILE *assembleur_file, tableSymbole table_symbole){
  fprintf(assembleur_file, "%s\n", ".data");
  gen_assembleur_data(assembleur_file, table_symbole);
  //TODO --> __str1_reserved_
}

void generate_text(FILE *assembleur_file, quad_list code){
  fprintf(assembleur_file, "%s\n", ".text");
  fprintf(assembleur_file, "%s\n", "main:");
  gen_assembleur_text(assembleur_file, code);
  fprintf(assembleur_file, "%s\n", "li $v0,10");
  fprintf(assembleur_file, "%s\n", "syscall");
}
