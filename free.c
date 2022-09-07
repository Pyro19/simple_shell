#include "shell.h"
/**
 * free_all - frees the whole memory
 * @ptr: pointer to be freed
 * Return: Nothing
*/

void free_all(char **ptr)
{
	unsigned int i = 0;

	if (ptr == NULL)
		return;

	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}

	if (ptr[i] == NULL)
		free(ptr[i]);
	free(ptr);
}
/**
 * free_if - function to free if
 * Return: Nothing
 */
void free_if(void)
{
	free(buff);
	free_all(cmd);
}
/**
 * free_elif - function frees the else if
 * Return: Nothing
 */
void free_elif(void)
{
	free(buff);
	free_all(cmd);
	exit(EXIT_SUCCESS);
}
/**
 * free_if - function to free if
 * @buff: pointer to buffer to be freed
 * @cmd: pointer to command to be freed
 * Return: Nothing
 */
void free_if(char *buff, char **cmd)
{
	free(buff);
	free_all(cmd);
}
/**
 * free_elif - function frees the else if
 * @buff: pointer to buffer to be freed
 * @cmd: pointer to command to be freed
 * Return: Nothing
 */
void free_elif(char *buff, char **cmd)
{
	free(buff);
	free_all(cmd);
	exit(EXIT_SUCCESS);
}

