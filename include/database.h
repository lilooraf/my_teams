/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** Database h
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <stdbool.h>

#include "my.h"
#include "server.h"

#ifndef DATABSE_H_
#define DATABSE_H_

#define DATABASE_NAME "./src/database/myteams.json"
#define DATABASE_RESET "./src/database/reset.json"

typedef struct table_s
{
    char **data;
    struct table_s *next;
} table_t;

char *read_file(char *path);
int len(char **tab);
char **push_tab(char **tab, char *str);
void free_tab(char **tab);
void print_tab(char **tab);
char **split(char *str, char *del);
int find_table(char **tab, char *str);
int find_table_end(char **tab, int start);
char **regroup(char **tab);
char **get_by_champ(char **tmp, char **str, char **champ);
char **cp_tab(char **tab);
int check_where(char **tab, char **where);
char **getdata(char *str, char **champ, char **where);
char **getdatabrut(char *str, char **champ, char **where);
void put_in_list(table_t **front_ptr, char **elem);
int len_list(table_t *list);
char **get_data_in_the_list(table_t *list, int pos);
void print_data_list_struct(table_t *front_ptr);
void free_data_list_struct(table_t *front_ptr);
table_t *dataselect(char *table, char **champ, char **where);
char **inster_tab(char **tab, char *str, int pos);
void put_in_file_pos(char *str, int pos);
char *data_json_code(char **data, int start, int end);
void datainsert(char *table, char **data);
void datareset();
char **updatedata_in_table(char **tab, char **champ);
char **clean_tab(char **tab);
char **delete_line_in_table(char **tab, int *pos);
void put_in_file(char **tab);
int *getpos_delete(char **tab_cp, char *table, char **where);
void datadelete(char *table, char **where);
void dataupdate(char *table, char **champ, char **where);
char *array_delete(char *str, char **elems);
char *array_update(char *str, char **elems);
int check_array_existe(char **val, char *elem);
char *construct_array_json(char **tab);
char *array_instert(char *str, char **elems);
char **delete_val_in_array(char **tab, char *str);
bool is_intab(char **tab, char *id);
char **create_reply_array(char *thread_id, char **command, char *user_id);
char **create_thread_array(char **command, unique_uuid_t *uuid, char *user_id);

#endif /* !SERVER_H_ */