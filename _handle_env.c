#include "lance.h"
#include "helpers.h"

/**
 * _handle_env - Print environment variables.
 *
 * This function iterates through the environment
 * variables and prints each variable
 * to the standard output.
 * Environment variables are stored as
 * a null-terminated
 * array of strings, with each string
 * in the format "NAME=VALUE".
 * The last element of the array is a null pointer.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_env(char **prompt_args)
{
	char **env;

	if (_strcmp(prompt_args[0], "env") == 0)
	{
		/* Iterate and print each environment variable */
		for (env = environ; *env != NULL; env++)
		{
			_puts(*env);
		}
	}
}

