#include "lance.h"

/**
 * _strlen - Calculate the length of a string.
 *
 * @str: The input string.
 * Return: The length of the string
 * (excluding the null terminator).
*/

size_t _strlen(const char *str)
{
  size_t length = 0;

  while (str[length] != '\0')
  {
    length++;
  }
  
  return (length);
}
