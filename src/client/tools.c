/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** tools
*/

#include "client.h"

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

char *change_string(char *str)
{
    if (my_strlen(str) == 1 && str[0] == ' ')
        return NULL;
    for (int i = 0; str[i]; i++) {
        switch (str[i])
        {
        case ' ':
            str[i] = 11;
            break;
        case ',':
            str[i] = 12;
            break;
        case ':':
            str[i] = 8;
            break;
        default:
            break;
        }
    }
    return str;
}

char **swap_to_the_end(char **array, int i)
{
    for (; array[i + 1]; i++)
        my_swap_string(&array[i], &array[i + 1]);
    return array;
}