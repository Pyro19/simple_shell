#include "shell.h"
/**
* err_messenger - function prints an error message
* @av: argument vector
* @fcmd: first command to print if not found
* @count: number of times executed
* Return: Nothing
*/

void err_messenger(char **av, char *fcmd, int count)
{
	int num_len = 1, cp, mult = 1;

	write(STDERR_FILENO, av[0], _strlen(av[0]));
	write(STDERR_FILENO, ": ", 2);
	cp = count;

	while (cp >= 10)
	{
		cp /= 10;
		mult *= 10;
		num_len++;
	}

	while (num_len > 1)
	{
		if ((count / mult) < 10)
			_puterror((count / mult + '0'));
		else
			_puterror((count / mult) % 10 + '0');
		--num_len;
		mult /= 10;
	}

	_puterror(count % 10 + '0');
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, fcmd, _strlen(fcmd));
	write(STDERR_FILENO, ": not found\n", 12);
}

/**
* _puterror - Prints a char
* @c: character to write
* Return: int to print
*/

int _puterror(char c)
{
	return (write(STDERR_FILENO, &c, 1));
}
/**
* _find - function finds the path
* @cmd: commands
* @buff: buffer
* @env: enviroment variables
* @av: argument vector
* @count: count number
* Return: Nothing
*/

void _find(char **cmd, char *buff, char **env, char **av, int count)
{
	struct stat file_s2;
	int i = 0;
	char **dirs;

	dirs = c_d_pointer(cmd[0], env);
	while (dirs[i])
	{
		if (stat(dirs[i], &file_s2) == 0)
			execve(dirs[i], cmd, NULL);
		i++;
	}
	err_messenger(av, cmd[0], count);
	free(buff);
	free_all(cmd);
	free_all(dirs);
	exit(EXIT_SUCCESS);
}
/**
* _eof - control end of file
* @buff: buffer array
* Return: Nothing
*/
void _eof(char *buff)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "\n", 1);
	free(buff);
	exit(0);
}

