#include "lance.h"
#include <limits.h>

/**
 * change_directory - Change the current working directory
 * @newDir: The path to the new directory or "-" to go back to the previous directory
 * @status: Status of the last executed command (unused)
 * Return: None
 */
void change_directory(const char *newDir, __attribute__((unused))int status)
{
	int result = -1;
	char current_dir[PATH];

	if (newDir == NULL)
	{
		result = chdir(getenv("HOME"));
	}
	else if (strcmp(newDir, "-") == 0)
	{
		result = chdir(getenv("OLDPWD"));
	}
	else
	{
		result = chdir(newDir);
	}

	if (result == -1)
	{
		perror("my_shell");
	}
	else if (result != -1)
	{
		getcwd(current_dir, sizeof(current_dir));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", current_dir, 1);
	}
}

