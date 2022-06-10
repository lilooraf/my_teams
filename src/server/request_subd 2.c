/*
** EPITECH PROJECT, 2020
** Visual Studio Live Share (Workspace)
** File description:
** request_subd
*/

#include "database.h"

bool is_intab(char **tab, char *id)
{
    for (int i = 0; tab[i]; i++)
        if (my_strcmp(tab[i], id) == 0)
            return true;
    return false;
}

char *database_request_subscribed_teams(char *current_id)
{
    char *champ[5] = {"id", "name", "description", "users_id" , NULL};
    table_t *teams = dataselect("teams", champ, NULL);
    char *res = NULL;

    print_data_list_struct(teams);
    for (; teams; teams = teams->next) {
        if (is_intab(split(strdup(teams->data[3]), "[], \""), current_id)) {
            res = my_strcat(res, teams->data[0]);
            res = my_strcat(my_strcat(res, ";"), teams->data[1]);
            res = my_strcat(my_strcat(res, ";"), teams->data[2]);
            res = my_strcat(res, " ");
        }
    }
    if (!res)
        return "SUBDTEAM ";
    return my_strcat("SUBDTEAM ", cl_str(res, '"'));
}

char *list_info_with_id(char **tab)
{
    char **where = calloc(sizeof(char *), 3);
    table_t *teams = NULL;
    char *res = NULL;
    
    where[0] = strdup("id");
    where[2] = NULL;
    for (int i = 0; tab[i]; i++, res = my_strcat(res, " ")) {
        where[1] = strdup(tab[i]);
        teams = dataselect("users", NULL, where);
        res = my_strcat(res, strdup(teams->data[0]));
        res = my_strcat(my_strcat(res, ";"), teams->data[1]);
        res = my_strcat(my_strcat(res, ";"), teams->data[2]);
        where[1] = NULL;
    }
    return res;
}

char *database_request_subscribed_users(char *team_id)
{
    char *where[3] = {"id", team_id, NULL};
    char *champ[2] = {"users_id", NULL};
    table_t *teams = dataselect("teams", champ, where);
    char **data = NULL;

    if (len_list(teams) == 0)
        return my_strcat("ERROR TEAM", team_id);
    data = split(strdup(teams->data[0]), "][, \"");
    return my_strcat("SUBDUSER ", cl_str(list_info_with_id(data), '"'));
}

char *subscribed(char **command, st_t *st)
{
    int i = find_user(st);
    char *res = NULL;

    if (command[0] == NULL)
        res = database_request_subscribed_teams(st->ct[i].user_id);
    else
        res = database_request_subscribed_users(command[0]);
    return res;
}