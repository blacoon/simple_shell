#include "shell.h"

/**
 * _atoi - function that converts a string to an integer.
 * @s: arg 1.
 * Return: returns an integer.
 */
int _atoi(char *s)
{
	unsigned int n = 0;
	int sign = 0;
	int i = 0;

	while (s[i] && (s[i] == '+' || s[i] == '-' || s[i] == ' ' || s[i] == '\t'))
	{
		if (s[i] == '-')
			sign++;
		i++;
	}
	while (s[i] && (s[i] < '0' || s[i] > '9'))
		i++;
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		n *= 10;
		n += s[i] - '0';
		i++;
	}
	if (sign % 2 == 0)
		return (n);
	return (-n);
}
