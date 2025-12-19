#include "main.h"

/**
 * free_env - frees a dynamically allocated array of environment strings
 * @env: array of environment variable strings to free
 *
 * Return: void
 */
void free_env(char **env)
{
	int i = 0;

	while (env[i])
	{
		free(env[i]);
		i++;
	}
	free(env);
}
