#include "main.h"

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

	return (0);
}
