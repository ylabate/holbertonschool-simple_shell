#ifndef __MAIN_H__
#define __MAIN_H__

#define BOLD          "\033[1m"
#define COLOR_GREEN  "\033[38;2;46;204;113m"
#define COLOR_RED   "\033[38;2;255;0;0m"
#define COLOR_RESET  "\033[0m"
#define COLOR_GOLD	 "\033[38;5;220m"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <dirent.h>
#include <pwd.h>

/**
 * struct command - Structure for command functions
 * @name: The command name
 * @function: The function pointer to execute the command
 * @arguments: The command arguments
 */
typedef struct command
{
	char *name;
	int (*function)(char **, char **);
} function_t;

char *search_path(char *buffer, char **PATH);
int exec_subprocess(char *path, char **token, char **envp);
char **split_arg(char *arg);
int start_subprocess(char *path_exec, char **token, char **envp);
void free_env(char **env);
char **env(char *var_name, char **envp);
void handle_sigint(int sig);
int prompt(char **usr_entry, size_t *size_usr_entry, char **envp);
int shell_env(char **envp, char **arguments);
int shell_cd(char **envp, char **arguments);
int _atoi(char *s);
int built_in_command(char **token, char **envp);
int __exit(int *exit_code, int *end, char **token, int count, char **av);

#endif /*__MAIN_H__*/
