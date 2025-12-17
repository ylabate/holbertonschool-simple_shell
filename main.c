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
	char *usr_entry = NULL, *path = NULL;
	size_t length = 0;
	char **token;
	char **path_env;
	int count = 1;
	(void)ac, (void)av;

	signal(SIGINT, handle_sigint);

	token = (char **)malloc(sizeof(char *) * 1024);
	if (!token)
		exit(EXIT_FAILURE);
	while (true)
	{
		prompt();
		if (getline(&usr_entry, &length, stdin) == -1)
			break;
		length = strlen(usr_entry);
		if (length > 0 && usr_entry[length - 1] == '\n')
			usr_entry[length - 1] = '\0';
		split_arg(usr_entry, token);
		if (!token[0] || token[0][0] == '\0')
			continue;
		path_env = env("PATH", envp);

		path = search_path(token[0], path_env);
		if (path)
		{
			start_subprocess(path, token, envp);
			;
		}
		else
			printf("%s: %d: %s: not found\n", av[0], count, token[0]);
		count++;
	}
	free(usr_entry);
	free(token);
	exit(EXIT_SUCCESS);
}
