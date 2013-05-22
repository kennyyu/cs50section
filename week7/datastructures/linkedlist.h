#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#define LIST_EMPTY_ERROR -10000

typedef struct list list;

list *make_list();
void free_list(list *);
void insert_first(list *, int);
int remove_first(list *);
int get_first(list *);
int get_nth(list *, int);

#endif
