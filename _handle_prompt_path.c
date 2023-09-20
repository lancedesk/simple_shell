#include "lance.h"
#include "helpers.h"

int _search_in_path(const char *prompt, char **prompt_path, const char *token);
int _execute_prompt(char *prompt_path, char **prompt_args);

/**
 * _handle_prompt_path - Search for executable prompts in PATH.
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_prompt_path(char **prompt_args)
{
	char *path, *prompt_command, *token, *prompt_path;

	prompt_command = prompt_args[0];
	if (access(prompt_command, X_OK) == 0)
	{
		if (_execute_prompt(prompt_command, prompt_args))
		{
			return;
		}
	}

	path = getenv("PATH");

	if (path == NULL)
	{
		perror("PATH environment variable is not set.\n");
		return;
	}

	token = _strtok(path, ":");
	while (token != NULL)
	{
		prompt_path = NULL;

		if (_search_in_path(prompt_command, &prompt_path, token))
		{
			if (_execute_prompt(prompt_path, prompt_args))
			{
				free(prompt_path);
				return;
			}
			free(prompt_path);
		}

		token = _strtok(NULL, ":");
	}

	perror("Prompt not found\n");
}

/**
 * _search_in_path - Search for an executable prompt in PATH.
 *
 * @prompt: The prompt to search for.
 * @prompt_path: A pointer to store the full path of the prompt.
 * @token: The current token from the PATH.
 *
 * Return: 1 if the prompt is found, 0 otherwise.
 */

int _search_in_path(const char *prompt, char **prompt_path, const char *token)
{
	if (access(prompt, X_OK) == 0)
	{
		*prompt_path = strdup(prompt);
		if (*prompt_path == NULL)
		{
			perror("strdup error");
			return (0);
		}
		return (1);
	}

	*prompt_path = _construct_full_path(token, prompt);

	if (*prompt_path == NULL)
	{
		perror("malloc error");
		return (0);
	}

	if (access(*prompt_path, X_OK) == 0)
	{
		return (1);
	}

	free(*prompt_path);
	return (0);
}

/**
 * _execute_prompt - Execute a prompt in a child process.
 *
 * @prompt_path: The full path of the prompt.
 * @prompt_args: An array of prompt arguments.
 *
 * Return: 1 if the prompt is executed successfully, 0 otherwise.
 */

int _execute_prompt(char *prompt_path, char **prompt_args)
{
	pid_t pid = fork();
	int status;

	if (pid < 0)
	{
		perror("fork error");
		free(prompt_path);
		return (0);
	}
	else if (pid == 0)
	{
		/* Child process */
		if (execve(prompt_path, prompt_args, environ) == -1)
		{
			/* If execve returns, there was an error */
			perror("execve error\n");
			free(prompt_path);
			exit(1);
		}
	}
	else
	{
		/* Parent process */
		wait(&status);
		if (WIFEXITED(status))
		{
			/* prompt executed successfully */
			free(prompt_path);
			return (1);
		}
		else
		{
			perror("Error executing prompt \n");
			free(prompt_path);
			return (0);
		}
	}
	return (0); /* Execution failed */
}

