#include "monty.h"
/**
 * stack_top - Prints the top element of the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void stack_top(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
	interpret.xtics = 0;
}
/**
 * insertNode - Insert a node at the beginning of the linked list
 * @top: Pointer to the head of the linked list
 * @n: Value to be stored in the new node
*/
void insertNode(stack_t **top, int n)
{
	stack_t *new, *sum;

	sum = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}
	if (sum)
		sum->prev = new;
	new->n = n;
	new->next = *top;
	new->prev = NULL;
	*top = new;
}
