#include "monty.h"

/**
 * pchar - Prints the char at the top of the stack, followed by a new line
 * @top: Pointer to the Pointer to the top of the stack
 * @line: Line number in the script
*/
void pchar(stack_t **top, unsigned int line)
{
	stack_t *current;

	current = *top;
	if (!current)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	if (current->n > 127 || current->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", current->n);
}
/**
 * printString - prints the string starting at the top of the stack,
 * followed by a new
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void printString(stack_t **top, unsigned int line)
{
	stack_t *current;
	(void)line;

	current = *top;
	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}
	printf("\n");
}
/**
  *rotate_op- This is to rotate the stack to the top
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_op(stack_t **top,  __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *top, *sum;

	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	sum = (*top)->next;
	sum->prev = NULL;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = *top;
	(*top)->next = NULL;
	(*top)->prev = temp;
	(*top) = sum;
}
/**
  *rotate_bottom- Rotates the stack elements towards the bottom
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void rotate_bottom(stack_t **top, __attribute__((unused)) unsigned int line)
{
	stack_t *duplicate;

	duplicate = *top;
	if (*top == NULL || (*top)->next == NULL)
	{
		return;
	}
	while (duplicate->next)
	{
		duplicate = duplicate->next;
	}
	duplicate->next = *top;
	duplicate->prev->next = NULL;
	duplicate->prev = NULL;
	(*top)->prev = duplicate;
	(*top) = duplicate;
}
/**
 * swap - Swaps the top two elements of the stack.
 * @top: Pointer to the top of the stack
 * @line: Line number of the script
*/
void swap(stack_t **top, unsigned int line)
{
	stack_t *current;
	int len = 0, sum;

	current = *top;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->n;
	current->n = current->next->n;
	current->next->n = sum;
}
