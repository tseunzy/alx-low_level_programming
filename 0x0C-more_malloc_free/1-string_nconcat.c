#include <stdlib.h>
#include "main.h"
/**
 * *string_nconcat - concatenates n bytes of a string to another string
 * @s1: string to append to
 * @s2: string to concatenate from
 * @n: number of bytes from s2 to concatenate to s1
 * Return: pointer to the resulting string
 */
		
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *s;
	unsigned int i = 0, len1 = 0, len2 = 0;
	
	while (s1 && s1[len1])
	{
		len1++;
	}

	while (s2 && s2[len2])
	{
		len2++;
	}
	if (n < len2){
	n = len2;
	}

	s = malloc(sizeof(char) * (len1 + n + 1));
	if (s == NULL) 
	{
		return (NULL);
	}
	for (i = 0; i < len1; i++)
	{
		s[i] = s1 ? s1[i] : '\0';
	}
	for (i = 0; i < n; i++)
	{
		s[len1 + i] = s2 ? s2[i] : '\0';
	}
	s[len1 + n] = '\0';
	
	return (s);
}
