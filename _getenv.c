#include "lance.h"
#include "helpers.h"

/**
 * _getenv - Get the value of an environment variable.
 *
 * @name: The name of the environment variable.
 *
 * Return: If the environment variable is found, return
 * a pointer to its value. If not found or
 * in case of an error, return NULL.
 */

char *_getenv(const char *name)
{
	/* Access the global environment variables */
	char *env_var, *var_name;
	char **env;

	if (name == NULL || environ == NULL)
	{
		return (NULL);
	}

	for (env = environ; *env != NULL; env++)
	{
		env_var = *env;
		var_name = (char *)name;

		while (*var_name != '\0' &&
				*var_name == *env_var && *env_var != '='
		      )
		{
			var_name++;
			env_var++;
		}

		if (*var_name == '\0' && *env_var == '=')
		{
			/* Return the value part of the environment variable */
			return (env_var + 1);
		}
	}
	/* Environment variable not found */
	return (NULL);
}

