/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** server
*/

#include "database.h"
#include "server.h"

void adjust_max(st_t *st)
{
    st->max_old = st->max;
    st->max = 0;
    for (st->desc = 0; st->desc < st->max_old; st->desc++)
        if ((st->desc > st->max) && (FD_ISSET(st->desc, &st->read_fd_set)))
            st->max = st->desc;
}

void handle_client(st_t *st)
{
    int readed;
    char *buf = (char*) calloc(BUFF_SIZE, sizeof(char));

    ioctl(st->desc,FIONREAD, &readed);
    if (readed == 0) {
        close(st->desc);
        FD_CLR(st->desc, &st->read_fd_set);
        if (st->desc == st->max)
            adjust_max(st);
    } else {
        read(st->desc,buf,BUFF_SIZE);
        dprintf(st->desc, "%s\n", api(my_str_to_word_array(buf, ' '), st));
    }
    free(buf);
}

void add_client(st_t *st)
{
    for (int i = 0; i < MAX_CLIENT; i++) {
        if (st->ct[i].id == 0) {
            st->ct[i].id = st->desc;
            break;
        }
    }
}

void handle_connect(st_t *st)
{
    if (FD_ISSET(st->desc, &st->test_fd_set)) {
        if (st->desc == st->descServ) {
            st->descClient = accept(st->descServ,
                (struct sockaddr *)&st->addrClient,
                (socklen_t *)&st->lg_addr_client);
            add_client(st);
            FD_SET(st->descClient, &st->read_fd_set);
            st->max = (st->max < st->descClient) ? st->descClient : st->max;
        } else
            handle_client(st);
    }
}

void server(fd_set read_fd_set, int descServ)
{
    st_t st;

    st.uuid = calloc(1, sizeof(unique_uuid_t));
    st.ct = calloc(MAX_CLIENT, sizeof(ct_t));
    st.read_fd_set = read_fd_set;
    st.descServ = descServ;
    st.lg_addr_client = sizeof(struct sockaddr_in);
    st.max = descServ;
    get_ids(st.uuid);
    listen(st.descServ, SOMAXCONN);
    FD_ZERO(&st.read_fd_set);
    FD_SET(st.descServ, &st.read_fd_set);
    while (1) {
        st.test_fd_set = st.read_fd_set;
        if (select(st.max+1, &st.test_fd_set, (fd_set *) 0, (fd_set *) 0,
        (struct timeval*) 0) < 1)
            error ("Pb Select");
        for (st.desc = 0; st.desc < st.max+1; st.desc++)
            handle_connect(&st);
    }
}