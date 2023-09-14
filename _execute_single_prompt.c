#include "lance.h"
#include "helpers.h"

/**
 * _execute_single_prompt - Execute a single shell command.
 *
 * This function takes an array of command arguments
 * and executes a single shell command in a child
 * process. It handles forking,
 * executing the command, and waiting for its completion.
 * If the command fails, it prints an error message to stderr.
 *
 * @prompt_args: An array of command arguments.
 */

#include "lance.h"
#include "helpers.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * _execute_single_prompt - Execute a single shell command.
 *
 * This function takes an array of command arguments
 * and executes a single shell command in a child
 * process. It handles forking,
 * executing the command, and waiting for its completion.
 * If the command fails, it prints an error message to stderr.
 *
 * @prompt_args: An array of command arguments.
 */

void _execute_single_prompt(char **prompt_args)
{
	int status;
	pid_t child_process_id = fork();

	if (child_process_id == -1)
	{
		perror("Forking error");
		exit(EXIT_FAILURE);
	}
	else if (child_process_id == 0)
	{
		if (execvp(prompt_args[0], prompt_args) == -1)
		{
			perror("Prompt execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(child_process_id, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			_printer("Prompt execution failed\n");
			exit(EXIT_FAILURE);
		}
	}
}
