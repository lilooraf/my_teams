/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** free_tool_box
*/

#include "database.h"

void free_tab(char **tab)
{
    if (tab == NULL) {
        free(tab);
        return;
    }
    for (int i = 0; tab[i + 1] != NULL; i++)
        free(tab[i]);
    free(tab);
}

void free_data_list_struct(table_t *front_ptr)
{
    table_t *list = front_ptr;

    for (; list != NULL; list = list->next) {
        free_tab(list->data);
    }
}