/*
** EPITECH PROJECT, 2023
** putnbr
** File description:
** lib
*/
#include "../../include/my.h"

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int a = 0;

    while (src[a] != '\0') {
        dest[i] = src[a];
        i++;
        a++;
    }
    dest[i] = '\0';
    return dest;
}
