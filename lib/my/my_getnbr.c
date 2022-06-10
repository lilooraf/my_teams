/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** getnbr
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

int my_getnbr(char *str)
{
    int nb = 0;
    int count = 0;
    int index = 1;

    if (str == NULL)
        return (-1);
    while (sign(str[count]) == 1) {
        if (str[count] == '-')
            index = index * (-1);
        count++;
    }
    while (number(str[count]) == 1) {
        nb = ((nb * 10) + (str[count] - '0'));
        count++;
    }
    return (nb * index);
}
