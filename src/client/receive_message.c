/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** receive
*/

#include "client.h"

char *receive_message(ressources_t res)
{
    char *line = NULL;
    size_t len = 0;

    getline(&line, &len, fdopen(res.server_fd, "r"));
    return line;
}