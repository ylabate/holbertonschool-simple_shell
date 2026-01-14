#include "main.h"

/**
 * split_arg - splits a string into tokens based on spaces
 * @usr_entry: the string to be split
 *
 * Return: the number of tokens created
 */
char **split_arg(char *usr_entry)
{
	char **token = malloc(sizeof(char *) * 1024);
	int i = 0, length = 0;

	if (!token)
		exit(EXIT_FAILURE);
	for (i = 0; i < 1024; i++)
		token[i] = NULL;
	i = 0;
	length = strlen(usr_entry);
	if (length > 0 && usr_entry[length - 1] == '\n')
		usr_entry[length - 1] = '\0';

	token[i] = strtok(usr_entry, " \t");
	while (token[i++])
		token[i] = strtok(NULL, " \t");
	return (token);
}
