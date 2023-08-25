#include <stdlib.h>
#include "lists.h"
/**
 * free_list - Frees a list_t list.
 * @head: Pointer to the first node of the list.
 * Description:
 * This function traverses each node of the provided list, freeing
 * the memory used by the string inside each node and then the node itself.
 */
void free_list(list_t *head)
{
	list_t *temp;

	while (head)
	{
		temp = head;
		head = head->next;

		free(temp->str);
		free(temp);
	}
}
