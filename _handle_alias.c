#include "lance.h"
#include "helpers.h"

void _print_all_aliases(void);
Alias *_find_alias_by_name(const char *name);
void _initialize_aliases(void);

/* An array to store alias mappings */
Alias aliases[MAX_ALIASES];


/**
 * _handle_alias - Handle the alias builtin prompt.
 *
 * @prompt_args: An array of prompt arguments.
 */

void _handle_alias(char **prompt_args)
{
	char *name, *value;
	Alias *alias;
	int i;

	if (prompt_args[1] == NULL)
	{
		/* No args provided, print a list of all aliases */
		_print_all_aliases();
	}
	else if (prompt_args[2] == NULL || _strcmp(prompt_args[2], "=") == 0)
	{
		/* One argument provided or an equal sign (=) */
		/* as the second argument, */
		/* treat it as an alias name without a value */
		name = prompt_args[1];
		alias = _find_alias_by_name(name);

		if (alias != NULL)
		{
			/* Print the alias without single quotes */
			printf("%s %s\n", alias->name, alias->value);
		}
		else
		{
			/* Alias not found */
			printf("Alias '%s' not found.\n", name);
		}
	}
	else
	{
		/* Two or more arguments provided, */
		/* define or redefine an alias */
		name = prompt_args[1];
		value = prompt_args[2];

		alias = _find_alias_by_name(name);

		if (alias != NULL)
		{
			/* Alias with the same name found, */
			/* update its value */
			/* Free the previous value and name */
			free(alias->value);
			free(alias->name);
			alias->value = _strdup(value);
			/* Assign the new name */
			alias->name = _strdup(name);
		}
		else
		{
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
			perror("Maximum number of aliases reached.\n");
		}
	}
}

/**
 * _initialize_aliases - Initialize the aliases array.
 */

void _initialize_aliases(void)
{
	int i;

	for (i = 0; i < MAX_ALIASES; i++)
	{
		aliases[i].name = NULL;
		aliases[i].value = NULL;
	}
}

/**
 * _print_all_aliases - Print a list of all aliases.
 */

void _print_all_aliases(void)
{
	int i;

	for (i = 0; i < MAX_ALIASES; i++)
	{
		if (aliases[i].name != NULL)
		{
			printf("%s %s\n", aliases[i].name, aliases[i].value);
		}
	}
}

/**
 * _find_alias_by_name - Find an alias by name.
 *
 * @name: The name of the alias to find.
 * Return: A pointer to the alias if found, NULL otherwise.
 */

Alias *_find_alias_by_name(const char *name)
{
	int i;

	for (i = 0; i < MAX_ALIASES; i++)
	{
		if (aliases[i].name != NULL && _strcmp(aliases[i].name, name) == 0)
		{
			return (&aliases[i]);
		}
	}
	return (NULL);
}

