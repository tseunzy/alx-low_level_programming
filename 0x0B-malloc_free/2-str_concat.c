#include "main.h"
#include <stdlib.h>
/**
 * str_concat - a function get ends of input and add together for size
 * @s1: input one to concat
 * @s2: input two to concat
 * @l_s1: length of s1
 * @l_s2: length of s2
 * Return: concat of s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *conct;
	int l_s1, l_s2;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	l_s1 = l_s2 = 0;
	while (s1[l_s1])
		l_s1++;
	while (s2[l_s2])
		l_s2++;
	conct = (char *)malloc(sizeof(char) * (l_s1 + l_s2 + 1));

	if (conct == NULL)
		return (NULL);
	l_s1 = l_s2 = 0;
	while (s1[l_s1])
	{
		conct[l_s1] = s1[l_s1];
		l_s1++;
	}

	while (s2[l_s2])
	{
		conct[l_s2] = s2[l_s2];
		l_s1++, l_s2++;
	}
	conct[l_s1] = '\0';
	return (conct);
}

