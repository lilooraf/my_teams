/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** database C
*/

#include "database.h"

table_t *dataselect(char *table, char **champ, char **where)
{
    char *path = DATABASE_NAME;
    char *file = read_file(path);
    char **tab = split(my_strdup(file), "\n");
    int start = find_table(tab, table);
    int end = find_table_end(tab, start);
    char **tmp = NULL;
    table_t *return_data = NULL;

    for (int i = start + 1; tab[i] && i < end; i++) {
        tmp = getdata(tab[i], champ, where);
        if (tmp != NULL)
            put_in_list(&return_data, tmp);
        tmp = NULL;
    }
    free_tab(tab);
    free(file);
    return (return_data);
}

void datainsert(char *table, char **data)
{
    char *path = DATABASE_NAME;
    char *file = read_file(path);
    char **tab = split(my_strdup(file), "\n");
    int start = find_table(tab, table);
    int end = find_table_end(tab, start);

    char *str = data_json_code(data, start, end);
    put_in_file_pos(str, start + 1);
}

void datareset()
{
    char *file = read_file(DATABASE_RESET);
    char **tab = split(my_strdup(file), "\n");

    remove(DATABASE_NAME);
    FILE *fp = fopen(DATABASE_NAME, "ab");
    if (fp != NULL) {
        for (int i = 0; tab[i]; i++)
            fputs(my_strcat(tab[i], "\n"), fp);
        fclose(fp);
    }
}

void datadelete(char *table, char **where)
{
    char *path = DATABASE_NAME;
    char *file = read_file(path);
    char **tab = split(my_strdup(file), "\n");
    int *pos = NULL;
    char **tab_cp = cp_tab(tab);

    if (where == NULL)
        return;
    pos = getpos_delete(tab_cp, table, where);
    if (pos == NULL)
        return;
    tab = delete_line_in_table(tab, pos);
    put_in_file(tab);
    free_tab(tab);
    free_tab(tab_cp);
}

void dataupdate(char *table, char **champ, char **where)
{
    char **tab = split(read_file(DATABASE_NAME), "\n");
    int start = find_table(tab, table);
    int end = find_table_end(tab, start);
    char **tmp = NULL;
    char **data = NULL;

    for (int i = start + 1; tab[i] && i < end; i++) {
        if (where != NULL)
            tmp = getdatabrut(tab[i], NULL, where);
        if (tmp != NULL && where != NULL) {
            tmp = clean_tab(tmp);
            data = updatedata_in_table(tmp, champ);
            datadelete(table, where);
            datainsert(table, data);
            data = NULL;
        }
        tmp = NULL;
    }
    free_tab(data);
    free_tab(tab);
    free_tab(tmp);
}