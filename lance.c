#include "lance.h"

/**
 * print_prompt - Print the shell prompt in interactive mode.
 * @is_interactive: check if interactive or not
 */

void print_prompt(int is_interactive)
{
	if (is_interactive)
	{
		_printer("ldshell> ");
	}
}

/**
 * read_input - Read a line of input from the user.
 * @input_size: input size;
 * Return: read input from user
 */

char *read_input(size_t *input_size)
{
	char *input = NULL;
	ssize_t result;

	result = getline(&input, input_size, stdin);

	if (result == -1 || is_input_empty(input))
	{
		if (input != NULL)
		{
			free(input); /* Free the memory allocated by getline. */
		}
		handle_ctrl_d();
	}

	input[_strlen(input) - 1] = '\0';
	return (input);
}

/**
 * split_input - Split the input into command and arguments.
 * @input: user input
 * @argc: input arguments
 * Return: tokenized array
 */

char **split_input(char *input, int argc)
{
	char *command = strtok(input, " ");
	/* +1 for NULL terminator */
	char **args = malloc(sizeof(char *) * (argc + 1));
	int i;

	if (args == NULL)
	{
		perror("Failed to allocate memory for arguments.\n");
		exit(1);
	}

	i = 0;
	while (command != NULL)
	{
		args[i] = command;
		command = strtok(NULL, " ");
		i++;
	}

	args[i] = NULL;
	return (args);
}

/**
 * main - The main entry point of the Lance Shell.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings containing the command-line arguments.
 * Return: An integer representing the exit status of the shell.
 */

int main(int argc, char **argv)
{
	char *input = NULL;
	int is_interactive, status;
	size_t input_size = 0;
	char **args = NULL;

	signal(SIGINT, SIG_IGN);
	is_interactive = isatty(fileno(stdin));
	while (1)
	{
		print_prompt(is_interactive);
		if (input != NULL)
		{
			free(input);
			input = NULL;
		}
		input = read_input(&input_size);
		if (_handle_comments(input)) /* Handle comments */
		{
			continue; /* Skip this iteration if line was a comment */
		}
		if (_strcmp(input, "exit") == 0)
		{
			free(input);
			exit_shell();
		}
		if (_strcmp(input, "env") == 0)
		{
			_handle_env(input);
		}
		else
		{
			args = split_input(input, argc);
			status = execute_command(args[0], args, is_interactive, argv[0]);
			free(args);
			(void)status;/* if (is_interactive && status != 0) {} */
		}
	}
	free(input);
	return (0);
}

