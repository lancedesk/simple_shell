#include "lance.h"
#include "helpers.h"

/**
 * _input_processor - Read and process user input.
 *
 * @prompt: A pointer to the character array
 * where user input is stored.
 * @size: The maximum number of characters
 * (including the null terminator)
 * that 'prompt' can hold.
 *
 * @file: A pointer to a FILE structure.
 * If not NULL, input will be read
 * from this file instead of stdin.
 * @fd: A file descriptor. If `file` is NULL
 * and `fd` is not -1,
 * input will be read from this file descriptor.
 */

void _input_processor(char *prompt, size_t size, FILE *file, int fd)
{
	ssize_t read_bytes;
	/* File mode: Read from the provided FILE structure */
	if (file != NULL)
	{
		read_bytes = read_input_from_file(prompt, size, file);
	}
	else if (fd != -1) /* Fd mode: Read from provided fd */
	{
		read_bytes = read_input_from_fd(prompt, size, fd);
	}
	else if (is_input_from_pipe()) /* Input from a pipe */
	{
		read_bytes = _read_input_from_pipe(prompt, size);
	}
	else /* Interactive mode: Read from stdin */
	{
		read_bytes = read_input_from_stdin(prompt, size);
	}
	if (read_bytes == -1)
	{
		if (feof(file) || (fd != -1 && read_bytes == 0))
		{
			if (file != stdin)
			{
				if (file != NULL)
				{
					close(fileno(file)); /* Close the file descriptor */
				}
				exit(EXIT_SUCCESS);
			}
		}
		else
		{
			perror("Error reading user input...\n");
		}
	}
	if (prompt[read_bytes - 1] == '\n')
	{
		prompt[read_bytes - 1] = '\0'; /* Remove newline character if present */
	}
}

/**
 * read_input_from_stdin - Read user input from standard input (stdin).
 *
 * @prompt: A pointer to the character array where user input is stored.
 * @size: The maximum number of characters (including the null terminator)
 *        that 'prompt' can hold.
 *
 * This function reads user input from the standard input (stdin) and stores
 * it in the character array 'prompt'. It ensures that no more than 'size'
 * characters are read to prevent buffer overflow.
 * Return: The function returns the number of characters read from stdin
 * or -1 if an error occurs.
 */

ssize_t read_input_from_stdin(char *prompt, size_t size)
{
	_printer("Lance-Shell$ "); /* Interactive mode: Print shell prompt */
	return (_getline(&prompt, &size));
}

/**
 * read_input_from_fd - Read user input from a file descriptor.
 *
 * @prompt: A pointer to the character array where user input is stored.
 * @size: The maximum number of characters (including the null terminator)
 *        that 'prompt' can hold.
 * @fd: The file descriptor from which to read input.
 *
 * This function reads user input from the provided file descriptor 'fd'
 * and stores it in the character array 'prompt'. It ensures that no more
 * than 'size' characters are read to prevent buffer overflow.
 * Return: The function returns the number of characters read
 * from the file descriptor or -1 if an error occurs.
 */

ssize_t read_input_from_fd(char *prompt, size_t size, int fd)
{
	return (read(fd, prompt, size));
}

/**
 * read_input_from_file - Read user input from a file.
 *
 * @prompt: A pointer to the character array where user input is stored.
 * @size: The maximum number of characters (including the null terminator)
 *        that 'prompt' can hold.
 * @file: A pointer to a FILE structure representing the input file.
 *
 * This function reads user input from the provided input file 'file' and
 * stores it in the character array 'prompt'. It ensures that no more than
 * 'size' characters are read to prevent buffer overflow.
 * Return: The function returns the number of characters read
 * from the file or -1 if an error occurs.
 */

ssize_t read_input_from_file(char *prompt, size_t size, FILE *file)
{
	return (getline(&prompt, &size, file));
}

/**
 * is_input_from_pipe - Check if input is coming from a pipe.
 *
 * This function checks if the input to the program is coming from a pipe.
 * It returns 1 if the input is from a pipe, and 0 otherwise. This information
 * can be useful for distinguishing between interactive and non-interactive
 * input sources.
 * Return: 1 if input is from a pipe, 0 otherwise
 */

int is_input_from_pipe(void)
{
	return (!isatty(fileno(stdin)));
}
