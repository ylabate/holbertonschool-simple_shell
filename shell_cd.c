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
				if (!exit_code)
					set_env("PWD", oldpwd[0], envp);
			}
			else
			{
				exit_code = chdir(arguments[1]);
				if (!exit_code)
					set_env("PWD", arguments[1], envp);
			}
		}
		else
		{
			if (home[0])
			{
				chdir(home[0]);
				if (!exit_code)
					set_env("PWD", home[0], envp);
			}
		}
	}
	if (exit_code)
		fprintf(stderr, "cd: directory don't existe\n");
	if (home)
		free_env(home);
	if (home)
		free_env(oldpwd);
	return (exit_code);
}
