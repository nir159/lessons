#include <cstddef>
#include <iostream>
#include <stdbool.h>
#include "linkedList.h"
#include "stack.h"
#include "utils.h"

/*

*/
void reverse(int* nums, unsigned int size) {
	int i = 0;
	node* curr = NULL;
	stack* s = new stack;
	initStack(s);
	for (i = size - 1; i >= 0; i--) {//i the last element on the array
		push(s, nums[i]);
	}
	curr = s->head;
	for (i = 0; i < size; i++) {
		nums[i] = curr->value;
		curr = curr->next;
	}
}