#include "main.h"

/**
 * prompt - displays the shell prompt
 *
 * Description: Prints a prompt symbol if input is from a terminal
 */
void prompt(void)
{
	if (isatty(0))
		printf("$ ");
}
