#include "shell.h"

/**
 * env_builtin - Prints the current environment
 */

void env_builtin(void)
{
	int i;
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
