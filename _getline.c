#include "lance.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_index = 0;

/**
 * my_getline - Custom getline function with buffer for efficient character reading.
 * Returns a dynamically allocated string containing the user's input line.
 * Caller is responsible for freeing the memory allocated for the string.
 * Returns NULL on EOF or error.
 */
char *my_getline(void)
{
	int line_index = 0;
	char c;
	ssize_t bytes_read;
	char *line;

	line = malloc(BUFFER_SIZE);
	if (!line)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		if (buffer_index == 0)
		{
			bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);
			if (bytes_read <= 0) 
			{
				free(line);			return (NULL);
			}
			buffer_index = bytes_read;
		}

		c = buffer[buffer_index - 1];
		buffer_index--;

		if (c == '\n')
		{
			line[line_index] = '\0';
			return (line);
		}
		else
		{
			line[line_index] = c;
			line_index++;
		}
	}
}

