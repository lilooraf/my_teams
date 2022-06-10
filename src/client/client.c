/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** client
*/

#include "client.h"

static void sighandler(int signum)
{
    (void)signum;
    write(1, "\n> ", 3);
}

void get_user_entry(ressources_t *res)
{
    char *line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != RETURN_F) {
        if (my_strcmp(line, "\n") == 0) {
            write(1, "> ", 2);
            continue;
        }
        choose_command(res, line);
        write(1, "> ", 2);
    }
    res->receive = false;
    close(res->server_fd);
}

void client(char *ip, unsigned short port)
{
    ressources_t res;
    fd_set rfds;
    int retval;

    FD_ZERO(&rfds);
    FD_SET(0, &rfds);
    write(1, "> ", 2);
    retval = select(1, &rfds, NULL, NULL, NULL);
    if (retval == -1)
        perror("select()");
    else if (retval){
        signal(SIGINT, &sighandler);
        init_ressources(&res, ip, port);
        get_user_entry(&res);
    }
}