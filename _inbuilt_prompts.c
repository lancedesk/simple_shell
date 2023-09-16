#include "lance.h"
#include "helpers.h"

void _call_builtin_handler(int index, char **prompt_args);

/**
 * _inbuilt_prompts - Process and execute
 * built-in shell commands.
 *
 * This function checks the first argument
 * in the array of command arguments
 * and, if it matches a built-in shell
 * command (such as exit, env, cd, path, or pwd),
 * it calls the corresponding handler function
 * to perform the requested action.
 *
 * @prompt_args: An array of command arguments.
 */

void _inbuilt_prompts(char **prompt_args)
{
	/* List of built-in prompts */
	const char *builtin_prompts[] = {
		"exit",
		"env",
		"cd",
		"path",
		"pwd",
		"setenv",
		"unsetenv",
		"alias",
		"ls",
		"clear",
		NULL /* NULL-terminated array */
	};

	int i;

	for (i = 0; builtin_prompts[i] != NULL; i++)
	{
		if (_strcmp(prompt_args[0], builtin_prompts[i]) == 0)
		{
			_call_builtin_handler(i, prompt_args);
			return; /* Exit the loop once a match is found */
		}
	}
}

/**
 * _call_builtin_handler - Call the corresponding handler
 * function for a built-in command.
 *
 * This function takes an index and an array of command
 * arguments. It uses the index to determine the built-in
 * command and calls the corresponding handler function
 * to perform the requested action.
 *
 * @index: The index of the built-in command.
 * @prompt_args: An array of command arguments.
 */

void _call_builtin_handler(int index, char **prompt_args)
{
	switch (index) /* Match found, call corresponding handler function */
	{
		case 0:
			_handle_exit(prompt_args);
			break;
		case 1:
			_handle_env(prompt_args);
			break;
		case 2:
			_handle_cd(prompt_args);
			break;
		case 3:
			_handle_path(prompt_args);
			break;
		case 4:
			_handle_pwd(prompt_args);
			break;
		case 5:
			_handle_setenv(prompt_args);
			break;
		case 6:
			_handle_unsetenv(prompt_args);
			break;
		case 7:
			_handle_alias(prompt_args);
			break;
		case 8:
			_handle_ls(prompt_args);
			break;
		case 9:
			_handle_clear(prompt_args);
			break;
	}
}

