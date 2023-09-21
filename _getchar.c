#include "lance.h"

/**
 * _getchar - Reads a character from the standard
 * input (stdin) and returns it.
 * If an error occurs or the end of the file (EOF)
 * is reached, it returns EOF.
 *
 * Return: The character read from stdin or EOF
 * on error or EOF.
 */

int _getchar(void)
{
	char c;
	ssize_t result;

	result = read(STDIN_FILENO, &c, 1);

	if (result == 0)
	{
		/* End of file (EOF) */
		return (EOF);
	}
	else if (result < 0)
	{
		/* Error reading */
		return (EOF);
	}
	else
	{
		/* Successfully read a character */
		return ((int)c);
	}
}

