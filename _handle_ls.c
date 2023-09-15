#include "lance.h"
#include "helpers.h"

/**
 * _handle_ls - Handle the "ls" prompt.
 *
 * This function executes the "ls" prompt
 * with provided arguments.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_ls(char **prompt_args)
{
	pid_t pid;
	int status;

	/* Create a child process */
	pid = fork();

	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		/* This code runs in the child process */
		execvp("ls", prompt_args);

		/* If execvp returns, an error occurred */
		perror("ls");
		exit(EXIT_FAILURE);
	}
	else
	{
		/* This code runs in the parent process */
		wait(&status); /* Wait for child process to finish */
	}
}

