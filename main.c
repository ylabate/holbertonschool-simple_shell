#include "main.h"

int main(int ac, char **av)
{
	char *buf = NULL;
	size_t length = 0;
	bool TTY = true; /* true = interactive*/

	if (isatty(0) == 0)
		TTY = false;

	while (true)
	{
		if (TTY)
			printf("$ ");
		getline(&buf, &length, stdin);
		if (!TTY)
			break;
	}

	exit(EXIT_SUCCESS);
}
