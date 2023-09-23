#ifndef LANCE_H
#define LANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <ctype.h>
#include <stddef.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <errno.h>


int _printer(const char *prompt);
char *find_directory(char *command);
int execute_command(
		char *command, char **args, int is_interactive, char *program_name);
int _printer(const char *prompt);
void exit_shell(void);
void handle_ctrl_d(void);
bool is_input_empty(const char *str);
int _strcmp(const char *strn1, const char *strn2);
size_t _strlen(const char *str);
int _putchar(char c);
void _puts(const char *str);
void _handle_env(char *input);
/* Declare the external environment variable */
extern char **environ;

int _handle_comments(char *input);
#endif

