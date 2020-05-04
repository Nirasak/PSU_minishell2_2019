/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** strdup
*/

#include "my_utils.h"

char *my_strdup(char const *src)
{
    char *dest = my_malloc(sizeof(char) * (my_strlen(src) + 1));

    return (my_strcpy(dest, src));
}
