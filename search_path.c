#include "main.h"

/**
 * search_path - search for a command in the PATH environment variable
 * @buffer: command to search for
 * @PATH: array of PATH directories to search
 * Return: path to the directory containing the command, or NULL if not found
 */

char *search_path(char *buffer, char **PATH)
{
	char *token, *result, *buf_copy;
	DIR *dir_ptr;
	struct dirent *entry;

	buf_copy = strdup(buffer);
	if (buf_copy == NULL || buf_copy[0] == '\0')
		return (NULL);

	if (buf_copy[0] == '/' || (buf_copy[0] == '.' && buf_copy[1] == '/'))
	{
		free_env(PATH);
		return (buf_copy);
	}
	token = strtok(PATH[0], ":");
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
				free(buf_copy);
				free_env(PATH);
				return (result);
			}
		}
		closedir(dir_ptr);
		token = strtok(NULL, ":");
	}
	free_env(PATH);
	free(buf_copy);
	return (NULL);
}
