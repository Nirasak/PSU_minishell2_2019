/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** minishell
*/

#include <signal.h>
#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

void check_commands(mysh_t *mysh)
{
    if (check_manipulations(mysh))
        return;
    if (my_commands(mysh) == false) {
        if (my_exec_binary(mysh) == false) {
            my_exec_path(mysh);
        }
    }
}

int check_manipulations(mysh_t *mysh)
{
    int i = 0;

    for (; mysh->cur_cmd[i]; i++);
    for (i -= 1; i >= 0; i--) {
        if (!my_strcmp(mysh->cur_cmd[i], ">")) {
            return (redirect_out(mysh, mysh->cur_cmd[i + 1], i));
        }
        if (!my_strcmp(mysh->cur_cmd[i], "<")) {
            return (redirect_in(mysh, mysh->cur_cmd[i + 1], i));
        }
        if (!my_strcmp(mysh->cur_cmd[i], "|")) {
            return (my_pipe(mysh, i));
        }
    }
    return (0);
}

void minishell(mysh_t *mysh)
{
    while (1) {
        my_printf("$> ");
        signal(SIGINT, SIG_IGN);
        get_commands(mysh);
        for (int i = 0; mysh->commands[i]; i++) {
            mysh->pipe = 0;
            mysh->parse_cmd = mysh->commands[i];
            mysh->cur_cmd = mysh->commands[i];
            check_commands(mysh);
            free_tab(mysh->cur_cmd);
        }
        free(mysh->commands);
    }
}
