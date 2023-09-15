#include "lance.h"
#include "helpers.h"

/**
 * _is_builtin_prompt - Check if a prompt
 * is a built-in prompt.
 *
 * This function checks if the given prompt
 * matches any of the
 * built-in prompts.
 *
 * @prompt: The prompt to check.
 * Return: 1 if the prompt is built-in, 0 otherwise.
 */

int _is_builtin_prompt(const char *prompt)
{
	int i;

	/* List of built-in prompts */
	const char *builtin_prompts[] = {
		"clear",
		"ls",
		"exit",
		"env",
		"cd",
		"PATH",
		"pwd",
		"alias",
		"setenv",
		"unsetenv",
		NULL /* NULL-terminated array */
	};

	for (i = 0; builtin_prompts[i] != NULL; i++)
	{
		if (_strcmp(prompt, builtin_prompts[i]) == 0)
		{
			/* Prompt is a built-in prompt */
			return (1);
		}
	}

	/* Prompt is not a built-in prompt */
	return (0);
}
