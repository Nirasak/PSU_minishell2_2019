/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my malloc
*/

#include <stdlib.h>
#include "my_utils.h"

void *my_malloc(size_t size)
{
    void *data = malloc(size);

    if (!data) {
        my_puterror("Error! memory not allocated.\n");
        exit(84);
    }
    return (data);
}
