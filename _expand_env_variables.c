#include "lance.h"

/**
 * _expand_env_variables - Replace environment variables
 * in a string with their values.
 *
 * This function searches for occurrences of environment
 * variables in the given string `prompt`
 * and replaces them with their corresponding values
 * from the system environment.
 * It handles variable names enclosed in '$' symbols.
 *
 * @prompt: The string in which environment variables
 * should be expanded.
 */

void _expand_env_variables(char *prompt)
{
	char *dollar_sign, *var, *val, *var_name;
	size_t var_len, val_len;

	/* Find the first occurrence of '$' in the prompt */
	while ((dollar_sign = strchr(prompt, '$')) != NULL)
	{
		/* Find the end of the variable name */
		/* (e.g., the first space or character */
		/* that's not valid in a variable name) */
		var = dollar_sign + 1;

		while (*var != '\0' && *var != ' ' && *var != '$')
		{
			var++;
		}

		/* A substring for the variable name */
		var_len = var - (dollar_sign + 1);

		/* Allocate memory dynamically for var_name */
		var_name = (char *)malloc(var_len + 1);

		if (var_name == NULL)
		{
			/* Handle memory allocation failure */
			exit(EXIT_FAILURE);
		}

		strncpy(var_name, dollar_sign + 1, var_len);
		var_name[var_len] = '\0';

		/* Get the value of the environment variable */
		val = getenv(var_name);

		/* Replace the variable with its value in the prompt */
		if (val != NULL)
		{
			val_len = strlen(val);
			memmove(dollar_sign + val_len, var, _strlen(var) + 1);
			memcpy(dollar_sign, val, val_len);
		}

		/* Free the dynamically allocated memory */
		free(var_name);
	}
}
