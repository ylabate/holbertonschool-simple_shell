#include "main.h"

/**
 * split_arg - splits a string into tokens based on spaces
 * @arg: the string to be split
 * @token: array to store the resulting tokens
 *
 * Return: the number of tokens created
 */
int split_arg(char *arg, char **token)
{
	int i = 0;

	token[i] = strtok(arg, " \t\n");
	while (token[i])
	{
		i++;
		token[i] = strtok(NULL, " \t\n");
	}
	return (i);
}
