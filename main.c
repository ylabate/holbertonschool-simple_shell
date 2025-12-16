#include "main.h"

/**
 * main - Entry point for the simple shell program
 * @ac: Argument count (unused)
 * @av: Argument vector (unused)
 * @envp: Environment variables array
 *
 * Return: EXIT_SUCCESS on normal termination
 */
int main(int ac, char **av, char **envp)
{
	char *usr_entry = NULL, *full_path = NULL, *path = NULL;
	size_t length = 0;
	int readed, last_result;
	char **token;
	(void)ac, (void)av, (void)last_result;

	token = (char **)malloc(sizeof(char *) * 1024);
	if (!token)
		exit(EXIT_FAILURE);
	while (true)
	{
		show_prompt(&usr_entry, &length);
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
			if (strcmp(path, token[0]))
				sprintf(full_path, "%s/%s", path, token[0]);
			else
			{
				free(full_path);
				full_path = path;
			}
			last_result = exec_subprocess(full_path, token, envp);
			if (path != full_path)
				free(full_path);
			free(path);
		}
		else
			printf("%s: command not found\n", token[0]);

		if (!isatty(0))
			break;
	}
	free(usr_entry);
	free(token);
	exit(EXIT_SUCCESS);
}
