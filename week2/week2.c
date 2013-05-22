#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>


/*
 * Question 1:
 *
 * Write a function string_len that takes a string argument and calculates
 * the length of the string. This function should return an int. 
 *
 * Examples:
 *     "apple" -> 5
 *     "" -> 0
 *     "hi" -> 2
 */
int string_len(string s) {
  int length = 0;
  for (int i = 0; s[i]; i++)
    length++;
  return length;
}


/*
 * Question 2:
 *
 * Write a function num_occur that takes a string argument and a char and 
 * returns the number of occurrences of the char in the string.
 *
 * Examples:
 *     "apple", 'a' -> 1
 *     "apple", 'p' -> 2
 *     "apple", 'z' -> 0
 */
int num_occur(string s, char c) {
  int num_occur = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == c)
      num_occur++;
  }
  return num_occur;
}


/*
 * Question 3:
 *
 * Write a function reverse_string that takes a string argument, a start index,
 * and an end index, and reverses the order of the letters in the string. From
 * start to end. This function should change the letters of the string in place, 
 * and should not return anything. If the indices are out of bounds, don't
 * do anything.
 * 
 * WARNING: Make sure the string terminates with the nill ('\0') character!
 *
 * Examples:
 *     "apple", start = 0, end = 4 -> "elppa"
 *     "apple", start = 1, end = 2 -> "apple"
 *     "apple", start = 1, end = 3 -> "alppe"
 *     "apple", start = -25, end = 61 -> "apple"
 */
void reverse_string(string s, int start, int end) {
  if (start < 0 || end > string_len(s))
    return;
  char temp;
  int mid = (end - start) / 2 + 1;
  for (int i = 0; i < mid; i++) {
    temp = s[start + i];
    s[start + i] = s[end - i];
    s[end - i] = temp;
  }
}


/*
 * Question 4: CHALLENGE (Tech Interview Question)
 * 
 * Write a function reverse_words that takes a string and reverses the order 
 * of the words in the string. You can assume all letters are lowercase or 
 * digits, there are no punctuation marks, and all words are separated by a 
 * space.
 *
 * Examples:
 *     "be sure to drink your ovaltine" -> "ovaltine your drink to sure be"
 *     "o hai world" -> "world hai o"
 */
void reverse_words(string s) {
  int string_length = string_len(s);

  /* reverse the whole string */
  reverse_string(s, 0, string_length - 1);

  /* we call reverse_string on every word, separated by spaces */
  int word_length = 0;
  for (int i = 0; s[i]; i++) {
    if (s[i] == ' ') {
      /* case in which string begins with space */
      if (i != 0)
	reverse_string(s, i - word_length, i - 1);
      word_length = 0;
    } else {
      word_length++;
    }
  }

  /* case in which our string does not end with a space */
  if (word_length != 0)
    reverse_string(s, string_length - word_length, string_length - 1);
}


/*
 * Question 5: CHALLENGE (Tech Interview Question)
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


/*
 * Question 0:
 *
 * Write a program where the function main prints out all the command line 
 * arguments in order, one per line.
 */
int main(int argc, string argv[]) {
  for (int i = 0; i < argc; i++) {
    printf("arg[%d]: %s\n", i, argv[i]); 
    printf("length: %d\n", string_len(argv[i]));
    printf("num occurrences of %c: %d\n", 'e', num_occur(argv[i],'e'));
    reverse_string(argv[i],0,4);
    printf("reverse, start = %d, end = %d: %s", 0, 4, argv[i]);
    printf("\n");
  }
  
  char s[] = "be sure to drink your ovaltine";
  printf("%s\n", s);
  reverse_words(s);
  printf("%s\n", s);
  return 0;
}
