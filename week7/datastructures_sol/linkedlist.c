#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"

typedef struct lnode lnode;
struct lnode {
  int value;
  struct lnode *next;
};

struct list {
  lnode *root;
};

/* mallocs a node and initializes it */
lnode *make_lnode(int v) {
  /* must malloc memory for the node */
  lnode *node = malloc(sizeof(lnode));
  if (!node)
    return NULL;

  /* initialize the node */
  node->value = v;
  node->next = NULL;
  return node;
}

/* mallocs a list and initializes it */
list *make_list() {
  /* malloc memory for a list if we can */
  list *lst = malloc(sizeof(list));
  if (!lst)
    return NULL;
  lst->root = NULL;
  return lst;
}

/* frees all the nodes in the list, then frees the list */
void free_list(list *lst) {
  if (!lst)
    return;
  if (!lst->root)
    return;
  lnode *current = lst->root->next;
  lnode *previous = lst->root;
  while (current) {
    previous = current;
    current = current->next;
    free(previous);
  }
  free(lst);
}

/* insert into beginning of list */
void insert_first(list *lst, int v) {
  /* make sure our list is not NULL */
  if (!lst)
    return;

  /* make a new node to contain our value */
  lnode *node = make_lnode(v);
  if (!node)
    return;

  /* out list us empty; set root to the new node */
  if (!lst->root) {
    lst->root = node;
  } 

  /* our list has some items in it already 
   * (1) assign node's next to what the root is currently pointing to
   * (2) assign root to node */
  else {
    node->next = lst->root;
    lst->root = node;
  }
}

/* removes from the front of the list. returns LIST_EMPTY ERROR if there
 * are no items */
int remove_first(list *lst) {
  if (!lst)
    return LIST_EMPTY_ERROR;
  if (!lst->root)
    return LIST_EMPTY_ERROR;

  /* pointer to the node we are removing */
  lnode *node = lst->root;

  /* assign root to be node's next */
  lst->root = node->next;
  
  /* save the value before freeing the node */
  int value = node->value;
  free(node);
  return value;
}

int get_first(list *lst) {
  if (!lst)
    return LIST_EMPTY_ERROR;
  if (!lst->root)
    return LIST_EMPTY_ERROR;

  return lst->root->value;
}

int get_nth(list *lst, int n) {
  if (!lst)
    return LIST_EMPTY_ERROR;
  lnode *current = lst->root;

  if (!current)
    return LIST_EMPTY_ERROR;

  for (int i = 0; i < n; i++) {
    if (!current->next)
      return LIST_EMPTY_ERROR;
    current = current->next;
  }
  return current->value;
}
