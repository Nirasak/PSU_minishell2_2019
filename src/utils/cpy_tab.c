/*
** EPITECH PROJECT, 2020
** cpy_tab.c
** File description:
** cpy tab
*/

#include "my_utils.h"

char **cpy_tab(char **tab)
{
    int i = 0;
    char **cpy = NULL;

    for (; tab[i]; i++);
    cpy = my_malloc(sizeof(char *) * (i + 1));
    for (i = 0; tab[i]; i++) {
        cpy[i] = my_strdup(tab[i]);
    }
    cpy[i] = NULL;
    return (cpy);
}
