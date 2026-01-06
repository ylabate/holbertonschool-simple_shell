#include "main.h"


/**
 * prompt - displays the shell prompt
 * @usr_entry: pointer to buffer for user input
 * @size: pointer to size of the buffer
 * @envp: pointer to environment variables
 *
 * Description: Prints a prompt symbol if input is from a terminal
 * Return: number of characters read, or -1 on error
 */
int prompt(char **usr_entry, size_t *size, char **envp)
{
	char **user = env("LOGNAME", envp);
	char *cwd = getcwd(NULL, 0);

	if (isatty(0))
	{
		printf("%s%s%s %s%s %s$ %s", BOLD, COLOR_GREEN, cwd,
			COLOR_RED, user[0], COLOR_GOLD, COLOR_RESET);
	}
	fflush(stdout);
	free_env(user);
	free(cwd);

	return (getline(usr_entry, size, stdin));
}


