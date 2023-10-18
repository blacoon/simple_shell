#include "shell.h"

/**
 * ft_abs - Calculates the absolute value of a number.
 * @n: The number to calculate the absolute value for.
 * Return: The absolute value of nb.
 */
static int ft_abs(int n)
{
	if (n < 0)
	{
		return (n * -1);
	}
	return (n);
}

/**
 * ft_nbrpow - Calculates the nuimber of digits in a number.
 * @n: The number to calculate the digit for.
 * Return: The number of digits in n.
 */
static int ft_nbrpow(int n)
{
	int pow = 1;

	while (n > 9 || n < -9)
	{
		n /= 10;
		pow++;
	}
	return (pow);
}

/**
 * _itoa - Converts an integer to a string.
 * @n: The integer to be converted.
 * Return: The resulting string.
 */
char *_itoa(int n)
{
	char *res;
	int len;
	int neg;

	neg = n < 0;
	len = ft_nbrpow(n) + neg;
	res = malloc(sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
		len--;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
