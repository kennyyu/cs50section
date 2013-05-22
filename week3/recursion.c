#include <stdio.h>
#include <stdlib.h>

int factorial(int);



int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf("usage: ./factorial [number]\n");
    return 1;
  }

  int number = atoi(argv[1]);
  int fact = factorial(number);
  printf("%d! == %d\n", number, fact);
  return 0;
}



int factorial(int n) {
  if (n == 1)
    return 1;
  else
    return n * factorial(n - 1);
}
