%{

#include <stdio.h>
#include <stdlib.h>
#define TABSIZE 1024

int tabInt[TABSIZE];
float tabFloat[TABSIZE];
int indiceInt = 0;
int indiceFloat = 0;

%}



INT ([0-9]([0-9])*)
FLO ([0-9]([0-9])*\.[0-9]([0-9])*)

%%
{FLO} { tabFloat[indiceFloat] = atof(yytext); indiceFloat++; }
{INT} { printf("IndiceINT--> %d", indiceInt); tabInt[indiceInt] = atoi(yytext); indiceInt++; }
%%



int main(int argc, char* argv[])
{
	printf("---Génération de MIPS :D---\n");
	yylex();
	FILE *f = fopen("file.mips", "w");
	fprintf(f, ".text\nmain:\n");

	int i;
	for(i = 0; i < indiceInt; i++){
		fprintf(f, "li $v0,1\n");
		fprintf(f, "li $a0,%d\n", tabInt[i]);
		fprintf(f, "syscall\n");
		fprintf(f, "li $v0,4\n");
		fprintf(f, "la $a0,str2\n");
		fprintf(f, "syscall\n");
	}

	for(i = 0; i < indiceFloat; i++){
		fprintf(f, "li $v0,2\n");
		fprintf(f, "l.s $f12,temp%d\n", i);
		fprintf(f, "syscall\n");
		fprintf(f, "li $v0,4\n");
		fprintf(f, "la $a0,str2\n");
		fprintf(f, "syscall\n");
	}
	fprintf(f, "li $v0,10\n");
	fprintf(f, "syscall\n");
	fprintf(f, ".data\n");
	for(i = 0; i < indiceFloat; i++){
		fprintf(f, "temp%d: .float %f\n", i, tabFloat[i]);
	}
	fprintf(f, "str1:  .asciiz \"\\n\"\n");
	fprintf(f, "str2:  .asciiz \" \"\n");

	fclose(f);

	return 0;
}