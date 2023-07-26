#include "monty.h"
/**
 * modu - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void modu(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = (*head)->next->n % (*head)->n;
	pop(head, line_number);
	(*head)->n = temp;
}
/**
 * pchar - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void pchar(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	if ((*head)->n < 0 || (*head)->n > 177)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
