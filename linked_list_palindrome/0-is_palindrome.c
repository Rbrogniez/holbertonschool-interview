#include "lists.h"


/**
 * is_palindrome - Check if the linked list is a palindrome
 *
 * @head - Linked list
 * Return: 1 if yes
 */
int is_palindrome(listint_t **head)
{
	int array[4096];
	listint_t *node = *head;
	size_t i, j;

	if (!*head)
		return 1;

	for (i = 0; node; i++, node = node->next)
		array[i] = node->n;

	i--;

	for (j = 0; j < i; j++, i--)
	{
		if (array[i] != array[j])
			return (0);
	}

	return (1);
}
