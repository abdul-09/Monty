#include "monty.h"

/**
* execute - executes the opcode
* @data: Pointer
* @line: line_counter
* @file: poiner to monty file
* @input: line input
* Return: no return
*/
int execute(char *input, stack_t **data, unsigned int line, FILE *file)
{
	instruction_t operations[] = {
				{"push", push}, {"pall", pall}, {"pint", pint},
				{"pop", pop},
				{"swap", swap},
				{"add", add},
				{"nop", nop},
				{"sub", sub},
				{"div", divide_top_two},
				{"mul", mul},
				{"mod", mod},
				{"pchar", pchar},
				{"pstr", printString},
				{"rotl", rotate_op},
				{"rotr", rotate_bottom},
				{"queue", queue_op},
				{"stack", stack_top},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *op;

	op = strtok(input, " \n\t");
	if (op && op[0] == '#')
		return (0);
	interpret.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && op)
	{
		if (strcmp(op, operations[i].opcode) == 0)
		{	operations[i].f(data, line);
			return (0);
		}
		i++;
	}
	if (op && operations[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", line, op);
		fclose(file);
		free(input);
		free_list(*data);
		exit(EXIT_FAILURE); }
	return (1);
}
