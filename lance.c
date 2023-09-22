#include "lance.h"

/**
 * print_prompt - Print the shell prompt in interactive mode.
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

	input[strlen(input) - 1] = '\0';
	return (input);
}

/**
 * split_input - Split the input into command and arguments.
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

int main(int argc, char **argv)
{
	char *input = NULL;
	int is_interactive;
	size_t input_size = 0;
	int status;
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

		if (strcmp(input, "exit") == 0)
		{
			free(input);
			exit_shell();
		}

		args = split_input(input, argc);
		status = execute_command(args[0], args, is_interactive, argv[0]);
		free(args);

		if (is_interactive && status != 0) {
			/* perror("Command failed"); */
		}
	}
	/* Free the memory allocated for the input. */
	free(input);

	return (0);
}
