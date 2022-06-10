/*
** EPITECH PROJECT, 2018
** my_putnbr
** File description:
** ecrire un chiffre
*/

#include <stdio.h>

void my_putchar(char c);
char *my_strdup(char *);

void my_put_nbr(int nb)
{
    int i;

    if (nb < 0) {
        my_putchar('-');
        nb = -nb;
    }
    if (nb > 9) {
        i = (nb % 10);
        nb = (nb / 10);
        my_put_nbr(nb);
        my_putchar(i + 48);
    }
    else
        my_putchar(nb + 48);
}

char *int_to_str(int nb)
{
    char id[10];

    snprintf(id, 10, "%d", nb);
    return my_strdup(id);
}