/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** exec binary
*/

#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include "my_utils.h"
#include "mysh.h"

int my_exec_binary(mysh_t *mysh)
{
    if (!access(mysh->cur_cmd[0], X_OK) && !opendir(mysh->cur_cmd[0])
        && mysh->cur_cmd[0][0] == '.' && mysh->cur_cmd[0][1] == '/') {
        return (my_execve(mysh, mysh->cur_cmd[0]));
    } else if (
        (mysh->cur_cmd[0][0] == '.' && mysh->cur_cmd[0][1] == '/')
        || (opendir(mysh->cur_cmd[0]) != 0)) {
        my_puterror(mysh->cur_cmd[0]);
        my_puterror(": Permission denied.\n");
        return (true);
    }
    return (false);
}
