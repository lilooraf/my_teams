/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** compter le nombre de caractere dans un string
*/

#include <stdio.h>

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}
