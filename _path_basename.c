#include "lance.h"

/**
 * _path_basename - Custom implementation of basename.
 * This function returns the last part
 * (directory name) of a path.
 *
 * @path: The path from which to extract the directory name.
 * Return: A pointer to the last part of the path.
*/

char *_path_basename(char *path)
{
  char *basename, *ptr;
  
  basename = path;
  ptr = path;

  while (*ptr != '\0')
  {
    if (*ptr == '/')
    {
      /* Move basename to the character after '/' */
      basename = ptr + 1; 
    }
      ptr++;
  }

  return (basename);
}
