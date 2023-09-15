#ifndef HELPERS_H
#define HELPERS_H

#include <stdlib.h>
#include <stdio.h>

/* Define initial buffer size */
#define INITIAL_MAX_LENGTH 100

/* Constant for maximum number of aliases */
#define MAX_ALIASES 128

/* Declare the external environment variable */
extern char **environ;

int count_tokens(const char *str);
char **copy_tokens(const char *str, int count);
char *read_input(size_t *length, size_t *max_length);
char *allocate_input_buffer(size_t *size);
void free_input_buffer(char *buffer);
char *_strip_whitespace(const char *str);

/* In-buil prmompt handlers */
void _handle_exit(char **prompt_args);
void _handle_env(char **prompt_args);
void _handle_cd(char **prompt_args);
void _handle_path(char **prompt_args);
void _handle_pwd(char **prompt_args);
void _handle_setenv(char **prompt_args);
void _handle_unsetenv(char **prompt_args);
void _handle_ls(char **prompt_args);
void _handle_clear(char **prompt_args);

/* Main in-built prompt handler */
void _inbuilt_prompts(char **prompt_args);
int _is_builtin_prompt(const char *prompt);
void _handle_prompt_separator(char **prompt_args);

/* Handle logical && and || operators */
void _handle_logical_and(char **prompt_args);
void _handle_logical_or(char **prompt_args);

void _execute_single_prompt(char **prompt_args);
char *_path_basename(char *path);
void _expand_env_variables(char *prompt);

/**
 * struct alias - Structure to store alias mappings.
 *
 * This structure represents an alias mapping,
 * where 'name' is a pointer to the alias name, and 'value'
 * is a pointer to the alias value or replacement text.
 *
 * @name: Pointer to the alias name
 * @value: Pointer to the alias value
 */

typedef struct alias
{
	char *name;
	char *value;
} Alias;

extern Alias aliases[MAX_ALIASES];

void _initialize_aliases(void);
void _handle_alias(char **prompt_args);
int _handle_comments(char **prompt_args);

void _handle_dollar(char **prompt_args, int status);

#endif
