/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** pipe
*/

#include <unistd.h>
#include "mysh.h"

int my_pipe_next(mysh_t *mysh, int fd[2], int save[2], int i)
{
    int j = 0;

    for (i += 1; mysh->cur_cmd[i]; i++) {
        mysh->cur_cmd[j] = mysh->cur_cmd[i];
        j++;
    }
    mysh->cur_cmd[j] = NULL;
    dup2(fd[0], STDIN_FILENO);
    check_commands(mysh);
    close(fd[0]);
    dup2(save[0], STDIN_FILENO);
    close(save[0]);
    return (1);
}

int my_pipe(mysh_t *mysh, int i)
{
    int save[2];
    int fd[2];

    save[1] = dup(STDOUT_FILENO);
    save[0] = dup(STDIN_FILENO);
    pipe(fd);
    dup2(fd[1], STDOUT_FILENO);
    mysh->cur_cmd[i] = NULL;
    check_commands(mysh);
    close(fd[1]);
    dup2(save[1], STDOUT_FILENO);
    close(save[1]);
    return (my_pipe_next(mysh, fd, save, i));
}