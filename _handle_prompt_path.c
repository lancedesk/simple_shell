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
	char *path = getenv("PATH"), *token, *prompt_path;

	if (path == NULL)
	{
		fprintf(stderr, "PATH environment variable is not set.\n");
		return;
	}

	token = strtok(path, ":");
	while (token != NULL)
	{
		prompt_path = NULL;

		/* Check if the prompt_args[0] is a full path or just the executable name */
		if (_search_in_path(prompt_args[0],
					&prompt_path, token)
				|| access(prompt_args[0], X_OK) == 0
		   )
		{
			if (_execute_prompt(prompt_path ?
						prompt_path : prompt_args[0], prompt_args)
			   )
			{
				return;
			}
		}
		token = strtok(NULL, ":");
	}

	fprintf(stderr, "%s: prompt not found\n", prompt_args[0]);
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

	*prompt_path = malloc(_strlen(token) + _strlen(prompt) + 2);

	if (*prompt_path == NULL)
	{
		perror("malloc error");
		return (0);
	}
	sprintf(*prompt_path, "%s/%s", token, prompt);

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
		execv(prompt_path, prompt_args);
		/* If execv returns, there was an error */
		perror("execv error");
		free(prompt_path);
		exit(1);
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
			fprintf(stderr, "Error executing prompt: %s\n", prompt_args[0]);
			free(prompt_path);
			return (0);
		}
	}
}
