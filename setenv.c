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

int env_insert(env_t **ht, char *key, char *value)
{
    env_t *insrt = malloc(sizeof(env_t));
    env_t *insrt_end;

    insrt->data = malloc(strlen(key) + 1);
    insrt->value = malloc(strlen(value) + 1);
    my_strcpy(insrt->data, key);
    my_strcpy(insrt->value, value);
    insrt->next = NULL;
    insrt->prev = NULL;
    if (*ht == NULL)
        *ht = insrt;
    else {
        insrt_end = *ht;
        while (insrt_end->next != NULL) {
            insrt_end = insrt_end->next;
        }
        insrt_end->next = insrt;
        insrt->prev = insrt_end;
    }
    return 0;
}
