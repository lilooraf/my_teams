/*
** EPITECH PROJECT, 2019
** my_strcmp.c
** File description:
** my_strcmp
*/

#include "../../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    if (!s1 || !s2)
        return 0;
    while (s1[i] && (s1[i] == s2[i]))
        i++;
    return s1[i] - s2[i];
}
