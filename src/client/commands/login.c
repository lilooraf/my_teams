/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** login
*/

#include "client.h"

void connect_to_server(ressources_t *res)
{
    res->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (res->server_fd == -1)
        exit(EXIT_F);
    res->addr.sin_addr.s_addr = inet_addr(res->ip);
    res->addr.sin_family = AF_INET;
    res->addr.sin_port = htons(res->port);
    if (connect(res->server_fd, (struct sockaddr *)&res->addr,
        sizeof(res->addr)) == -1)
        exit(EXIT_F);
    res->is_connected = true;
    res->receive = true;
}

void login_resp(ressources_t *res, char **params)
{
    if (params == NULL || params[0] == NULL || params[1] == NULL)
        return;
    res->user.uuid = params[0];
    res->user.username = params[1];
    client_event_loggedin(res->user.uuid, res->user.username);
    res->user.is_logged = true;
}

void login(ressources_t *res, char **params)
{
    if (my_array_height(params) != 1 || res->user.is_logged)
        return;
    if (!res->is_connected)
        connect_to_server(res);
    send_message(*res, "LOGIN", params);
    choose_response(res, receive_message(*res));
}
