#include "lance.h"

int wait_for_child(pid_t pid, int is_interactive);
int execute_child_command(char *command, char **args, char *program_name);
void handle_execution_error(char *command, char *program_name);

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 * @args: An array of command arguments, including the command itself.
 * @is_interactive: Flag indicating if the shell is in interactive mode.
 * @program_name: The name of the program (usually argv[0]).
 *
 * This function forks a child process to execute the specified command. It
 * handles both absolute and relative paths to commands. If the command is not
 * found or execution fails, it prints an error message to stderr.
 *
 * Return: If successful, the exit status of the child process; otherwise, an
 *         error code.
 */

int execute_command(char *command,
		char **args, int is_interactive, char *program_name
		)
{
	pid_t pid = fork();
	int result, status;

	if (command == NULL)
	{
		return (1);
	}

	if (pid == 0)
	{
		/* Child process. */
		result = execute_child_command(command, args, program_name);
		free(args);
		exit(result);
	}
	else
	{
		/* Parent process. */
		status = wait_for_child(pid, is_interactive);
		return (status);
	}
}

/**
 * wait_for_child - Wait for the child process to complete.
 * @pid: The process ID of the child process.
 * @is_interactive: Flag indicating if the shell is in interactive mode.
 *
 * This function waits for the child process to complete, and if in
 * interactive mode, it returns the exit status of the child process.
 *
 * Return: If in interactive mode, the exit status of the child process;
 *         otherwise, 0.
 */
int wait_for_child(pid_t pid, int is_interactive)
{
	int status;

	waitpid(pid, &status, WUNTRACED);

	if (is_interactive)
	{
		return (status);
	}

	return (0);
}

/**
 * execute_child_command - Execute the command in the child process.
 * @command: The command to execute.
 * @args: An array of command arguments, including the command itself.
 * @program_name: The name of the program (usually argv[0]).
 *
 * This function handles the execution of the command in the child process.
 * It first determines whether the command is an absolute path or not and
 * executes it accordingly. It also prints error messages if execution fails.
 *
 * Return: If successful, the exit status of the child process; otherwise, an
 *         error code.
 */
int execute_child_command(char *command, char **args, char *program_name)
{
	char *full_path = NULL;

	if (command[0] == '/')
	{
		execve(command, args, NULL);
		handle_execution_error(command, program_name);
	}

	full_path = find_directory(command);

	if (full_path == NULL)
	{
		handle_execution_error(command, program_name);
	}

	execve(full_path, args, NULL);
	handle_execution_error(command, program_name);

	/* This return statement is added to prevent a compilation error. */
	return (1);
}

/**
 * handle_execution_error - Handle execution error
 * and print an error message.
 * @command: The command that failed to execute.
 * @program_name: The name of the program (usually argv[0]).
 *
 * This function prints an error message to stderr
 * when a command fails to execute.
 */

void handle_execution_error(char *command, char *program_name)
{
	fprintf(stderr, "%s: %d: %s: %s\n", program_name, errno,
			command, strerror(errno)
	       );
	exit(1);
}
