#include "main.h"

/**
 * search_path - search for a command in the PATH environment variable
 * @buffer: command to search for
 * @PATH: array of PATH directories to search
 * Return: path to the directory containing the command, or NULL if not found
 */

char *search_path(char *buffer, char **path_env)
{
	char *token = NULL;
	DIR *dir_ptr;
	struct dirent *file_ptr;

	if (!path_env || !path_env[0])
		return (NULL);

	if (!buffer || buffer[0] == '\0')
		return (NULL);

	if (buffer[0] == '/' || buffer[0] == '.')
	{
		return (buffer);
	}

	token = strtok(path_env[0], ":");
	while (token)
	{
		dir_ptr = opendir(token);
		if (dir_ptr)
		{
			while ((file_ptr = readdir(dir_ptr)))
				if (strcmp(buffer, file_ptr->d_name) == 0)
				{
					closedir(dir_ptr);
					return (token);
				}

			closedir(dir_ptr);
			token = strtok(NULL, ":");
		}
		else
			token = strtok(NULL, ":");
	}
	return (NULL);
}
