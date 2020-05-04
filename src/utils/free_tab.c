/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** free tab
*/

#include <stdlib.h>

void free_tab(char **tab)
{
    for (int i = 0; tab[i]; i++) {
        free(tab[i]);
    }
    free(tab);
}
