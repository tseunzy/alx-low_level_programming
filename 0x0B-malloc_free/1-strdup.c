#include <stdlib.h>
#include "main.h"
/**
 * _strdup - a function that duplicate to new memory space location
 * @str: char
 * Return: pointer
 */
char *_strdup(char *str)
{
	char *dup;
	int i, j = 0;

	if (str == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;

	dup = (char *) malloc(sizeof(char) * (i + 1));

	if (dup == NULL)
		return (NULL);

	for (j = 0; str[j]; j++)
		dup[j] = str[j];

	return (dup);
}

