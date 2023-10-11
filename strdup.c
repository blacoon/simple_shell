#include "shell.h"

/**
 * _strdup - it duplicates a string.
 * @s1: the string to be duplicated
 * Return: the duplicated string
 */

char *_strdup(const char *s1)
{
	int len;
	int idx;
	char *str_cpy;

	len = 0;
	idx = -1;

	while (s1[len])
		len++;
	str_cpy = malloc(sizeof(char) * (len + 1));
	if (!str_cpy)
		return (NULL);
	while (s1[++idx])
		str_copy[idx] = s1[idx];
	str_cpy[idx] = '\0';
	return (str_cpy);
}
