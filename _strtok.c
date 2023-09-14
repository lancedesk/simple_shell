#include "lance.h"

/**
 * _strtok - Tokenizes a string into substrings.
 *
 * @str: The string to tokenize. If NULL,
 * continues tokenization from the last call's position.
 * @delim: A string containing delimiter characters.
 *
 * Return: A pointer to the next token found
 * in the input string, or NULL if no more tokens
 * are available.
 */

char *_strtok(char *str, const char *delim)
{
	/* Stores the state between calls */
	static char *saved_str;
	char *token_start, *token_end;

	if (str != NULL)
	{
		saved_str = str;
	}
	else if (saved_str == NULL)
	{
		return (NULL); /* No string to tokenize */
	}
	token_start = saved_str;
	token_end = saved_str;

	/* Find the start of the next token */
	while (*token_start && strchr(delim, *token_start))
	{
		token_start++;
	}
	if (*token_start == '\0')
	{
		saved_str = NULL; /* No more tokens */
		return (NULL);
	}
	token_end = token_start; /* Find the end of the token */
	while (*token_end && !strchr(delim, *token_end))
	{
		token_end++;
	}
	if (*token_end != '\0')
	{
		*token_end = '\0'; /* Null-terminate the token */
		saved_str = token_end + 1; /* Update saved_str for the next call */
	}
	else
	{
		saved_str = NULL; /* No more tokens after this */
	}
	return (token_start);
}
