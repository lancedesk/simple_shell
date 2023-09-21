#include "lance.h"
#include "helpers.h"

/**
 * _handle_logical_and - Execute prompts
 * separated by the logical AND (&&) operator.
 *
 * This function processes an array of prompt
 * arguments and executes them one by one,
 * separated by the logical AND operator (&&).
 * All prompts must succeed (return with
 * a status of 0) for the execution to be
 * considered successful. If any prompt fails,
 * the execution stops, and the function returns failure.
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_logical_and(char **prompt_args)
{
	int i = 0;
	/* Size of the array */
	char *single_prompt[2];

	while (prompt_args[i] != NULL)
	{
		single_prompt[0] = prompt_args[i];
		/* Null-terminate the array */
		single_prompt[1] = NULL;
		/* Pass a single-prompt array */
		_execute_single_prompt(single_prompt);
		i++;
	}
}
