#include "main.h"

void set_env(char *key, char *content, char **envp)
{
	char *new_env = malloc(strlen(key) + strlen(content) + 2);
	char *envp_cpy = NULL, *key_cpy = NULL;
	int i;
	char **rm_env;

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
			break;
		}
		free(envp_cpy);
	}
	rm_env = &envp[i];
	envp[i] = malloc(strlen(new_env) + 1);
	strcpy(envp[i], new_env);

	free(*rm_env);
	free(new_env);
	free(envp_cpy);
}

