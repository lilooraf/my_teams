/*
** EPITECH PROJECT, 2019
** array cat
** File description:
** strcat on arrays
*/

#include "../../include/my.h"

char **cat_these_arrays(char **array1, char **array2)
{
    int size = my_array_height(array1) + my_array_height(array2);
    char **res = my_calloc(sizeof(char *), size + 2);
    int i = 0;

    for (i = 0; array1[i] != NULL; i++)
        res[i] = my_strdup(array1[i]);
    for (int j = 0; array2[j] != NULL; j++, i++)
        res[i] = my_strdup(array2[j]);
    array1 = my_arraydup(res);
    for (int count = 0; res[count]; count++)
        free(res[count]);
    free(res);
    return (array1);
}

char **array_cat(char **array1, char **array2)
{
    if (!array1 && array2)
        return (array2);
    if (!array1)
        return (NULL);
    if (!array2)
        return (array1);
    return (cat_these_arrays(array1, array2));
}
