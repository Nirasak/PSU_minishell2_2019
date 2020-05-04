/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exec path
*/

#include <stdlib.h>
#include <unistd.h>
#include "my_utils.h"
#include "mysh.h"

char *get_path(char *path, char *cmd)
{
    int len = my_strlen(path);
    char *str = my_malloc(sizeof(char) * (len + my_strlen(cmd) + 2));

    str = my_strcpy(str, path);
    if (str[len - 1] != '/') {
        str[len] = '/';
        str[len + 1] = '\0';
    }
    str = my_strcat(str, cmd);
    return (str);
}

int my_exec_path(mysh_t *mysh)
{
    char *path = get_from_env(mysh, "PATH");
    char **paths = my_str_to_word_array(path, ':');
    char *str = NULL;

    if (!access(mysh->cur_cmd[0], X_OK)) {
        my_execve(mysh, mysh->cur_cmd[0]);
        return (1);
    }
    for (int i = 0; paths[i]; i++) {
        str = get_path(paths[i], mysh->cur_cmd[0]);
        if (!access(str, X_OK)) {
            my_execve(mysh, str);
            free(str);
            return (1);
        }
        free(str);
    }
    my_puterror(mysh->cur_cmd[0]);
    my_puterror(": Command not found.\n");
    return (1);
}
