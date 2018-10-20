#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include "queue.h"

int main(int argc, char** argv)
{
	int i = 0;
	queue* q = new queue();
	initQueue(q, 10);
	cleanQueue(q);
	enqueue(q, 12);
	enqueue(q, 10);
	std::cout << dequeue(q) << "\n";
	for (i = 0; i < q->size; i++) {
		std::cout << "the number in place " << i << " is " << q->values[i] << "\n";
	}
	cleanQueue(q);
	delete(q);
	getchar();
	return 0;
}