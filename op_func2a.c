#include "monty.h"
/**
*op_mul - function multiplies the two elements of the stack
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_mul(stack_t **head, unsigned int n)
{
	stack_t *temp = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);

	if (!temp2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", n);

		clean(1);
		exit(EXIT_FAILURE);
	}
	temp2->n *= temp->n;
	if (temp->next)
	{
		temp->next->prev = NULL;
		*head = temp->next;
	}
	else
	{
		*head = NULL;
	}
	free(temp);
}
