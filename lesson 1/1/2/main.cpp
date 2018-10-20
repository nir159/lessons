#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include "linkedList.h"

int main(int argc, char** argv)
{
	int i = 0;
	node* a = new node();
	node* b = new node();
	node* c = new node();
	a->value = 1;
	b->value = 2;
	c->value = 3;
	a->next = b;
	addElement();
	/*std::cout << dequeue(q) << "\n";
	for (i = 0; i < q->size; i++) {
		std::cout << "the number in place " << i << " is " << q->values[i] << "\n";
	}*/
	delete(a,b,c);
	getchar();
	return 0;
}