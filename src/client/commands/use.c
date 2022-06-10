/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** use
*/

#include "client.h"

void use_resp(ressources_t *res, char **params)
{
    (void)res;
    (void)params;
    printf("Context changed.\n");
}

void use(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (params != NULL && my_array_height(params) > 3)
        return;
    send_message(*res, "USE", params);
    choose_response(res, receive_message(*res));
}
