#include "main.h"

/**
 * shell_env - prints the current environment variables
 * @envp: environment variables
 * @arguments: command arguments
 * @count: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */

int shell_env(char **envp, char **arguments, int count, char **av)
{
	char **exit_env;
	int i = 0;
	(void)count;
	(void)av;
	if (arguments && arguments[1] && arguments[2])
	{
		fprintf(stderr, "env: too many arguments\n");
		return (1);
	}
	exit_env = env(arguments[1], envp);
	while (exit_env[i])
	{
		printf("%s\n", exit_env[i]);
		i++;
	}
	fflush(stdout);
	free_env(exit_env);

	return (0);
}
