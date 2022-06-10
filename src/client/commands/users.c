/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** users
*/

#include "client.h"

void users_resp(ressources_t *res, char **params)
{
    char **user = NULL;
    (void)res;

    if (params == NULL || my_strcmp(params[0], "") == 0)
        return;
    for (int i = 0; params[i]; i++) {
        user = my_str_to_word_array(params[i], ';');
        client_print_users(user[0], user[1], atoi(user[2]));
        free_array(user);
    }
}

void users(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (params != NULL)
        return;
    send_message(*res, "USERS", NULL);
    choose_response(res, receive_message(*res));
}