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
	int i = 0;
	char **result = malloc(sizeof(char *) * 100);
	char *env_copy, *key, *temp;

	if (!result)
		exit(EXIT_FAILURE);
	while (i < 99)
	{
		result[i] = NULL;
		i++;
	}
	i = 0;
	while (envp[i])
	{
		if (var_name)
		{
			env_copy = strdup(envp[i]);
			key = strtok(env_copy, "=");
			if (!strcmp(key, var_name))
			{
				temp = strtok(NULL, "=");
				result[0] = (temp ? strdup(temp) : NULL);
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
		if (i >= 99)
			break;
	}
	result[i] = NULL;
	return (result);
}


