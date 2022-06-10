/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** commands
*/

#include "database.h"

char *database_request_info_user(char *user_id)
{
    char *where[3] = {"id", user_id, NULL};
    table_t *user = dataselect("users", NULL, where);
    
    return cl_str(my_strcat(user_id, my_strcat(" ", my_strcat(user->data[1],
        my_strcat(" ", user->data[2])))), '"');
}

char *datebase_request_info_team(char *team_id)
{
    char *where[3] = {"id", team_id, NULL};
    table_t *team = dataselect("teams", NULL, where);
    
    return cl_str(my_strcat(team_id, my_strcat(" ", my_strcat(team->data[1],
        my_strcat(" ", team->data[2])))), '"');
}

char *database_request_info_channel(char *channel_id)
{
    char *where[3] = {"id", channel_id, NULL};
    table_t *channel = dataselect("channels", NULL, where);
    
    return cl_str(my_strcat(channel_id, my_strcat(" ", my_strcat(channel->data[1],
        my_strcat(" ", channel->data[2])))), '"');
}

char *database_request_info_thread(char *thread_id)
{
    char *where[3] = {"id", thread_id, NULL};
    table_t *thread = dataselect("threads", NULL, where);

    return cl_str(my_strcat(thread_id, my_strcat(" ", my_strcat(thread->data[1],
        my_strcat(" ", my_strcat(thread->data[3], my_strcat("$",
        my_strcat(thread->data[4], my_strcat(" ", my_strcat(thread->data[4],
        my_strcat(" ", thread->data[5])))))))))), '"');
}

char *info(char **command, st_t *st)
{
    int i = find_user(st);

    (void)command;
    if (i == -1)
        return "ERROR";
    if (st->ct[i].thread) {
        return my_strcat("INFO THREAD ",
            database_request_info_thread(st->ct[i].thread));
    }
    if (st->ct[i].chanel) {
        return my_strcat("INFO CHANNEL ",
            database_request_info_channel(st->ct[i].chanel));
    }
    if (st->ct[i].team) {
        return my_strcat("INFO TEAM ",
            datebase_request_info_team(st->ct[i].team));
    } else {
        return my_strcat("INFO USER ",
            database_request_info_user(st->ct[i].user_id));
    }
    return "ERROR EXISTS";
}