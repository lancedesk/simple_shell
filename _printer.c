#include "lance.h"

/**
 * _printer - Write a prompt message to standard output.
 *
 * @prompt: A pointer to the null-terminated string
 * containing the prompt message.
 *
 * Return: Upon success, the number of characters written
 * otherwise, -1 is returned,
 * and errno is set to indicate the error.
 *
 */

int _printer(const char *prompt)
{
	return (write(STDOUT_FILENO, prompt, strlen(prompt)));
}
