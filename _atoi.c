#include "lance.h"
#include "helpers.h"

/**
 * _atoi - Converts a string to an integer.
 *
 * This function takes a string and converts
 * it to an integer.
 * It handles positive and negative integers
 * and ignores leading
 * white spaces.
 *
 * @str: The input string to convert.
 * Return: The integer value represented
 * by the input string.
 * If the input is not a valid integer,
 * it returns 0.
 */

int _atoi(const char *str)
{
	int result = 0;
	/* Initialize sign as positive */
	int sign = 1;

	/* Skip leading white spaces */
	while (*str == ' ' || *str == '\t')
		str++;

	/* Check for a sign (+/-) */
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}

	/* Convert the digits to an integer */
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}

	/* Apply the sign */
	return (sign * result);
}
