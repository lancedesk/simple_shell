#include "lance.h"
#include "helpers.h"

/**
 * _handle_exit - Checks if the user wants to exit
 * the program.
 *
 * This function examines the first element
 * of the provided array of command arguments
 * and, if it matches the "exit" command, frees
 * allocated memory and exits the program
 * with a success status.
 *
 * @prompt_args: An array of command arguments.
*/

void _handle_exit(char **prompt_args)
{
	int status_code;

	if (_strcmp(prompt_args[0], "exit") == 0)
	{
		/* If there are arguments, try to parse */
		/* the status code */

		if (prompt_args[1] != NULL)
		{
			status_code = _atoi(prompt_args[1]);

			/* Free the prompt_args array before exit */
			free(prompt_args);
			exit(status_code);
		}
		else
		{
			/* No status code provided, exit with a default status */
			/* Free the prompt_args array before exit */
			free(prompt_args);
			exit(EXIT_SUCCESS);
		}
	}
}
