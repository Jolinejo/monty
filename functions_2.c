#include "monty.h"
/**
 * add - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void add(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = (*head)->n + (*head)->next->n;
	pop(head, line_number);
	(*head)->n = temp;
}
/**
 * nop - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}
