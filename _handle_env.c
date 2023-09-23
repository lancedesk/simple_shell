#include "lance.h"

/**
 * _handle_env - Print environment variables.
 *
 * @input: input from user.
 */

void _handle_env(char *input)
{
	char **env = NULL;

	if (_strcmp(input, "env") == 0)
	{
		/* Iterate and print each environment variable */
		for (env = environ; *env != NULL; env++)
		{
			_puts(*env);
		}
	}
}
