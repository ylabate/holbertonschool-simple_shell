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
	pid_t pid;
	int exit_status;
	int exit_code = 0;

	{
		pid = fork();
		if (pid != 0)
		{
			waitpid(pid, &exit_status, WUNTRACED);
			if (WIFEXITED(exit_status))
				exit_code = WEXITSTATUS(exit_status);
			else if (WIFSIGNALED(exit_status))
				exit_code = 128 + WTERMSIG(exit_status);
			else if (WIFSTOPPED(exit_status))
				exit_code = 128 + WSTOPSIG(exit_status);
		}
		else
		{
			signal(SIGINT, SIG_DFL);
			execve(path, token, envp);
			perror("execve");
			exit(127);
		}
	}
	return (exit_code);
}

