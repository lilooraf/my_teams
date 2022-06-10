/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** info
*/

#include "client.h"

void info_thread(char **params)
{
    time_t timestamp = create_time_stamp(params[3]);

    if (timestamp == RETURN_F)
        return;
    client_print_thread(params[1], params[2], timestamp, params[4], params[5]);
    return;
}

void info_resp(ressources_t *res, char **params)
{
    (void)res;
    if (my_strcmp("USER", params[0]) == 0) {
        client_print_user(params[1], params[2], atoi(params[3]));
        return;
    }
    if (my_strcmp("TEAM", params[0]) == 0) {
        client_print_team(params[1], params[2], params[3]);
        return;
    }
    if (my_strcmp("CHANNEL", params[0]) == 0) {
        client_print_channel(params[1], params[2], params[3]);
        return;
    }
    if (my_strcmp("THREAD", params[0]) == 0) {
        info_thread(params);
        return;
    }
}

void info(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (params != NULL)
        return;
    send_message(*res, "INFO", params);
    choose_response(res, receive_message(*res));
}
