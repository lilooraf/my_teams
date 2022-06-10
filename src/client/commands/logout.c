/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** logout
*/

#include "client.h"

void disconnect_from_server(ressources_t *res)
{
    close(res->server_fd);
    res->is_connected = false;
    res->server_fd = 0;
    res->receive = false;
}

void logout_resp(ressources_t *res, char **params)
{
    (void)params;
    client_event_loggedout(res->user.uuid, res->user.username);
    res->user.is_logged = false;
    res->user.username = my_strdup("");
    res->user.uuid = my_strdup("");
    disconnect_from_server(res);
}

void logout(ressources_t *res, char **params)
{
    char **array = NULL;

    (void)params;
    if (!res->is_connected)
        return;
    if (!res->user.is_logged) {
        disconnect_from_server(res);
        return;
    }
    array = my_calloc(sizeof(char *), 3);
    array[0] = my_strdup(res->user.username);
    array[1] = my_strdup(res->user.uuid);
    array[2] = NULL;
    send_message(*res, "LOGOUT", array);
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
    choose_response(res, receive_message(*res));
    exit(0);
}