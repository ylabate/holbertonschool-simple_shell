#include "main.h"

/**
 * handle_sigint - handles the SIGINT signal (Ctrl+C)
 * @sig: signal number
 *
 * Return: void
 */
void handle_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
