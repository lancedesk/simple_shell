#include "lance.h"
#include "helpers.h"


/* An array to store alias mappings */
Alias aliases[MAX_ALIASES];

/**
 * _initialize_aliases - Initialize the aliases array.
 *
 * This function initializes the array of aliases,
 * setting all elements to NULL
 * to prepare it for storing alias mappings.
 */

void _initialize_aliases()
{
	int i;

	for (i = 0; i < MAX_ALIASES; i++)
	{
		aliases[i].name = NULL;
		aliases[i].value = NULL;
	}
}

/**
 * _handle_alias - Handle the alias builtin prompt.
 *
 * This function parses the arguments for the alias
 * prompt and performs the specified actions
 * (e.g., defining or listing aliases).
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_alias(char **prompt_args)
{
	int i;
	char *name, *value;

	if (prompt_args[1] == NULL)
	{
		/* No args provided, print a list of all aliases */
		for (i = 0; i < MAX_ALIASES; i++)
		{
			if (aliases[i].name != NULL)
			{
				printf("%s %s\n", aliases[i].name, aliases[i].value);
			}
		}
	}
	else if (prompt_args[2] == NULL || strcmp(prompt_args[2], "=") == 0)
	{
		/* One argument provided or an equal sign (=) */
		/* as the second argument, */
		/* treat it as an alias name without a value */
		name = prompt_args[1];

		for (i = 0; i < MAX_ALIASES; i++)
		{
			if (aliases[i].name != NULL && _strcmp(aliases[i].name, name) == 0)
			{
				/* Print the alias without single quotes */
				value = aliases[i].value;
				printf("%s %s\n", aliases[i].name, value);
				return;
			}
		}
		/* Alias not found */
		fprintf(stderr, "Alias '%s' not found.\n", name);
	}
	else
	{
		/* Two or more arguments provided, */
		/* define or redefine an alias */
		name = prompt_args[1];
		value = prompt_args[2];

		/* Check if an alias with the same */
		/* name already exists */
		for (i = 0; i < MAX_ALIASES; i++)
		{
			if (aliases[i].name != NULL && _strcmp(aliases[i].name, name) == 0)
			{
				/* Alias with the same name found, */
				/* update its value */
				/* Free the previous value */
				free(aliases[i].value);
				/* Free the previous name */
				free(aliases[i].name);
				aliases[i].value = _strdup(value);
				/* Assign the new name */
				aliases[i].name = _strdup(name);
				return;
			}
		}


		/* Alias with the same name not found, */
		/* create a new alias */
		for (i = 0; i < MAX_ALIASES; i++)
		{
			if (aliases[i].name == NULL)
			{
				aliases[i].name = _strdup(name);
				aliases[i].value = _strdup(value);
				return;
			}
		}

		/* Maximum number of aliases reached */
		fprintf(stderr, "Maximum number of aliases reached.\n");
	}
}
