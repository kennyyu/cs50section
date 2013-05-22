#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "queue.h"

struct queue {
  stack *stack_in;
  stack *stack_out;
};

queue *make_queue() {
  queue *qu = malloc(sizeof(queue));
  if (!qu)
    return NULL;
  qu->stack_in = make_stack();
  if (!qu->stack_in) {
    free(qu);
    return NULL;
  }    
  qu->stack_out = make_stack();
  if (!qu->stack_out) {
    free_stack(qu->stack_in);
    free(qu);
    return NULL;
  }
  return qu;
}

void free_queue(queue *qu) {
  if (!qu)
    return;
  free_stack(qu->stack_in);
  free_stack(qu->stack_out);
}

void enqueue(queue *qu, int v) {
  /* TODO */
}

int dequeue(queue *qu) {
  if (!qu)
    return QUEUE_EMPTY_ERROR;

  /* TODO */

  return 0;
}

int front(queue *qu) {
  if (!qu)
    return QUEUE_EMPTY_ERROR;

  /* TODO */

  return 0;
}

