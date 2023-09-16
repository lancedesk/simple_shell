#include "lance.h"
#include "helpers.h"

/**
 * _handle_echo - Handle the custom 'echo' prompt.
 *
 * This function prints the arguments provided
 * as part of the 'echo' prompt.
 * It iterates through the arguments starting
 * from the second one (the first argument is 'echo')
 * and prints each argument. Multiple arguments are
 * separated by spaces, and a newline character
 * is printed at the end.
 *
 * @prompt_args: An array of prompt arguments,
 * where the first argument is 'echo'.
 */

void _handle_echo(char **prompt_args)
{
	int i;

	for (i = 1; prompt_args[i] != NULL; i++)
	{
		if (i > 1)
		{
			/* Print a space between arguments */
			_putchar(' ');
		}
		/* Print the argument */
		while (*prompt_args[i])
		{
			_putchar(*prompt_args[i]);
			prompt_args[i]++;
		}
	}
	/* Print a newline character at the end */
	_putchar('\n');
}
