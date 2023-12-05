#include "shell.h"
/**
 * execute_command: creates a child process
 * @command: function parameter
 * return: void
 */

void execute_command(const char *command)
{
pid_t child_pid = fork();
if (child_pid == -1)
{
print_input("Error forking process.\n");
exit(EXIT_FAILURE);
}
else if (child_pid == 0)
{
char *args[128];
int arg_count = 0;

char *token = strtok((char *)command, " ");
while (token != NULL)
{
args[arg_count++] = token;
token = strtok(NULL, " ");
}
 args[arg_count] = NULL;

execvp(args[0], args);

print_input("Error executing command.\n");
exit(EXIT_FAILURE);
}
else
{
wait(NULL);
}
}
