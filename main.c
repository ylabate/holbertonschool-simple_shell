#include "main.h"

int main(int ac, char **av)
{
	char *usr_entry = NULL;
	size_t length = 0;
	bool TTY = true; /* true = interactive*/
	int exec_exist;
	char *token;

	if (isatty(0) == 0)
		TTY = false;

	while (true)
	{
		if (TTY)
			printf("$ ");

		getline(&usr_entry, &length, stdin);

		token = strtok(usr_entry, " ");

		exec_exist = search_path(usr_entry);

		if (exec_exist != 0)
			exec_subprocess(usr_entry, token);
		else
			printf("%s", usr_entry);

		if (!TTY)
			break;
	}

	exit(EXIT_SUCCESS);
}
