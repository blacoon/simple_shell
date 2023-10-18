#include "shell.h"

/**
 * putnbr_fd - Print an integer to a specified fd
 * @n: the integer
 * @fd: the specified file descriptor
 */
void putnbr_fd(int n, int fd)
{
	if (n < 10)
	{
		write(fd, &"0123456789"[n % 10], 1);
	}
	else
	{
		putnbr_fd(n / 10, fd);
		putnbr_fd(n % 10, fd);
	}
}
