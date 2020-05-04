/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** execve
*/

#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

int my_waitpid(pid_t pid)
{
    int status = 0;

    waitpid(pid, &status, 0);
    if (!WIFEXITED(status)) {
        if (WTERMSIG(status) != 8) {
            my_puterror(strsignal(WTERMSIG(status)));
        }
        if (WTERMSIG(status) == 8) {
            my_puterror("Floating exception");
        }
        if (WCOREDUMP(status) == 128) {
            my_puterror(" (core dumped)");
        }
        my_puterror("\n");
    }
    return (0);
}

int my_execve(mysh_t *mysh, char *path)
{
    pid_t pid;

    pid = fork();
    if (pid == -1) {
        my_puterror("error with fork\n");
    } else if (!pid) {
        if (execve(path, mysh->cur_cmd, mysh->env) == -1) {
            my_puterror(mysh->cur_cmd[0]);
            my_puterror(": Exec format error. Wrong Architecture.\n");
            exit(1);
        }
    } else {
        my_waitpid(pid);
    }
    return (1);
}
