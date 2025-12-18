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

char *search_path(char *buffer, char **PATH);
int exec_subprocess(char *path, char **token, char **envp);
char **split_arg(char *arg);
int start_subprocess(char *path_exec, char **token, char **envp);
void free_env(char **env);
char **env(char *var_name, char **envp);
void handle_sigint(int sig);
void prompt(void);
int local_command(char **token);

#endif /*__MAIN_H__*/
