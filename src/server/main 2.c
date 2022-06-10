/*
** EPITECH PROJECT, 2020
** NWP_myteams_2019
** File description:
** main
*/

#include "database.h"
#include "server.h"

int check_error(int ac, char **av)
{
    if (ac != 2 || my_isnum(av[1]))
        return 1;
    else
        return 0;
}

int main (int ac, char **av)
{
    int descServ;
    struct sockaddr_in addrServ;
    struct sigaction act;
    fd_set read_fd_set;
    int len;

    if (check_error(ac, av))
        return 84;
    descServ = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
    act.sa_handler = rightclose;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    sigaction(SIGINT, &act,0);
    addrServ.sin_family = AF_INET;
    addrServ.sin_addr.s_addr = inet_addr("127.0.0.1");
    addrServ.sin_port = htons(atoi(av[1]));
    if (bind(descServ, (struct sockaddr *) &addrServ,
    (sizeof(struct sockaddr_in))) == -1)
        error("Erreur de nommage");
    if (getsockname(descServ, (struct sockaddr *) &addrServ, (socklen_t *)&len) == -1)
        error("Erreur lors de la recuperation du port");
    server(read_fd_set, descServ);
}