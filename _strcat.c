#include "lance.h"

/**
 * _strcat - Concatenate two strings.
 *
 * This function concatenates the string `src`
 * to the end of the string `dest`.
 * The resulting concatenated string is stored in `dest`.
 *
 * @dest: The destination string where the result will be stored.
 * @src: The source string to be concatenated to the end of `dest`.
 *
 * Return: A pointer to the destination string `dest`.
 */

char *_strcat(char *dest, const char *src)
{
	char *original_dest = dest;

	if (dest == NULL || src == NULL)
	{
		/* Return NULL if dest || src is NULL*/
		return (NULL);
	}

	/* Move to the end of the destination string */
	while (*dest)
		dest++;

	/* Copy the source string to the end of the destination string */
	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}

	/* Add the null-terminator to the end */
	*dest = '\0';

	return (original_dest);
}

