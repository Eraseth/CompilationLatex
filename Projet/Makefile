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
OBJS = variable.o tableSymbole.o
EXECY = latex.y
EXECL = latex.l
LEX = lex
YACC = yacc -d
SRC =
DEPS = include/*.h
CFLAGS = -W -Wall
LDFLAGS =  -lfl -ly

# Création de l'executable Out
all: y.tab.c lex.yy.c $(OBJS)
	$(CC) $^ -o $(BIN) $(LDFLAGS) 

#Création du y.tab.c
y.tab.c: $(EXECY)
	$(YACC) $(EXECY)

#Création du lex.yy.c
lex.yy.c: $(EXECL)
	$(LEX) $(EXECL)

#Création des fichiers objets avec les fichiers c renseignés
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

# Suppression des fichiers temporaires
clean:
	rm -rf y.tab.c lex.yy.c $(OBJS)

mrproper: clean
	rm $(BIN)
