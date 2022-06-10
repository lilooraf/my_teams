/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** send
*/

#include "client.h"

void recv_resp(ressources_t *res, char **params)
{
    (void)res;
    if (params == NULL)
        return;
    client_event_private_message_received(params[0], params[1]);
}

void my_send(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (my_array_height(params) != 2)
        return;
    send_message(*res, "SEND", params);
    choose_response(res, receive_message(*res));
}
