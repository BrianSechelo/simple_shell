#include "shell.h"
char *read_line(void)
{
char *line = NULL;
size_t len = 0;
int k;
if (isatty(STDIN_FILENO))
write(STDOUT_FILENO, "$ ", 2);
k = getline(&line, &len, stdin);
if (k == -1)
{
free(line);
return (NULL);
}
return(line);
}
