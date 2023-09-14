#include "lance.h"
#include "helpers.h"

/**
 * _handle_setenv - Set or modify an environment variable.
 *
 * This function takes two arguments:
 * the variable name and its value.
 * It uses the `setenv` function to set or
 * modify the environment variable.
 * If successful, it updates the environment,
 * and if there's an error, it prints
 * an error message to stderr.
 *
 * Command syntax: setenv VARIABLE VALUE
 *
 * @prompt_args: An array of command arguments.
 */

void _handle_setenv(char **prompt_args)
{
    if (prompt_args[1] != NULL && prompt_args[2] != NULL)
    {
        if (setenv(prompt_args[1], prompt_args[2], 1) != 0)
        {
            /* fprintf(stderr, "setenv: Unable to set environment variable\n"); */
        }
    }
    else
    {
        /* fprintf(stderr, "setenv: Invalid syntax. Usage: setenv VARIABLE VALUE\n"); */
    }
}
