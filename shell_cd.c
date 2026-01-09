#include "main.h"

int shell_cd(char **envp, char **arguments)
{
	char **home = env("HOME", envp);
	char **oldpwd = env("OLDPWD", envp);
	int exit_code = 0;

	if (arguments)
	{
		if (arguments[1])
		{
			if (arguments[2])
			{
				fprintf(stderr, "cd: too many arguments\n");
				return (1);
			}
			if (strcmp(arguments[1], "-") == 0)
			{
				exit_code = chdir(oldpwd[0]);
				set_env("PWD", oldpwd[0], envp);
			}
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
	free_env(home);
	free_env(oldpwd);
	return (exit_code);
}
