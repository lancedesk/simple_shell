#include "lance.h"

/**
 * _handle_comments - Handle lines that contain comments.
 * @input: User input as a string.
 * Return: Returns 1 if the line contains a comment
 * and has been handled, 0 otherwise.
 */

int _handle_comments(char *input)
{

	int i;
	int in_quote = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '"' && (i == 0 || input[i - 1] != '\\')) {
			in_quote = !in_quote;
		}

		if (input[i] == '#' && !in_quote)
		{
			input[i] = '\0';
			return 1;  /* Return 1 if a comment is found and has been handled */
		}
	}
	return 0;  /* Return 0 if no comment is found */
}
