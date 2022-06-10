/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_create
*/

#include "database.h"

char *database_request_create_reply(char *thread_id, char **command,
    char *user_id)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *date = my_strcat(int_to_str(tm.tm_mday), my_strcat("/",
        my_strcat(int_to_str(tm.tm_mon + 1), my_strcat("/",
        int_to_str(tm.tm_year + 1900)))));
    char *time = my_strcat(int_to_str(tm.tm_hour), my_strcat("-",
        (int_to_str(tm.tm_min))));

    datainsert("reply", create_reply_array(thread_id, command, user_id));
    server_event_thread_new_message(thread_id, user_id, command[0]);
    return my_strcat(thread_id, my_strcat(" ",
        my_strcat(user_id , my_strcat(" ", my_strcat(date, my_strcat("$",
        my_strcat(time, my_strcat(" ", command[0]))))))));
}

char *database_request_create_thread(char *channel_id, char **command,
    unique_uuid_t *uuid, char *user_id)
{
    char *id = int_to_str(++uuid->threads_id);
    char *val[2] = {id, NULL};
    char *where1[3] = {"id", channel_id, NULL};
    char *champ[2] = {"thread_id", NULL};
    table_t *channel = dataselect("channels", champ, where1);
    char *where[3] = {"thread_id", array_instert(channel->data[0], val), NULL};
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char *date = my_strcat(int_to_str(tm.tm_mday), my_strcat("/",
        my_strcat(int_to_str(tm.tm_mon + 1), my_strcat("/",
        int_to_str(tm.tm_year + 1900)))));
    char *time = my_strcat(int_to_str(tm.tm_hour), my_strcat("-",
        (int_to_str(tm.tm_min))));

    datainsert("threads", create_thread_array(command, uuid, user_id));
    dataupdate("channels", where, where1);
    server_event_thread_created(channel_id, id, user_id, command[1]);
    return my_strcat(id, my_strcat(" ",
        my_strcat(user_id , my_strcat(" ", my_strcat(date, my_strcat("$",
        my_strcat(time, my_strcat(" ", my_strcat(command[0], my_strcat(" ",
        command[1]))))))))));
}

char *database_request_create_channel(char *team_id, char **command,
    unique_uuid_t *uuid)
{
    char **data = calloc(sizeof(char *), 10);
    char *id = int_to_str(++uuid->channels_id);
    char *val[2] = {id, NULL};
    char *where1[3] = {"id", team_id, NULL};
    char *champ[2] = {"channels_id", NULL};
    table_t *team = dataselect("teams", champ, where1);
    char *where[3] = {"channels_id", array_instert(team->data[0], val), NULL};

    data[0] = "id";
    data[1] = id;
    data[2] = "name";
    data[3] = command[0];
    data[4] = "description";
    data[5] = command[1];
    data[6] = "thread_id";
    data[7] = "[]";
    datainsert("channels", data);
    dataupdate("teams", where, where1);
    server_event_channel_created(team_id, id, command[0]);
    return my_strcat(id, my_strcat(" ", my_strcat(command[0],
        my_strcat(" ", command[1]))));
}

char *database_request_create_team(char *user_id, char **command,
    unique_uuid_t *uuid)
{
    char **data = calloc(sizeof(char * ), 10);

    data[0] = "id";
    data[1] = int_to_str(++uuid->teams_id);
    data[2] = "name";
    data[3] = strdup(command[0]);
    data[4] = "description";
    data[5] = strdup(command[1]);
    data[6] = "channels_id";
    data[7] = "[]";
    data[8] = "users_id";
    data[9] = my_strcat(my_strcat("[\"", user_id), "\"]");
    datainsert("teams", data);
    server_event_team_created(int_to_str(uuid->teams_id), command[0], user_id);
    return my_strcat(int_to_str(uuid->teams_id), my_strcat(" ",
        my_strcat(command[0], my_strcat(" ", command[1]))));
}

char *create(char **command, st_t *st)
{
    int i = find_user(st);

    if (i == -1)
        return "ERROR";
    if (st->ct[i].thread)
        return my_strcat("CREATE REPLY ",
            database_request_create_reply(st->ct[i].thread,
            command, st->ct[i].user_id));
    if (st->ct[i].chanel)
        return my_strcat("CREATE THREAD ",
            database_request_create_thread(st->ct[i].chanel,
            command, st->uuid, st->ct[i].user_id));
    if (st->ct[i].team)
        return my_strcat("CREATE CHANNEL ",
            database_request_create_channel(st->ct[i].team,
            command, st->uuid));
    else
        return my_strcat("CREATE TEAM ",
            database_request_create_team(st->ct[i].user_id,
            command, st->uuid));
    return "ERROR EXISTS";
}
