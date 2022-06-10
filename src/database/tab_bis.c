/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** tab_bis
*/

#include "database.h"

char **clean_tab(char **tab)
{
    int len = 0;

    if (tab == NULL)
        return (NULL);
    for (int i = 0; tab[i]; i++) {
        if (tab[i][0] == '"') {
            tab[i] = tab[i] + 1;
            tab[i] = my_strcat(tab[i], "\"");
            len = strlen(tab[i]);
            tab[i][len - 2] = '\0';
        }
    }
    return (tab);
}

char **inster_tab(char **tab, char *str, int pos)
{
    char *tmp = NULL;
    int b = 0;
    int i = 0;
    char **new = cp_tab(tab);

    if (new == NULL || str == NULL || pos < 0 || len(new) < pos)
        return (NULL);
    for (i = 0; new[i]; i++) {
        (pos == i) ? b = 1 : 0;
        if (b == 1) {
            tmp = new[i];
            new[i] = str;
            b = 2;
        } else if (b == 2) {
            str = new[i];
            new[i] = tmp;
            b = 1;
        }
    }
    new[i] = (b == 1) ? str : tmp;
    return new;
}

char **delete_line_in_table(char **tab, int *pos)
{
    char **new = calloc(sizeof(char *), len(tab));
    int k = 0;

    for (int i = 0, j = 0; tab[i]; i++) {
        if (i == pos[j]) {
            j++;
            free(tab[i]);
            continue;
        } else {
            new[k] = tab[i];
            k++;
        }
    }
    new[k ] = NULL;
    free(tab);
    return (new);
}

char **get_by_champ(char **tmp, char **str, char **champ)
{
    for (int j = 0; champ[j]; j++) {
        if (str[1] != NULL &&
        strcmp(str[0] + 1, my_strcat(champ[j], "\"")) == 0) {
            tmp = push_tab(tmp, str[1]);
        }
    }
    return tmp;
}