#include "lance.h"
#include "helpers.h"

/**
 * _handle_dollar - Handle variable replacement for $?, $$
 *
 * This function checks if the user's command contains $?, $$
 * and replaces them with their respective values.
 *
 * @prompt_args: An array of command arguments.
 * @status: The status of the last command executed.
 */
void _handle_dollar(char **prompt_args, int status)
{
	int i;
	char *path, *arg;

	for (i = 0; prompt_args[i] != NULL; i++)
	{
		arg = prompt_args[i];
		if (arg[0] == '$')
		{
			if (_strcmp(arg, "$?") == 0)
			{
				/* Replacing $? */
				/* The status of the last command executed */
				printf("%d\n", status);
			}
			else if (_strcmp(arg, "$$") == 0)
			{
				/* Replacing $$ */
				/* The process ID of the shell */
				printf("%d\n", getpid());
			}
			else if (_strcmp(arg, "$PATH") == 0)
			{
				/* $PATH replaced with the current PATH */
				/* environment variable */
				path = getenv("PATH");
				if (path != NULL)
				{
					printf("%s\n", path);
				}
			}
			else
			{
				/* To handle other variables later */
			}
		}
	}
}

