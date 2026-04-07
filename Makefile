CC = clang
CFLAGS = -Wall -std=c17
CLIBS = -lncurses

SRC = moteur.c affichage.c main.c
OBJ = $(SRC:.c=.o)

all : jeu_de_la_vie

jeu_de_la_vie: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)


%.o : %.c
	$(CC) $(CFLAGS) -c $<


clean:
	rm -f *.o jeu_de_la_vie
