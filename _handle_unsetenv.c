#include "lance.h"
#include "helpers.h"

/**
 * _handle_unsetenv - Unset an environment variable.
 *
 * This function takes one argument: the variable name to unset.
 * It uses the `unsetenv` function to remove the environment variable.
 * If there's an error, it uses `perror` to print an error message to stderr.
 *
 * @prompt_args: An array of command arguments.
 *
 * Return: None.
 */
void _handle_unsetenv(char **prompt_args)
{
	/* Check if the variable name is provided as an argument */
	if (prompt_args[1] != NULL)
	{
		/* Attempt to unset the environment variable */
		if (unsetenv(prompt_args[1]) != 0)
		{
			/* If there's an error, print an error message to stderr */
			/*perror("unsetenv: Unable to unset */
			/*environment variable\n");*/
		}
	}
	else
	{
		/* If the argument is missing, print an error message to stderr */
		perror("unsetenv: Invalid syntax. Usage: unsetenv VARIABLE");
	}
}
