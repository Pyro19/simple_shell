#include "shell.h"
/**
 * _perror - prints error message
 * Return: Nothing
 */
void _perror(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
}
/**
* handler - handles signals and write the prompt
* @_signal: signal to handle
* Return: Nothing
*/
void handler(int _signal)
{
	(void)_signal;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
* cisfun - Function to print cisfun$
* Return: Nothing
*/
void cisfun(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "cisfun$ ", 8);
}
/**
* main - the main function
* @ac: count of the argument
* @av: argument vector
* @env: enviroment variable
* Return: 0, 1 on failure
*/
int main(int ac, char **av, char **env)
{
	char *buff = NULL, **cmd;
	size_t len = 0;
	ssize_t chars;
	pid_t pid;
	int status, count = 0;
	(void)ac;
	cisfun();
	while ((chars = getline(&buff, &len, stdin)))
	{
		signal(SIGINT, handler);
		if (chars == EOF)
			_eof(buff);
		count++;
		cmd = _strtok(buff);
		pid = fork();
		if (pid == -1)
		_perror();
		if (pid == 0)
			_execve(cmd, buff, env, av, count);
		else
		{
			wait(&status);
			if (cmd == NULL)
			free_if(buff, cmd);
			else if (_strcmp("exit", cmd[0]))
			free_elif(buff, cmd);
			else
			{
				free(buff);
				free_all(cmd);
			}
		}
		len = 0, buff = NULL;
		cisfun();
	}
	if (chars == -1)
	{
		return (EXIT_FAILURE);
	}
		return (EXIT_SUCCESS);
}
