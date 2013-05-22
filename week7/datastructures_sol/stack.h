#ifndef STACK_H
#define STACK_H

#define STACK_EMPTY_ERROR -10000

typedef struct stack stack;

stack *make_stack();
void free_stack(stack *);
void push(stack *, int);
int pop(stack *);
int top(stack *);

#endif
