#include "shell.h"
/**
 * printError - Prints an error message to the standard error output
 * @cmd: The name of the command where the error occurred
 * @msg: The error message to be displayed
 * @global: A pointer to the global state struct
 * Return: Always return 1
 */
int	printError(char *cmd, char *msg, global_t *global)
{
	write(2, global->name, _strlen(global->name));
	write(2, ": ", 2);
	putnbr_fd(global->n, 2);
	write(2, ": ", 2);
	write(2, cmd, _strlen(cmd));
	write(2, ": ", 2);
	write(2, msg, _strlen(msg));
	write(2, "\n", 1);
	return (1);
}

/**
 * _print - Writes a string to a specified file descriptor
 * @str: The string to be written
 * @fd: The specified file descriptor
 * @new: A flag indicating whether to append a newline  or not
 * Return: The numberof char written (excluding the '\n' char if written)
 */
int _print(char *str, int fd, int new)
{
	write(fd, str, _strlen(str));
	if (new)
		return (write(fd, "\n", 1));
	return (1);
}
