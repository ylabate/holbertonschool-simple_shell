#include "main.h"
/**
 * exec_subprocess - Executes a subprocess with the specified command.
 * @path: The path to the command to execute in the subprocess.
 * @arguments: Array of arguments to pass to the command.
 * @envp: Array of environment variables.
 *
 * Return: Returns the exit code of the subprocess.
 */
int exec_subprocess(char *path, char **arguments, char **envp)
{
	pid_t pid_proc;
	int status;
	int exit_code;

	if (!strcmp(path, "exit"))
		exit(EXIT_SUCCESS);
	else
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
			execve(path, arguments, envp);
			perror("execve");
			exit(1);
		}
	}
	return (exit_code);
}

