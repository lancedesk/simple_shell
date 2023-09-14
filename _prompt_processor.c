#include "lance.h"
#include "helpers.h"

/**
 * _prompt_processor - Processes and executes
 * a prompt string in a child process.
 *
 * @prompt: The prompt string to be executed.
 */

void _prompt_processor(const char *prompt)
{
	int arg_count, i = 0, j;
	char **prompt_args;

	arg_count = count_tokens(prompt);
	prompt_args = copy_tokens(prompt, arg_count);

	/* Handle comments */
	if (_handle_comments(prompt_args))
	{
		/* This is a comment line, exit early */
		return;
	}

	/* Expand environment variables in the command */
	for (j = 0; prompt_args[j] != NULL; j++)
	{
		_expand_env_variables(prompt_args[j]);
	}

	/* Handle variable replacement for $? and $$ */
	_handle_dollar(prompt_args);

	/* Check if it's a built-in command */
	if (_is_builtin_prompt(prompt_args[0]))
	{
		_inbuilt_prompts(prompt_args);
	}
	else
	{
		/* Search for && and || operators */
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

		/* If no operators found and it's not */
		/* a built-in command, execute the command as usual */
		if (prompt_args[i] == NULL)
		{
			_execute_single_prompt(prompt_args);
		}
	}

	/* Free memory allocated for prompt_args */
	free(prompt_args);
}
