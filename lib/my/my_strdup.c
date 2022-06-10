/*
** EPITECH PROJECT, 2018
** my_strdup
** File description:
** task01 Day08
*/

#include "../../include/my.h"

char *my_strcpy(char *dest, char *str);

char *my_strdup(char *src)
{
    char *dest;
    int i = 0;

    while (src[i] != '\0')
        i++;
    dest = my_calloc(sizeof(char), (i + 1));
    dest = my_strcpy(dest, src);
    return (dest);
}
