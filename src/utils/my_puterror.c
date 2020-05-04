/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my puterror
*/

#include <unistd.h>
#include "my_utils.h"

void my_puterror(char const *str)
{
    write(2, str, my_strlen(str));
}
