/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** cpy tab
*/

#include <stdlib.h>
#include "my_utils.h"

char **realloc_tab(char **tab, int lines)
{
    int i = 0;
    char **cpy = NULL;

    if (!tab) {
        return (NULL);
    }
    for (; tab[i]; i++);
    cpy = my_malloc(sizeof(char *) * (i + 1 + lines));
    for (i = 0; tab[i]; i++) {
        cpy[i] = my_strdup(tab[i]);
        free(tab[i]);
    }
    for (int j = 0; j <= lines; j++) {
        cpy[i + j] = NULL;
    }
    return (cpy);
}
