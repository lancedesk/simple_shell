#include "lance.h"

int _initialize_buffer_if_needed(char **buffer, size_t *size);
int _validate_input_parameters(char **buffer, size_t *size);

/**
 * _getline - Reads a line from standard input.
 *
 * @buffer: A pointer to the buffer where the line will be stored.
 * @size: A pointer to the buffer size.
 *
 * Return: The number of bytes read, -1 on error, or -2 on EOF.
 */

ssize_t _getline(char **buffer, size_t *size)
{
	ssize_t bytes_read = 0;
	ssize_t total_bytes_read = 0;
	char c;

	if (_validate_input_parameters(buffer, size) != 0)
	{
		return (-1);  /* Invalid input */
	}
	if (_initialize_buffer_if_needed(buffer, size) != 0)
	{
		return (-1);  /* Initialization error */
	}
	while (1)
	{
		bytes_read = read(STDIN_FILENO, &c, 1);
		if (bytes_read <= 0)
		{
			break;  /* Error or EOF */
		}
		(*buffer)[total_bytes_read] = c;
		total_bytes_read++;
		if ((size_t)total_bytes_read >= *size)
		{
			*size *= 2;  /* Resize the buffer if necessary */
			*buffer = realloc(*buffer, *size);

			if (*buffer == NULL)
			{
				perror("Memory allocation failed");
				return (-1);  /* Allocation failure */
			}
		}
		if (c == '\n')
		{
			(*buffer)[total_bytes_read] = '\0';  /* EOL - Null-terminate the string */
			return (total_bytes_read);
		}
	}
	if (bytes_read == 0 && total_bytes_read == 0)
	{
		return (-2);  /* EOF reached */
	}
	return (-1);  /* Error */
}

/**
 * _validate_input_parameters - Validates input parameters.
 *
 * @buffer: A pointer to the buffer.
 * @size: A pointer to the buffer size.
 *
 * Return: 0 for valid input, -1 for invalid input.
 */

int _validate_input_parameters(char **buffer, size_t *size)
{
	if (!buffer || !size)
	{
		/* Invalid input */
		return (-1);
	}
	return (0);
}

/**
 * _initialize_buffer_if_needed - Initializes the buffer if necessary.
 *
 * @buffer: A pointer to the buffer.
 * @size: A pointer to the buffer size.
 *
 * Return: 0 for success, -1 for failure.
 */

int _initialize_buffer_if_needed(char **buffer, size_t *size)
{
	if (*buffer == NULL || *size == 0)
	{
		/* Initial buffer size */
		*size = 1024;
		*buffer = malloc(*size);

		if (*buffer == NULL)
		{
			perror("Memory allocation failed");
			return (-1);  /* Allocation failure  */
		}
	}
	return (0);  /* Success */
}

