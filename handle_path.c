#include "shell.h"
char *get_path(char *cmd)
{
char *path_environ, *full_command, *dirr;
int i; 
struct stat st;
path_environ = getenviron ("PATH");
if (!path_environ)
return (NULL);
dirr = strtok(path_environ, ":");

for (i = 0; cmd[i]; i++)
{
if (cmd[i] == '/')
{
if (stat(cmd, &st) == 0)
return (_strdup(cmd));

return (NULL);
}
}
while (dirr)
{
full_command = malloc(_strlen(dirr) + _strlen(cmd) + 2);

while (full_command)
{
_strcpy(full_command, dirr);
_strcat(full_command, "/");
_strcat(full_command, cmd);
if (stat(full_command,&st) == 0)
{
free(path_environ);
return (full_command);
}
free(full_command), full_command = NULL;
dirr = strtok(NULL, ":");
}
}
free(path_environ);
return (NULL);
}
