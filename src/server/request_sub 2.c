/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_sub
*/

#include "database.h"

void update_team_array(char *str, char *team_id)
{
    char *champ[3] = {"users_id", str, NULL};
    char *where[3] = {"id", team_id, NULL};

    dataupdate("teams", champ, where);
}

char *database_request_subscible(char *team_id, char *current_id)
{
    char *where[3] = {"id", team_id, NULL};
    table_t *team = dataselect("teams", NULL, where);
    char *data[2] = {current_id, NULL};
    
    if (len_list(team) == 0)
        return my_strcat("ERROR TEAM ", team_id);
    update_team_array(array_instert(team->data[4], data), team_id);
    return my_strcat(current_id, my_strcat (" ", team_id));
}

char *database_request_unsubscible(char *team_id, char *current_id)
{
    char *where[3] = {"id", team_id, NULL};
    table_t *team = dataselect("teams", NULL, where);
    char *data[2] = {current_id, NULL};

    if (len_list(team) == 0)
        return my_strcat("ERROR TEAM ", team_id);
    update_team_array(array_delete(team->data[4], data), team_id);
    return my_strcat(current_id, my_strcat (" ", team_id));
}

char *subscribe(char **command, st_t *st)
{
    int i = find_user(st);
    char *ret = database_request_subscible(command[0], st->ct[i].user_id);

    if (my_strcmp(split(my_strdup(ret), " ")[0], "ERROR") == 0)
        return ret;
    server_event_user_join_a_team(command[0], st->ct[i].user_id);
    return my_strcat("SUB ", ret);
}

char *unsubscribe(char **command, st_t *st)
{
    int i = find_user(st);
    char *ret = database_request_unsubscible(command[0], st->ct[i].user_id);

    if (my_strcmp(split(my_strdup(ret), " ")[0], "ERROR") == 0)
        return ret;
    server_event_user_join_a_team(command[0], st->ct[i].user_id);
    return my_strcat("UNSUB ", ret);
}