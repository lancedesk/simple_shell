#include "lance.h"
#include "helpers.h"

/**
 * _handle_cd - Change the current working directory.
 *
 * This function handles the "cd" command by changing
 * the current working directory. It supports changing
 * to the home directory (~), the previous directory (-),
 * and specified directories.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_cd(char **prompt_args)
{
	char *new_dir, *arg1 = prompt_args[1];

	if (_strcmp(prompt_args[0], "cd") == 0)
	{
		new_dir = NULL;
		if (arg1 == NULL || _strcmp(arg1, "~") == 0)
		{
			/* No arg or "~" provided, change to home dir */
			new_dir = getenv("HOME");
		}
		else if (_strcmp(arg1, "-") == 0)
		{
			/* Handle "cd -" to switch to the previous dir */
			new_dir = getenv("OLDPWD");
		}
		else
		{
			new_dir = arg1; /* Change to specified dir */
		}
		if (new_dir != NULL)
		{
			if (chdir(new_dir) == -1)
			{
				perror("cd error");
			}
			else
			{
				/* Update the PWD environment variable */
				setenv("PWD", new_dir, 1);
				/* Print the new working directory */
				/* printf("Changed directory to %s\n", new_dir); */
				/* Update the OLDPWD environment variable */
				setenv("OLDPWD", getenv("PWD"), 1);
			}
		}
		else
		{
			_puts("Usage: cd [DIRECTORY | ~ | -]");
		}
	}
}
