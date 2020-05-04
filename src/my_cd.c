/*
** EPITECH PROJECT, 2020
** minishell
** File description:
** my cd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my_utils.h"
#include "mysh.h"

void change_pwd(mysh_t *mysh, int i)
{
    char *str = my_malloc(sizeof(char) * 1024);

    if (!getcwd(str, 1024)) {
        return;
    }
    if (mysh->env[i]) {
        free(mysh->env[i]);
    } else {
        mysh->env = realloc_tab(mysh->env, 1);
    }
    mysh->env[i] = my_malloc(sizeof(char) * (my_strlen(str) + 5));
    mysh->env[i] = my_strcpy(mysh->env[i], "PWD=");
    mysh->env[i] = my_strcat(mysh->env[i], str);
    free(str);
}

void change_oldpwd(mysh_t *mysh)
{
    int i = 0;
    int j = 0;

    for (; mysh->env[i] && my_strncmp(mysh->env[i], "PWD", 3); i++);
    for (; mysh->env[j] && my_strncmp(mysh->env[j], "OLDPWD", 6); j++);
    if (!mysh->env[i]) {
        change_pwd(mysh, i);
        return;
    }
    if (mysh->env[j]) {
        free(mysh->env[j]);
    } else {
        mysh->env = realloc_tab(mysh->env, 1);
    }
    mysh->env[j] = my_malloc(sizeof(char) * (my_strlen(mysh->env[i]) + 4));
    mysh->env[j] = my_strcpy(mysh->env[j], "OLD");
    mysh->env[j] = my_strcat(mysh->env[j], mysh->env[i]);
    change_pwd(mysh, i);
}

void check_dir(mysh_t *mysh)
{
    struct stat st;

    if (chdir(mysh->cur_cmd[1]) != -1)
        return;
    my_puterror(mysh->cur_cmd[1]);
    if (lstat(mysh->cur_cmd[1], &st) != -1
        && (st.st_mode & S_IFMT) != S_IFDIR) {
        my_puterror(": Not a directory.\n");
    } else {
        my_puterror(": No such file or directory.\n");
    }
}

bool my_cd(mysh_t *mysh)
{
    if (mysh->cur_cmd[2]) {
        my_puterror("cd: Too many arguments.\n");
        return (true);
    }
    if (!mysh->cur_cmd[1] || !my_strcmp(mysh->cur_cmd[1], "~")) {
        if (chdir(get_from_env(mysh, "HOME")) == -1) {
            my_puterror("cd: No HOME in env.\n");
        }
    } else if (!my_strcmp(mysh->cur_cmd[1], "-")) {
        if (chdir(get_from_env(mysh, "OLDPWD")) == -1) {
            my_puterror(": No such file or directory.\n");
        }
    } else {
        check_dir(mysh);
    }
    change_oldpwd(mysh);
    return (true);
}
