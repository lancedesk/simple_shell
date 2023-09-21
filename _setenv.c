#include "lance.h"
#include "helpers.h"

/**
 * _setenv - Set or update an environment variable.
 *
 * @name: The name of the environment variable
 * to set or update.
 * @value: The new value to assign to the
 * environment variable.
 * @overwrite: A flag indicating whether to overwrite
 * an existing variable (1) or not (0).
 *
 * Return: If successful, returns 0.
 * If memory allocation fails or an error occurs,
 * returns -1. If 'name' or 'value' is NULL, returns -1.
 */

int _setenv(const char *name, const char *value, int overwrite)
{
	char *existing, *env_var;
	int result;

	if (name == NULL || value == NULL)
	{
		return (-1); /* Invalid input */
	}

	/* Check if the environment variable already exists */
	existing = _getenv(name);
	if (existing != NULL && !overwrite)
	{
		/* Variable already exists, */
		/* and overwrite is not allowed */
		return (0);
	}

	/* Construct the full environment variable string */
	env_var = _construct_full_path(name, value);

	if (env_var == NULL)
	{
		return (-1); /* Memory allocation failed */
	}

	/* Set the environment variable  */
	result = putenv(env_var);
	if (result != 0)
	{
		free(env_var); /* Free allocated memory if error */
	}

	return (result);
}

