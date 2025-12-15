#include "main.h"

int exec_subprocess(char *usr_entry, char * const *arguments, char *path)
{
	pid_t pid_proc;
	extern char **environ;

	if (path == "exit")
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

