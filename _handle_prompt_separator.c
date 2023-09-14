#include "lance.h"
#include "helpers.h"

/**
 * _handle_prompt_separator - Process and execute
 * prompts separated by ';'.
 *
 * This function searches for the presence
 * of a prompt separator ';' in the provided array
 * of prompt arguments. If found,
 * it splits the command line into two parts
 * and recursively calls _prompt_processor
 * to handle each part.
 * This allows the execution of multiple prompts
 * separated by ';'.
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_prompt_separator(char **prompt_args)
{
	int i;
	char *trimmed_prompt;

	for (i = 0; prompt_args[i] != NULL; i++)
	{
		if (_strcmp(prompt_args[i], ";") == 0)
		{
			/* Replace the semicolon with a NULL terminator */
			prompt_args[i] = NULL;

			/* Strip trailing whitespace */
			prompt_args[i - 1] = _strip_whitespace(prompt_args[i - 1]);
			/* Strip leading whitespace */
			trimmed_prompt = _strip_whitespace(prompt_args[i + 1]);

			/* Update prompt_args with the trimmed prompt */
			prompt_args[i + 1] = trimmed_prompt;

			/* Recursively call _prompt_processor with the first prompt */
			_prompt_processor(prompt_args[i - 1]);

			/* Recursively call _prompt_processor with the second prompt */
			_prompt_processor(trimmed_prompt);


			/* Move the pointer to the next command after the separator */
			prompt_args = &prompt_args[i + 2];

			/* Recursively call _handle_prompt_separator with the remaining commands */
			_handle_prompt_separator(prompt_args);

			return;
		}
	}

	/* If no separator found, execute the last command */

	/* Strip trailing whitespace */
	_strip_whitespace(prompt_args[i - 1]);
	_prompt_processor(prompt_args[i - 1]);
}
