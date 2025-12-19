#include "main.h"

/**
 * built_in_command - checks if the command is a local command
 * @token: array of command and its arguments
 * @envp: environment variables
 * Return: 0 if command is a local command, 256 otherwise
 */
int built_in_command(char **token, char **envp)
{
	int i = 0;
	function_t func[] = {
		{"env", shell_env, NULL},
		{NULL, NULL, NULL}};

	func[0].arguments = envp;
	while (func[i].name)
	{
		if (strcmp(token[0], func[i].name) == 0)
			return (func[i].function(func[i].arguments));
		i++;
	}
	return (256);
}
