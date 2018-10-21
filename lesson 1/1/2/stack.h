#ifndef STACK_H
#define STACK_H

/* a positive-integer value stack, with no size limit */
typedef struct stack
{
	node* head = NULL;
} stack;

void push(stack* s, unsigned int element);
int pop(stack* s); // Return -1 if stack is empty

void initStack(stack* s);
void cleanStack(stack* s);

#endif // STACK_H