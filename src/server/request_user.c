/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_user
*/

#include "database.h"

char *database_request_users()
{
    table_t *list = dataselect("users", NULL, NULL);
    char *res = NULL;

    for (; list != NULL; list = list->next) {
        for (int i = 0; list->data[i]; i++) {
            if (!i)
                res = my_strcat(my_strcat(res, " "), list->data[i]);
            else
                res = my_strcat(my_strcat(res, ";"), list->data[i]);
        }
    }
    return res;
}

char *database_request_user(char *id)
{
    char *where[3] = {"id", id, NULL};
    table_t *user = dataselect("users", NULL, where);

    if (len_list(user) == 0)
        return my_strcat("ERROR USER ", id);
    return my_strcat("USER ", my_strcat(user->data[0], my_strcat(" ", my_strcat(user->data[1], my_strcat(" ", user->data[2])))));
}

char *users(char **command, st_t *st)
{
    (void)command;
    (void)st;
    return my_strcat("USERS", cl_str(database_request_users(), '\"'));
}

char *user(char **command, st_t *st)
{
    (void)st;
    return cl_str(database_request_user(command[0]), '"');
}