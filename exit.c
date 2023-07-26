#include "monty.h"

/**
 * safe_exit - Entry point
 * Description: frees everything
 * @exit_status: exit status
 * Return: 0 on success -1 on failure
 */
void safe_exit(int exit_status)
{
	stack_t *temp = glob.head;
	
	fclose(glob.fp);
	if (glob.line)
		free(glob.line);
	while (glob.head != NULL)
	{
		temp = temp->next;
		free(glob.head);
		glob.head = temp;	
	}
	exit(exit_status);
}
