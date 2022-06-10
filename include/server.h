/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include "my.h"
#include "logging_server.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/time.h>

#define LIB_PATH    "./libs/myteams/libmyteams.so"
#define BUFF_SIZE 128
#define MAX_CLIENT 128

typedef struct ct
{
    int id;
    char *user_id;
    char *team;
    char *chanel;
    char *thread;
}ct_t;

typedef struct unique_uuid
{
    int teams_id;
    int channels_id;
    int threads_id;
    int messages_id;
    int users_id;
} unique_uuid_t;

typedef struct st
{
    int desc;
    int descServ;
    fd_set test_fd_set;
    struct sockaddr_in addrClient;
    int lg_addr_client;
    int descClient;
    int max;
    int max_old;
    fd_set read_fd_set;
    ct_t *ct;
    unique_uuid_t *uuid;
}st_t;

void server(fd_set, int);
void rightclose(int sig);
void error(const char *msg);
char *api(char **, st_t *);
int find_user(st_t *st);
void add_client(st_t *st);
void get_ids(unique_uuid_t *uuid);

char *database_request_login(char *name, unique_uuid_t *uuid);
void database_request_logout(char *name, char *id, unique_uuid_t *uuid);
char *database_request_users();

void display_thread_create(char *channel_id, char *thread_id,
    char *user_id, char *message);
void display_channel_create(char *team_id, char *channel_id, char *channel_name);

#endif /* !SERVER_H_ */