#include "main.h"

/**
 * local_command - checks if the command is a local command
 * @token: array of command and its arguments
 * Return: 1 if local command, 0 otherwise
 */
int local_command(char **token, char **envp)
{
	int i = 0;
	function_t func[] = {
		{"exit", shell_exit, NULL},
		{"env", shell_env, NULL},
		{NULL, NULL, NULL}
	};

	func[1].arguments = envp;
	while (func[i].name)
	{
		if (strcmp(token[0], func[i].name) == 0)
			return (func[i].function(func[i].arguments));
		i++;
	}
	return (256);
}
