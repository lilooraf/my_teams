/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** client
*/

#ifndef CLIENT_H_
#define CLIENT_H_

#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>
#include <stdbool.h>
#include <string.h>
#include <strings.h>
#include <pwd.h>
#include <linux/limits.h>
#include <ctype.h>
#include <signal.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>

#include "my.h"
#include "logging_client.h"

#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr

#define LIB_PATH    "./libs/myteams/libmyteams.so"
#define EXIT_S      0
#define EXIT_F      84
#define RETURN_S    0
#define RETURN_F    -1

typedef struct user
{
    char *username;
    char *uuid;
    bool is_logged;
} user_t;

typedef struct ressources
{
    char *ip;
    unsigned short port;
    int server_fd;
    struct sockaddr_in addr;
    user_t user;
    bool is_connected;
    bool receive;
} ressources_t;

void client(char *ip, unsigned short port);
void create_receive_thread(ressources_t *res);

void init_ressources(ressources_t *res, char *ip, unsigned short port);

char *delete_end_line(char *line);
void choose_response(ressources_t *res, char *message);
int choose_command(ressources_t *res, char *line);

int send_message(ressources_t res, char *cmd, char **params);
void *receive_server_message(void *args);
char *receive_message(ressources_t res);

time_t create_time_stamp(char *time);

void free_array(char **array);

char *change_string(char *str);
char *change_back_string(char *str);

char **split(char *str, char *del);
char **swap_to_the_end(char **array, int i);

#endif /* !CLIENT_H_ */
