#include "lance.h"

/**
 * _isspace - checks if a character is a whitespace character.
 *
 * @c: The character to be checked.
 * Return: true if 'c' is a whitespace character,
 * false otherwise.
 */

bool _isspace(int c)
{
	return (c == ' ' ||
			c == '\t' || c == '\n' || c == '\r' ||
			c == '\v' || c == '\f'
	       );
}
