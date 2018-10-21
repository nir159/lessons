#include <cstddef>
#include <iostream>
#include <stdbool.h>
#include "linkedList.h"
#include "stack.h"
#include "utils.h"

/*
Function recieves an array and returns the array reversed
input:
nums - array of numbers
size - length of the array
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
	for (i = 0; i < size; i++) { //reversing the array
		nums[i] = curr->value;
		curr = curr->next;
	}
}

/*
Function will get from user an array and returns the array reversed
output:
an array of numbers
*/
int* reverse10() {
	int i = 0;
	int *nums = new int[10];
	std::cout << "Enter 10 numbers\n";
	for (i = 0; i < 10; i++) {
		std::cin >> nums[i];
	}
	reverse(nums, 10);
	return nums;
}