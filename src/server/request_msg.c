/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_user
*/

#include "database.h"

char **create_message_array(char *id, char *message,
    char *recv_id, unique_uuid_t *uuid)
{
    char **msg = my_calloc(13, sizeof(char *));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    msg[0] = my_strdup("id");
    msg[1] = int_to_str(++uuid->messages_id);
    msg[2] = my_strdup("sender_id");
    msg[3] = my_strdup(id);
    msg[4] = my_strdup("recv_id");
    msg[5] = my_strdup(recv_id);
    msg[6] = my_strdup("date");
    msg[7] = my_strcat(int_to_str(tm.tm_mday), my_strcat("/",
        my_strcat(int_to_str(tm.tm_mon + 1), my_strcat("/",
        int_to_str(tm.tm_year + 1900)))));
    msg[8] = my_strdup("time");
    msg[9] = my_strcat(int_to_str(tm.tm_hour), my_strcat("-",
        (int_to_str(tm.tm_min))));
    msg[10] = my_strdup("message");
    msg[11] = my_strdup(message);
    msg[12] = NULL;
    return msg;
}

char *database_request_send(char *id, char *message,
    char *recv_id, unique_uuid_t *uuid)
{
    char *where[3] = {"id", id, NULL};
    table_t *user = dataselect("users", NULL, where);
    char *where1[3] = {"id", recv_id, NULL};
    table_t *user2 = dataselect("users", NULL, where1);

    if (len_list(user) == 0)
        return my_strcat("ERROR USER ", id);
    if (len_list(user2) == 0)
        return my_strcat("ERROR USER ", recv_id);
    datainsert("messages", create_message_array(id, message,
        recv_id, uuid));
    return "OK";
}

char *database_request_messages(char *current_id, char *id)
{
    char *where[3] = {"id", id, NULL}, *res = NULL;
    table_t *user = dataselect("users", NULL, where);
    char *where1[5] = {"sender_id", id, "recv_id", current_id, NULL};
    table_t *msg = dataselect("messages", NULL, where1);

    if (len_list(user) == 0)
        return my_strcat("ERROR USER ", id);
    if (len_list(msg) == 0)
        return NULL;
    for (; msg != NULL; msg = msg->next)
        for (int i = 0; msg->data[i]; i++) {
            if (i == 0 || i == 2)
                continue;
            if (i == 1)
                res = my_strcat(my_strcat(res, " "), msg->data[i]);
            else if (i == 4)
                res = my_strcat(my_strcat(res, "$"), msg->data[i]);
            else
                res = my_strcat(my_strcat(res, ";"), msg->data[i]);
        }
    return cl_str(res, '\"');
}

char *_send(char **command, st_t *st)
{
    int i = find_user(st);
    char *ret = database_request_send(st->ct[i].user_id, command[1],
        command[0], st->uuid);

    if (my_strcmp(split(my_strdup(ret), " ")[0], "ERROR") == 0)
        return ret;
    server_event_private_message_sended(st->ct[i].user_id, command[0], command[1]);
    return my_strcat("SEND ", ret);
}

char *message(char **command, st_t *st)
{
    int i = find_user(st);
    char *ret = database_request_messages(st->ct[i].user_id, command[0]);

    if (ret == NULL)
        return "MSG";
    if (my_strcmp(split(my_strdup(ret), " ")[0], "ERROR") == 0)
        return ret;
    return my_strcat("MSG", ret);
}