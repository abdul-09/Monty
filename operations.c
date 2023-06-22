#include "monty.h"

/**
 * add - adds the top two elements of the stack.
 * @top: Pointer to the stack
 * @line: Line number where the function is called
 *
 * Description: Adds the top two elements of the stack and updates the stack
*/
void add(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(interpret.file); /* Close a file tied with the 'interpret' object */
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->n + current->next->n;
	current->next->n = sum;
	*top = current->next;
	free(current);
}
/**
 * divide_top_two - Computes the quotient of the top two stack elements.
 * @top: Pointer to the stack
 * @line: Line number where the division operation is performed.
*/

void divide_top_two(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = current->next->n / current->n;
	current->next->n = sum;
	*top = current->next;
	free(current);
}
/**
 * mod - Computes the remainder of division for top stack elements
 * top element of the stack by the top element of the stack
 * @top: Pointer to the stack
 * @line: Current line number
*/
void mod(stack_t **top, unsigned int line)
{
	stack_t *current;
	int len = 0, total;

	current = *top;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	total = current->next->n % current->n;
	current->next->n = total;
	*top = current->next;
	free(current);
}
#include "monty.h"
/**
 * mul - Multiplication of the top two elements in the stack.
 * @top: Pointer to the stack
 * @line: Line number in the script
 * Return: no return
*/
void mul(stack_t **top, unsigned int line)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	sum = current->next->n * current->n;
	current->next->n = sum;
	*top = current->next;
	free(current);
}
#include "monty.h"
/**
  *sub - Subtract two numbers
  *@top: Pointer to the top of the stack
  *@line: Line number of the script
 */
void sub(stack_t **top, unsigned int line)
{
	stack_t *sum;
	int dif, count;

	sum = *top;
	for (count = 0; sum != NULL; count++)
		sum = sum->next;
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(interpret.file);
		free(interpret.content);
		free_list(*top);
		exit(EXIT_FAILURE);
	}
	sum = *top;
	dif = sum->next->n - sum->n;
	sum->next->n = dif;
	*top = sum->next;
	free(sum);
}
