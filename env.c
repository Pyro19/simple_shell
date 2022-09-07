#include "shell.h"

/**
* dir_num - function gets the total number of directories
* @path: path string
* Return: number of directories in the path
*/
unsigned int dir_num(char *path)
{
	unsigned int i = 0, fl = 0, num_dir = 0;

	while (path[i])
	{
		if (path[i] != ':')
			fl = 1;

		if ((fl && path[i + 1] == ':') || (fl && path[i + 1] == '\0'))
		{
			num_dir++;
			fl = 0;
		}
		i++;
		}

		return (num_dir);
}

/**
* c_d_pointer - Function that create a double pointer array
* @fcmd: first command inserted in the prompt
* @environ: enviroment variables
* Return: directories
*/
char **c_d_pointer(char *fcmd, char **environ)
{
	char **dirs, *path_env, *dir;
	unsigned int len, i = 0;
	int dir_len, cmd_len;

	path_env = _env("PATH", environ);
	len = dir_num(path_env);
	dirs = malloc(sizeof(char *) * (len + 1));
	if (dirs == NULL)
		return (NULL);

	dir = strtok(path_env, ":");

	while (dir != NULL)
	{
		dir_len = _strlen(dir);
		cmd_len = _strlen(fcmd);
		dirs[i] = malloc(sizeof(char *) * (dir_len + cmd_len + 2));
		if (dirs[i] == NULL)
		{
			free_all(dirs);
			return (NULL);
		}
			append_cmd(dirs[i], dir, fcmd, dir_len, cmd_len);
			i++;
		dir = strtok(NULL, ":");
	}

		dirs[i] = NULL;

	return (dirs);
}

/**
* _env - function that get's the enviroment variable
* @name: name of the enviroment variable
* @environ: enviroment variables
* Return: the value associated with the variable
*/

char *_env(const char *name, char **environ)
{
	char *env_value, *cp_name;
	unsigned int i = 0, len;

	len =  _strconstlen(name);
	cp_name = malloc(sizeof(char) * len + 1);
	if (cp_name == NULL)
		return (NULL);
	_strcpyconst(cp_name, name, len);
	env_value = strtok(environ[i], "=");
	while (environ[i])
	{
		if (_strcmp(env_value, cp_name))
			{																																										env_value = strtok(NULL, "\n");
			free(cp_name);
			return (env_value);
		}
		i++;
		env_value = strtok(environ[i], "=");
	}
	free(cp_name);
	return (NULL);
}

/**
* append_cmd - Function that appends command
* @s1: string 1
* @s2: string 2
* @cmd: command to append
* @n: length of destination
* @c: length of command
* Return: s1
*/

char *append_cmd(char *s1, char *s2, char *cmd, int n, int c)
{
	int i, j;

	for (i = 0; i < n && s2[i] != '\0'; i++)
		s1[i] = s2[i];
	s1[i] = '/';
	i++;

	for (j = 0; j < c && cmd[j] != '\0'; j++, i++)
		s1[i] = cmd[j];
	s1[i] = '\0';
	return (s1);
}

/**
* print_env - Function to print all enviroment variables
* @environ: enviroment variables
* Return: Nothing
*/

void print_env(char **environ)
{
	unsigned int i = 0, len;

	while (environ[i])
	{
		len = _strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], len);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

