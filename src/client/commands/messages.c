/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** messages
*/

#include "client.h"

time_t create_time_stamp(char *time)
{
    int year = 0, month = 0, day = 0, hour = 0, min = 0;

    if (sscanf(time, "%2d/%2d/%4d$%2d-%2d",
        &day, &month, &year, &hour, &min) == 5) {
        struct tm breakdown = {0};
        breakdown.tm_year = year - 1900;
        breakdown.tm_mon = month - 1;
        breakdown.tm_mday = day;
        breakdown.tm_hour = hour;
        breakdown.tm_min = min;
        return mktime(&breakdown);
    } else
        return RETURN_F;
}

void free_array(char **array)
{
    for (int i = 0; array[i]; i++)
        free(array[i]);
    free(array);
}

void messages_resp(ressources_t *res, char **params)
{
    char **message = NULL;
    time_t result = 0;

    (void)res;
    if (params == NULL || my_strcmp(params[0], "") == 0) {
        printf("No messages with that user.\n");
        return;
    }
    for (int i = 0; params[i]; i++) {
        message = my_str_to_word_array(params[i], ';');
        result = create_time_stamp(message[1]);
        if (result == 0)
            return;
        client_private_message_print_messages(message[0], result, message[2]);
        free_array(message);
    }
}

void messages(ressources_t *res, char **params)
{
    if (!res->user.is_logged) {
        client_error_unauthorized();
        return;
    }
    if (my_array_height(params) != 1)
        return;
    send_message(*res, "MSG", params);
    choose_response(res, receive_message(*res));
}
