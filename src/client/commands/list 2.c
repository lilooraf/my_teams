/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** list
*/

#include "client.h"

void list_threads(char **params)
{
    char **array = NULL;
    time_t timestamp = 0;

    for (int i = 1; params[i]; i++) {
        array = my_str_to_word_array(params[i], ';');
        timestamp = create_time_stamp(array[2]);
        if (timestamp == RETURN_F)
            return;
        client_channel_print_threads(array[0], array[1], timestamp, array[3], array[4]);
        free_array(array);
        timestamp = 0;
    }
}

void list_replies(char **params)
{
    char **array = NULL;
    time_t timestamp = 0;

    for (int i = 1; params[i]; i++) {
        array = my_str_to_word_array(params[i], ';');
        timestamp = create_time_stamp(array[2]);
        if (timestamp == RETURN_F)
            return;
        client_thread_print_replies(array[0], array[1], timestamp, array[3]);
        free_array(array);
        timestamp = 0;
    }
}

void list_thread_and_replies(char **params)
{
    if (my_strcmp("THREAD", params[0]) == 0) {
        list_threads(params);
        return;
    }
    if (my_strcmp("REPLY", params[0]) == 0) {
        list_replies(params);
        return;
    }
}

void list_resp(ressources_t *res, char **params)
{
    char **array = NULL;

    (void)res;
    if (my_strcmp("TEAM", params[0]) == 0) {
        for (int i = 1; params[i]; i++) {
            array = my_str_to_word_array(params[i], ';');
            client_print_teams(array[0], array[1], array[2]);
            free_array(array);
        }
    } else if (my_strcmp("CHANNEL", params[0]) == 0) {
        for (int i = 1; params[i]; i++) {
            array = my_str_to_word_array(params[i], ';');
            client_team_print_channels(array[0], array[1], array[2]);
            free_array(array);
        }
    } else
        list_thread_and_replies(params);
}

void list(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (params != NULL)
        return;
    send_message(*res, "LIST", params);
    choose_response(res, receive_message(*res));
}
