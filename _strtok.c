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

char* _strtok(char* str, const char* delim)
{
	/* Stores the state between calls */
	static char* saved_str = NULL;
	char *token_start, *token_end; 

	if (str != NULL) {
		saved_str = str;
	}
	else if (saved_str == NULL)
	{
		/* No string to tokenize */
		return (NULL);
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
		/* No more tokens */
		saved_str = NULL;
		return (NULL);
	}

	/* Find the end of the token */
	token_end = token_start;
	while (*token_end && !strchr(delim, *token_end))
	{
		token_end++;
	}

	if (*token_end != '\0')
	{
		/* Null-terminate the token */
		*token_end = '\0';
		/* Update saved_str for the next call */
		saved_str = token_end + 1;
	}
	else
	{
		/* No more tokens after this */
		saved_str = NULL;
	}

	return (token_start);
}
