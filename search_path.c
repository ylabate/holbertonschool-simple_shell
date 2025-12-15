#include "main.h"

/**
 * search_path - search for a command in the PATH environment variable
 * @buffer: command to search for
 * Return:
 * 0 if the command does not exist
 * 1 if the command exists
 * 2 if the command is built-in
 */

char *search_path(char *buffer)
{
    char *path, *token, **path_splited;
    char *full_path;
    DIR *dir_ptr;
    struct dirent *entry;
    int i = 0;

    if (buffer == NULL)
        return (0);

    if (buffer == "exit")
        return ("exit");

    path = getenv("PATH");
    if (!path)
        return (0);
    token = strtok(path, ":");
    while (path_splited[i] = strtok(NULL, ":"))
    {
        dir_ptr = opendir(path_splited[i]);
        while ((entry = readdir(dir_ptr)) != NULL)
        {
            if (buffer == *entry->d_name)
            {
                closedir(dir_ptr);
                return (path_splited[i]);
            }
        }
        i++;
        path_splited[i] = strtok(NULL, ":");
    }
    closedir(dir_ptr);

    return (NULL);
}
