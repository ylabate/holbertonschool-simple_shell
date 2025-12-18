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
	char *usr_entry = NULL, *path_exec = NULL;
	size_t size_usr_entry = 0; /* la taille du malloc de l'user entry */
	char **token = NULL;	   /* user entry une fois séparer */
	char **path_env = NULL;	   /* le PATH de l'environement */
	int count = 1, exit_code = 0, length = 0, end = 0;
	(void)ac;

	signal(SIGINT, handle_sigint);

	while (end == 0)
	{
		prompt();
		if (getline(&usr_entry, &size_usr_entry, stdin) == -1)
			break;

		length = strlen(usr_entry);
		if (length > 0 && usr_entry[length - 1] == '\n')
			usr_entry[length - 1] = '\0';

		token = split_arg(usr_entry);
		if (!token[0])
			end = 1;
		else
		{
			path_env = env("PATH", envp);
			path_exec = search_path(token[0], path_env);
			if (strcmp(token[0], "exit") == 0)
				end = 1;
			else if (built_in_command(token, envp) != 256)
				;
			else if (path_exec)
				exit_code = start_subprocess(path_exec, token, envp);
			else
			{
				fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, token[0]);
				exit_code = 127;
			}
		}
		if (token)
			free(token);
		free_env(path_env);
		token = NULL;
		count++;
	}
	free(usr_entry);
	exit(exit_code);
}
