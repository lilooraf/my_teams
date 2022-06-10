/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** unsubscribe
*/

#include "client.h"

void unsubscribe_resp(ressources_t *res, char **params)
{
    (void)res;
    if (params == NULL)
        return;
    client_print_unsubscribed(params[0], params[1]);
}

void unsubscribe(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (my_array_height(params) != 1)
        return;
    send_message(*res, "UNSUB", params);
    choose_response(res, receive_message(*res));
}
