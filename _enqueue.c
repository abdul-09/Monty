#include "monty.h"
/**
 * queue_op - Prints the elements of the queue
 * @top: Pointer to the top of the stack
 * @line: line_number
 * Return: no return
*/
void queue_op(stack_t **top, unsigned int line)
{
	(void)top;
	(void)line;
	interpret.xtics = 1;
}

/**
 * enqueue - Adds an element to the queue
 * @top: Pointer to the front of the queue
 * @n: Element to be added
 * Return: no return
*/
void enqueue(stack_t **top, int n)
{
	stack_t *new, *count;

	count = *top;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = n;
	new->next = NULL;
	if (count)
	{
		while (count->next)
			count = count->next;
	}
	if (!count)
	{
		*top = new;
		new->prev = NULL;
	}
	else
	{
		count->next = new;
		count->prev = count;
	}
}
