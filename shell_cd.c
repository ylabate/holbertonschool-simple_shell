#include "main.h"

int shell_cd(char **envp, char **arguments)
{
	char **home;

	if (arguments)
	{
		if (arguments[1] && arguments[2])
		{
			fprintf(stderr, "cd: too many arguments\n");
			return (1);
		}
		if (arguments[1])
		{
			if (chdir(arguments[1]))
			{
				fprintf(stderr, "cd: directory don't existe\n");
				return (1);
			}
		}
		else
		{
			home = env("HOME", envp);
			chdir(home[0]);
		}
	}
	return (0);
}
