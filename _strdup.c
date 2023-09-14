#include "lance.h"

/**
 * _strdup - Duplicates a string.
 *
 * @str: The string to duplicate.
 *
 * Return: A dynamically allocated duplicate
 * of the input string.
 * Returns NULL if memory allocation fails.
 */

char *_strdup(const char *str)
{
	size_t len;
	char *new_string;

	if (str == NULL)
	{
		return (NULL);
	}

	len = _strlen(str);
	new_string = (char *)malloc(len + 1);

	if (new_string == NULL)
	{
		/* Memory allocation failed */
		return (NULL);
	}

	_strcpy(new_string, str);
	return (new_string);
}
