#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"

struct stack {
  list *lst;
};

stack *make_stack() {
  stack *st = malloc(sizeof(stack));
  if (!st)
    return NULL;
  st->lst = make_list();
  if (!st->lst) {
    free(st);
    return NULL;
  }
  return st;
}

void free_stack(stack *st) {
  if (!st)
    return;
  free_list(st->lst);
}

void push(stack *st, int v) {
  if (!st)
    return;
  insert_first(st->lst, v);
}

int pop(stack *st) {
  if (!st)
    return STACK_EMPTY_ERROR;
  return remove_first(st->lst);
}

int top(stack *st) {
  if (!st)
    return STACK_EMPTY_ERROR;
  int v = get_first(st->lst);
  if (v == LIST_EMPTY_ERROR)
    return STACK_EMPTY_ERROR;
  return v;
}



