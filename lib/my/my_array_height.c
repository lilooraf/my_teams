/*
** EPITECH PROJECT, 2018
** my_array_height
** File description:
** return array height
*/

#include <stddef.h>

int my_array_height(char **array)
{
    int count = 0;

    if (array == NULL)
        return 0;
    while (array[count] != NULL)
        count++;
    return (count);
}
