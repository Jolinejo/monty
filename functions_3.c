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
		fprintf(stderr, "L%u: can't modu, stack too short\n", line_number);
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
