#include "main.h"
/**
 * exec_subprocess - Executes a subprocess with the specified command.
 * @path: The path to the command to execute in the subprocess.
 * @token: Array of arguments to pass to the command.
 * @envp: Array of environment variables.
 *
 * Return: Returns the exit code of the subprocess.
 */
int exec_subprocess(char *path, char **token, char **envp)
{
	pid_t pid_proc;
	int status;
	int exit_code = 0;


	{
		pid_proc = fork();
		if (pid_proc != 0)
		{
			waitpid(pid_proc, &status, 0);
			if (WIFEXITED(status))
			{
				exit_code = WEXITSTATUS(status);
			}
		}
		else
		{
			signal(SIGINT, SIG_DFL);
			execve(path, token, envp);
			perror("execve");
			exit(1);
		}
	}
	return (exit_code);
}

/**
 * start_subprocess - Starts a subprocess with the given command.
 * @path: The path to the command or directory containing the command.
 * @token: Array of command tokens (command and arguments).
 * @envp: Array of environment variables.
 *
 * Return: Nothing (void).
 */
void start_subprocess(char *path, char **token, char **envp)
{
	char *full_path = NULL;

	if (strcmp(path, token[0]) != 0)
	{
		full_path = malloc(strlen(path) + 1 + strlen(token[0]) + 1);
		if (!full_path)
		{
			free(path);
			return;
		}
		sprintf(full_path, "%s/%s", path, token[0]);
	}
	else
		full_path = NULL;
	exec_subprocess((full_path ? full_path : path), token, envp);
	if (full_path)
		free(full_path);
	free(path);
}
