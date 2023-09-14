#include "lance.h"
#include "helpers.h"

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

void _mode_interactive()
{
	char *prompt = NULL;
	size_t size = 0, max_size = 0;

	while (1)
	{
		_prompter();
		prompt = read_input(&size, &max_size);
		_prompt_processor(prompt);
		free(prompt);
	}
}
