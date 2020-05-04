/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** get from env
*/

#include "my_utils.h"
#include "mysh.h"

char *get_from_env(mysh_t *mysh, char *str)
{
    char *dest = NULL;
    int i = 0;

    for (; mysh->env[i]; i++) {
        if (!my_strncmp(mysh->env[i], str, my_strlen(str))) {
            break;
        }
    }
    if (!mysh->env[i]) {
        return (NULL);
    }
    dest = my_malloc(sizeof(char) * (my_strlen(mysh->env[i]) + 1));
    dest = my_strcpy(dest, mysh->env[i]);
    for (; *dest != '='; dest++);
    return (dest + 1);
}
