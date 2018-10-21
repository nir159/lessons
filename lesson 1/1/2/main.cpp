#include <iostream>
#include <stdbool.h>
#include <cstddef>
#include "linkedList.h"
#include "stack.h"
#include "utils.h"

int main(int argc, char** argv)
{
	int i = 0;
	int* nums = NULL;
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
	delete(head->next->next);
	stack* s = new stack;
	initStack(s);
	s->head->value = 2;
	push(s, 4);
	std::cout << "new node is " << s->head->next->value << "\n";
	push(s, 7);
	pop(s);
	push(s, 9);
	cleanStack(s);
	nums[0] = 1;
	nums[1] = 2;
	nums[2] = 3;
	reverse(nums, 3);
	std::cout << "new array is " << nums[0] << nums[1] << nums[2] << "\n";*/
	nums = reverse10();
	for (i = 0; i < 10; i++) {
		std::cout << "the number in position " << i << " is " << nums[i] << "\n";
	}
	getchar();
	getchar();
	return 0;
}