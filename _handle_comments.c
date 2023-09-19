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
	int i;
	char *comment_pos, *arg;

	/* Iterate through the arguments */
	for (i = 0; prompt_args[i] != NULL; i++)
	{
		arg = prompt_args[i];
		comment_pos = strchr(arg, '#');  /* Find '#' char */

		if (comment_pos != NULL)
		{
			/* If '#' char found, terminate the argument before '#' */
			*comment_pos = '\0';

			/* Indicate that the line contains a comment */
			return (1);
		}
	}

	/* Indicate that the line does not contain a comment */
	return (0);
}

