/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** command
*/

#include "cli_commands.h"

char *delete_end_line(char *line)
{
    for (int i = 0; line[i]; i++)
        if (line[i] == '\n' || line[i] == '\r') {
            line[i] = '\0';
            break;
        }
    return my_strdup(line);
}

bool check_quotes(char *message)
{
    int quotes = 0;

    for (int i = 0; message[i]; i++) {
        if (message[i] == '"')
            quotes++;
    }
    if (quotes == 0 || quotes % 2 != 0)
        return false;
    else
        return true;
    return true;
}

void choose_response(ressources_t *res, char *message)
{
    char **response_array = my_str_to_word_array(delete_end_line(message),
        ' ');

    for (int i = 1; response_array[i]; i++)
        response_array[i] = change_back_string(response_array[i]);
    if (response_array == NULL || response_array[0] == NULL)
        return;
    
    for (int i = 0; i < RESP_NBR; i++) {
        if (my_strcmp(response[i].resp, response_array[0]) == 0) {
            response[i].func(res, &response_array[1]);
            return;
        }
    }
}

char *change_back_string(char *str)
{
    for (int i = 0; str[i]; i++) {
        switch (str[i])
        {
        case 11:
            str[i] = ' ';
            break;
        case 12:
            str[i] = ',';
            break;
        case 8:
            str[i] = ':';
            break;
        default:
            break;
        }
    }
    return str;
}

int choose_command(ressources_t *res, char *line)
{
    char **cmd = split(delete_end_line(line), 
    check_quotes(delete_end_line(line)) == true ? "\"" : " ");

    if (cmd == NULL)
        return RETURN_F;
    cmd[0] = cl_str(cmd[0], ' ');
    for (int i = 1; cmd[i]; i++) {
        cmd[i] = change_string(cmd[i]);
        if (cmd[i] == NULL)
            cmd = swap_to_the_end(cmd, i--);
    }
    for (int i = 0; i < CMD_NBR; i++) {
        if (my_strcmp(commands[i].cmd, cmd[0]) == 0) {
            if (cmd[1] == NULL)
                commands[i].func(res, NULL);
            else 
                commands[i].func(res, &cmd[1]);
            return RETURN_S;
        }
    }
    return RETURN_F;
}