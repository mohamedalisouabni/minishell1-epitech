/*
** EPITECH PROJECT, 2023
** strlen
** File description:
** task3
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i++;
    }
    return i;
}
