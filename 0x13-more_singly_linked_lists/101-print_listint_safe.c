#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_listint_safe - prints all elements of a listint_t linked list
 * @head: pointer to the head of the list
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t i, nodes = 0;
	const listint_t *current = head;
	const listint_t *array[1024] = {NULL};

	if (head == NULL)
		exit(98);
	while (current)
	{
		for (i = 0; i < nodes; i++)
		{
			if (array[i] == current)
			{
				printf("-> [%p] %d\n", (void *)current, current->n);
				return (nodes);
			}
		}
		printf("[%p] %d\n", (void *)current, current->n);
		array[nodes] = current;
		nodes++;
		current = current->next;
	}
	return (nodes);
}

