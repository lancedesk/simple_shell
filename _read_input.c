#include "lance.h"
#include "helpers.h"

/**
 * read_input - Reads and allocates memory for user input.
 *
 * Return: A dynamically allocated character buffer containing user input.
 * This buffer is automatically resized as needed.
 */

char *read_input(void)
{
  char *input = NULL;
  size_t size = 0;
  ssize_t bytes_read = -1;
  size_t buffer_size = 256;

    if (isatty(STDIN_FILENO))
    {
        /* Input is coming from a terminal, use getline */
        bytes_read = getline(&input, &size, stdin);
    }
    else
    {
        /* Input is not from a terminal, use read */
        input = (char *)malloc(buffer_size);
        if (input == NULL)
        {
            perror("Memory allocation failed");
            return (NULL);
        }
        /* Read one less than buffer size to leave space for null terminator */
        bytes_read = read(STDIN_FILENO, input, buffer_size - 1);
        if (bytes_read != -1)
        {
            input[bytes_read] = '\0'; /* Null-terminate the string */
        }
    }

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
