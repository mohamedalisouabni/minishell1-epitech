/*
** EPITECH PROJECT, 2023
** shell
** File description:
** lib
*/
#include <stdio.h>
#include "./include/my.h"
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>

int env_btins(char **env)
{
    int i = 0;

    while (env[i]) {
        my_putstr(env[i]);
        my_putchar('\n');
        i++;
    }
    return 0;
}

int cd_btins(char **av)
{
    if (av[1] == NULL) {
        write(2, "cd: missing argument\n", 22);
    } else if (chdir(av[1]) != 0) {
        my_putstr(av[0]);
        write(2, ": No such file or directory.\n", 30);
    }
    return 1;
}

int pwd_btins(void)
{
    char *cwd = getcwd(NULL, 0);

    if (cwd != NULL)
        my_putstr(cwd);
    else
        perror("pwd");
    write(1, "\n", 1);
    return 1;
}
