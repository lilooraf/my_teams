/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** user
*/

#include "client.h"

void user_resp(ressources_t *res, char **params)
{
    (void)res;
    if (params == NULL)
        return;
    client_print_users(params[0], params[1], atoi(params[2]));
}

void user(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (my_array_height(params) != 1)
        return;
    send_message(*res, "USER", params);
    choose_response(res, receive_message(*res));
}
