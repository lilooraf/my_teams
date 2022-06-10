/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** server_func
*/

#include "database.h"

void error(const char *msg)
{
    printf("%s\n", msg);
    exit(84);
}

void rightclose(int sig)
{
    (void)sig;
    int descServ = 0;
    char *champ[3] = {"connected", "0", NULL};
    char *champ1[2] = {"id", NULL};
    table_t *users = dataselect("users", champ1, NULL);

    for (; users != NULL; users = users->next)
        dataupdate("users", champ,
            my_str_to_word_array(my_strcat("\"id\" ", users->data[0]), ' '));
    if (close(descServ) != -1)
    exit(0);
}