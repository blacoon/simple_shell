#include "shell.h"

/**
 * _strcmp - Compares two strings
 * @str1: first string argument
 * @str2: second string argument
 * @n: maximum number of character to compare
 * Return: 0 if equal
 */
int _strcmp(const char *str1, const char *str2, size_t n)
{
	size_t = i;

	i = 0;
	if (!n)
		return (0);
	while (str1[i] && str2[i] && str1[i] == str2[i] && i < n - 1)
		i++;
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}
