/*
** EPITECH PROJECT, 2018
** my_strcpy
** File description:
** task 01 Day 06 thomas contini
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char *str)
{
    int i = 0;

    if (str == NULL)
        return (NULL);
    while (str[i] != '\0') {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
