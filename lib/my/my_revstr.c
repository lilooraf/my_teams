/*
** EPITECH PROJECT, 2018
** my_revstr
** File description:
** retourner une str
*/

#include "../../include/my.h"

char *my_revstr(char *str)
{
    char c = 0;

    for (int i = 0, j = my_strlen(str) - 1; i < j; i++, j--) {
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
    return (str);
}