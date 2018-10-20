#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include "linkedList.h"

int main(int argc, char** argv)
{
	int i = 0;
	node* head = new node();
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
	delete(head->next->next);
	getchar();
	return 0;
}