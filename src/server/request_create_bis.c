/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_create
*/

#include "database.h"

char **create_reply_array(char *thread_id, char **command, char *user_id)
{
    char **reply = calloc(11, sizeof(char *));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    reply[0] = my_strdup("thread_id");
    reply[1] = thread_id;
    reply[2] = my_strdup("user_id");
    reply[3] = my_strdup(user_id);
    reply[4] = my_strdup("date");
    reply[5] = my_strcat(int_to_str(tm.tm_mday), my_strcat("/",
        my_strcat(int_to_str(tm.tm_mon + 1), my_strcat("/",
        int_to_str(tm.tm_year + 1900)))));
    reply[6] = my_strdup("time");
    reply[7] = my_strcat(int_to_str(tm.tm_hour), my_strcat("-",
        (int_to_str(tm.tm_min))));
    reply[8] = my_strdup("body");
    reply[9] = my_strdup(command[0]);
    return reply;
}

char **create_thread_array(char **command, unique_uuid_t *uuid, char *user_id)
{
    char **thread = calloc(13, sizeof(char *));
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    thread[0] = my_strdup("id");
    thread[1] = int_to_str(uuid->threads_id);
    thread[2] = my_strdup("user_id");
    thread[3] = my_strdup(user_id);
    thread[4] = my_strdup("date");
    thread[5] = my_strcat(int_to_str(tm.tm_mday), my_strcat("/",
        my_strcat(int_to_str(tm.tm_mon + 1), my_strcat("/",
        int_to_str(tm.tm_year + 1900)))));
    thread[6] = my_strdup("time");
    thread[7] = my_strcat(int_to_str(tm.tm_hour), my_strcat("-",
        (int_to_str(tm.tm_min))));
    thread[8] = my_strdup("title");
    thread[9] = my_strdup(command[0]);
    thread[10] = my_strdup("body");
    thread[11] = my_strdup(command[1]);
    return thread;
}