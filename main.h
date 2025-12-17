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
int split_arg(char *arg, char **token);
void start_subprocess(char *path, char **token, char **envp);
void free_env(char **env);
char **env(char *var_name, char **envp);
void handle_sigint(int sig);
void prompt(void);
int local_command(char **token);

#endif /*__MAIN_H__*/
