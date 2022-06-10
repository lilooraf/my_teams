/*
** EPITECH PROJECT, 2019
** put int alpha
** File description:
** put in alpha
*/

#include "../../include/my.h"

void swap_two_string(char **array, int count, int point)
{
    if (my_strcmp(array[count], array[point]) > 0)
        my_swap_string(&array[count], &array[point]);
}

char **my_put_in_alpha(char **array)
{
    for (int count = 0; array[count] != NULL; count++)
        for (int point = count + 1; array[point] != NULL; point++)
            swap_two_string(array, count, point);
    return (array);
}