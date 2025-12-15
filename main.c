#include "main.h"
#include <limits.h>

int main(int ac, char **av)
{
	char *usr_entry = NULL;
	size_t length = 0;
	bool TTY = true; /* true = interactive*/
	int exec_exist, readed, last_result;
	char **token;

	if (isatty(0) == 0)
		TTY = false;

	token = (char **)malloc(sizeof(char *) * _SC_ARG_MAX);

	while (true)
	{
		if (TTY)
			printf("$ ");

		readed = getline(&usr_entry, &length, stdin);
		if (readed == -1)
			exit(EXIT_FAILURE);

		split_arg(usr_entry, token);

		exec_exist = search_path(usr_entry);

		if (exec_exist != 0)
			last_result = exec_subprocess(usr_entry, token, exec_exist);
		else
			printf("%s", usr_entry);

		if (!TTY)
			break;
	}

	free(usr_entry);
	exit(EXIT_SUCCESS);
}
