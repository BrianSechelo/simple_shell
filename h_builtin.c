#include "shell.h"

int f_bultin(char *comm)
{
int i;
char *builtins[] = { "exit", "env", "setenv", "cd", NULL };


for (i = 0; builtins[i]; i++)
{
if (_strcmp(comm, builtins[i]) == 0)
return (1);
}
return (0);
}
void h_bultin(char **comm, char **av, int *status, int idx)
{
if (_strcmp(comm[0], "exit") == 0)
shell_exit(comm, av, status, idx);
else if (_strcmp(comm[0], "env") == 0)
env_print(comm, status);
}
void shell_exit(char **comm, char **av, int *status, int idx)
{
char * index, mssg[] = ": exit: illegal number: ";
int exit_value = (*status);
if (comm[1])
{
if (is_positive_number(comm[1]))
{
exit_value = _atoi(comm[1]);
}
else
{
index = itoa(idx);
write(STDERR_FILENO, av[0], _strlen(av[0]));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, mssg, _strlen(mssg));
write(STDERR_FILENO, comm[1],_strlen(comm[1]));
write(STDERR_FILENO, "\n", 1);
free(index);
freearray2D(comm);
(*status) = 2;
return;
}
		}
freearray2D(comm);
exit(exit_value);
}
void env_print(char **comm, int *status)
{
int i;
for (i = 0; environ[i]; i++)
{
write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
write(STDOUT_FILENO, "\n", 1);
}
freearray2D(comm);
*status = 0;
}
