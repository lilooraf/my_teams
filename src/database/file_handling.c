/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** file_handeling
*/

#include "database.h"

char *read_file(char *path)
{
    FILE *fd;
    struct stat st;
    int error = stat(path, &st);
    int size = 0;
    char *str = NULL;

    if (error == -1) {
        datareset();
        if (stat(path, &st) == -1)
            exit(84);
    }
    fd = fopen(path, "r");
    if (fd == NULL)
        printf("Could not open file %s", path);
    size = st.st_size;
    str = calloc(sizeof(char), size + 1);
    read(fileno(fd), str, size);
    fclose(fd);
    return str;
}

void put_in_file_pos(char *str, int pos)
{
    char *path = DATABASE_NAME;
    char *file = read_file(path);
    char **tab = split(file, "\n");

    tab = inster_tab(tab, str, pos);
    remove(path);
    FILE *fp = fopen(path, "ab");
    if (fp != NULL) {
        for (int i = 0; tab[i]; i++)
            fputs(my_strcat(tab[i], "\n"), fp);
        fclose(fp);
    }
}

void put_in_file(char **tab)
{
    if (tab != NULL)
        remove(DATABASE_NAME);
    FILE *fp = fopen(DATABASE_NAME, "ab");
    if (fp != NULL && tab != NULL) {
        for (int i = 0; tab[i]; i++)
            fputs(my_strcat(tab[i], "\n"), fp);
        fclose(fp);
    }
}

char *data_json_code(char **data, int start, int end)
{
    char *str = "        {\"";
    int i = 0;

    for (i = 0; data[i]; i += 2) {
        str = my_strcat(my_strcat(my_strcat(str, data[i]), "\""), ": ");
        if (data[i + 1][0] == '[') {
            str = my_strcat(str, data[i + 1]);
            (data[i + 2] != NULL) ? str = my_strcat(str, ", ") : 0;
        } else {
            str = my_strcat(str, "\"");
            str = my_strcat(str, data[i + 1]);
            (data[i + 2] != NULL) ? str = my_strcat(str, "\", ") : 0;
        }
        if (data[i + 2] != NULL)
            str = my_strcat(str, "\"");
    }
    str = data[i - 1][0] != '[' ? my_strcat(str, "\"}") : my_strcat(str, "}");
    (end - start != 1) ? str = my_strcat(str, ",") : 0;
    return str;
}

char **updatedata_in_table(char **tab, char **champ)
{
    for (int i = 2; tab[i]; i += 2) {
        for (int j = 0; champ[j]; j += 2) {
            if (strcmp(tab[i], champ[j]) == 0) {
                free(tab[i + 1]);
                tab[i + 1] = strdup(champ[j + 1]);
            }
        }
    }
    return tab;
}