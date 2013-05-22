#ifndef QUEUE_H
#define QUEUE_H

#define QUEUE_EMPTY_ERROR -10000

typedef struct queue queue;

queue *make_queue();
void free_queue(queue *);
void enqueue(queue *, int);
int dequeue(queue *);
int front(queue *);

#endif
