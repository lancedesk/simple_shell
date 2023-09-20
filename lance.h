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

char *_strcat(char *dest, const char *src);
void _puts(const char *str);
int _putchar(char c);
ssize_t _getline(char **buffer, size_t *size);
char *_strtok(char *str, const char *delim);
int _atoi(const char *str);
size_t _strlen(const char *str);
char *_strcpy(char *dest, const char *src);
char *_strdup(const char *str);
int _strcmp(const char *strn1, const char *strn2);
int _printer(const char *prompt);
void _prompter(void);
void _input_processor(char *prompt, size_t size, FILE *file, int fd);
void _prompt_processor(const char *prompt);

/* File and interactive modes */
void _mode_file(const char *filename);
void _mode_interactive(void);

#endif



