#include "shell.h"
/**
* _execve - function to verify and execute
* @cmd: command
* @buff: command from getline
* @env: enviroment variable
* @av: argument vector
* @count: how many times it executed
* Return: Nothing
*/
void _execve(char **cmd, char *buff, char **env, char **av, int count)
{
	struct stat file_s;

	if (cmd == NULL)
	{
		free(buff);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp("exit", cmd[0]))
	{
		free(buff);
		free_all(cmd);
		exit(EXIT_SUCCESS);
	}
	else if (_strcmp("env", cmd[0]))
	{
		free(buff);
		free_all(cmd);
		print_env(env);
		exit(EXIT_SUCCESS);
	}
	else if (stat(cmd[0], &file_s) == 0)
		execve(cmd[0], cmd, NULL);
	else
		_find(cmd, buff, env, av, count);
}
