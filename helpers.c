#include "lance.h"
#include "helpers.h"

/**
 * count_tokens - Counts the number of tokens in a string.
 *
 * @str: The input string containing tokens.
 * Return : The count of tokens in the string.
*/

int count_tokens(const char *str)
{
  char *token, *copy;
  int count = 0;
  
  copy = _strdup(str);
  if (copy == NULL)
  {
    _printer("Memory allocation error\n");
    exit(EXIT_FAILURE);
  }

  token = _strtok(copy, " \t\n\r");

  while (token)
  {
    count++;
    token = _strtok(NULL, " ");
  }

  /* Free the copy of the original string */
  free(copy);
  return (count);
}

/**
 * copy_tokens - Copies tokens from a string into an array.
 *
 * @str : The input string containing tokens.
 * @count: The number of tokens in the string.
 * Return: An array of strings containing
 * the copied tokens, terminated by NULL.
*/

char **copy_tokens(const char *str, int count)
{
    char *copy, *token;
    int i;
    char **tokens;
  
    tokens = malloc((count + 1) * sizeof(char *));
    if (tokens == NULL)
    {
        _printer("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    copy = _strdup(str);

    if (copy == NULL)
    {
        _printer("Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = _strtok(copy, " \t\n\r");
    i = 0;

    while (token)
    {
        tokens[i] = _strdup(token);
        if (tokens[i] == NULL)
        {
            _printer("Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        i++;
        token = _strtok(NULL, " \t\n\r");
    }

    /* Null-terminate the tokens array */
    tokens[i] = NULL;

    /* Free the copy of the original string */
    free(copy);
    return (tokens);
}