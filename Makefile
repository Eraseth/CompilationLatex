# Définition des cibles particulières
.PHONY: clean, mrproper

# Désactivation des règles implicites
.SUFFIXES:

# Variables
CC = gcc#Le compilateur
PROJECT = Compilateur#Le nom du projet
TYPE = .out#Le type de l'executable final (exe, out, ...)
BIN = $(PROJECT)$(TYPE)#L'executable
DOUT =#Le dossier des objets
OBJS =#Les .o à utiliser
EXECY = arithm.y#Le fichier à utiliser pour Yacc
EXECL = arithm.l#Le fichier à utiliser pour Lex
LEX = lex#Lex (Flex, ...)
YACC = yacc -d#Yacc
SRC =#Le dossier des sources
DEPS =#Les dépendances à inclure (Fichier h spécifique ou dossier include/*.h)
CFLAGS = -W -Wall#Les flags pour la compilation classique
LDFLAGS =  -lfl -ly#Les flags pour lex et yacc

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
