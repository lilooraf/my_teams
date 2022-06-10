/*
** EPITECH PROJECT, 2020
** delivery
** File description:
** request_user
*/

#include "database.h"

char **fill_data_user(char *id, char *name, char *connected)
{
    char **data = calloc(6, sizeof(char *));
    
    data[0] = my_strdup("id");
    data[1] = my_strdup(id);
    data[2] = my_strdup("name");
    data[3] = my_strdup(name);
    data[4] = my_strdup("connected");
    data[5] = my_strdup(connected);
    data[6] = NULL;
    return data;
}

char *database_request_login(char *name, unique_uuid_t *uuid)
{
    char *champ[3] = {"id", "name", NULL};
    char *where[3] = {"name", name, NULL};
    table_t *user = dataselect("users", champ, where);
    char *champ2[3] = {"connected", "1", NULL};
    char *id = int_to_str(++uuid->users_id);
    char *where2[3] = {"id", len_list(user) != 0 ? user->data[0] : "", NULL};

    if (len_list(user) == 0) {
        datainsert("users", fill_data_user(id, name, "1"));
        server_event_user_created(id, name);
        return id;
    } else {
        dataupdate("users", champ2, where2);
        user->data = clean_tab(user->data);
        server_event_user_logged_in(user->data[0]);
        return user->data[0];
    }
}

void database_request_logout(char *name, char *id, unique_uuid_t *uuid)
{
    char *champ[3] = {"connected", "0", NULL};
    char *where[3] = {"id", id, NULL};

    (void)name;
    (void)uuid;
    dataupdate("users", champ, where);
}

char *login(char **command, st_t *st)
{
    int i = 0;
    char *id = NULL;

    add_client(st);
    id = database_request_login(command[0], st->uuid);
    i = find_user(st);
    st->ct[i].user_id = id;
    return my_strcat(my_strcat(my_strcat("LOGIN ", id), " "), command[0]);
}

char *logout(char **command, st_t *st)
{
    int i = find_user(st);

    if (i == -1)
        return "ERROR";
    st->ct[i].team = NULL;
    st->ct[i].chanel = NULL;
    st->ct[i].thread = NULL;
    st->ct[i].id = 0;
    database_request_logout(command[0], command[1], st->uuid);
    server_event_user_logged_out(command[0]);
    return "LOGOUT OK";
}