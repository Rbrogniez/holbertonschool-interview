#include "list.h"

/**
 * add_node_end - Add a node at the end of the list
 *
 * @list: Double linked list
 * @str: string to copy
 *
 * Return: NULL in case of failure or the address of the new node
 */
List *add_node_end(List **list, char *str)
{
	static List *firstNode;
	static List *lastNode;
	List *newNode = NULL, *head = NULL;

	if (!list || !*str)
		return (NULL);

	newNode = create_node(str);
	if (!newNode)
		return (NULL);

	if (!*list)
	{
		*list = newNode;
		firstNode = newNode;
	}
	else
	{
		head = *list;

		while (head != lastNode)
			head = head->next;

		head->next = newNode;
		newNode->prev = head;
		newNode->next = firstNode;
		firstNode->prev = newNode;
	}
	lastNode = newNode;
	return (newNode);
}

/**
 * add_node_begin - Add a node at the beginning of the list
 *
 * @list: Double linked list
 * @str: string to copy
 *
 * Return: NULL in case of failure or the address of the new node
 */
List *add_node_begin(List **list, char *str)
{
	static List *startNode;
	static List *endNode;
	List *newNode = NULL, *head = NULL;

	if (!list || !*str)
		return (NULL);

	newNode = create_node(str);
	if (!newNode)
		return (NULL);

	if (!*list)
	{
		*list = newNode;
		endNode = newNode;
	}
	else
	{
		head = *list;
		while (head != startNode)
			head = head->prev;

		head->prev = newNode;
		newNode->next = head;
		endNode->next = newNode;
		newNode->prev = endNode;
	}
	startNode = newNode;
	*list = startNode;
	return (newNode);
}

/**
 * create_node - Create a new node
 *
 * @str: string to copy in the node
 *
 * Return: NULL in case of failure or the new node
 */
List *create_node(char *str)
{
	List *node = NULL;

	if (!*str)
		return (NULL);

	node = malloc(sizeof(List));

	if (!node)
		return (NULL);

	node->next = node;
	node->prev = node;
	node->str = strdup(str);

	return (node->str ? node : NULL);
}
