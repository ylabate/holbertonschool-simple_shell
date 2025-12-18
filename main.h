#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <linux/limits.h>
#include <signal.h>

/**
 * struct command - Structure for command functions
 * @name: The command name
 * @function: The function pointer to execute the command
 * @arguments: The command arguments
 */
typedef struct command
{
	char *name;
	int (*function)(char **);
	char **arguments;
} function_t;

char *search_path(char *buffer, char **PATH);
int exec_subprocess(char *path, char **token, char **envp);
char **split_arg(char *arg);
int start_subprocess(char *path_exec, char **token, char **envp);
void free_env(char **env);
char **env(char *var_name, char **envp);
void handle_sigint(int sig);
void prompt(void);
int local_command(char **token, char **envp);
int shell_exit(char **nothing);
int shell_env(char **envp);

#endif /*__MAIN_H__*/
