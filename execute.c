#include "shell.h"

/**
 * print_environment: Prints the current environment variables
 */
void print_environment(void)
{
	int i;
	char **env_copy = malloc(sizeof(char *) * (MAX_ENV_VARS));

	if (env_copy == NULL)
	{
		perror("Memory allocation error");
		return;
	}
	
	for (i = 0; environ[i] != NULL; i++)
	{
		env_copy[i] = strdup(environ[i]);
		if (env_copy[i] == NULL)
		{
			perror("Memory allocation error");
			/** frees previously allocated memory before the exit */
			freearray2D(env_copy);
			return;
		}
		printf("%s\n", environ[i]);
	}

	freearray2D(env_copy); /** Moved outside of the loop */
}

/**
 * execute_command: creates a child process
 * @command: function parameter
 * @av: function parameter
 * @idx: function parameter
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
	if (strcmp(command[0], "exit") == 0)
	{
		freearray2D(command);
		exit(EXIT_SUCCESS);
	}

	/** Command is 'env' */
	if (strcmp(command[0], "env") == 0)
	{
		print_environment();
		freearray2D(command);
		free(full_command);
		return (0);
	}

	child_pid = fork();
	if (child_pid == 0)
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
