#include "monty.h"
/**
* op_rotl - function rotates stack to the top
*
* @head: pointer to top of the stack
* Return: node at the top of stack
*/
stack_t **op_rotl(stack_t **head)
{
	stack_t *stack = *head;

	while (!stack)
	{
		stack = stack->next;
		/* stack is now pointing to the second node */
		*head = (*head)->next;
		stack->next = (*head)->prev;
		(*head)->prev = NULL;
		stack->next->prev = stack;
		stack = stack->next;
		stack->next = NULL;
	}
		return (head);
}
