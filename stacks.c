#include "lists.h"
/**
*dlistint_print- function to print the elements of a list
*
*@h: pointer to the beginning of the list
*
*Return: number of nodes
*/
size_t dlistint_print(const dlistint_t *h)
{
	size_t ab = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		ab++;
	}
	return (ab);
}
/**
*add_dnodeint- function that adds a new node at the beginning of a list
*
*@head: pointer to the beginning of a list.
*@n: new data for the new node
*
*Return: address of new element or NULL if fail
*/
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *newnode;

	newnode = malloc(sizeof(dlistint_t));
	if (newnode == NULL)
	{
		return (NULL);
	}
	newnode->n = n;
	newnode->next = *head;
	newnode->prev = NULL;
	if (*head != NULL)
	{
		(*head)->prev = newnode;
	}
	*head = newnode;
	return (*head);
}
/**
*get_dnodeint_at_index- function that returns node at given index
*
*@head: start of the list
*@index: position of node to be returned
*
*Return: node at nth position or NULL if fail
*/
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int ab;
	dlistint_t *temprary;

	temprary = head;
	for (ab = 0; ab < index; ab++)
	{
		if (temprary != NULL)
		{
			temprary = temprary->next;
		}
		else
		{
			return (NULL);
		}
	}
	return (temprary);
}
#include "lists.h"
/**
*dlistint_len- function that returns the number of elements in a list
*
*@h: pointer to the beginning of the list
*
*Return: number of elements in a list
*/
size_t dlistint_len(const dlistint_t *h)
{
	size_t ab = 0;

	while (h != NULL)
	{
		h = h->next;
		ab++;
	}
	return (ab);
}
#include "lists.h"
/**
*dlistint_free- function that frees a list
*
*@head: beginning of the list
*
*Return: none, void type
*/
void dlistint_free(dlistint_t *head)
{
	dlistint_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
