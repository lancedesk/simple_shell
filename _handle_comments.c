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
	int in_comment = 0;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && (i == 0 || input[i - 1] == ' '))
		{
			in_comment = 1;
			input[i] = '\0'; /* Swap '#' with '\0' */
		}
		else if (input[i] != ' ' && in_comment)
		{
			in_comment = 0;
		}
	}
	/* Return 1 if a comment was handled, 0 otherwise */
	return (in_comment);
}

