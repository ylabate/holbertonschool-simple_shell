#include "main.h"

/**
 * __exit - handles the exit command for the shell
 * @exit_code: pointer to the exit code value
 * @end: pointer to flag indicating shell should end
 * @token: array of command tokens
 *
 * Return: 1 if exit command was processed, 0 otherwise
 */
int __exit(int *exit_code, int *end, char **token, int count)
{
	int ext_code = 0;

	if (token[1])
		ext_code = _atoi(token[1]);

	if (strcmp(token[0], "exit") == 0)
	{
		if (ext_code < 0)
		{
			fprintf(stderr, "%s: %d: exit: Illegal number: %d\n", token[0], count, ext_code);
			*exit_code = 2;
		}
		else
			*exit_code = ext_code;
		*end = 1;
		return (1);
	}
	return (0);
}
