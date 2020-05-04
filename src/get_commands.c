/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** get commands
*/

#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

int fill_command(mysh_t *mysh, char **tab, int i, int index)
{
    int nb_words = 0;

    for (; tab[i + nb_words] && my_strcmp(tab[i + nb_words], ";"); nb_words++);
    mysh->commands[index] = my_malloc(sizeof(char *) * (nb_words + 1));
    for (int j = 0; j < nb_words; j++) {
        mysh->commands[index][j] = my_strdup(tab[i + j]);
    }
    mysh->commands[index][nb_words] = NULL;
    return (i + nb_words + 1);
}

void get_commands(mysh_t *mysh)
{
    char *input = get_input();
    char **command = input_to_command(input);
    int nb_commands = 1;
    int j = 0;

    for (int i = 0; command[i]; i++) {
        if (!my_strcmp(command[i], ";")) {
            nb_commands++;
        }
    }
    mysh->commands = my_malloc(sizeof(char **) * (nb_commands + 1));
    for (int i = 0; i < nb_commands; i++) {
        j = fill_command(mysh, command, j, i);
    }
    mysh->commands[nb_commands] = NULL;
    free(input);
    free_tab(command);
}
