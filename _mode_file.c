#include "lance.h"
#include "helpers.h"

/**
 * _mode_file - Run the program in file mode.
 *
 * This function runs the program in file mode,
 * reading input from a specified file.
 * It takes the filename as a parameter and opens
 * the file for reading.
 *
 * @filename: The name of the file to read input from.
 */

void _mode_file(const char *filename)
{
	char *prompt = NULL;
	size_t size = 0;
	ssize_t read_bytes;
	int file_fd;

	/* Open file for reading */
	file_fd = open(filename, O_RDONLY);

	if (file_fd == -1)
	{
		perror("File opening failed");
		exit(EXIT_FAILURE);
	}

	while (1)
	{
		/* File mode: Read from the provided file descriptor */
		_input_processor(prompt, size, NULL, file_fd);
		_prompt_processor(prompt);

		read_bytes = getline(&prompt, &size, NULL);

		if (read_bytes == -1)
		{
			/* End of file reached, exit if in file mode */
			if (file_fd != STDIN_FILENO)
			{
				close(file_fd);
				exit(EXIT_SUCCESS);
			}
		}
		/* Remove newline character if present */
		if (prompt[read_bytes - 1] == '\n')
		{
			prompt[read_bytes - 1] = '\0';
		}
	}
}
