#include "shell.h"
/**
 * print_input: function that writes to standard output
 * @input: string to be written to standard output
 */

void print_input(const char *input)
{
write(STDOUT_FILENO, input, strlen(input));
}
