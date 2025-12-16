#include "main.h"

int exec_subprocess(char *path, char **arguments)
{
	pid_t pid_proc;
	int status;
	extern char **environ;

	if (path == "exit")
		exit(EXIT_SUCCESS);
	else
	{
		pid_proc = fork();
		if (pid_proc != 0)
			waitpid(pid_proc, &status, 0);
		else
		{
			execve(path, arguments, environ);
		}
	}
	return (0);
}

