/*
** EPITECH PROJECT, 2019
** mysh.h
** File description:
** mysh.h
*/

#ifndef MYSH_H_
#define MYSH_H_

#define unused __attribute__((unused))

#include <stdbool.h>

typedef struct mysh
{
    char **env;
    char ***commands;
    char **parse_cmd;
    char **cur_cmd;
    int pipe;
} mysh_t;

void change_pwd(mysh_t *mysh, int i);
void get_commands(mysh_t *mysh);
char *get_from_env(mysh_t *mysh, char *str);
char *get_input(void);
bool hub_setenv(mysh_t *mysh);
char **input_to_command(char *str);
void minishell(mysh_t *mysh);
bool my_cd(mysh_t *mysh);
bool my_commands(mysh_t *mysh);
int my_execve(mysh_t *mysh, char *path);
int my_exec_binary(mysh_t *mysh);
int my_exec_path(mysh_t *mysh);
bool my_print_env(mysh_t *mysh);
bool my_unsetenv(mysh_t *mysh);
void check_commands(mysh_t *mysh);
int check_manipulations(mysh_t *mysh);
int redirect_out(mysh_t *mysh, char *file, int i);
int redirect_in(mysh_t *mysh, char *file, int i);
int my_pipe(mysh_t *mysh, int i);

#endif /* MYSH */
