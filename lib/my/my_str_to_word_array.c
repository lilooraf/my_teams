/*
** EPITECH PROJECT, 2019
** my_str_to_word_array
** File description:
** str to word array
*/

#include "../../include/my.h"

char **my_str_to_word_array(char *str, char stop)
{
    int j = 2;
    int size = 0;
    char **dest = NULL;

    for (int i = 0; str[i] != 0; i++)
        if (str[i] == stop)
            j++;
    dest = malloc(sizeof(char *) * j);
    for (j = 0; str[0] != 0; j++) {
        if (str[0] == stop)
            str = str + 1;
        for (size = 0; str[size] != stop && str[size]; size++);
        dest[j] = calloc(sizeof(char), size + 1);
        for (size = 0; str[size] != stop && str[size]; size++)
            dest[j][size] = str[size];
        str = str + size;
    }
    dest[j] = NULL;
    return (dest);
}
