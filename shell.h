#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>

void brian_prompt(void);
void read_command(char *user_input, size_t size);
void execute_command(const char *command);
void print_input(const char *input);

#endif
