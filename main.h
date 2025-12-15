#ifndef __MAIN_H__
#define __MAIN_H__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>


char *search_path(char *buffer);
int exec_subprocess(char *path);

#endif /*__MAIN_H__*/
