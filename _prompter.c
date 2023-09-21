#include "lance.h"
#include "helpers.h"

/**
 * _prompter - Print a shell prompt message.
 *
 * This function displays a shell prompt message
 * "lance_shell$ ", along with the current working directory
 * (with "Lance-Shell/" prefix), to the standard
 * output (stdout).
 * It is used to indicate that the shell
 * is ready to accept user input.
 */

void _prompter(void)
{
	_printer("Lance-Shell$ ");
}
