/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** cli_commands
*/

#ifndef CLI_COMMANDS_H_
#define CLI_COMMANDS_H_

#include "client.h"

#define CMD_NBR     14
#define RESP_NBR    15

typedef struct commands
{
    char *cmd;
    void (*func) (ressources_t *res, char **params);
} commands_t;

void help(ressources_t *res, char **params);
void login(ressources_t *res, char **params);
void logout(ressources_t *res, char **params);
void users(ressources_t *res, char **params);
void user(ressources_t *res, char **params);
void my_send(ressources_t *res, char **params);
void messages(ressources_t *res, char **params);
void subscribe(ressources_t *res, char **params);
void subscribed(ressources_t *res, char **params);
void unsubscribe(ressources_t *res, char **params);
void use(ressources_t *res, char **params);
void create(ressources_t *res, char **params);
void list(ressources_t *res, char **params);
void info(ressources_t *res, char **params);

commands_t commands[] = {
    {"/help", &help},
    {"/login", &login},
    {"/logout", &logout},
    {"/users", &users},
    {"/user", &user},
    {"/send", &my_send},
    {"/messages", &messages},
    {"/subscribe", &subscribe},
    {"/subscribed", &subscribed},
    {"/unsubscribe", &unsubscribe},
    {"/use", &use},
    {"/create", &create},
    {"/list", &list},
    {"/info", &info},
};

typedef struct responses
{
    char *resp;
    void (*func) (ressources_t *res, char **params);
} responses_t;

void error_resp(ressources_t *res, char **params);
void login_resp(ressources_t *res, char **params);
void logout_resp(ressources_t *res, char **params);
void users_resp(ressources_t *res, char **params);
void user_resp(ressources_t *res, char **params);
void recv_resp(ressources_t *res, char **params);
void messages_resp(ressources_t *res, char **params);
void subscribe_resp(ressources_t *res, char **params);
void subscribed_teams_resp(ressources_t *res, char **params);
void subscribed_users_resp(ressources_t *res, char **params);
void unsubscribe_resp(ressources_t *res, char **params);
void use_resp(ressources_t *res, char **params);
void create_resp(ressources_t *res, char **params);
void list_resp(ressources_t *res, char **params);
void info_resp(ressources_t *res, char **params);

responses_t response[] = {
    {"ERROR", &error_resp},
    {"LOGIN", &login_resp},
    {"LOGOUT", &logout_resp},
    {"USERS", &users_resp},
    {"USER", &user_resp},
    {"RECV", &recv_resp},
    {"MSG", &messages_resp},
    {"SUB", &subscribe_resp},
    {"SUBDTEAM", &subscribed_teams_resp},
    {"SUBDUSER", &subscribed_users_resp},
    {"UNSUB", &unsubscribe_resp},
    {"USE", &use_resp},
    {"CREATE", &create_resp},
    {"LIST", &list_resp},
    {"INFO", &info_resp},
};

#endif /* !CLI_COMMANDS_H_ */
