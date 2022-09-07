#include "shell.h"
/**
 * _strlen - function gives length of a string
 * @s: string
 * Return: length of string
 */
unsigned int _strlen(char *s)
{
	unsigned int len;

	for (len = 0; *s != '\0'; s++)
	{
		len++;
	}
	return (len);
}
/**
* _strconstlen - Function that gives the length of a constant string
* @s: string
* Return: length of string
*/
unsigned int _strconstlen(const char *s)
{
	unsigned int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
}
/**
* _strcpy - function that copies string
* @s1: destination string
* @s2: source string
* @n: length of the string
* Return: s1
*/
char *_strcpy(char *s1, char *s2, int n)
{
	int i;

	for (i = 0; i < n && s2[i] != '\0'; i++)
		s1[i] = s2[i];
	for ( ; i < n; i++)
		s1[i] = '\0';
	return (s1);
}
/**
* _strcpyconst - function that copies a constant string into other
*@s1: destination string
*@s2: source string
*@n: length of the string
*Return: s1
*/
char *_strcpyconst(char *s1, const char *s2, int n)
{
	int i;

	for (i = 0; i < n && s2[i] != '\0'; i++)
		s1[i] = s2[i];
	for ( ; i < n; i++)
		s1[i] = '\0';

	return (s1);
}
/**
 * _strcmp - function that compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 1, 0 in failure
 */
int _strcmp(char *s1, char *s2)
{
	unsigned int i = 0;

	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}

	return (1);
}
