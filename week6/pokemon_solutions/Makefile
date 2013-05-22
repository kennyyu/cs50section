CC = gcc
FLAGS = -std=c99
LIBS = -lcs50
INCLUDES = pokemon.h

all: read write

read: $(INCLUDES) read_pokemon.c
	$(CC) -o read read_pokemon.c $(LIBS) $(FLAGS)

write: $(INCLUDES) write_pokemon.c
	$(CC) -o write write_pokemon.c $(LIBS) $(FLAGS)

clean:
	rm -rf read write