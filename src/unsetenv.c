/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** unsetenv
*/

#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

bool my_unsetenv(mysh_t *mysh)
{
    bool status = false;

    if (!mysh->cur_cmd[1]) {
        my_puterror("unsetenv: Too few arguments.\n");
        return (true);
    }
    for (int i = 0; mysh->env[i]; i++) {
        if (!my_strncmp(
                mysh->env[i], mysh->cur_cmd[1], my_strlen(mysh->cur_cmd[1]))
            && mysh->env[i][my_strlen(mysh->cur_cmd[1])] == '=') {
            free(mysh->env[i]);
            status = true;
        }
        if (status == true) {
            mysh->env[i] = mysh->env[i + 1];
        }
    }
    return (true);
}
