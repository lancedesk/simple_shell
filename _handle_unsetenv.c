#include "lance.h"
#include "helpers.h"

/**
 * _handle_unsetenv - Unset an environment variable.
 *
 * This function takes one argument: the variable
 * name to unset.
 * It uses the `unsetenv` function to remove
 * the environment variable.
 * If successful, it updates the environment,
 * and if there's an error, it prints
 * an error message to stderr.
 *
 * Command syntax: unsetenv VARIABLE
 *
 * @prompt_args: An array of command arguments.
*/

void _handle_unsetenv(char **prompt_args)
{
    if (prompt_args[1] != NULL)
    {
        if (unsetenv(prompt_args[1]) != 0)
        {
            /* fprintf(stderr, "unsetenv: Unable to unset environment variable\n"); */
        }
    }
    else
    {
        /* fprintf(stderr, "unsetenv: Invalid syntax. Usage: unsetenv VARIABLE\n"); */
    }
}
