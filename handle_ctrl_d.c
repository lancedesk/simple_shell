#include "lance.h"

/**
 * handle_ctrl_d - Handle the CTRL+D signal.
 *
 * This function handles the CTRL+D signal,
 * either by printing a newline character
 * or by doing nothing, depending on whether
 * input is from a pipe or
 * terminal.
 */

void handle_ctrl_d(void)
{
	if (!isatty(fileno(stdin)))
	{
		/*  Input is from a pipe, so don't print a newline character. */
	}
	else
	{
		/*  Input is not from a pipe, so print a newline character. */
		_printer("\n");
	}

	exit(0);
}
