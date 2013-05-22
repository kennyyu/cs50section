#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 0:
 * 
 * Write a function that takes an int argument and allocates a char array of that
 * size. Set the first few characters to be the string "cheese" null-terminated.
 * Return a pointer to this array. If size < 7, return NULL
 */
char *make_string(int size) {
  if (size < 7)
    return NULL;
  char *array = (char *) malloc(sizeof(char) * size);
  if (!array)
    return NULL; // malloc failed;
  array[0] = 'c';
  array[1] = 'h';
  array[2] = 'e';
  array[3] = 'e';
  array[4] = 's';
  array[5] = 'e';
  array[6] = '\0';
  return array;
}

/*
 * Problem 1:
 *
 * Write a function that takes a string argument, and sets all the 'e's to 'p's.
 * Don't return anything.
 */
void e_to_p(char *str) {
  if (!str) // check if NULL
    return;
  while (*str) {
    if (*str == 'e') {
      *str = 'p';
    }
    str++;   // okay to modify our own local pointer.
  }
}

/* 
 * Problem 2: 
 * 
 * Write a function that takes a string argument and frees it.
 */
void free_my_string(char *str) {
  if (!str)
    return;
  free(str);
}


/*
 * CHALLENGE (Interview Question): What does this function do?
 */
void mystery(char *s, char *p) {
  while(*s++ = *p++);
}
// copies the string from p into s!
// this is really bad though, you should make sure that s is as long as p.



int main(void) {
  char *str = make_string(5);
  if (!str)
    printf("make_string returned NULL with 5\n");
  else
    return -1;
  
  str = make_string(9);
  printf("make_string with 7 gave me: %s\n",str);
  e_to_p(str);
  printf("e_to_p gave me: %s\n",str);
  free_my_string(str);
}
