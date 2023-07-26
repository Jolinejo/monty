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

	if (glob.av[1] == NULL || glob.av[1][0] == '\0')
	{
		fprintf(stderr, "L%u: usage: push integer", line_number);
		safe_exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		safe_exit(EXIT_FAILURE);
	}
	while (glob.av[1][i])
	{
		if (glob.av[1][i] < '0' || glob.av[1][i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer", line_number);
			safe_exit(EXIT_FAILURE);
		}
		i++;
	}
	n = atoi(glob.av[1]);
	new->n = n;
	new->prev = NULL;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
		return;
	}
	new->next = *head;
	(*head)->prev = new;
	*head = new;
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

