#include "shell.h"

/**
 * len_cmd - find number of commands in string
 * @str: string with the commands
 * Return: number of commands
*/

unsigned int len_cmd(char *str)
{
	unsigned int i = 0, cmd = 0, fl = 0;

	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			fl = 1;
		if ((fl && str[i + 1] == ' ')
			|| (fl && str[i + 1] == '\0'))
		{
			++cmd;
			fl = 0;
		}
		i++;
	}
	return (cmd);
}

/**
 * _strtok - create a double pointer array that point to each string
 * @str: command from the terminal
 * Return: array of pointers
*/
char **_strtok(char *str)
{
	char *token, **holder;
	unsigned int len;
	int i = 0;

	str[_strlen(str) - 1] = '\0';
	len = len_cmd(str);
	if (len == 0)
		return (NULL);
	holder = malloc((sizeof(char *) * (len + 1)));
	if (holder == NULL)
		return (NULL);
	token = strtok(str, " ");
	while (token != NULL)
	{
		holder[i] = malloc(_strlen(token) + 1);
		if (holder[i] == NULL)
		{
			free_all(holder);
			return (NULL);
		}
		_strcpy(holder[i], token, _strlen(token) + 1);
		token = strtok(NULL, " ");
		i++;
	}
	holder[i] = NULL;
	return (holder);
}
