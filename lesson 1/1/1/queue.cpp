#include <cstddef>
#include <iostream>
#include <stdbool.h>
#include "queue.h"

/*
Function check if queue is empty
input:
q - the queue
output:
1 if empty, or 0 if not
*/
int isEmpty(queue* q) {
	unsigned int flag = 0, i = 0;
	for (i = 0; i < (q->size); i++) {
		if (q->values[i] == NULL) {
			flag = 1;
		}
	}
	return flag;
}

/*
Function initialize the queue
Input:
q - the queue.
size - the size of the queue
*/
void initQueue(queue* q, unsigned int size) {
	q->values = new unsigned int[size];
	q->size = size;
}

/*
The function removes all the elements from the queue
input:
q - the queue
*/
void cleanQueue(queue* q) {
	unsigned int i = 0;
	for (i = 0; i < (q->size); i++) {
		q->values[i] = NULL; //clean the i position in the queue
	}
}

/*
This function adds a new value to the queue
input:
q - the queue
newValue - the value to put in the queue
*/
void enqueue(queue* q, unsigned int newValue) {
	unsigned int i = 0, flag = 1;
	while (i < (q->size) && flag) {
		if (q->values[i] == NULL) {
			q->values[i] = newValue;
			flag = 0;
		}
		i++;
	}
	if (flag) {
		std::cout << "queue is full\n";
	}
}

/*
Function will remove the top element from the queue
input:
q - the queue
output:
the top element or -1 if empty
*/
int dequeue(queue* q) {
	unsigned int i = 0, flag = 1;
	int value = -1;
	if (!(isEmpty(q))) {
		while (i < (q->size) && flag) {
			if (q->values[i] != NULL) {
				value = q->values[i];
				q->values[i] = NULL;
				flag = 0;
			}
			i++;
		}
	}
	return value;
}