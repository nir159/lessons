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
	if (curr) {
		while (curr->next) {
			curr = curr->next;
		}
		curr->next = newNode;
	}
	else {
		curr->value = element;
	}
}

/*
Function removes last element in list
input:
s - the stack
*/
int pop(stack* s) {
	node* curr = s->head;
	if (curr && curr->next) {
		while (curr->next->next) {
			curr = curr->next;
		}
		delete(curr->next);
		curr->next = NULL;
	}
}

/*
Function will initialize the stack
input:
s - the stack
*/
void initStack(stack* s) {
	s->head = new node;
}

/*
Function will remove all elements from stack
input:
s - the stack
*/
void cleanStack(stack* s) {
	while (s->head) {
		pop(s);
	}
}