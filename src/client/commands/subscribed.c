/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** subscribed
*/

#include "client.h"

void subscribed_teams_resp(ressources_t *res, char **params)
{
    char **team = NULL;
    (void)res;

    if (params == NULL || my_strcmp(params[0], "") == 0) {
        printf("No subscribed teams.\n");
        return;
    }
    for (int i = 0; params[i]; i++) {
        if (my_strcmp(params[i], "") == 0)
            return;
        team = my_str_to_word_array(params[i], ';');
        client_print_teams(team[0], team[1], team[2]);
        free_array(team);
    }
}

void subscribed_users_resp(ressources_t *res, char **params)
{
    char **user = NULL;
    (void)res;

    if (params == NULL)
        return;
    for (int i = 0; params[i]; i++) {
        if (my_strcmp(params[i], "") == 0)
            return;
        user = my_str_to_word_array(params[i], ';');
        client_print_users(user[0], user[1], atoi(user[2]));
        free_array(user);
    }
}

void subscribed(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (params != NULL && my_array_height(params) != 1)
        return;
    send_message(*res, "SUBD", params);
    choose_response(res, receive_message(*res));
}
