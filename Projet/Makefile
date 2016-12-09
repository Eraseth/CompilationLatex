# Définition des cibles particulières
.PHONY: clean, mrproper

# Désactivation des règles implicites
.SUFFIXES:

# Variables
CC = gcc
PROJECT = Compilateur
TYPE = .out
BIN = $(PROJECT)$(TYPE)
DOUT =
OBJS = variable.o tableSymbole.o quad.o quad_list.o expression_arithm.o
EXECY = latex.y
EXECL = latex.l
LEX = lex
YACC = yacc -d -v
SRC =
DEPS = include/*.h ./*.h
CFLAGS = -W -Wall
LDFLAGS =  -lfl -ly

# Création de l'executable Out
all: y.tab.c lex.yy.c $(OBJS)
	$(CC) $^ -o $(BIN)

#Création du lex.yy.c
lex.yy.c: $(EXECL) $(DEPS)
	$(LEX) $(EXECL)

#Création du y.tab.c
y.tab.c: $(EXECY) $(DEPS)
	$(YACC) $(EXECY)


#Création des fichiers objets avec les fichiers c renseignés
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

# Suppression des fichiers temporaires
clean:
	rm -rf y.tab.c lex.yy.c $(OBJS)

mrproper: clean
	rm $(BIN)
