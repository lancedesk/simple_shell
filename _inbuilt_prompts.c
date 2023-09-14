#include "lance.h"
#include "helpers.h"

/**
 * _inbuilt_prompts - Process and execut
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
	/* Handle some of the in-build prompts */
	_handle_exit(prompt_args);
	_handle_env(prompt_args);
	_handle_cd(prompt_args);
	_handle_path(prompt_args);
	_handle_pwd(prompt_args);
	_handle_setenv(prompt_args);
	_handle_unsetenv(prompt_args);
	_handle_alias(prompt_args);
}
