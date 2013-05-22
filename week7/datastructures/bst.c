#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode bstnode;
struct bstnode {
  /* TODO */
};

/* Write a function that calculates the height of a tree, starting at root
 * HINT: Use recursion. */
int bst_height(bstnode *root) {
  /* TODO */
  return 0;
}

/* Write a function that calculates the minimum of a well-formed BST. */
int bst_min(bstnode *root) {
  /* TODO */
  return 0;
}

/* Write a function that searches for value in the well-formed BST. 
 * Returns 1 if found, 0 if not. */
int bst_find(bstnode *root, int value) {
  /* TODO */
  return 0;
}

int main(void) {
  /* remove this commenting when you are finished
  bstnode n5 = {5, NULL, NULL};
  bstnode n3 = {3, NULL, NULL};
  bstnode n1 = {1, NULL, NULL};
  bstnode n9 = {9, NULL, NULL};
  bstnode n6 = {6, NULL, NULL};
  bstnode n7 = {7, NULL, NULL};
  bstnode n8 = {8, NULL, NULL};
  n5.left = &n3;
  n3.left = &n1;
  n5.right = &n9;
  n9.left = &n6;
  n6.right = &n7;
  n7.right = &n8;
  printf("bst_height: %d\n", bst_height(&n5)); // 5
  printf("bst_min: %d\n", bst_min(&n5)); // 1
  printf("bst_find %d in n5: %d\n", 7, bst_find(&n5, 7)); // 1
  printf("bst_find %d in n5: %d\n", 4, bst_find(&n5, 4)); // 0
  */
  return 0;
}
