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
  free(qu);
}

void enqueue(queue *qu, int v) {
  if (!qu)
    return;
  push(qu->stack_in, v);
}

int dequeue(queue *qu) {
  if (!qu)
    return QUEUE_EMPTY_ERROR;

  /* if the out stack has items, pop it */
  if (top(qu->stack_out) != STACK_EMPTY_ERROR)
    return pop(qu->stack_out);
  
  /* otherwise push all the items from the in stack onto the out stack */
  while (top(qu->stack_in) != STACK_EMPTY_ERROR) {
    push(qu->stack_out, pop(qu->stack_in));
  }

  /* return the top of the new out stack */
  if (top(qu->stack_out) != STACK_EMPTY_ERROR)
    return pop(qu->stack_out);

  /* otherwise we have no elements */
  return QUEUE_EMPTY_ERROR;
}

int front(queue *qu) {
  if (!qu)
    return QUEUE_EMPTY_ERROR;

  /* if the out stack has items, return the top */
  int v = top(qu->stack_out);
  if (v != STACK_EMPTY_ERROR)
    return v;
  
  /* otherwise push all the items from the in stack onto the out stack */
  while (top(qu->stack_in) != STACK_EMPTY_ERROR) {
    push(qu->stack_out, pop(qu->stack_in));
  }

  /* return the top of the new out stack */
  v = top(qu->stack_out);
  if (v != STACK_EMPTY_ERROR)
    return v;

  /* otherwise error */
  return STACK_EMPTY_ERROR;
}

