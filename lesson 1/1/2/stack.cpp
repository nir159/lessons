#include <cstddef>
#include <iostream>
#include <stdbool.h>
#include "linkedList.h"
#include "stack.h"

/*
Function adds an element at the end of list
input:
s - the stack
element - the value to add
*/
void push(stack* s, unsigned int element) {
	node* curr = s->head;
	node* newNode = new node();
	newNode->value = element;
	if (curr->value) { // if head exists
		while (curr->next->value) {
			curr = curr->next;
		}
		curr->next = newNode;
		newNode->next = new node();
		newNode->next->value = 0;
	}
	else {
		curr->value = element;
		curr->next = new node();
		curr->next->value = 0;
	}
}

/*
Function removes last element in list
input:
s - the stack
output:
the value of the last element or -1 if list is empty
*/
int pop(stack* s) {
	node* curr = s->head;
	int value = -1;
	if (curr->value) { // if head exists
		if (curr->next->value) {
			while (curr->next->next->value) {
				curr = curr->next;
			}
			value = curr->next->value; // keep the value to return
			delete(curr->next);
			curr->next = new node();
			curr->next->value = 0;
		}
		else {
			value = s->head->value;
			delete(s->head);
			s->head = NULL;
		}
	}
	return value;
}

/*
Function will initialize the stack
input:
s - the stack
*/
void initStack(stack* s) {
	s->head = new node;
	s->head->value = 0;
	s->head->next = new node();
	s->head->next->value = 0;
}

/*
Function will remove all elements from stack
input:
s - the stack
*/
void cleanStack(stack* s) {
	while (s->head) {
		pop(s); // removes all the elements
	}
	initStack(s); // initialize the stack
}