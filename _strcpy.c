#include "lance.h"

/**
 * _strcpy - Copy one string to another.
 *
 * @dest: The destination string.
 * @src: The source string to be copied.
 *
 * Return: A pointer to the destination string (dest).
*/

char *_strcpy(char *dest, const char *src)
{
  char *original_dest;
  
  /* Store the original destination pointer */
  original_dest = dest;

  /* Copy characters from source to destination */
  /* until null terminator is encountered */
  while ((*dest++ = *src++) != '\0')
  {
    /* Continue copying */
  }

  /* Return a pointer to the beginning */
  /* of the destination string */
  return (original_dest);
}
