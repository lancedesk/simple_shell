#include "lance.h"
#include "helpers.h"

/**
 * _handle_logical_or - Execute prompts
 * separated by the logical OR (||) operator.
 *
 * This function processes an array of prompt
 * arguments and executes them one by one,
 * separated by the logical OR operator (||).
 * If any prompt succeeds (returns with
 * a status of 0), the execution stops and
 * the function returns success. If all prompts
 * fail, it returns failure.
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_logical_or(char **prompt_args)
{
	pid_t child_process_id;
	int i = 0, status;
	/* Flag to track if any prompt succeeded */
	int success = 0;
	/* Temporary array for a single prompt */
	char *single_prompt[2];

	while (prompt_args[i] != NULL)
	{
		single_prompt[0] = prompt_args[i];
		/* Null-terminate the array */
		single_prompt[1] = NULL;

		child_process_id = fork();

		if (child_process_id == -1)
		{
			_printer("Forking error\n");
			exit(EXIT_FAILURE);
		}
		else if (child_process_id == 0)
		{
			_execute_single_prompt(single_prompt);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
			{
				/* Prompt succeeded, set the success flag */
				success = 1;
			}
		}
		i++;
	}

	/* If none of the prompts succeeded, exit with failure */
	if (!success)
	{
		exit(EXIT_FAILURE);
	}
}
