#include "main.h"

/**
 * split_arg - splits a string into tokens based on spaces
 * @arg: the string to be split
 * @token: array to store the resulting tokens
 *
 * Return: the number of tokens created
 */
char **split_arg(char *arg)
{
	char **token = malloc(sizeof(char *) * 1024);
	int i = 0;

	if (!token)
		exit(EXIT_FAILURE);

	token[i] = strtok(arg, " \t");
	while (token[i])
	{
		i++;
		token[i] = strtok(NULL, " \t\n");
	}
	return (token);
}
