#include "lance.h"
#include "helpers.h"

/**
 * _handle_path - Print the current PATH
 * environment variable.
 *
 * This function checks if the user entered
 * "PATH" as a command and prints the current
 * PATH environment variable.
 * If the PATH variable is not set, it indicates so.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_path(char **prompt_args)
{
	if (_strcmp(prompt_args[0], "PATH") == 0)
	{
		/* Get and print the current PATH */
		/* environment variable */
		char *path = getenv("PATH");

		if (path != NULL)
		{
			printf("PATH=%s\n", path);
		}
		else
		{
			printf("PATH environment variable not set.\n");
		}
	}
}
