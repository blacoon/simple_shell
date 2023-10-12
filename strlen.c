#include "shell.h"

/**
 * _strlen - calculate the length.
 * @s: the string
 * Return: The lenth of the string
 */
size_t _strlen(const char *s)
{
	size_t len;

	len = 0;
	while(s[len])
		len++;
	return (len);
}
