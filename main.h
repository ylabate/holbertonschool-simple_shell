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

char *search_path(char *buffer);
int exec_subprocess(char *usr_entry, char * const *arguments, char *path);
int split_arg(char *usr_entry, char **token);

#endif /*__MAIN_H__*/
