#include "lance.h"
#include "helpers.h"

/**
 * _handle_comments - Handle lines that contain comments.
 *
 * @prompt_args: An array of command arguments.
 *
 * Return: Returns 1 if the line contains a comment
 * and has been handled, 0 otherwise.
 */

int _handle_comments(char **prompt_args)
{
	int i, j;
	char *arg;

	/* Iterate through the arguments */
	for (i = 0; prompt_args[i] != NULL; i++)
	{
		arg = prompt_args[i];

		/* Iterate through the characters in the argument */
		for (j = 0; arg[j] != '\0'; j++)
		{
			if (arg[j] == '#')
			{
				/* If '#' char found, terminate the argument */
				/* before '#' */
				arg[j] = '\0';
				/* Indicate that the line contains a comment */
				return (1);
			}
		}
	}

	/* Indicate that the line does not contain a comment */
	return (0);
}

