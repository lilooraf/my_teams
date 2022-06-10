/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** list
*/

#include "database.h"

void put_in_list(table_t **front_ptr, char **elem)
{
    table_t *list = malloc(sizeof(table_t));

    if (*front_ptr == NULL) {
        list->data = elem;
        list->next = NULL;
        *front_ptr = list;
        return;
    }
    list->data = elem;
    list->next = *front_ptr;
    *front_ptr = list;
}

int len_list(table_t *list)
{
    int i = 0;

    for (i = 0; list != NULL; list = list->next, i++);
    return (i);
}

char **get_data_in_the_list(table_t *list, int pos)
{
    if (list == NULL || len_list(list) < 1) {
        return (NULL);
    } else {
        for (int i = 0; list->next != NULL; list = list->next, i++)
            if (i == pos)
                return (list->data);
    }
    return (list->data);
}

void print_data_list_struct(table_t *front_ptr)
{
    table_t *list = front_ptr;

    for (; list != NULL; list = list->next) {
        print_tab(list->data);
        if (list->next != NULL)
            printf("\n");
    }
}

char **delete_val_in_array(char **tab, char *str)
{
    char **new = NULL;

    for (int i = 0; tab[i]; i++) {
        if (strcmp(tab[i], str) == 0)
            continue;
        else
            new = push_tab(new, tab[i]);
    }
    return (new);
}