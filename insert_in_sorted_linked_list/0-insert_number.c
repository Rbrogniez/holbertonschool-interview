
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_node - adds a new node at the list
 * @head: pointer to pointer of first node of listint_t list
 * @number: integer to be included in new node
 * Return: address of the new element or NULL if it fails
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new;
	listint_t *current;

	current = *head;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
	return (NULL);

	new->n = number;
	new->next = NULL;

	if (*head == NULL)
		*head = new;
	else
	{
		while (current->next != NULL && current->next->n < new->n)
			current = current->next;
		if (current == *head)
		{
			new->next = current;
			*head = new;
		}
		else
		{
			new->next = current->next;
			current->next = new;
		}
	}

	return (new);
}
