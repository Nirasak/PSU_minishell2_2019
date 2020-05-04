/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** setenv
*/

#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

char *get_line_env(mysh_t *mysh)
{
    char *line =  my_malloc(
        sizeof(char) * (my_strlen(mysh->cur_cmd[1])
                        + my_strlen(mysh->cur_cmd[2]) + 3));

    line = my_strcpy(line, mysh->cur_cmd[1]);
    line[my_strlen(mysh->cur_cmd[1])] = '=';
    line[my_strlen(mysh->cur_cmd[1]) + 1] = '\0';
    line = my_strcat(line, mysh->cur_cmd[2]);
    return (line);
}

bool my_setenv(mysh_t *mysh)
{
    int i = 0;
    char *line = get_line_env(mysh);

    for (; mysh->env[i]; i++) {
        if (!my_strncmp(
                mysh->env[i], mysh->cur_cmd[1], my_strlen(mysh->cur_cmd[1]))
            && mysh->env[i][my_strlen(mysh->cur_cmd[1])] == '=') {
            free(mysh->env[i]);
            mysh->env[i] = line;
            return (true);
        }
    }
    mysh->env = realloc_tab(mysh->env, 1);
    mysh->env[i] = line;
    return (true);
}

int check_setenv(mysh_t *mysh, int i)
{
    if ((mysh->cur_cmd[1][i] > '9' && mysh->cur_cmd[1][i] < 'A')
        || (mysh->cur_cmd[1][i] > 'Z' && mysh->cur_cmd[1][i] < 'a')
        || (mysh->cur_cmd[1][i] > 'z' && mysh->cur_cmd[1][i] < '0')) {
        if (i == 0) {
            my_puterror("setenv: Variable name must begin with a letter.\n");
            return (1);
        } else {
            my_puterror(
                "setenv: Variable name must contain alphanumeric "
                "characters.\n");
            return (1);
        }
    }
    return (0);
}

bool hub_setenv(mysh_t *mysh)
{
    if (!mysh->cur_cmd[1]) {
        return (my_print_env(mysh));
    }
    if (mysh->cur_cmd[2] && mysh->cur_cmd[3]) {
        my_puterror("setenv: Too many arguments.\n");
        return (true);
    }
    for (int i = 0; mysh->cur_cmd[1][i]; i++) {
        if (check_setenv(mysh, i) == 1) {
            return (true);
        }
    }
    return (my_setenv(mysh));
}
