/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tool_box
*/

#include "database.h"

int check_where(char **tab, char **where)
{
    int size = len(tab);
    int size2 = len(where);
    int nb = 0, i = 0;
    char *str = NULL;
    char *str2 = NULL;
    char **tmp = clean_tab(cp_tab(tab));
    char **where2 = clean_tab(where);

    for (i = 0; i < size; i += 2) {
        for (int j = 0; j < size2; j += 2) {
            str = my_strdup(tmp[i]);
            str2 = my_strdup(tmp[i + 1]);
            if (my_strcmp(str, where2[j]) == 0 &&
            my_strcmp(str2, where2[j + 1]) == 0)
                nb++;
        }
    }
    free(str);
    free(str2);
    free(tmp);
    return (((len(where) / 2) == nb) ? 1 : 0);
}

int find_table(char **tab, char *str)
{
    int i = 0;
    char *tmp = my_strcat("\"", str);

    if (tab == NULL || str == NULL)
        return (-1);
    tmp = my_strcat(tmp, "\"");
    for (i = 0; tab[i]; i++) {
        if (strstr(tab[i], tmp) != NULL) {
            free(tmp);
            return (i);
        }
    }
    free(tmp);
    return (-1);
}

int find_table_end(char **tab, int start)
{
    if (tab == NULL || start == -1)
        return (-1);
    if (start > len(tab))
        return (-1);
    for (int i = start + 1; tab[i]; i++) {
        if (strstr(tab[i], "    ]") != NULL)
            return (i);
    }
    return (-1);
}

char **regroup(char **tab)
{
    char **tmp = NULL;
    char *str = NULL;
    int b = 0, nb = 0;

    for (int i = 0; tab[i]; i++) {
        (tab[i][0] == '[') ? b = 1 : 0;
        if (b == 1) {
            str = my_strcat(str, tab[i]);
        } else {
            nb = strlen(tab[i]) - 1;
            tab[i][nb] == ',' ? tab[i][nb] = '\0' : 0;
            (tab[i][0] != '\0') ? tmp = push_tab(tmp, tab[i]) : 0;
        }
        if (b == 1 && strstr(tab[i], "]") != NULL) {
            (str[strlen(str) - 1] == ',') ? str[strlen(str) - 1] = '\0' : 0;
            tmp = push_tab(tmp, str);
            str = NULL;
            b = 0;
        }
    }
    free(str);
    return (tmp);
}

int *getpos_delete(char **tab_cp, char *table, char **where)
{
    int start = find_table(tab_cp, table);
    int end = find_table_end(tab_cp, start);
    char **tmp = NULL;
    int *pos = calloc(sizeof(int), (end - start));
    int j = 0;

    if (end == -1)
        return (NULL);
    for (int i = start + 1; tab_cp[i] && i < end; i++) {
        tmp = getdata(tab_cp[i], NULL, where);
        (tmp != NULL) ? tmp = clean_tab(tmp) : 0;
        (tmp != NULL && strcmp(tmp[0], where[1]) == 0) ? pos[j] = i, j++ : 0;
        free_tab(tmp);
        tmp = NULL;
    }
    if (j == 0)
        return (NULL);
    return pos;
}