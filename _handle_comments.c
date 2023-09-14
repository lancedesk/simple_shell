#include "lance.h"
#include "helpers.h"

/**
 * _handle_comments - Handle lines that start
 * with a comment character '#'.
 *
 * @prompt_args: An array of command arguments.
 * 
 * Return: Returns 1 if the line is a comment
 * and has been handled, 0 otherwise.
*/

int _handle_comments(char **prompt_args)
{
  /* Check if the line starts with a comment */
  /* character '#' */

  if (prompt_args[0][0] == '#')
  {
    /* This is a comment line, ignore it */
    free(prompt_args);
    /* Indicate that the line is a comment */
    return (1);
  }

  /* Indicate that the line is not a comment */
  return (0);
}
