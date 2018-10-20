#include <cstddef>
#include <iostream>
#include <stdbool.h>
#include "linkedList.h"

/*
Function will add an element to the head of the list
input:
head - the first node of list
newNode - the node to add to the list
return:
head - the new head of the list
*/
node* addElement(node** head, node* newNode) {
	newNode->next = (*head);
	(*head) = newNode;
	return *head;
}

/*
Function removes the list head
Input:
head - the list head
Output:
the new head of the list
*/
node* deleteElement(node** head)
{
	(*head) = (*head)->next;
	return *head;
}