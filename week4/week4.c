#include <stdio.h>
#include <stdlib.h>

/*
 * Problem 0:
 * 
 * Write a function that takes an int argument and allocates a char array of that
 * size. Set the first few characters to be the string "cheese" null-terminated.
 * Return a pointer to this array. If size < 7, return NULL
 */
char *
make_string(int size) {
  if (size < 7)
    return NULL;
  char *s = (char *) malloc(size * sizeof(char));
  if (s == NULL) {
    return NULL; // malloc failed to allocate memory
  }
  s[0] = 'c'; // *(s + 0) = 'c';
  s[1] = 'h'; // *(s + 1) = 'h';
  s[2] = 'e';
  s[3] = 'e';
  s[4] = 's';
  s[5] = 'e';
  s[6] = '\0';
  s[7] = 'z';
  return s;
}

/*
 * Problem 1:
 *
 * Write a function that takes a string argument, and sets all the 'e's to 'p's.
 * Don't return anything.
 */
void e_to_p(char *str) {
  if (str == NULL) // always make sure your pointers are not NULL
    return;
  while (*str != '\0') {
    if (*str == 'e') {
      *str = 'p';
    }
    str++;
  }
}

/* 
 * Problem 2: 
 * 
 * Write a function that takes a string argument and frees it.
 */
void free_my_string(char *str) {
  if (!str) // check if str is NULL strcmp
    return;
  free(str); // make sure that str was a pointer returned by malloc
}


/*
 * CHALLENGE (Interview Question): What does this function do?
 */
void mystery(char *s, char *p) {
  while(*s++ = *p++); // copies the string from p into s, assuming len(s) > len(p)     
}



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
