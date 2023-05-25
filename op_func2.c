#include "monty.h"
/**
*op_add - function adds the two elements of the stack
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_add(stack_t **head, unsigned int n)
{
	stack_t *temp = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);

	if (!temp2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	temp2->n += temp->n;

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
/**
*op_swap - function swas the top two elements of the stack
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_swap(stack_t **head, unsigned int n)
{
	stack_t *temp1 = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);
	int swap = 0;

	if (!temp1 || !temp2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	swap = temp1->n;
	temp1->n = temp2->n;
	temp2->n = swap;
}
/**
*op_sub - function subtracts the two elements of the stack
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_sub(stack_t **head, unsigned int n)
{
	stack_t *temp = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);

	if (!temp2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	temp2->n -= temp->n;

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
/**
*op_div - function divides the two elements of the stack
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_div(stack_t **head, unsigned int n)
{
	stack_t *temp = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);

	if (!temp2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp2->n /= temp->n;

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
}
/**
*op_mod - function divides the two elements of the stack to find the remainder
*
*@head: beginning of the list
*@n: line number
*
*Return: void
*/
void op_mod(stack_t **head, unsigned int n)
{
	stack_t *temp = get_dnodeint_at_index(*head, 0);
	stack_t *temp2 = get_dnodeint_at_index(*head, 1);

	if (!temp2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	if (temp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", n);
		clean(1);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp2->n %= temp->n;

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
}

