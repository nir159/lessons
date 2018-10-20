#ifndef LINKEDLISTH
#define LINKEDLISTH

typedef struct node
{
	unsigned int value;
	struct node* next;
} node;


int addElement(node** head);
int remElement(node** head);


#endif /* LINKEDLIST_H */