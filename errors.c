#include "shell.h"

/**
 * print - Writes a string to a specified file descriptor
 * @str: The string to be written
 * @fd: The specified file descriptor
 * @new: A flag indicating whether to append a newline  or not
 * Return: The numberof char written (excluding the '\n' char if written)
 */
int print(char *str, int fd, int new)
{
	write(fd, str, _strlen(str));
	if (new)
		return (write(fd, "\n", 1));
	return (1);
}
