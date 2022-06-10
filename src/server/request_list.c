/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_list
*/

#include "database.h"

char *database_request_list_team()
{
    table_t *teams = dataselect("teams", NULL, NULL);
    char *res = NULL;

    if (len_list(teams) == 0)
        return "";
    for (; teams != NULL; teams = teams->next)
        for (int i = 0; teams->data[i] && i <= 2; i++) {
            if (i == 0)
                res = my_strcat(my_strcat(res, " "), teams->data[i]);
            else
                res = my_strcat(my_strcat(res, ";"), teams->data[i]);
        }
    return cl_str(res, '\"');
}

char *database_request_list_channel(char *team_id)
{
    char **where1 = calloc(3, sizeof(char *));
    char *res = NULL;
    char *where[3] = {"id", team_id, NULL};
    char *champ[2] = {"channels_id", NULL};
    table_t *team = dataselect("teams", champ, where);
    table_t *channel = NULL;
    if (len_list(team) == 0 || !my_strcmp(team->data[0], "[]"))
        return "";
    char **list_id_channel = split(strdup(team->data[0]), "[] ,\"");

    where1[0] = "id";
    for (int i = 0; list_id_channel[i]; i++) {
        where1[1] = list_id_channel[i];
        channel = dataselect("channels", NULL, where1);
        for (int j = 0; channel->data[i] && j <= 2; j++) {
            if (j == 0)
                res = my_strcat(my_strcat(res, " "), channel->data[j]);
            else
                res = my_strcat(my_strcat(res, ";"), channel->data[j]);
        }
    }
    return cl_str(res, '\"');
}

char *database_request_list_thread(char *id_channel)
{
    char **where1 = calloc(3, sizeof(char *)), *res = NULL;
    char *where[3] = {"id", id_channel, NULL};
    char *champ[2] = {"thread_id", NULL};
    table_t *threads = dataselect("channels", champ, where);
    table_t *thread = NULL;
    if (len_list(threads) == 0 || !my_strcmp(threads->data[0], "[]"))
        return "";
    char **list_id_thread = split(strdup(threads->data[0]), "[] ,\"");

    where1[0] = "id";
    for (int i = 0; list_id_thread[i]; i++) {
        where1[1] = list_id_thread[i];
        thread = dataselect("threads", NULL, where1);
        for (int j = 0; thread->data[i] && j <= 5; j++) {
            if (j == 3) {
                res = my_strcat(my_strcat(res, "$"), thread->data[j]);
                continue;
            }
            if (j == 0)
                res = my_strcat(my_strcat(res, " "), thread->data[j]);
            else
                res = my_strcat(my_strcat(res, ";"), thread->data[j]);
        }
    }
    return cl_str(res, '\"');
}

char *database_request_list_reply(char *id_thread)
{
    char *where[3] = {"thread_id", id_thread, NULL};
    char *res = NULL;
    table_t *reply = dataselect("reply", NULL, where);

    for (; reply; reply = reply->next) {
        for (int j = 0; reply->data[j] && j <= 4; j++) {
            if (j == 3) {
                res = my_strcat(my_strcat(res, "$"), reply->data[j]);
                continue;
            }
            if (j == 0)
                res = my_strcat(my_strcat(res, " "), reply->data[j]);
            else
                res = my_strcat(my_strcat(res, ";"), reply->data[j]);
        }
    }
    return cl_str(res, '\"');
}

char *list(char **command, st_t *st)
{
    int i = find_user(st);

    (void)command;
    if (i == -1)
        return "ERROR";
    if (st->ct[i].thread) {
        return my_strcat("LIST REPLY",
            database_request_list_reply(st->ct[i].thread));
    }
    if (st->ct[i].chanel) {
        return my_strcat("LIST THREAD",
            database_request_list_thread(st->ct[i].chanel));
    }
    if (st->ct[i].team) {
        return my_strcat("LIST CHANNEL",
            database_request_list_channel(st->ct[i].team));
    } else {
        return my_strcat("LIST TEAM",
            database_request_list_team());
    }
    return "ERROR EXISTS";
}