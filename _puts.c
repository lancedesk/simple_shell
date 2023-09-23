#include "lance.h"

/**
 * _puts - Write a null-terminated string
 * to the standard output followed by a newline.
 *
 * This function writes the null-terminated string
 * 'str' to the standard output
 * and appends a newline character ('\n')
 * at the end of the string.
 *
 * @str: The null-terminated string to be written.
 */

void _puts(const char *str)
{
	if (str == NULL)
	{
		return;
	}
	while (*str)
	{
		_putchar(*str);
		str++;
	}
	/* Newline character at the end */
	_putchar('\n');
}

