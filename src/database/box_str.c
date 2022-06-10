/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** box_str
*/

#include "database.h"

char *array_delete(char *str, char **elems)
{
    char **val = split(strdup(str), "\",[] ");

    if (str != NULL && str[0] != '[')
        return (NULL);
    if (elems == NULL)
        return (str);
    for (int i = 0; elems[i]; i += 2) {
        if (check_array_existe(val, elems[i]) >= 0)
            val = delete_val_in_array(val, elems[i]);
    }
    str = construct_array_json(val);
    free_tab(val);
    return (str);
}

char *array_update(char *str, char **elems)
{
    char **val = split(strdup(str), "\",[] ");

    if (str != NULL && str[0] != '[')
        return (NULL);
    if (elems == NULL)
        return (str);
    for (int i = 0; elems[i]; i += 2) {
        if (check_array_existe(val, elems[i]) >= 0) {
            val = delete_val_in_array(val, elems[i]);
            val = push_tab(val, elems[i + 1]);
        }
    }
    str = construct_array_json(val);
    free_tab(val);
    return (str);
}

int check_array_existe(char **val, char *elem)
{
    int nb = 0;

    for (int i = 0; val[i]; i++) {
        if (strcmp(val[i], elem) == 0)
            nb++;
    }
    return (nb);
}

char *construct_array_json(char **tab)
{
    char *str = "[";

    if (tab == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        str = my_strcat(str, "\"");
        str = my_strcat(str, my_strdup(tab[i]));
        str = my_strcat(str, "\"");
        if (tab[i + 1] != NULL)
            str = my_strcat(str, ", ");
    }
    str = my_strcat(str, "]");
    return (str);
}

char *array_instert(char *str, char **elems)
{
    char **val = split(strdup(str), "\",[] ");

    if (val == NULL)
        return (construct_array_json(elems));
    if (str != NULL && str[0] != '[')
        return (NULL);
    if (elems == NULL)
        return (str);
    for (int i = 0; elems[i]; i++) {
        if (check_array_existe(val, elems[i]) == 0)
            val = push_tab(val, elems[i]);
    }
    str = construct_array_json(val);
    free_tab(val);
    return (str);
}