#include <stdio.h>
#include <stdlib.h>

#include "linkedlist.h"
#include "stack.h"
#include "queue.h"

void run_linkedlist() {
  int nums[10] = {0,9,4,3,7,6,5,8,1,2};
  list *lst = make_list();
  if (!lst) {
    printf("make_list() failed\n");
    return;
  }
  for (int i = 0; i < 10; i++) {
    insert_first(lst, nums[i]);
    printf("just inserted %d into list\n", nums[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("get_nth(%d): %d\n", i, get_nth(lst,i));
  }
  for (int i = 0; i < 10; i++) {
    printf("remove_first: %d\n", remove_first(lst));
  }
  free_list(lst);
}

void run_stack() {
  int nums[10] = {0,9,4,3,7,6,5,8,1,2};
  stack *st = make_stack();
  if (!st) {
    printf("make_stack() failed\n");
    return;
  }
  for (int i = 0; i < 10; i++) {
    push(st, nums[i]);
    printf("just pushed %d onto stack\n", nums[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("pop: %d\n", pop(st));
  }
  free_stack(st);
}

void run_queue() {
  int nums[10] = {0,9,4,3,7,6,5,8,1,2};
  queue *qu = make_queue();
  if (!qu) {
    printf("make_queue() failed\n");
    return;
  }
  for (int i = 0; i < 10; i++) {
    enqueue(qu, nums[i]);
    printf("just enqueued %d into queue\n", nums[i]);
  }
  for (int i = 0; i < 10; i++) {
    printf("dequeue: %d\n", dequeue(qu));
  }
  free_queue(qu);
}

int main(void) {
  run_linkedlist();
  run_stack();
  run_queue();
}
