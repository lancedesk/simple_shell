#include "lance.h"
#include "helpers.h"

/**
 * free_input_buffer - Frees memory allocated
 * for user input buffer.
 *
 * @buffer: A pointer to the user input buffer to be freed.
*/

void free_input_buffer(char *buffer)
{
  free(buffer);
}