/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** api
*/

#ifndef API_H_
#define API_H_

#include "server.h"

typedef struct type
{
    char *command;
    char *(*fonction)(char **, st_t *);
} type_t;

char *login(char **, st_t *);
char *logout(char **, st_t *);
char *use(char **, st_t *);
char *users(char **, st_t *);
char *user(char **, st_t *);
char *_send(char **, st_t *);
char *message(char **, st_t *);
char *subscribe(char **, st_t *);
char *subscribed(char **, st_t *);
char *unsubscribe(char **, st_t *);
char *create(char **, st_t *);
char *list(char **, st_t *);
char *info(char **, st_t *);

type_t const types[] =
{
    {"LOGIN", &login},
    {"LOGOUT", &logout},
    {"USE", &use},
    {"USERS", &users},
    {"USER", &user},
    {"SEND", &_send},
    {"MSG", &message},
    {"SUB", &subscribe},
    {"SUBD", &subscribed},
    {"UNSUB", &unsubscribe},
    {"CREATE", &create},
    {"LIST", &list},
    {"INFO", &info},
    {NULL, NULL}
};

#endif /* !API_H_ */
