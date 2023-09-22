#ifndef LANCE_H
#define LANCE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>

int _printer(const char *prompt);
char *find_directory(char *command);
int execute_command(
		char *command, char **args, int is_interactive, char *program_name);
int _printer(const char *prompt);
void exit_shell(void);
void handle_ctrl_d(void);
bool is_input_empty(const char *str);
#endif
