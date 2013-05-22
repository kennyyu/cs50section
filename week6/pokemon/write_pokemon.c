#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pokemon.h"


/*
 * Problem 2
 * Complete main with the following specifications:
 *    (1) main takes in two command line arguments in the order: the output file name
 *        and the number of pokemon to prompt for, in that order
 *    (2) open a file pointer to the output file for writing
 *    (3) for each pokemon, prompt the user for the following input:
 *        (a) pokemon's name. You will need to use strcpy to copy the string returned
 *            by GetString() into the name char buffer.
 *        (b) pokemon's poketype (user can only enter ints representing the previously
 *            defined poketype enumerated type)
 *        (c) pokemon's level
 *        (d) write the struct containing the data into the output file
 *    (4) after prompting for all the pokemon, close the file
 */
int main(int argc, char *argv[]) {
  /* check to make sure the appropriate command line arguments are passed in */
  if (argc != 3) {
    printf("Usage: ./write <output-file-name> <num-pokemon>\n");
    return -1;
  }

  FILE *outfile = fopen(argv[1], "w");

  pokemon current;
  string s;
  for (int i = 0, n = atoi(argv[2]); i < n; i++) {
    printf("Enter pokemon name\n");
    s = GetString();
    strcpy(current.name,s);
    free(s);

    printf("Enter pokemon type (fire=%d, water=%d, electric=%d, leaf=%d)\n",
	   FIRE, WATER, ELECTRIC, LEAF);
    current.type = GetInt();

    printf("Enter pokemon level:\n");
    current.level = GetInt();

    fwrite(&current,sizeof(pokemon),1,outfile);

  }
  
  fclose(outfile);
  return 0;
}
