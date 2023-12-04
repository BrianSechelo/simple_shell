#include "shell.h"

void read_command(char *user_input, size_t size)
{
if (fgets(user_input, size, stdin) == NULL)
{
if (feof(stdin))
{
print_input("\n");
exit(EXIT_SUCCESS);
}
else 
{
input_print("Error while reading input.\n");
exit(EXIT_FAILURE);
}
}
print_input[strcspn(user_input, "\n")] = '\0';
}
