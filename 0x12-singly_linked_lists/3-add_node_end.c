#include <stdlib.h>
#include <string.h>
#include "lists.h"
/**
 * add_node_end - Adds a new node at the end of a list_t list.
 * @head: A double pointer to the head of the list.
 * @str: The string to be included in the new node.
 * Return: Returns the address of the new node, or NULL if the operat failed.
 */
list_t *add_node_end(list_t **head, const char *str)
{
	list_t *new_node;
	list_t *current = *head;

	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	new_node->str = strdup(str);
	if (!new_node->str)
	{
		free(new_node);
		return (NULL);
	}
	new_node->len = strlen(str);
	new_node->next = (NULL);
	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}
	while (current->next)
		current = current->next;
	current->next = new_node;
	return (new_node);
}

