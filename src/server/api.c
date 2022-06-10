/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** api
*/

#include "api.h"
#include "database.h"
#include <stdlib.h>

void get_ids(unique_uuid_t *uuid)
{
    table_t *list = dataselect("users", NULL, NULL);

    for (int i = 0; list != NULL; list = list->next)
        if ((i = atoi(cl_str(list->data[0], '\"'))) > uuid->users_id)
            uuid->users_id = i;
    list = dataselect("teams", NULL, NULL);
    for (int i = 0; list != NULL; list = list->next)
        if ((i = atoi(cl_str(list->data[0], '\"'))) > uuid->teams_id)
            uuid->teams_id = i;
    list = dataselect("channels", NULL, NULL);
    for (int i = 0; list != NULL; list = list->next)
        if ((i = atoi(cl_str(list->data[0], '\"'))) > uuid->channels_id)
            uuid->channels_id = i;
    list = dataselect("threads", NULL, NULL);
    for (int i = 0; list != NULL; list = list->next)
        if ((i = atoi(cl_str(list->data[0], '\"'))) > uuid->threads_id)
            uuid->threads_id = i;
    list = dataselect("messages", NULL, NULL);
    for (int i = 0; list != NULL; list = list->next)
        if ((i = atoi(cl_str(list->data[0], '\"'))) > uuid->messages_id)
            uuid->messages_id = i;
}

char *api(char **command, st_t *st)
{
    char *response;

    for (int i = 0; types[i].command; i++) {
        if (!strcmp(types[i].command, command[0])) {
            response = types[i].fonction(command + 1, st);
            break;
        }
    }
    return (response) ? response : "FAILURE";
}

int find_user(st_t *st)
{
    for (int i = 0; i < st->max; i++)
        if (st->ct[i].id == st->desc)
            return i;
    return -1;
}