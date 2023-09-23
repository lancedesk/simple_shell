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

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#')
		{
			input[i] = '\0';
			return (1);  /* Return 1 if a comment is found */
		}
	}
	return (0);  /* Return 0 if no comment is found */
}


