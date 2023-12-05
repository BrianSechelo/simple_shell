#include "shell.h"
/**
  * main - prompts user to enter input and executes user command
 **/
int main(void)
{
	char command[128];
	while (1)
	{
		brian_prompt();
		read_command(command, sizeof(command));
		execute_command(command);
	}
	return (0);
}
