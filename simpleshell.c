#include "shell.h"
/**
  * main - prompts user to enter input and executes user command
  * @ac: arg count
 * @av: arg vector
 * 
 * Return: 0 on success 1 on failure
 **/
int main(int ac, char **av)
{
	char *line = NULL, **command = NULL;
	int status = 0, idx;
	(void) ac;
	
	while (1)
	{
		line = read_line();
		if (line == NULL)
		{
		if (isatty(STDIN_FILENO) == 0)
                write(STDOUT_FILENO, "\n", 1);
		return (status);
		}
		idx++;
	        command = tokenizer(line);
	      	if (!command)
		continue;
		
		status = execute_command(command, av, idx);
	}
	return (0);
}
