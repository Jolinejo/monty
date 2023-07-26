#include "monty.h"
/**
 * push - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void push(stack_t **head, unsigned int line_number)
{
	stack_t *new;
	int n, i = 0;

	(void)head;
	if (glob.av[1] == NULL || glob.av[1][0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		safe_exit(EXIT_FAILURE);
	}
	if (glob.av[1][0] == '-')
		i++;
	while (glob.av[1][i])
	{
		if (glob.av[1][i] < '0' || glob.av[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free(new);
			safe_exit(EXIT_FAILURE);
		}
		i++;
	}
	n = atoi(glob.av[1]);
	if (glob.mod == 1)
		pushs(&new, n);
	else
		pushq(&new, n);
}
/**
 * pall - Entry point
 * Description: print
 * @head: head
 * @line_number: line
 * Return: int
 */
void pall(stack_t **head, unsigned int line_number)
{

	stack_t *temp = *head;

	(void)line_number;
	if (*head == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * pop - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = (*head)->next;
	if (temp != NULL)
		temp->prev = NULL;
	free(*head);
	*head = temp;
}
/**
 * swap - Entry point
 * Description: print
 * @head: head
 * @line_number: number
 * Return: int
 */
void swap(stack_t **head, unsigned int line_number)
{
	int temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		safe_exit(EXIT_FAILURE);
	}
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;

}
