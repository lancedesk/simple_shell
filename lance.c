#include "lance.h"
#include "helpers.h"

/**
 * main - Entry point of the lance_shell program.
 *
 * @argc: The number of command-line arguments.
 * @argv: An array of strings representing
 * the command-line arguments.
 *
 * Return: The main function returns 0
 * to indicate successful execution of the
 * lance_shell program.
 */

int main(int argc, char *argv[])
{
  (void)argc;
  (void)argv;
	/* Initialize aliases */
	_initialize_aliases();

	/* Interactive mode: Read from stdin */
	_mode_interactive();

	return (0);
}
