#include "shell.h"
/**
 * read_command: reads users command
 * @user_input: users input command
 * @size: length of input command
 * return: void
 */

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
print_input("Error while reading input.\n");
exit(EXIT_FAILURE);
}
}
user_input[strcspn(user_input, "\n")] = '\0';
}
