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

int find_env_egl(char **env, int i)
{
    int start = -1;

    for (int j = 0; env[i][j] != '\0'; j++) {
        if (env[i][j] == '=') {
            start = j;
            break;
        }
    }
    return start;
}

void copy_env(env_t **envList, char **env)
{
    int index;
    int key_l;
    int value_l;
    char *key;
    char *value;

    for (int i = 0; env[i] != NULL; i++) {
        index = find_env_egl(env, i);
        if (index != -1) {
            key_l = index;
            value_l = my_strlen(env[i]) - key_l - 1;
            key = malloc(key_l + 1);
            value = malloc(value_l + 1);
            my_strncpy(key, env[i], key_l);
            key[key_l] = '\0';
            my_strncpy(value, &env[i][index + 1], value_l);
            value[value_l] = '\0';
            env_insert(envList, key, value);
        }
    }
}

void l_env(env_t *envList, char **env)
{
    env_t *current = envList;

    copy_env(&current, env);
    while (current != NULL) {
        my_putstr(current->data);
        my_putchar('=');
        my_putstr(current->value);
        my_putchar('\n');
        current = current->next;
    }
}
