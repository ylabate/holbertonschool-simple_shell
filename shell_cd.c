#include "main.h"

int shell_cd(char **envp, char **arguments)
{
	char **home = env("HOME", envp);
	char **oldpwd = env("OLDPWD", envp);
	int exit_code = 0;

	if (arguments)
	{
		if (arguments[1] && arguments[2])
		{
			fprintf(stderr, "cd: too many arguments\n");
			return (1);
		}

		if (arguments[1])
		{
			if (strcmp(arguments[1], "-") == 0)
				exit_code = chdir(oldpwd[0]);
			else
				exit_code = chdir(arguments[1]);
		}
		else
		{
			chdir(home[0]);
		}
	}
	if (exit_code)
		fprintf(stderr, "cd: directory don't existe\n");
	return (exit_code);
}
