#include "shell.h"
/**
 * _strdup: function stdup
 * @str: string input
 *
 * Return: char string
 */
char *_strdup(const char *str)
{
char *ptr;
int i, len = 0;
if (str == NULL)
return (NULL);
while (str[len])
len++;

ptr = malloc(sizeof(char) * (len + 1));
if (ptr == NULL)
return (NULL);

for (i = 0; i <= len; i++)
ptr[i] = str[i];
return (ptr);
}
/**
 * _strcmp: function that compares strings
 * @string1: first string
 * @string2: second string
 *
 * Return: cmp
 */
int _strcmp(char *string1, char *string2)
{
int cmp;
cmp = (int)*string1 - (int)*string2;

while (*string1)
{
if (*string1 != *string2)
break;
string1++;
string2++;

cmp = (int)*string1 - (int)*string2;
}
return (cmp);
}
/**
 * _strlen: function that calculates the string length
 * @s: string input
 *
 * Return: length of string
 */
int _strlen(char *s)
{
int len = 0;

while (s[len])
len++;
return (len);
}
/**
 * _strcat: function that cats string
 * @destn: destination of string
 * @src: source of string
 *
 * Return: destination string
 */
char *_strcat(char *destn, char *src)
{
char *pt = destn;
while (*pt)
pt++;
while (*src)
{
*pt = *src;
pt++;
src++;
}
*pt = '\0';
return (destn);
}
/**
 * _strcpy: function taht copies string
 * @destn: string destination
 * @src: string source
 *
 * Return: destination
 */
char *_strcpy(char *destn, char *src)
{
int i = 0;
while (src[i])
{
destn[i] = src[i];
i++;
}
destn[i] = '\0';
return (destn);
}
