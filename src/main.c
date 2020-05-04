/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "my_utils.h"
#include "mysh.h"

void create_env(mysh_t *mysh)
{
    mysh->env = my_malloc(sizeof(char *) * 12);
    mysh->env[0] = my_strdup("HOSTTYPE=x86_64-linux");
    mysh->env[1] = my_strdup("VENDOR=unknow");
    mysh->env[2] = my_strdup("OSTYPE=linux");
    mysh->env[3] = my_strdup("MATCHTYPE=x86_64");
    mysh->env[4] = my_strdup("SHLVL=1");
    mysh->env[5] = my_strdup("LOGNAME=nallain");
    mysh->env[6] = my_strdup("USER=nallain");
    mysh->env[7] = my_strdup("GROUP=nallain");
    mysh->env[8] = my_strdup("HOST=localdomain");
    mysh->env[9] = my_strdup("HOME=/home/nallain");
    mysh->env[10] =
        my_strdup("PATH=/home/nallain/bin:/usr/local/bin:/usr/bin:/bin");
    mysh->env[11] = NULL;
    change_pwd(mysh, 11);
}

int main(int ac, char unused **av, char **env)
{
    mysh_t mysh;

    if (ac != 1) {
        return (84);
    }
    if (!env[0]) {
        create_env(&mysh);
    } else {
        mysh.env = cpy_tab(env);
    }
    minishell(&mysh);
    return (0);
}
