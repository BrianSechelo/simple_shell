#include "shell.h"
char **tokenizer(char *line)
{
char *token = NULL, *tep = NULL;
char **cmd = NULL;
int cpt = 0, i = 0;
if (!line)
return (NULL);
tep =_strdup(line);
token = strtok(tep, DELIM);
while (token)
{
cpt++;
token = strtok(NULL, DELIM);
}
free(tep), tep = NULL;
cmd = malloc(sizeof(char *) * (cpt + 1));
if (!cmd)
{
free(line);
return (NULL);
}
token = strtok(line, DELIM);
while (token)
{
cmd[i] = token;
token = strtok(NULL, DELIM);
i++;
}
free(line), line = NULL;
cmd[i] = NULL;
return (cmd);
}
