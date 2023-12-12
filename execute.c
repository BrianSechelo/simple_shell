#include "shell.h"

/**
 * execute_command: creates a child process
 * @command: function parameter
 *
 * return: void
 */

int execute_command(char **command, char **av, int idx)
{
	char *full_command;
	pid_t child_pid;
	int status;

	full_command = get_path(command[0]);
	if (!full_command)
	{
		printerror(av[0], command[0], idx);
		freearray2D(command);
		return (127);
	}

	/** Command is 'exit' */
	if (_strcmp(command[0], "exit") == 0)
	{
		freearray2D(command);
		exit(EXIT_SUCCESS);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		print_input("Error forking process.\n");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		if (execve(full_command, command, environ) == -1)
		{
			free(full_command), full_command = NULL;
			freearray2D(command);
		}

	}
	else
	{
		waitpid(child_pid, &status, 0);
		freearray2D(command);
		free(full_command), full_command = NULL;
	}

	return (WEXITSTATUS(status));
}
