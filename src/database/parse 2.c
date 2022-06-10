/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** parse
*/

#include "database.h"

char **getdata(char *str, char **champ, char **where)
{
    char **tab = split(my_strdup(str), "{}: ");
    char **group = regroup(tab);
    int b = (where == NULL) ? 1 : check_where(group, where);
    char **tmp = NULL;
    char **tmp2 = NULL;
    int size = len(tab);

    if (b == 0)
        return (NULL);
    for (int i = 0; group[i] && i < size; i += 2) {
        if (champ == NULL) {
            tmp = push_tab(tmp, group[i + 1]);
            continue;
        }
        tmp2 = push_tab(tmp2, group[i]);
        tmp2 = push_tab(tmp2, group[i + 1]);
        tmp = get_by_champ(tmp, tmp2, champ);
        tmp2 = NULL;
    }
    free(tmp2);
    return tmp;
}

char **getdatabrut(char *str, char **champ, char **where)
{
    char **tab = split(my_strdup(str), "{}: ");
    char **group = regroup(tab);
    int b = check_where(group, where);
    char **tmp = NULL;
    char **tmp2 = NULL;
    int size = len(tab);

    if (b == 0)
        return (NULL);
    return (group);
    for (int i = 0; group[i] && i < size; i += 2) {
        if (champ == NULL) {
            tmp = push_tab(tmp, group[i + 1]);
            continue;
        }
        tmp2 = push_tab(tmp2, group[i]);
        tmp2 = push_tab(tmp2, group[i + 1]);
        tmp = get_by_champ(tmp, tmp2, champ);
        tmp2 = NULL;
    }
    free(tmp2);
    return tmp;
}