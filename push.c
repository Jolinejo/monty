#include "monty.h"
/**
 * pushs - Entry point
 * Description: print
 * @newt: head
 * @n: number
 * Return: int
 */
void pushs(stack_t **newt, int n)
{
	(*newt)->n = n;
	(*newt)->prev = NULL;
	if (glob.head == NULL)
	{
		(*newt)->next = NULL;
		glob.head = (*newt);
		return;
	}
	(*newt)->next = glob.head;
	glob.head->prev = (*newt);
	glob.head = (*newt);
}
/**
 * pushq - Entry point
 * Description: print
 * @newt: head
 * @n: number
 * Return: int
 */
void pushq(stack_t **newt, int n)
{
	stack_t *temp = glob.head;

	(*newt)->n = n;
	(*newt)->next = NULL;
	if (glob.head == NULL)
	{
		(*newt)->prev = NULL;
		glob.head = (*newt);
		return;
	}
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (*newt);
	(*newt)->prev = temp;
}
