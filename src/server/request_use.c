/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_use
*/

#include "database.h"

char *request_use_team(char *team_id, char *user_id)
{
    char *where[3] = {"id", team_id, NULL};
    char *champ[2] = {"users_id", NULL};
    table_t *team = dataselect("teams", champ, where);

    if (len_list(team) == 0)
        return my_strcat("ERROR TEAM ", team_id);
    if (is_intab(split(strdup(team->data[0]), "[], \""), user_id))
        return NULL;
    return my_strcat("ERROR TEAM ", team_id);
}

char *request_use_channel(char *channel_id, char *team_id)
{
    char *where[3] = {"id", team_id, NULL};
    char *where1[3] = {"id", channel_id, NULL};
    char *champ[2] = {"channels_id", NULL};
    table_t *channel = dataselect("channels", NULL, where1);
    table_t *teams = dataselect("teams", champ, where);

    if (len_list(channel) == 0)
        return my_strcat("ERROR CHANNEL ", channel_id);
    if (is_intab(split(strdup(teams->data[0]), "[], \""), channel_id))
        return NULL;
    return my_strcat("ERROR CHANNEL ", channel_id);
}

char *request_use_thread(char *thread_id, char *channel_id)
{
    char *where[3] = {"id", thread_id, NULL};
    char *where1[3] = {"id", channel_id, NULL};
    char *champ[2] = {"thread_id", NULL};
    table_t *thread = dataselect("threads", NULL, where);
    table_t *channel = dataselect("channels", champ, where1);

    if (len_list(thread) == 0)
        return my_strcat("ERROR THREAD ", thread_id);
    if (is_intab(split(strdup(channel->data[0]), "[], \""), thread_id))
        return NULL;
    return my_strcat("ERROR THREAD ", thread_id);
}

char *database_request_use(char **path, char *user_id)
{
    char *ret = NULL;
    int size = len(path);

    if (size >= 1) {
        ret = request_use_team(path[0], user_id);
        if (ret)
            return ret;
    }
    if (size >= 2) {
        ret = request_use_channel(path[1], path[0]);
        if (ret)
            return ret;
    }
    if (size >= 3) {
        ret = request_use_thread(path[2], path[1]);
        if (ret)
            return ret;
    }
    return NULL;
}

char *use(char **command, st_t *st)
{
    int i = find_user(st);
    int size = len(command);
    char *error = NULL;

    if (command[0] == NULL) {
        st->ct[i].team = NULL;
        st->ct[i].chanel = NULL;
        st->ct[i].thread = NULL;
        return "USE OK";
    }
    error = database_request_use(command, st->ct[i].user_id);
    if (i == -1)
        return "ERROR";
    if (error)
        return error;
    if (size >= 1)
        st->ct[i].team = command[0];
    if (size >= 2)
        st->ct[i].chanel = command[1];
    if (size >= 3)
        st->ct[i].thread = command[2];
    return "USE OK";
}