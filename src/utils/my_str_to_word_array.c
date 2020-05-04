/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** str to word array
*/

#include "my_utils.h"

int count_words(char const *str, char c)
{
    int count = 0;

    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return (count);
}

char **my_str_to_word_array(char const *str, char c)
{
    int count = count_words(str, c);
    int j = 0;
    int x = 0;
    char **array = my_malloc(sizeof(char *) * (count + 2));

    for (int i = 0; str[i]; j++) {
        for (; str[i] == c && str[i]; i++);
        if (!str[i] || !array) {
            break;
        }
        for (x = i; str[x] != c && str[x]; x++);
        array[j] = my_malloc(sizeof(char) * (x - i + 2));
        for (x = 0; str[i] != c && str[i]; i++) {
            array[j][x] = str[i];
            x++;
        }
        array[j][x] = '\0';
    }
    array[j] = NULL;
    return (array);
}
