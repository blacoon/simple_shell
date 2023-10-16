#include "shell.h"

/**
 * str_copy1 - Copies a substring from the input string
 * @str: The input string from which the substring is copied
 * @idx: A pointer to index from which copying starts
 * @a: The character at which copying stops.
 * Return: The copied substring
 */
char *str_copy1(char *str, int *idx, char a)
{
	int i, start, y;
	char *ptr;

	i = *idx;
	start = *idx;
	while (str[i] && str[i] != a)
	{
		i++;
		*idx = *idx + 1;
	}
	ptr = malloc(i + 1);
	y = 0;
	while (y < 1)
		ptr[y++] = str[start++];
	ptr[i] = '\0';
	return (ptr);
}
