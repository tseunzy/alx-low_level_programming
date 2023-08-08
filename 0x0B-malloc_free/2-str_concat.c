#include "main.h"
#include <stdlib.h>
/**
 * str_concat - a function get ends of input and add together for size
 * @s1: input one to conct
 * @s2: input two to conct
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *conct;
	int l1, l2;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}

	l1 = l2 = 0;
	while (s1[l1])
		l1++;
	while (s2[l2])
		l2++;
	conct = (char *) malloc(sizeof(char) * (l1 + l2 + 1));

	if (conct == NULL)
		return (NULL);

	for (int i = 0; i < l1; i++)
	{
		conct[i] = s1[i];
	}

	for (int i = 0; i < l2; i++)
	{
		conct[i + l1] = s2[i];
	}
	conct[l1 + l2] = '\0';
	return (conct);
}

