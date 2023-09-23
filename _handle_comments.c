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
	char *comment = NULL;

	for (i = 0; input[i] != '\0'; i++)
	{
		if (input[i] == '#' && !in_comment)
		{
			in_comment = 1;
		}
		else if (input[i] != ' ' && in_comment)
		{
			in_comment = 0;
		}
	}

	/* If the entire line is a comment, return 1. */
	if (in_comment)
	{
		return (1);
	}

	/* Remove the comment from the input string. */
	while (*input == ' ')
	{
		input++;
	}

	comment = strchr(input, '#');
	if (comment != NULL)
	{
		*comment = '\0';
	}

	return (0);
}

