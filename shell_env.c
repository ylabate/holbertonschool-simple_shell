#include "main.h"

/**
 * shell_env - prints the current environment variables
 * @envp: environment variables
 *
 * Return: 0 on success
 */

int shell_env(char **envp)
{
	char **exit_env;
	int i = 0;

	exit_env = env((NULL), envp);
	while (exit_env[i])
	{
		printf("%s\n", exit_env[i]);
		i++;
	}
	fflush(stdout);
	free_env(exit_env);

	return (0);
}
