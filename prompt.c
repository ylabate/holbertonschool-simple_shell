#include "main.h"

/**
 * show_prompt - displays a prompt and reads user input
 * @usr_entry: pointer to buffer for storing user input
 * @length: pointer to size of the buffer
 *
 * Return: number of characters read, or -1 on error
 */
int show_prompt(char **usr_entry, size_t *length)
{
	int readed;

	if (isatty(0))
		printf("$ ");

	readed = getline(usr_entry, length, stdin);
	if (readed == -1)
		exit(EXIT_FAILURE);

	return (readed);
}
