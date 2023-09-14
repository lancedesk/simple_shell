#include "lance.h"
#include "helpers.h"

/**
 * allocate_input_buffer - Allocates memory
 * for user input buffer.
 *
 * @size:   A pointer to a size_t variable
 * representing the size of the buffer.
 * Return:  A dynamically allocated character
 * buffer for user input.
*/

char *allocate_input_buffer(size_t *size)
{
  char *buffer;
  
  /* Set the initial size */
  *size = INITIAL_MAX_LENGTH;
  buffer = (char *)malloc(*size * sizeof(char));

  if (buffer == NULL)
  {
    _printer("Memory allocation error\n");
    exit(EXIT_FAILURE);
  }
    
  return (buffer);
}