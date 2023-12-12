#include "shell.h"
char *getenviron (char *varr)
{
char *tep, *key, *value,*env;
int i;

for (i = 0; environ[i]; i++)
{
tep = _strdup(environ[i]);
key = strtok(tep, "=");
if (_strcmp(key, varr) == 0)
{
	value = strtok(NULL, "\n");
	free(tep);
	env = _strdup(value);
	return (env);
}
free(tep),tep = NULL;
}
return (NULL);
}
