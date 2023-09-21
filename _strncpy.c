#include "lance.h"

/**
 * _strncpy - Custom strncpy function that copies at most
 * 'n' characters from 'src' to 'dest'.
 * If 'src' is shorter than 'n' characters,
 * it pads 'dest' with null bytes ('\0') to
 * reach 'n' characters.
 *
 * @dest: The destination buffer where the
 * copied string will be stored.
 * @src: The source string to be copied.
 * @n: The maximum number of characters to copy.
 *
 * Return: A pointer to 'dest'.
 */

char *_strncpy(char *dest, const char *src, size_t n)
{
	char *dest_start = dest;

	/* Copy at most 'n' characters from 'src' to 'dest' */
	while (n > 0 && *src != '\0')
	{
		*dest++ = *src++;
		n--;
	}

	/* If 'src' is shorter than 'n', */
	/* pad 'dest' with null bytes */
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}

	return (dest_start);
}
