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
	int i = 1;

	token[0] = strtok(arg, " ");

	while (token[i] = strtok(NULL, " "))
		i++;

	token[i] = NULL;
	return (i);
}
