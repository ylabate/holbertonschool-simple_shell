#include "main.h"

/**
 * shell_cd - changes the current directory
 * @envp: environment variables
 * @arguments: command arguments
 * @count: command count
 * @av: argument vector
 *
 * Return: 0 on success, 1 on failure
 */
int shell_cd(char **envp, char **arguments, int count, char **av)
{
	char **home = env("HOME", envp);
	char **oldpwd = env("OLDPWD", envp);
	char **pwd = env("PWD", envp);
	int exit_code = 0;

	if (arguments[2])
		fprintf(stderr, "cd: too many arguments\n");
	else if (arguments[1])
	{
		if (strcmp(arguments[1], "-") == 0)
		{
			if (oldpwd && oldpwd[0])
			{
				exit_code = chdir(oldpwd[0]);
				if (!exit_code && pwd && pwd[0])
					update_pwd(pwd[0], envp);
			}
		}
		else
		{
			exit_code = chdir(arguments[1]);
			if (!exit_code && pwd && pwd[0])
				update_pwd(pwd[0], envp);
		}
	}
	else
	{
		if (home && home[0])
		{
			exit_code = chdir(home[0]);
			if (!exit_code && pwd && pwd[0])
				update_pwd(pwd[0], envp);
		}
	}
	if (exit_code)
		fprintf(stderr, "%s: %d: cd: can't cd to %s\n", av[0], count, arguments[1]);
	free_env(home);
	free_env(oldpwd);
	free_env(pwd);
	return (exit_code);
}
