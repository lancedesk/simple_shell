#include "lance.h"
#include "helpers.h"

/**
 * _strdup - Duplicates a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A statically allocated duplicate
 * of the input string.
 * Returns NULL if the input string is NULL or if the string is too long.
 */

char *_strdup(const char *str)
{
	size_t len;

	/* Define a static buffer with a maximum size */
	static char static_buffer[STR_INPUT_MAX_LENGTH];

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);

	/* Check if the string is too long for the static buffer */
	if (len >= STR_INPUT_MAX_LENGTH)
	{
		return (NULL);
	}

	/* Copy the input string to the static buffer */
	_strcpy(static_buffer, str);

	return (static_buffer);
}

