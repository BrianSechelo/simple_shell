#include "shell.h"
void freearray2D(char **array)
{
int i;
if (!array)
return;

for (i = 0; array[i]; i++)
{
free(array[i]);
array[i] = NULL;
}
free(array), array = NULL;
}
void printerror(char *name, char *command, int idx)
{
char *index, mssg[] = ": not found";
index = itoa(idx);
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, index, _strlen(index));
write(STDERR_FILENO, name, _strlen(name));
write(STDERR_FILENO, ": ", 2);
write(STDERR_FILENO, command,_strlen(command));
write(STDERR_FILENO, mssg, _strlen(mssg));

free(index);
}
char *itoa(int m)
{
char buff[20];
int i = 0;

if (m == 0)
buff[i++] = '0';
else
{
while (m > 0)
{
buff[i++] = (m %10) + '0';
m /=10;
}
}
buff[i] = '\0';
reverse_string(buff, i);
return (_strdup(buff));
}
void reverse_string(char *st, int len)
{
char temp;
int stat = 0;
int end = len-1;

while (stat < end)
{
temp = st[stat];
st[stat] = st[end];
st[end] = temp;
stat++;
end--;
}
}
