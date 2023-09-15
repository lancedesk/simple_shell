#include "lance.h"
#include "helpers.h"

/**
 * _handle_clear - Clear the terminal screen.
 *
 * This function sends ANSI escape codes
 * to clear the terminal screen.
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_clear(char **prompt_args)
{
	if (_strcmp(prompt_args[0], "clear") == 0)
	{
		/* ANSI escape sequence to clear the screen */
		_printer("\033[H\033[J");
	}
}

