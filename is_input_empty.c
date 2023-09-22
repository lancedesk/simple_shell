#include "lance.h"

/**
 * is_input_empty - Check if a string consists only of spaces.
 * @str: The string to check.
 *
 * This function checks if the given string consists
 * only of spaces (or is NULL
 * or empty) up to the newline character.
 *
 * Return: true if the string is empty or contains
 * only spaces; otherwise, false.
 */

bool is_input_empty(const char *str)
{
	if (str == NULL)
	{
		return (true);
	}

	while (*str && *str != '\n')
	{
		if (*str != ' ')
		{
			return (false);
		}
		str++;
	}
	return (true);
}