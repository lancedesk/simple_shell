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
	char cwd[1024];
	char *home_dir, *dir_name, *shell_path, *current_wd;
	size_t shell_path_len;

	current_wd = getcwd(cwd, sizeof(cwd));

	if (current_wd != NULL)
	{
		home_dir = getenv("HOME");
		dir_name = _path_basename(cwd);

		/* Construct the full shell path as"home_dir/dir_name"*/
		/* +1 for '/', +1 for null terminator */
		shell_path_len = _strlen(home_dir) + _strlen(dir_name) + 2;
		shell_path = (char *)malloc(shell_path_len);

		if (shell_path != NULL)
		{
			snprintf(shell_path, shell_path_len, "%s/%s", home_dir, dir_name);

			if (_strcmp(cwd, shell_path) == 0)
			{
				_printer("Lance-Shell$ ");
			}
			else
			{
				printf("Lance-Shell/%s$ ", dir_name);
			}
			/* Free the allocated memory */
			free(shell_path);
		}
		else
		{
			perror("malloc");
			/* Fallback to a basic prompt */
			_printer("Lance-Shell$ ");
		}
	}
	else
	{
		perror("getcwd");
		_printer("Lance-Shell$ ");
	}
}
