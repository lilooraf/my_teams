/*
** EPITECH PROJECT, 2018
** my_put_nbr_base
** File description:
** my_put_nbr_base
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_revstr(char *);

char *my_putnbr_base(int nb, char *base)
{
    int size = my_strlen(base);
    char *tab = malloc(sizeof(char) * size);
    int i = 0;
    int sign = nb;

    if (sign < 0)
        nb = nb * (-1);
    while (nb > 0) {
        tab[i] = base[nb % size];
        nb = nb / size;
        i++;
    }
    if (sign < 0)
        tab[i] = '-';
    return (my_revstr(tab));
}