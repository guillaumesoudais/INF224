##########################################
#
#  Exemple de Makefile
#  Eric Lecolinet - Reda Dehak - Telecom ParisTech 2015
#  INF224 - TP Java/Swing - http://www.telecom-paristech.fr/~elc/inf224
#
##########################################

#
# Nom du programme (doit correspondre au fichier qui contient main())
#
PROG = swing/Fenetre

#
# Fichiers sources .java
#
SOURCES = Fenetre.java  Client.java  Exit_button.class Info_buton.class Play_buton.class Select.class

#
# Compilateur Java
#
JC = javac

#
# Options du compilateur Java
#
JFLAGS = -g

VPATH = swing/

##########################################
#
# Regles de construction/destruction des .class et de l'executable
#

all: classes

run: all
	java ${PROG}

classes: $(SOURCES:.java=.class)

%.class : %.java
	$(JC) $(JFLAGS) $^

clean:
	-@$(RM) swing/*.class 1>/dev/null 2>&1

tar:
	tar cvf ${PROG}.tar.gz ${SOURCES}


###########################################
#
# Regles implicites
#

.SUFFIXES: .java .class

.java.class:
	$(JC) $(JFLAGS) $*.java
