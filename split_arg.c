#include "main.h"

int split_arg(char *usr_entry, char **token)
{
	int i = 1;

	token[0] = strtok(usr_entry, " ");

	while (token[i] = strtok(NULL, " "))
		i++;

	token[i] = NULL;
	return (i);
}
