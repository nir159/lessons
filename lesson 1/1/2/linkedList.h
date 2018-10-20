#ifndef LINKEDLISTH
#define LINKEDLISTH

typedef struct node
{
	unsigned int value;
	struct node* next;
} node;

node* addElement(node** head, node* newNode);
node* deleteElement(node** head);

#endif /* LINKEDLIST_H */