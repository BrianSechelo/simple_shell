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
	int j =0;
	char command[128];
	while(j < ac)
	{
		printf ("av[%d]:%s\n", j, av[j]); 
                 ++j;
	}
	
	while (1)
	{
		brian_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
