#include "lance.h"
#include "helpers.h"

/**
 * _handle_logical_operators - Execute logical AND and OR
 * operations.
 *
 * This function processes an array of prompt arguments
 * and performs logical AND and OR operations on them.
 * It calls _handle_logical_and to execute prompts
 * separated by the logical AND (&&) operator and
 * _handle_logical_or to execute prompts separated
 * by the logical OR (||) operator.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_logical_operators(char **prompt_args)
{
	int i = 0;

	while (prompt_args[i] != NULL)
	{
		if (_strcmp(prompt_args[i], "&&") == 0)
		{
			/* Handle && operator */
			_handle_logical_and(prompt_args + i + 1);
			break;
		}
		else if (_strcmp(prompt_args[i], "||") == 0)
		{
			/* Handle || operator */
			_handle_logical_or(prompt_args + i + 1);
			break;
		}
		i++;
	}
}

