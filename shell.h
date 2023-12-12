#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>

#define DELIM " \n\t"

extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
int execute_command(char **command, char **av, int idx);
void print_input(const char *input);
char *getenviron (char *varr);
char *get_path(char *cmd);

char *_strdup (const char *str);
int _strcmp (char *string1, char *string2);
int _strlen(char *s);
char *_strcat (char *destn, char *src);
char *_strcpy (char *destn, char *src);

int f_bultin(char *comm);
void h_bultin(char **comm, char **av, int *status, int idx);
void shell_exit(char **comm, char **av, int *status, int idx);
void env_print(char **comm, int *status);

void printerror(char *name, char *command, int idx);
void freearray2D(char **array);
char *itoa(int m);
void reverse_string(char *st, int len);
int _atoi(char *str);
int is_positive_number(char *str);

#endif
