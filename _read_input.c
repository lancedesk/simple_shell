#include "lance.h"
#include "helpers.h"

/**
 * read_input - Reads and allocates memory
 * for user input.
 *
 * @length: A pointer to a size_t variable
 * representing the length of the input string.
 *
 * @max_length: A pointer to a size_t variable
 * ( maximum allocated length of input buffer.
 * This value may be increased as needed
 * to accommodate longer input.
 *
 * Return: A dynamically allocated character buffer
 * containing the user input
 */

char *read_input(size_t *length, size_t *max_length)
{
	int c;
	char *input = NULL, *temp;
	size_t i;

	/* Initialize max_length */
	*max_length = INITIAL_MAX_LENGTH;

	/* Allocate memory for the input buffer */
	/* using the new function */
	input = allocate_input_buffer(max_length);

	/* Initialize length */
	*length = 0;

	while ((c = _getchar()) != '\n' && c != EOF)
	{
		if (*length >= *max_length - 1)
		{
			/* Double the buffer size */
			*max_length *= 2;
			temp = allocate_input_buffer(max_length);

			/* Copy data from old buffer to new one */
			for (i = 0; i < *length; i++)
			{
				temp[i] = input[i];
			}

			/* Free the old buffer */
			free_input_buffer(input);
			input = temp;
		}
		input[(*length)++] = (char)c;
	}

	/* Null-terminate the input string */
	input[*length] = '\0';

	/* Return the dynamically allocated buffer */
	return (input);
}
