#include "main.h"
#include <limits.h>

int main(int ac, char **av, char **envp)
{
	char *usr_entry = NULL;
	char *path = NULL;
	char *full_path;
	size_t length = 0;
	bool TTY = true; /* true = interactive*/
	int readed, last_result;
	char **token;

	if (isatty(0) == 0)
		TTY = false;

	token = (char **)malloc(sizeof(char *) * 1024);
	if (!token)
		exit(EXIT_FAILURE);

	while (true)
	{
		if (TTY)
			printf("$ ");

		readed = getline(&usr_entry, &length, stdin);
		if (readed == -1)
		{
			if (TTY)
				printf("\n");
			break;
		}
		split_arg(usr_entry, token);

		path = search_path(token[0]);
	
		if (path)
		{
			full_path = malloc(strlen(path) + 1 + strlen(token[0]) + 1);
			if (!full_path)
			{
				free(path);
				continue;
			}
			sprintf(full_path, "%s/%s", path, token[0]);
			last_result = exec_subprocess(full_path, token);
			free(path);
			free(full_path);
		}
		else
			printf("%s: command not found\n", token[0]);

		if (!TTY)
			break;
	}
	free(usr_entry);
	free(token);
	exit(EXIT_SUCCESS);
}
