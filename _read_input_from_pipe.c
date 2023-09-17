#include "lance.h"

/**
 * _read_input_from_pipe - Read user input from a pipe.
 *
 * @prompt: A pointer to the character array where user input is stored.
 * @size: The maximum number of characters (including the null terminator)
 *        that 'prompt' can hold.
 *
 * This function reads user input from a pipe and stores it in the character
 * array 'prompt'. It ensures that no more than 'size' characters are read to
 * prevent buffer overflow.
 *
 * Return: The function returns the number of characters read from the pipe or
 * -1 if an error occurs.
 */

ssize_t _read_input_from_pipe(char *prompt, size_t size)
{
	ssize_t read_bytes;

	/* Read from the standard input (stdin) which is connected to the pipe */
	read_bytes = read(STDIN_FILENO, prompt, size);

	if (read_bytes == -1)
	{
		perror("Error reading input from pipe...\n");
	}

	return (read_bytes);
}

