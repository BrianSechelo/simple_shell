#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define DELIM " \n\t"
#define MAX_ENV_VARS 100

extern char **environ;
void freearray2D(char **array);
void print_environment(void);
void printerror(char *name, char *command, int idx);
char *itoa(int m);
void reverse_string(char *st, int len);
char *_strdup(const char *str);
int _strcmp(char *string1, char *string2);
int _strlen(char *s);
char *_strcat(char *destn, char *src);
char *_strcpy(char *destn, char *src);

#endif
