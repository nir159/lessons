#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include "linkedList.h"
#include "stack.h"

int main(int argc, char** argv)
{
	int i = 0;
	/*node* head = new node();
	head->next = new node();
	node* n = new node();
	head->value = 2;
	head->next->value = 3;
	n->value = 1;
	head = addElement(&head, n);
	std::cout << "n is " << head->value << "\n";
	head = deleteElement(&head);
	std::cout << "n is " << head->value;
	
	delete(head);
	delete(head->next);
	delete(head->next->next);*/
	stack* s = new stack;
	initStack(s);
	s->head->value = 2;
	push(s, 4);
	std::cout << "new node is " << s->head->next->value << "\n";
	push(s, 7);
	pop(s);
	push(s, 9);
	cleanStack(s);
	getchar();
	return 0;
}