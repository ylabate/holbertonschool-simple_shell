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
	int i = 1, j;

	token[0] = strtok(arg, " ");
	for (j = 0 ; token[0][j] != '\0' ; j++)
	;
	token[0][j - 1] = '\0';

	while (token[i] = strtok(NULL, " "))
		i++;

	token[i] = NULL;
	return (i);
}
