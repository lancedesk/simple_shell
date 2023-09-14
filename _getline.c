#include "lance.h"

/**
 * _getline - Read a line from standard input.
 *
 * @buffer: A pointer to the buffer
 * where the line will be stored.
 * @size: The size of the buffer.
 *
 * Return: The number of bytes read,
 * or -1 if there was an error or if EOF is reached.
 */

ssize_t _getline(char **buffer, size_t *size)
{
	ssize_t bytes_read = 0;
	ssize_t total_bytes_read = 0;
	char c;

	if (!buffer || !size)
	{
		return (-1);  /* Invalid input */
	}

	/* Initialize the buffer */
	if (*buffer == NULL || *size == 0)
	{
		/* Initial buffer size */
		*size = 1024;
		*buffer = malloc(*size);
		if (!*buffer)
		{
			perror("Memory allocation failed");
			return -1;
		}
	}

	while (1)
	{
		bytes_read = read(STDIN_FILENO, &c, 1);
		if (bytes_read <= 0)
		{
			/* Error or EOF */
			break;
		}

		(*buffer)[total_bytes_read] = c;
		total_bytes_read++;

		if ((size_t)total_bytes_read >= *size)
		{
			/* Resize the buffer if necessary */
			*size *= 2;
			*buffer = realloc(*buffer, *size);
			if (!*buffer)
			{
				perror("Memory allocation failed");
				return (-1);
			}
		}

		if (c == '\n')
		{
			/* End of line */
			/* Null-terminate the string */
			(*buffer)[total_bytes_read] = '\0';
			return (total_bytes_read);
		}
	}

	if (bytes_read == 0 && total_bytes_read == 0)
	{
		/* EOF reached */
		return (-1);
	}

	return (-1);  /* -1 for error */
}
