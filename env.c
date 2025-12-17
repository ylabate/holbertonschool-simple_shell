#include "main.h"

/**
 * env - retrieves environment variables or a specific variable value
 * @var_name: name of the environment variable to search for, or NULL for all
 * @envp: array of environment variable strings
 *
 * Return: array of strings containing the result, must be freed by caller
 */
char **env(char *var_name, char **envp)
{
	int i = 0, j = 0;
	char **result = malloc(sizeof(char *) * 50);
	char *env_copy, *key;

	while (result[j])
	{
		result[i] = NULL;
		i++;
	}
	while (envp[i])
	{
		if (var_name)
		{
			env_copy = strdup(envp[i]);
			key = strtok(env_copy, "=");
			if (!strcmp(key, var_name))
			{
				result[0] = strdup(strtok(NULL, "="));
				free(env_copy);
				result[1] = NULL;
				return (result);
			}
			free(env_copy);
		}
		else
		{
			result[i] = strdup(envp[i]);
		}
		i++;
		if (i >= 50)
			break;
	}
	result[i] = NULL;
	return (result);
}

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
