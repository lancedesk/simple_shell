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
	int i, inside_quotes;
	char *arg;

	for (i = 1; prompt_args[i] != NULL; i++)
	{
		if (i > 1)
		{
			_putchar(' '); /* Print a space between arguments */
		}
		/* Print the argument without enclosing double quotes */
		arg = prompt_args[i];
		inside_quotes = 0;

		while (*arg)
		{
			if (*arg == '"')
			{
				inside_quotes = !inside_quotes;
			}
			else if (*arg == '\\' && inside_quotes)
			{
				arg++;  /* Skip the escape character '\' */
				if (*arg == 'n')
				{
					_putchar('\n');  /* Interpret '\n' as newline */
				}
				else
				{
					_putchar(*arg);
				}
			}
			else
			{
				_putchar(*arg);
			}
			arg++;
		}
	}
	_putchar('\n'); /* Print a newline character at the end */
}
