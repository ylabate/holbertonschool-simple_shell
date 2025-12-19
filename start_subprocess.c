#include "main.h"

/**
 * start_subprocess - Starts a subprocess with the given command.
 * @path_exec: The path to the command or directory containing the command.
 * @token: Array of command tokens (command and arguments).
 * @envp: Array of environment variables.
 *
 * Return: Exit code of the subprocess.
 */
int start_subprocess(char *path_exec, char **token, char **envp)
{
	char *full_path = NULL;
	int exit_code = 0;

	if (strcmp(path_exec, token[0]) != 0)
	{
		full_path = malloc(strlen(path_exec) + 1 + strlen(token[0]) + 1);
		if (!full_path)
			exit(EXIT_FAILURE);
		sprintf(full_path, "%s/%s", path_exec, token[0]);
	}
	else
		full_path = NULL;
	exit_code = exec_subprocess((full_path ? full_path : path_exec), token, envp);
	if (full_path)
		free(full_path);
	return (exit_code);
}
