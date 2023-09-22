#include "lance.h"

/**
 * find_directory - Search for a directory in PATH.
 * @command: The command to search for.
 *
 * This function searches for the given command
 * in the directories listed in the
 * PATH environment variable. If found,
 * it returns the full path to the command.
 * If not found, it returns NULL.
 *
 * Return: If found, a dynamically allocated string
 * containing the full path to the command; otherwise, NULL.
*/

char *find_directory(char *command)
{
  char *path = getenv("PATH");
  char *directory = NULL;
  char *full_path = NULL;

  if (command == NULL)
  {
	return (NULL);
  }

  while ((directory = strtok(path, ":")) != NULL)
  {
	/*  +2 for '/' and '\0' */
	full_path = (char *)malloc(strlen(directory) + strlen(command) + 2); 
	if (full_path == NULL)
	{
	  perror("malloc");
	  exit(1);
	}

	sprintf(full_path, "%s/%s", directory, command);

	if (access(full_path, F_OK) == 0)
	{
	  return (full_path);
	}

	free(full_path); /*  Free the memory if file is not found. */
	full_path = NULL;
	path = NULL;
  }

  return (NULL);
}