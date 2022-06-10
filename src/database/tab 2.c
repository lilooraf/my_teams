/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tool_box
*/

#include "database.h"

int len(char **tab)
{
    int nb = 0;

    if (tab == NULL)
        return nb;
    else
        for (nb = 0; tab[nb]; nb++);
    return nb;
}

char **push_tab(char **tab, char *str)
{
    char **tmp = calloc(sizeof(char *), len(tab) + 2);
    int i = 0;

    if (tab == NULL) {
        tab = calloc(sizeof(char *), 2);
        tab[0] = str;
        tab[1] = NULL;
        free(tmp);
        return tab;
    } else {
        tmp = calloc(sizeof(char *), len(tab) + 2);
        for (i = 0; tab[i]; i++)
            tmp[i] = strdup(tab[i]);
        tmp[i] = str;
        tmp[i + 1] = NULL;
    }
    free(tab);
    return tmp;
}

void print_tab(char **tab)
{
    if (tab == NULL)
        return;
    for (int i = 0; tab[i]; i++)
        printf("%s\n", tab[i]);
}

char **split(char *str, char *del)
{
    char *strToken = strtok(str, del);
    char **tab = NULL;

    if (str == NULL)
        return (NULL);
    while (strToken != NULL) {
        tab = push_tab(tab, strdup(strToken));
        strToken = strtok(NULL, del);
    }
    free(strToken);
    return (tab);
}

char **cp_tab(char **tab)
{
    int size = len(tab);
    char **new = calloc(sizeof(char *), size + 2);

    for (int i = 0; i < size; i++) {
        new[i] = strdup(tab[i]);
    }
    return new;
}