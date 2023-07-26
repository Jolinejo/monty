#include "monty.h"
#include <string.h>
/**
 * get_op_func - Entry point
 * Description: to check if letter is uppercase
 * @s: op
 * Return: int
 */
void (*get_op_func(char *s))(stack_t**, unsigned int)
{
	instruction_t ops[] = {
		{"push", push}, {"pall", pall},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(ops[i].opcode, s) == 0)
			return (ops[i].f);
		i++;
	}

	return (NULL);
}
