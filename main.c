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
	char *usr_entry = NULL, *path_exec = NULL, **token = NULL, **path_env = NULL;
	size_t size_usr_entry = 0;
	int count = 1, exit_code = 0, end;
	(void)ac;
	signal(SIGINT, handle_sigint);
	signal(SIGTSTP, SIG_IGN);
	for (end = 0 ; end == 0 ; count++)
	{
		if (prompt(&usr_entry, &size_usr_entry) == -1)
			break;
		token = split_arg(usr_entry);
		if (token[0])
		{
			path_env = env("PATH", envp);
			path_exec = search_path(token[0], path_env);
			if (__exit(&exit_code, &end, token, count, av))
			;
			else if (built_in_command(token, envp) != 256)
			;
			else if (path_exec)
				exit_code = start_subprocess(path_exec, token, envp);
			else
			{
				fprintf(stderr, "%s: %d: %s: not found\n", av[0], count, token[0]);
				exit_code = 127;
			}
			_free(path_env, "env");
		}
		_free(token, NULL);
	}
	free(usr_entry);
	exit(exit_code);
}
