/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** init
*/

#include "client.h"

void init_ressources(ressources_t *res, char *ip, unsigned short port)
{
    res->ip = my_strdup(ip);
    res->port = port;
    res->server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (res->server_fd == -1)
        exit(EXIT_F);
    res->addr.sin_addr.s_addr = inet_addr(res->ip);
    res->addr.sin_family = AF_INET;
    res->addr.sin_port = htons(res->port);
    if (connect(res->server_fd, (struct sockaddr *)&res->addr,
        sizeof(res->addr)) == -1)
        exit(EXIT_F);
    res->user.is_logged = false;
    res->user.username = NULL;
    res->is_connected = true;
    res->receive = true;
}