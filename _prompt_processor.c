#include "lance.h"
#include "helpers.h"

void _handle_built_in_prompt(char **prompt_args);
void _process_prompt(const char *prompt, int *status);

/**
 * _prompt_processor - Processes and executes
 * a prompt string in a child process.
 *
 * @prompt: The prompt string to be executed.
 */

void _prompt_processor(const char *prompt)
{
	int status = 0; /* Status initialization */

	_process_prompt(prompt, &status); /* Passing status by reference */
}

/**
 * _handle_built_in_prompt - Handle built-in commands.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_built_in_prompt(char **prompt_args)
{
	if (_is_builtin_prompt(prompt_args[0]))
	{
		_inbuilt_prompts(prompt_args);
	}
}

/**
 * _process_prompt - Process and execute a single prompt.
 *
 * @prompt: The prompt string to be executed.
 * @status: A pointer to the status variable.
 */

void _process_prompt(const char *prompt, int *status)
{
	int arg_count, j;
	char **prompt_args;

	arg_count = count_tokens(prompt);
	prompt_args = copy_tokens(prompt, arg_count);

	/* Handle comments */
	if (_handle_comments(prompt_args))
	{
		/* This is a comment line, exit early */
		free(prompt_args);
		return;
	}

	/* Expand environment variables in the command */
	for (j = 0; prompt_args[j] != NULL; j++)
	{
		_expand_env_variables(prompt_args[j]);
	}

	/* Pass status to _handle_dollar */
	_handle_dollar(prompt_args, *status); /* Passing status by value */

	/* Check if it's a built-in command */
	_handle_built_in_prompt(prompt_args);

	/* Handle logical operators */
	_handle_logical_operators(prompt_args);

	/* Execute the command as usual if no operators found */
	if (prompt_args[j] != NULL)
	{
		_execute_single_prompt(prompt_args);
	}

	/* Free memory allocated for prompt_args */
	free(prompt_args);
}

