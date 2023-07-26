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
/**
 * sub - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void sub(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = -1 * (*head)->n + (*head)->next->n;
	pop(head, line_number);
	(*head)->n = temp;
}
/**
 * divide - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void divide(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
	safe_exit(EXIT_FAILURE);
	}
	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = (*head)->next->n / (*head)->n;
	pop(head, line_number);
	(*head)->n = temp;
}
