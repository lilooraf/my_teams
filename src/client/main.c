/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** main
*/

#include "client.h"

int usage()
{
    printf("USAGE: ./myteams_cli ip port\n");
    printf("\tip\tis the server ip address on which the server socket");
    printf("listens\n");
    printf("\tport\tis the port number on which the server socket listens\n");
    return EXIT_SUCCESS;
}

int error_handling(char *ip, char *port)
{
    struct sockaddr_in sa;

    if (!inet_pton(AF_INET, ip, &(sa.sin_addr)))
        return RETURN_F;
    for (int i = 0; port[i]; i++)
        if (!isdigit(port[i]))
            return RETURN_F;
    return RETURN_S;
}

int main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return usage();
    else if (ac == 3 && error_handling(av[1], av[2]) == RETURN_S)
        client(av[1], atoi(av[2]));
    else
        return EXIT_F;
    return EXIT_S;
}