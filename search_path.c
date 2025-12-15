#include "main.h"

/**
 * search_path - search for a command in the PATH environment variable
 * @buffer: command to search for
 * Return:
 * 0 if the command does not exist
 * 1 if the command exists
 * 2 if the command is built-in
 */

int search_path(char *buffer)
{
    char *path, *token;
    char *full_path[PATH_MAX];
    DIR *dir_ptr;
    struct dirent *entry;

    if (buffer == NULL)
        return (0);

    if (strcmp(buffer, "exit") == 0)
        return (2);

    path = getenv("PATH");
    if (!path)
        return (0);
    token = strtok(path, ":");
    while (path_splited[i] = strtok(NULL, ":"))
    {
        dir_ptr = opendir(path_splited[i]);
        while ((entry = readdir(dir_ptr)) != NULL)
        {
            printf("fichier = %s\n", entry->d_name);
            if (av[1] == *entry->d_name)
            
        }
        i++;
    }
    closedir(dir_ptr);
    while (path != NULL)
    {
        
        if (access(path, X_OK) == 0)
            return (1);
        else
            return (0);
    }
    if (path != NULL)
        return (1);
    else
        return (0);
}
