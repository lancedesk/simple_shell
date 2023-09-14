#include "lance.h"
#include "helpers.h"

/**
 * _handle_pwd - Print the current working directory.
 *
 * This function checks if the user entered "pwd"
 * as a command and prints the current working directory.
 * If there's an error in obtaining the current
 * directory, it reports the error.
 *
 * @prompt_args: An array of command arguments.
*/

void _handle_pwd(char **prompt_args)
{
  if (_strcmp(prompt_args[0], "pwd") == 0)
  {
    /* Get and print the current working directory */
    char cwd[1024];
    
    if (getcwd(cwd, sizeof(cwd)) != NULL)
    {
      printf("%s\n", cwd);
    }
    else
    {
      perror("getcwd error");
    }
  }
}