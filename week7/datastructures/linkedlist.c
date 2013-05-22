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
  /* TODO */
  return NULL;
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

  /* FILL OUR REST YOURSELF: Solutions will be posted next week */

  /* out list is empty; set root to the new node */
  /* TODO */


  /* our list has some items in it already 
   * (1) assign node's next to what the root is currently pointing to
   * (2) assign root to node */
  /* TODO */

}





/* removes from the front of the list. returns LIST_EMPTY ERROR if there
 * are no items */
int remove_first(list *lst) {
  if (!lst)
    return LIST_EMPTY_ERROR;
  if (!lst->root)
    return LIST_EMPTY_ERROR;

  /* pointer to the node we are removing */
  /* lnode *node = lst->root; */

  /* assign root to be node's next */
  /* TODO */
  
  /* save the value before freeing the node */
  /* TODO */

  return 0;
}




int get_first(list *lst) {
  if (!lst)
    return LIST_EMPTY_ERROR;
  if (!lst->root)
    return LIST_EMPTY_ERROR;

  /* TODO */
  return 0;
}



int get_nth(list *lst, int n) {
  /* TODO */
  return 0;
}
