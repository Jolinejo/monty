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
	if ((*head)->n < 32 || (*head)->n >= 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	printf("%c\n", (*head)->n);
}
/**
 * pstr - Entry point
 * Description: print
 * @head: head
 * @line_number: line
 * Return: int
 */
void pstr(stack_t **head, unsigned int line_number)
{

	stack_t *temp = *head;

	(void)line_number;
	while (temp != NULL && temp->n >= 32 && temp->n < 127)
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
/**
 * rotl - Entry point
 * Description: print
 * @head: head
 * @line_number: line
 * Return: int
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *new;

	if (*head == NULL || (*head)->next == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		safe_exit(EXIT_FAILURE);
	}
	pushq(&new, (*head)->n);
	pop(head, line_number);
}
