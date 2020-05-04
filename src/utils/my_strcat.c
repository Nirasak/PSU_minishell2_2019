/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my strcat
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;

    for (; dest[i]; i++);
    if (src) {
        for (int j = 0; src[j]; j++) {
            dest[i] = src[j];
            i++;
        }
    }
    dest[i] = '\0';
    return (dest);
}
