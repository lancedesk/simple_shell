#include "lance.h"

/**
 * _input_processor - Read and process user input.
 *
 * @prompt: A pointer to the character array
 * where user input is stored.
 * @size: The maximum number of characters
 * (including the null terminator)
 * that 'prompt' can hold.
 *
 * @file: A pointer to a FILE structure.
 * If not NULL, input will be read
 * from this file instead of stdin.
 * @fd: A file descriptor. If `file` is NULL
 * and `fd` is not -1,
 * input will be read from this file descriptor.
 */

void _input_processor(char *prompt, size_t size, FILE *file, int fd)
{
  ssize_t read_bytes;

  if (file == NULL && fd != -1)
  {
    /* File descriptor mode: Read from the provided */
    /* file descriptor */
    read_bytes = read(fd, prompt, size);
  }
  else if (file != NULL)
  {
    /* File mode: Read from the provided FILE structure */
    read_bytes = getline(&prompt, &size, file);
  }
  else
  {
    /* Interactive mode: Read from stdin */
    _printer("Lance-Shell$ ");
    read_bytes = _getline(&prompt, &size);
  }

  if (read_bytes == -1)
  {
    if (feof(file) || (fd != -1 && read_bytes == 0))
    {
      /* End of file reached, exit if in file mode */
      if (file != stdin)
      {
        if (file != NULL)
        {
          fclose(file);
        }
          exit(EXIT_SUCCESS);
      }
    }
    else
    {
      perror("Error reading user input...\n");
    }
  }

  /* Remove newline character if present */
  if (prompt[read_bytes - 1] == '\n')
  {
    prompt[read_bytes - 1] = '\0';
  }
}