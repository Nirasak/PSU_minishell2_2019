/*
** EPITECH PROJECT, 2019
** my_utils.h
** File description:
** my_utils.h
*/

#ifndef MY_UTILS_H_
#define MY_UTILS_H_

#include <stddef.h>

void my_printf(char *str, ...);
char **cpy_tab(char **tab);
void free_tab(char **tab);
int my_atoi(char const *str);
void *my_malloc(size_t size);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char const *str);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strcat(char *dest, char const *src);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
char **my_str_to_word_array(char const *str, char c);
void my_puterror(char const *str);
char **realloc_tab(char **tab, int lines);
char **remove_str_from_tab(char **tab, int i);

#endif /* MY_UTILS */
