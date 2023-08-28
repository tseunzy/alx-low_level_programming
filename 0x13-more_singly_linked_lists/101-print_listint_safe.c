#include "lists.h"
#include <stdio.h>

int node_is_in_list(const listint_t *node, const listint_t *list[]);
const listint_t *print_node(const listint_t *node);


/**
 * node_is_in_list - Checks if a node is in a list
 * @node: The node to check
 * @list: The list to check in
 * Return: 1 if the node is in the list, 0 otherwise
 */
int node_is_in_list(const listint_t *node, const listint_t *list[])
{
	int i;

	for (i = 0; list[i] != NULL; i++)
	{
		if (list[i] == node)
			return (1);
	}
	return (0);
}

/**
 * print_node - Prints a node
 * @node: The node to print
 * Return: The address of the node
 */
const listint_t *print_node(const listint_t *node)
{
	printf("[%p] %d\n", (void *)node, node->n);
	return (node);
}

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: The list
 * Return: The number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	const listint_t *visited[1024];
	int i;

	if (head == NULL)
		exit(98);
	for (i = 0; head != NULL && i < 1024; i++)
	{
		if (node_is_in_list(head, visited))
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			return (i);
		}
		visited[i] = print_node(head);
		head = head->next;
	}
	visited[i] = NULL;
	return (i);
}

