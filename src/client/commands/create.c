/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** create
*/

#include "client.h"

void create_thread(char **params)
{
    time_t timestamp = create_time_stamp(params[3]);

    if (timestamp == RETURN_F)
        return;
    client_print_thread_created(params[1], params[2], timestamp, params[4], params[5]);
    return;
}

void create_reply(char **params)
{
    time_t timestamp = create_time_stamp(params[3]);

    if (timestamp == RETURN_F)
        return;
    client_print_reply_created(params[1], params[2], timestamp, params[4]);
    return;
}

void create_resp(ressources_t *res, char **params)
{
    (void)res;
    if (my_strcmp("TEAM", params[0]) == 0) {
        client_event_team_created(params[1], params[2], params[3]);
        return;
    }
    if (my_strcmp("CHANNEL", params[0]) == 0) {
        client_event_channel_created(params[1], params[2], params[3]);
        return;
    }
    if (my_strcmp("THREAD", params[0]) == 0) {
        create_thread(params);
        return;
    }
    if (my_strcmp("REPLY", params[0]) == 0) {
        create_reply(params);
        return;
    }
}

void create(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (my_array_height(params) != 1 && my_array_height(params) != 2)
        return;
    send_message(*res, "CREATE", params);
    choose_response(res, receive_message(*res));
}
