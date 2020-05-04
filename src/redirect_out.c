/*
** EPITECH PROJECT, 2020
** minishell2
** File description:
** redirect_out
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include "my_utils.h"
#include "mysh.h"

int redirect_out_end(mysh_t *mysh, int fd_file, int keep_fd)
{
    if (dup2(fd_file, STDOUT_FILENO) == -1) {
        my_puterror(strerror(errno));
        return (1);
    }
    check_commands(mysh);
    close(fd_file);
    if (dup2(keep_fd, STDOUT_FILENO) == -1) {
        my_puterror(strerror(errno));
        return (1);
    }
    close(keep_fd);
    return (1);
}

int redirect_out(mysh_t *mysh, char *file, int i)
{
    int fd_file = 0;
    int keep_fd = dup(STDOUT_FILENO);

    if (!file) {
        return (1);
    }
    if (keep_fd == -1) {
        my_puterror(strerror(errno));
        return (1);
    }
    fd_file = open(file, O_CREAT | O_RDWR | O_TRUNC, 00664);
    if (fd_file == -1) {
        my_puterror(strerror(errno));
        return (1);
    }
    remove_str_from_tab(mysh->cur_cmd, i);
    remove_str_from_tab(mysh->cur_cmd, i);
    return (redirect_out_end(mysh, fd_file, keep_fd));
}