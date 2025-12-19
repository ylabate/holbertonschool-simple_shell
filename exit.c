#include "main.h"

/**
 * __exit - handles the exit command for the shell
 * @exit_code: pointer to the exit code value
 * @end: pointer to flag indicating shell should end
 * @token: array of command tokens
 * @count: command execution count for error messages
 * @av: array of argument vectors (program name)
 *
 * Return: 1 if exit command was processed, 0 otherwise
 */
int __exit(int *exit_code, int *end, char **token, int count, char **av)
{
	int ext_code = 0, i = 0;

	if (token[1])
	{
		ext_code = _atoi(token[1]);
		while (token[1][i])
		{
			if (token[1][i] > '9' || token[1][i] < '0')
				ext_code = -1;
			i++;
		}
	}
	if (strcmp(token[0], "exit") == 0)
	{
		if (ext_code < 0)
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %s\n", av[0], count, token[1]);
			*exit_code = 2;
		}
		else
			if (*exit_code == 0)
				*exit_code = ext_code;
		*end = 1;
		return (1);
	}
	return (0);
}
