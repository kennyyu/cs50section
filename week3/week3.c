#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * Question 0a: Fibonacci Sequence
 *
 * Write a function called fib_rec that takes an integer n and returns
 * the nth fibonacci number, where f_0 = 0, f_1 = 1, f_2 = 1, and so
 * on. Write this recursively. Test it on small inputs and then large
 * inputs. Is it slow?
 */
int fib_rec(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  return fib_rec(n-1) + fib_rec(n-2);
}



/*
 * Question 0b
 *
 * Now write the fibonacci sequence generate iteratively. Call it 
 * fib_iter. Test it on small and large inputs. How does it compare
 * with your recursive solution.
 */
int fib_iter(int n) {
  if (n == 0)
    return 0;
  if (n == 1)
    return 1;
  int prevprev = 0;
  int prev = 1;
  for (int i = 0; i < n - 2; i++) {
    int temp = prev;
    prev = prev + prevprev;
    prevprev = temp;
  }
  return prev + prevprev;
}







/* This returns a random integer from start to end inclusive */
int rand_int(int start, int end) {
  srand(time(NULL));
  int r = rand() % (end - start + 1);
  return r + start;
}

/* Question 1: Interview Problem!
 *
 * Watch this animation here: http://www.allsortsofsorts.com/fisheryates/
 *
 * Implement the Fisher-Yates shuffle--this is a linear time shuffle
 * with respect to the length of the list! More specifically, given
 * an int array and an int that is the size of the array, shuffle the
 * aray in place.
 */
void shuffle(int array[], int n) {
  for (int i = 0; i < n; i++) {
    int swap_dest = rand_int(i,n-1); // this returns a random number between i, n-1 inclusive
    int temp = array[i];
    array[i] = array[swap_dest];
    array[swap_dest] = temp;
  }
}

/*
 * Question 2: (Tech Interview) Stock Market Problem
 *
 * You are given an array of ints that represents the price of a stock on 
 * different days. On the days repesented by these prices, you want to
 * buy and sell stocks so that you make the most profit possible. Write
 * a function that takes an array an the length of the array and computes
 * the largest possible profit.
 */
int stocks(int array[], int n) {
  int lowest_price = 100000;
  int highest_diff = -100000;
  int current_diff = 0;
  for (int i = 0; i < n; i++) {
    /* make sure lowest_price is up to date */
    if (array[i] < lowest_price)
      lowest_price = array[i];
    
    /* make sure highest_diff is up to date */
    current_diff = array[i] - lowest_price;
    if (current_diff > highest_diff)
      highest_diff = current_diff;
  }
  return highest_diff;
}


/*
 * CHALLENGE: Another Tech Interview Question
 *
 * Write a function that takes an int array and the size of the array and
 * returns the largest sum formed by a continuous sequence in the array.
 *
 * Examples:
 *    [1,2,3,4] -> 10 = 1 + 2 + 3 + 4
 *    [2,3,-1,-3] -> 5 = 2 + 3
 *    [0,-5,100,-1000] -> 95 = -5 + 100
 *    [-1, -5, -6, -1000] -> 0
 */




int main(int argc, char *argv[]) {
  int f = fib_iter(7);
  printf("iterative: f_7: %d\n", f);
  f = fib_iter(43);
  printf("iterative: f_43: %d\n", f);

  f = fib_rec(7);
  printf("recursive: f_7: %d\n", f);
  f = fib_rec(43);
  printf("recursive: f_43: %d\n", f);



  int array[10] = {0,1,2,3,4,5,6,7,8,9};
  shuffle(array, 10);
  for (int i = 0; i < 10; i++)
    printf("%d, ", array[i]);
  printf("\n");


  /* largest profit should be 12 */
  int prices[10] = {0,-2,5,10,-4,-9,-1,-3,3,-2};
  int profit = stocks(prices, 10);
  printf("profit: %d\n", profit);

  return 0;
}
