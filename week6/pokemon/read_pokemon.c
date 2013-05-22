#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

#include "pokemon.h"

/*
 * Helper function to convert poketype's to strings for printing.
 */
char *poketype_to_string(poketype type) {
  switch (type) {
    case FIRE:
      return "FIRE";
    case WATER:
      return "WATER";
    case ELECTRIC:
      return "ELECTRIC";
    case LEAF:
      return "LEAF";
  }
  return NULL;
}


/*
 * Problem 3
 * Complete main with the following specifications:
 *    (1) main takes in one command line argument: the input file name
 *    (2) open a file pointer to the output file for reading
 *    (3) while there are still bytes in the file:
 *        (a) read a pokemon struct size's worth of bytes into a pokemon struct
 *        (b) output the name, type (use poketype_to_string), and level of the 
 *            pokemon
 *    (4) close the file when there are no more pokemon to be printed
 */
int main(int argc, char *argv[]) {
  /* check to make sure the appropriate command line argument is passed in */
  if (argc != 2) {
    printf("Usage: ./read <input-file-name>\n");
    return -1;
  }

  FILE *infile = fopen(argv[1], "r");
  pokemon current;
  int num_read;

  while (!feof(infile)) {
    num_read = fread(&current, sizeof(pokemon), 1, infile);
    
    if (num_read) {
      printf("name: %s, type: %s, level: %d\n",
	     current.name,
	     poketype_to_string(current.type),
	     current.level);
    }
  }

  fclose(infile);
  return 0;
}
