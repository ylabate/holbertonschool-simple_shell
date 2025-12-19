#include "main.h"

/**
 * _free - frees allocated memory based on env flag
 * @mallocd: pointer to allocated memory
 * @env: flag to determine free method
 */
void _free(char **mallocd, char *env)
{
	if (mallocd)
	{
		if (env)
			free_env(mallocd);
		else
			free(mallocd);
	}
	mallocd = NULL;
}
