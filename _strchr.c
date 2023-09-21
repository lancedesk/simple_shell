#include "lance.h"
#include <stdlib.h>

/**
 * _strchr - Locate the first occurrence
 * of a character in a string.
 *
 * @str: The string to search.
 * @c: The character to search for.
 *
 * Return: A pointer to the first occurrence
 * of `c` in `str`, or NULL if not found.
 */

char *_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
		{
			return ((char *)str);
		}
		str++;
	}

	if ((char)c == '\0')
	{
		return ((char *)str); /* Special case for null character */
	}

	return (NULL);
}

