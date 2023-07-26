#include "monty.h"
/**
 * arguments - Entry point
 * Description: sets command line arguments
 * @buffer: input buffer
 * @av: arguments
 * Return: int
 */
int arguments(char **buffer, char **av)
{
	int num = 0;
	char *args_s;

	args_s = strtok(*buffer, " ");
	while (args_s != NULL && num != 4)
	{
		av[num] = args_s;
		args_s = strtok(NULL, " ");
		num++;
	}
	av[num] = NULL;
	if (av[0] != NULL && av[0][0] == '#')
		av[0] = NULL;
	return (0);
}
