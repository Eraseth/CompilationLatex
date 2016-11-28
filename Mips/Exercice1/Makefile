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
OBJS =
EXECL = mips.lex
LEX = lex
CFLAGS = -W -Wall
LDFLAGS =  -lfl

# Création de l'executable Out
all: lex.yy.c $(OBJS)
	$(CC) $^ -o $(BIN) $(LDFLAGS) $(CFLAGS)

#Création du lex.yy.c
lex.yy.c: $(EXECL)
	$(LEX) $(EXECL)

#Création des fichiers objets avec les fichiers c renseignés
%.o: %.c $(DEPS)
	$(CC) -c $< -o $@

# Suppression des fichiers temporaires
clean:
	rm -rf lex.yy.c $(OBJS)

mrproper: clean
	rm $(BIN)
