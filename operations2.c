#include "monty.h"

/**
 * push - add node to the stack
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/

void push(stack_t **top, unsigned int line)
{
	int n, j = 0, flag = 0;

	if (interpret.arg)
	{
		if (interpret.arg[0] == '-')
			j++;
		for (; interpret.arg[j] != '\0'; j++)
		{
			if (interpret.arg[j] > 57 || interpret.arg[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(interpret.file);
			free(interpret.content);
			free_list(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	n = atoi(interpret.arg);
	if (interpret.xtics == 0)
		insertNode(top, n);
	else
		enqueue(top, n);
}
/**
 * pop - Prints the deleted element from the top of the stack
 * @top: Pointer to the stack
 * @line: Line number in the file
*/
void pop(stack_t **top, unsigned int line)
{
	stack_t *current;

	if (*top == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	*top = current->next;
	free(current);
}
/**
 * pall - Prints all the elements of the stack
 * @top: Pointer to the stack
 * @line: Line number in the script (unused)
*/
void pall(stack_t **top, unsigned int line)
{
	stack_t *current;
	(void)line;

	current = *top;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pint - Prints the top element of the stack
 * @top: Pointer to the stack
 * @line: Line number of the command
*/

void pint(stack_t **top, unsigned int line)
{
	if (*top == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*top)->n);
}
/**
 *nop - does absolutely nothing
 *@top: Pointer to the stack
 *@line: Line number in the script
*/
void nop(stack_t **top, unsigned int line)
{
	(void) line;
	(void) top;
}
