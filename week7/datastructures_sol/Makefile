CC = gcc
LIBS =
FLAGS = -g -Wall -Werror -std=c99

all: run bst

bst: bst.c
	$(CC) $(FLAGS) $(LIBS) -o bst bst.c

run: run.o linkedlist.o stack.o queue.o
	$(CC) $(FLAGS) $(LIBS) -o run run.o linkedlist.o stack.o queue.o

run.o: linkedlist.h stack.h queue.h run.c
	$(CC) $(FLAGS) $(LIBS) -c run.c

linkedlist.o: linkedlist.h linkedlist.c
	$(CC) $(FLAGS) $(LIBS) -c linkedlist.c

stack.o: stack.h stack.c
	$(CC) $(FLAGS) $(LIBS) -c stack.c

queue.o: queue.h queue.c
	$(CC) $(FLAGS) $(LIBS) -c queue.c

clean:
	rm -rf *.o run bst bst.dSYM