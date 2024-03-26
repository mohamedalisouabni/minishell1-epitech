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
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

char *find_var(char **env, char *var)
{
    char *key;

    for (int i = 0; env[i]; i++) {
        key = strtok(env[i], "=");
        if (my_strcmp(var, key) == 0)
            return (strtok(NULL, "\n"));
    }
    return NULL;
}

int error_handling1(char *cmd)
{
    if (cmd == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
}

char *ex_cmd(char **env, char *argv)
{
    struct stat st;
    char *path_cmd;
    char *token;
    char *cmd;

    path_cmd = find_var(env, "PATH");
    token = strtok(path_cmd, ":");
    while (token != NULL) {
        cmd = malloc(my_strlen(token) + my_strlen(argv) + 2);
        error_handling1(cmd);
        my_strcpy(cmd, token);
        my_strcat(cmd, "/");
        my_strcat(cmd, argv);
        if (stat(cmd, &st) == 0)
            return cmd;
        free(cmd);
        token = strtok(NULL, ":");
    }
    return NULL;
}

int lineform_inpt(char *com, char **tokens)
{
    int i = 0;
    char *tok;

    tok = strtok(com, " \t\r\n\a");
    while (tok != NULL) {
        tokens[i] = tok;
        tok = strtok(NULL, " \t\r\n\a");
        i++;
    }
    tokens[i] = NULL;
    return i;
}

int index_found(size_t len, char *com, char **tokens)
{
    int token_count = 0;

    for (size_t i = 0; i < len; i++) {
        if (com[i] == '\n') {
            com[i] = '\0';
            break;
        }
    }
    token_count = lineform_inpt(com, tokens);
    return token_count;
}
