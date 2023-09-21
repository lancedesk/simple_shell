#include "lance.h"
#include "helpers.h"

/**
 * read_input - Reads and allocates memory for user input using getline.
 *
 * Return: A dynamically allocated character buffer containing user input.
 * This buffer is automatically resized by getline as needed.
 */

char *read_input(void)
{
	char *input = NULL;
	size_t size = 0;

	ssize_t bytes_read = getline(&input, &size, stdin);

	if (bytes_read == -1)
	{
		perror("Error reading input");
		free(input); /* Free the buffer if an error occurs */
		return (NULL);
	}

	/* Remove the newline character at the end, if it exists */
	if (bytes_read > 0 && input[bytes_read - 1] == '\n')
	{
		input[bytes_read - 1] = '\0';
	}

	return (input);
}
