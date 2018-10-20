#ifndef QUEUE_H
#define QUEUE_H

/* a queue contains positive integer values. */
typedef struct queue
{
	unsigned int* values;
	unsigned int size;
} queue;

void initQueue(queue* q, unsigned int size);
void cleanQueue(queue* q);

void enqueue(queue* q, unsigned int newValue);
int dequeue(queue* q); // return element in top of queue, or -1 if empty

int isEmpty(queue* q); // return 0 if there are elements, 1 if empty

#endif /* QUEUE_H */