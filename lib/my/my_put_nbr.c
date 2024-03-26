/*
** EPITECH PROJECT, 2023
** putnbr
** File description:
** lib
*/
#include "../../include/my.h"

int my_put_nbr(int nb)
{
    int temp = nb;

    if (nb < 0) {
        my_putchar('-');
        nb = -temp;
    }
    if (nb >= 10) {
        temp = (nb % 10);
        nb = (nb - temp) / 10;
        my_put_nbr(nb);
        my_putchar(48 + temp);
    } else if (nb >= 0 && nb < 10) {
        temp = 48 + nb % 10;
        my_putchar(temp);
    }
    return 0;
}
