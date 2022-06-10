/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** send
*/

#include "client.h"

char *create_message(char *cmd, char **params)
{
    char *message = my_strdup(cmd);

    if (params != NULL) {
        for (int i = 0; params[i]; i++) {
            message = my_strcat(message, " ");
            message = my_strcat(message, params[i]);
        }
    }
    return message;
}

int send_message(ressources_t res, char *cmd, char **params)
{
    char *message = create_message(cmd, params);

    if (dprintf(res.server_fd, "%s", message) < 0)
        return RETURN_F;
    return RETURN_S;
}