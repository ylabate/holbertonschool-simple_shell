#include "main.h"

/**
 * handle_sigint - handles the SIGINT signal (Ctrl+C)
 * @sig: signal number
 *
 * Return: void
 */
void handle_sigint(int sig)
{
	uid_t uid = getuid();
	struct passwd *pw = getpwuid(uid);

	char *cwd = getcwd(NULL, 0);

	if (isatty(0))
	{
		printf("\n%s%s%s %s%s %s$ %s", BOLD, COLOR_GREEN, cwd,
			COLOR_RED, pw->pw_name, COLOR_GOLD, COLOR_RESET);
		fflush(stdout);
	}
	(void)sig;
}
