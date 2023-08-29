#include "lists.h"

size_t looped_len_listint(const listint_t *head);
size_t print_listint_safe(const listint_t *head);


/**
 * looped_len_listint - Counts the number of unique nodes
 * in a looped listint_t linked list.
 * @head: A pointer to the head of the listint_t to check.
 *
 * Return: If the list is not looped - 0.
 * Otherwise - the number of unique nodes in the list.
 */
size_t looped_len_listint(const listint_t *head)
{
	const listint_t *slow_ptr, *fast_ptr;
	size_t num_nodes = 1;

	if (head == NULL || head->next == NULL)
		return (0);

	slow_ptr = head->next;
	fast_ptr = (head->next)->next;
	while (fast_ptr)
	{
		if (slow_ptr == fast_ptr)
		{
			slow_ptr = head;
			while (slow_ptr != fast_ptr)
			{
				num_nodes++;
				slow_ptr = slow_ptr->next;
				fast_ptr = fast_ptr->next;
			}
			slow_ptr = slow_ptr->next;
			while (slow_ptr != fast_ptr)
			{
				num_nodes++;
				slow_ptr = slow_ptr->next;
			}
			return (num_nodes);
		}
		slow_ptr = slow_ptr->next;
		fast_ptr = (fast_ptr->next)->next;
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
	size_t num_nodes, idx = 0;

	num_nodes = looped_len_listint(head);
	if (num_nodes == 0)
	{
		for (; head != NULL; num_nodes++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
	}
	else
	{
		for (idx = 0; idx < num_nodes; idx++)
		{
			printf("[%p] %d\n", (void *)head, head->n);
			head = head->next;
		}
		printf("-> [%p] %d\n", (void *)head, head->n);
	}
	return (num_nodes);
}

