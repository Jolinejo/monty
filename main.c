#define _GNU_SOURCE
#include "monty.h"
/*void nothing(void);*/
globals glob = {NULL, {NULL}, NULL, NULL};

/**
 * main - Entry point
 * Description: prints line by line no extra spaces
 * Return: nothing
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t read;
	unsigned int line_num = 1;
	void (*p)(stack_t**, unsigned int);
	
	if (argc != 2)
	{
		dprintf(2, "USAGE: monty file\n");
		return(EXIT_FAILURE);
	}
	glob.fp = fopen(argv[1], "r");
	if (glob.fp == NULL)
	{
		dprintf(2, "Error: Can't open file %s\n", argv[1]);
		return(EXIT_FAILURE);
	}
	while ((read = getline(&(glob.line), &len, glob.fp)) != -1)
	{
		glob.line[read - 1] = '\0';
		arguments(&(glob.line), glob.av);
		if (glob.av[0] != NULL)
		{
			p = get_op_func(glob.av[0]);
			if (p == NULL)
			{
				dprintf(2, "L%u: unknown instruction %s", line_num, glob.av[0]);
				safe_exit(EXIT_FAILURE);
			}
			p(&(glob.head), line_num);
		}
		line_num++;
	}
	if (read == -1 && errno == ENOMEM)
	{
		dprintf(2, "Error: malloc failed\n");
		safe_exit(EXIT_FAILURE);
	}
	safe_exit(0);
	return (0);
}
