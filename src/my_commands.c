/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my commands
*/

#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

void my_exit(mysh_t *mysh)
{
    my_printf("exit\n");
    free_tab(mysh->env);
    if (!mysh->cur_cmd[1]) {
        exit(0);
    }
    exit(my_atoi(mysh->cur_cmd[1]));
}

bool my_print_env(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i]; i++) {
        my_printf("%s\n", mysh->env[i]);
    }
    return (true);
}

bool my_commands(mysh_t *mysh)
{
    if (!my_strcmp(mysh->cur_cmd[0], "exit")) {
        my_exit(mysh);
    }
    if (!my_strcmp(mysh->cur_cmd[0], "env")) {
        return (my_print_env(mysh));
    }
    if (!my_strcmp(mysh->cur_cmd[0], "unsetenv")) {
        return (my_unsetenv(mysh));
    }
    if (!my_strcmp(mysh->cur_cmd[0], "setenv")) {
        return (hub_setenv(mysh));
    }
    if (!my_strcmp(mysh->cur_cmd[0], "cd")) {
        return (my_cd(mysh));
    }
    return (false);
}
