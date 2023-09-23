#include "lance.h"

/**
 * _putchar - Write a character to the standard output.
 *
 * This function writes a single character 'c'
 * to the standard output.
 *
 * @c: The character to be written.
 *
 * Return: On success, the character written
 * as an unsigned char cast to an int.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

