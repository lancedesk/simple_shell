#include "lance.h"
#include "helpers.h"

void _handle_eof_condition(void);

/**
 * _mode_interactive - Run the program in interactive mode.
 *
 * This function runs the program in interactive mode,
 * which means it interacts with the user through
 * the command prompt.
 * It continuously displays the prompt, reads user input,
 * processes it using the input processor and prompt
 * processor, and repeats this process until the
 * program is terminated.
 */

void _mode_interactive(void)
{
	char *prompt = NULL;

	/*  Check if stdin is associated with a terminal */
	bool is_terminal = isatty(STDIN_FILENO);

	while (1)
	{
		if (is_terminal)
		{
			/* Only call _prompter() if input is from a terminal */
			_prompter();
		}

		prompt = read_input();

		/* Check for EOF (Ctrl+D) condition */
		if (prompt == NULL || _strlen(prompt) == 0)
		{
			/* Handle EOF condition */
			_handle_eof_condition();
			return;
		}

		_prompt_processor(prompt);
		free(prompt);
	}
}


/**
 * _handle_eof_condition - Handles the end-of-file (EOF) condition.
 *
 * This function checks if the input stream is at the end of the file
 * (EOF) and takes appropriate action based on the input source.
 *
 * If not NULL, the function checks if the input is coming from
 * this file. If NULL, it checks if the input is coming from stdin.
 */

void _handle_eof_condition(void)
{
	_putchar('\n'); /* Handle end of file (Ctrl+D) */
	return; /* No need to process further if EOF is detected */
}
