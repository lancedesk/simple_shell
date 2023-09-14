#include "lance.h"
#include "helpers.h"

/**
 * _strip_whitespace - Removes leading and trailing
 * whitespace from a string.
 *
 * @str: The string to be stripped of whitespace.
 * Return: A new dynamically allocated string
 * with leading and trailing whitespace removed.
*/

char *_strip_whitespace(const char *str)
{
	size_t len, start, end, new_len;
	char *new_str;

	if (str == NULL)
		return (NULL);

	/* Find the length of the string */
	len = strlen(str);

	/* Initialize indices for the start */
	/* and end of the new string */
	start = 0, end = len - 1;

	/* Skip leading whitespace */
	while (start < len && isspace(str[start]))
		start++;

	/* Skip trailing whitespace */
	while (end > start && isspace(str[end]))
		end--;

	/* Calculate the length of the new string */
	new_len = end - start + 1;

	/* Allocate memory for the new string */
	new_str = (char *)malloc(new_len + 1);

	if (new_str == NULL)
	{
		/* Memory allocation failed */
		perror("Memory allocation failed");
		exit(EXIT_FAILURE);
	}

	/* Copy the stripped string into the new buffer */
	strncpy(new_str, &str[start], new_len);

	/* Null-terminate the new string */
	new_str[new_len] = '\0';
	return (new_str);
}
