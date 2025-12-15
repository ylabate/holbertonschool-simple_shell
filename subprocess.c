#include "main.h"

int exec_subprocess(char *path, char * const *arguments, int exec_exist)
{
	pid_t pid_proc;
	extern char **environ;

	if (exec_exist == 2)
		printf("aaa");
	else
	{
		pid_proc = fork();
		if (pid_proc != 0)
			wait(&pid_proc);
		else
		{
			execve(path, arguments, environ);
		}
	}
	return (0);
}
