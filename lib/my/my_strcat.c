/*
** EPITECH PROJECT, 2018
** my_strcat
** File description:
** my_strcat
*/

#include "../../include/my.h"

int my_strlen(char *str);

void *my_calloc(size_t elem_size, size_t elems);

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;
    int s = 0;
    char *new = NULL;

    if (dest == NULL && src != NULL)
        return (src);
    if (dest != NULL && src == NULL)
        return (dest);
    if (dest == NULL && src == NULL)
        return (NULL);
    for (i = 0; dest[i] != '\0'; i++);
    for (j = 0; src[j] != '\0'; j++);
    new = calloc(sizeof(char), (i + j + 4));
    for (j = 0; dest[j] != '\0'; j++, s++)
        new[s] = dest[j];
    for (j = 0; src[j] != '\0'; j++, s++)
        new[s] = src[j];
    new[s] = '\0';
    return (new);
}