#include "shell.h"

void print_input(const char *input)
{
	write(STDOUT_FILENO, input, strlen(input));
}
