#include <stdio.h>
#include <stdlib.h>

typedef struct bstnode bstnode;
struct bstnode {
  int value;
  struct bstnode *left;
  struct bstnode *right;
};

/* Write a function that calculates the height of a tree, starting at root
 * HINT: Use recursion. */
int bst_height(bstnode *root) {
  if (!root)
    return 0;
  int left_height = bst_height(root->left);
  int right_height = bst_height(root->right);
  return 1 + ((left_height > right_height) ? left_height : right_height);
}

/* Write a function that calculates the minimum of a well-formed BST. */
int bst_min(bstnode *root) {
  if (!root)
    return 0;
  if (!root->left)
    return root->value;
  return bst_min(root->left);
}

/* Write a function that searches for value in the well-formed BST. 
 * Returns 1 if found, 0 if not. */
int bst_find(bstnode *root, int value) {
  if (!root)
    return 0;
  if (value == root->value)
    return 1;
  else if (value < root->value)
    return bst_find(root->left, value);
  else
    return bst_find(root->right, value);
}

int main(void) {
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
}
