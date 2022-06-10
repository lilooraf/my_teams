/*
** EPITECH PROJECT, 2018
** get_unsnbr
** File description:
** get unsigned number
*/

#include <stdio.h>

int sign(char c)
{
    if (c == '-' || c == '+')
        return (1);
    else
        return (0);
}

int number(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int negativ_or_positiv(int nbr)
{
    if (nbr < 0)
        return (-1);
    else
        return (nbr);
}

int my_get_unsnbr(char *str)
{
    int nb = 0;
    int count = 0;
    int index = 1;

    while (sign(str[count]) == 1) {
        if (str[count] == '-')
            index = index * (-1);
        count++;
    }
    while (number(str[count]) == 1) {
        nb = ((nb * 10) + (str[count] - '0'));
        count++;
    }
    nb = negativ_or_positiv((nb * index));
    return (nb);
}
