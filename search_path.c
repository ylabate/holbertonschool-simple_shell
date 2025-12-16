#include "main.h"

/**
 * search_path - search for a command in the PATH environment variable
 * @buffer: command to search for
 * Return:
 * 0 if the command does not exist
 * 1 if the command exists
 * 2 if the command is built-in
 */

char *search_path(char *buffer)
{
	char *path_env, *path_copy, *token, *result;
	DIR *dir_ptr;
	struct dirent *entry;

	if (buffer == NULL || buffer[0] == '\0')
		return (NULL);

	path_env = getenv("PATH");
	if (!path_env)
		return (NULL);

	path_copy = strdup(path_env);
	if (!path_copy)
		return (NULL);

	token = strtok(path_copy, ":");
	while (token)
	{
		dir_ptr = opendir(token);
		if (!dir_ptr)
		{
			token = strtok(NULL, ":");
			continue;
		}

		while ((entry = readdir(dir_ptr)) != NULL)
		{
			if (strcmp(buffer, entry->d_name) == 0)
			{
				closedir(dir_ptr);
				result = strdup(token);
				free(path_copy);
				return (result);
			}
		}
		closedir(dir_ptr);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}
