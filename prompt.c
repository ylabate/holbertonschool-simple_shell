#include "main.h"


/**
 * prompt - displays the shell prompt
 * @usr_entry: pointer to buffer for user input
 * @size: pointer to size of the buffer
 *
 * Description: Prints a prompt symbol if input is from a terminal
 * Return: number of characters read, or -1 on error
 */
int prompt(char **usr_entry, size_t *size)
{
	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);
	char *cwd = getcwd(NULL, 0);

	if (isatty(0))
	{
		printf("%s%s%s %s%s %s$ %s", BOLD, COLOR_GREEN, cwd,
			COLOR_RED, pw->pw_name, COLOR_GOLD, COLOR_RESET);
	}
	fflush(stdout);
	free(cwd);
	return (getline(usr_entry, size, stdin));
}


