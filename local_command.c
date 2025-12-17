#include "main.h"

/**
 * local_command - checks if the command is a local command
 * @token: array of command and its arguments
 * Return: 1 if local command, 0 otherwise
 */
int local_command(char **token)
{
	if (token && token[0] != NULL)
	{
		if (strcmp(token[0], "cd") == 0)
			return (1);

		if (strcmp(token[0], "exit") == 0)
			return (1);

		if (strcmp(token[0], "env") == 0)
			return (1);
		return (0);
	}
	else
		return (0);
}