#include "main.h"

/**
 * set_env - sets an environment variable
 * @key: the name of the environment variable
 * @content: the value of the environment variable
 * @envp: array of environment variables
 *
 * Return: void
 */
void set_env(char *key, char *content, char **envp)
{
	char *new_env = NULL;
	char *envp_cpy = NULL, *key_cpy = NULL;
	int i;

	if (!key || !content)
		return;
	new_env = malloc(strlen(key) + strlen(content) + 2);
	if (!new_env)
		exit(EXIT_FAILURE);
	for (i = 0; envp[i]; i++)
	{
		envp_cpy = malloc(strlen(envp[i]) + 1);
		if (!envp_cpy)
			exit(EXIT_FAILURE);
		strcpy(envp_cpy, envp[i]);
		key_cpy = strtok(envp_cpy, "=");
		if (strcmp(key_cpy, key) == 0)
		{
			sprintf(new_env, "%s=%s", key, content);
			free(envp_cpy);
			break;
		}
		free(envp_cpy);
	}
	free(envp[i]);
	envp[i] = malloc(strlen(new_env) + 1);
	strcpy(envp[i], new_env);

	free(new_env);
}
