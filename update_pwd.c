#include "main.h"

/**
 * update_pwd - Updates the PWD and OLDPWD environment variables
 * @oldpwd: The previous working directory
 * @envp: Pointer to the environment variables array
 *
 * Return: void
 */
void update_pwd(char *oldpwd, char **envp)
{
	char buf[4096];

	buf[0] = '\0';
	if (getcwd(buf, sizeof(buf)))
	{
		set_env("PWD", buf, envp);
		set_env("OLDPWD", oldpwd, envp);
	}
}
