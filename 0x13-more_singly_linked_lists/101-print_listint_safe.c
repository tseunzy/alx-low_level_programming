#include "lists.h"
#include <stdio.h>

size_t find_loop(const listint_t *head);
size_t print_listint_safe(const listint_t *head);

/**
 * find_loop - Finds the loop in a listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: The number of nodes before the loop starts.
 * If there is no loop, returns 0.
 */
size_t find_loop(const listint_t *head)
{
	const listint_t *slow = head, *fast = head;
	size_t nodes = 0;

	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		nodes++;

		if (slow == fast)
		{
			return (nodes);
		}
	}

	return (0);
}

/**
 * print_listint_safe - Prints a listint_t list safely.
 * @head: A pointer to the head of the listint_t list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0, loop_start;

	loop_start = find_loop(head);

	while (head)
	{
		printf("[%p] %d\n", (void *)head, head->n);
		nodes++;
		head = head->next;

		if (loop_start == nodes)
		{
			printf("-> [%p] %d\n", (void *)head, head->n);
			break;
		}
	}

	return (nodes);
}

