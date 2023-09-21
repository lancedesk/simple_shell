#include "lance.h"
#include <stdlib.h>

static char *_find_env_variable(const char *str);
static int _expand_single_env_variable(char *var_name_start);

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
	char *var_name_start;

	while ((var_name_start = _find_env_variable(prompt)) != NULL)
	{
		if (!_expand_single_env_variable(var_name_start))
		{
			/* Variable not found, move to the next character */
			prompt = var_name_start + 1;
		}
	}
}

/**
 * _find_env_variable - Find an environment variable within a string.
 *
 * This function searches for the first occurrence of an environment
 * variable enclosed in '$' symbols in the given string `str`.
 * It returns a pointer to the variable name if found, or NULL otherwise.
 *
 * @str: The string to search for environment variables.
 *
 * Return: A pointer to the start of the variable name if found, or NULL.
 */

static char *_find_env_variable(const char *str)
{
	char *dollar_sign, *var_start, *var_end;

	dollar_sign = _strchr(str, '$');
	if (dollar_sign == NULL)
	{
		return (NULL);
	}

	var_start = dollar_sign + 1;
	var_end = var_start;

	while (*var_end != '\0' && *var_end != ' ' && *var_end != '$')
	{
		var_end++;
	}

	if (var_start != var_end)
	{
		return (var_start);
	}
	return (NULL);
}

/**
 * _expand_single_env_variable - Replace a single environment variable
 * with its value in a string.
 *
 * This function takes a pointer to the start of a variable name in a string
 * and replaces it with its corresponding value from the system environment.
 * It modifies the string in-place.
 *
 * @var_name_start: A pointer to the start of the variable
 * name in the string.
 *
 * Return: 1 if a replacement was made, 0 otherwise.
 */

static int _expand_single_env_variable(char *var_name_start)
{
	size_t var_len;
	char *var_end = var_name_start, *var_name, *val;

	while (*var_end != '\0' && *var_end != ' ' && *var_end != '$')
	{
		var_end++;
	}

	var_len = var_end - var_name_start;
	var_name = (char *)malloc(var_len + 1);

	if (var_name == NULL)
	{
		/* Handle memory allocation failure */
		exit(EXIT_FAILURE);
	}

	_strncpy(var_name, var_name_start, var_len);
	var_name[var_len] = '\0';

	val = _getenv(var_name);

	if (val != NULL)
	{
		_strcpy(var_name_start, val);
		_strcat(var_name_start, var_end);
		free(var_name);
		return (1); /* Variable replaced */
	}

	free(var_name);
	return (0); /* Variable not replaced */
}

