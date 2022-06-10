/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** error
*/

#include "client.h"

int unknown_erros_next(char **params)
{
    if (my_strcmp("CHANNEL", params[0]) == 0) {
        client_error_unknown_channel(params[1]);
        return RETURN_S;
    }
    if (my_strcmp("THREAD", params[0]) == 0) {
        client_error_unknown_thread(params[1]);
        return RETURN_S;
    }
    return RETURN_F;
}

int unknown_errors(char **params)
{
    if (my_strcmp("USER", params[0]) == 0) {
        client_error_unknown_user(params[1]);
        return RETURN_S;
    } else if (my_strcmp("TEAM", params[0]) == 0) {
        client_error_unknown_team(params[1]);
        return RETURN_S;
    } else
        return unknown_erros_next(params);
    return RETURN_F;
}

void error_resp(ressources_t *res, char **params)
{
    (void)res;
    if (my_array_height(params) != 2)
        return;
    if (unknown_errors(params) == RETURN_S)
        return;
    if (my_strcmp("EXISTS", params[0]) == 0) {
        client_error_already_exist();
        return;
    }
}