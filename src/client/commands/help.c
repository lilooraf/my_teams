/*
** EPITECH PROJECT, 2020
** 2ndYear
** File description:
** help
*/

#include "client.h"

void display_create_help()
{
    printf("\n\t/CREATE:\n");
    printf("\tWhen the context is not defined (/use):\n");
    printf("\t\t/create [\"team_name\"] [\"team_description\"]:\t");
    printf("create a new team\n");
    printf("\tWhen team_uuid is defined (/use \"team_uuid\"):\n");
    printf("\t\t/create [\"channel_name\"] [\"channel_description\"]:\t");
    printf("create a new channel\n");
    printf("\tWhen team_uuid and channel_uuid are defined");
    printf(" (/use \"team_id\" \"channel_uuid\"):\n");
    printf("\t\t/create [\"thread_title\"] [\"thread_message\"]:\t");
    printf("create a new thread\n");
    printf("\tWhen team_uuid, channel_uuid and thread_uuid are defined");
    printf(" (/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t\t/create [\"comment_body\"]:\tcreate a new reply\n");
}

void display_list_help()
{
    printf("\n\t/LIST:\n");
    printf("\tWhen the context is not defined (/use):\n");
    printf("\t\t/list:\tlist all existing teams\n");
    printf("\tWhen team_uuid is defined (/use \"team_uuid\"):\n");
    printf("\t\t/list:\tlist all existing channels\n");
    printf("\tWhen team_uuid and channel_uuid are defined");
    printf(" (/use \"team_id\" \"channel_uuid\"):\n");
    printf("\t\t/list:\tlist all existing threads\n");
    printf("\tWhen team_uuid, channel_uuid and thread_uuid are defined");
    printf(" (/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t\t/list:\tlist all existing replies\n");
}

void display_info_help()
{
    printf("\n\t/INFO:\n");
    printf("\tWhen the context is not defined (/use):\n");
    printf("\t\t/info:\tdisplay currently logged user infos\n");
    printf("\tWhen team_uuid is defined (/use \"team_uuid\"):\n");
    printf("\t\t/info:\tdisplay currently selected team infos\n");
    printf("\tWhen team_uuid and channel_uuid are defined");
    printf(" (/use \"team_id\" \"channel_uuid\"):\n");
    printf("\t\t/info:\tdisplay currently selected channel infos\n");
    printf("\tWhen team_uuid, channel_uuid and thread_uuid are defined");
    printf(" (/use \"team_uuid\" \"channel_uuid\" \"thread_uuid\"):\n");
    printf("\t\t/info:\tdisplay currently selected thread infos\n");
}

void display_help()
{
    printf("\t/subscribe [\"team_uuid\"] :\tsubscribe to the event of a team ");
    printf("and its sub directories (enable reception of all events from a team)\n");
    printf("\t/subscribed ?[\"team_uuid\"]:\tlist all subscribed teams or ");
    printf("list all users subscribed to a team\n");
    printf("\t/unsubscribe [\"team_uuid\"]:\tunsubscribe from a team\n");
    printf("\t/use ?[\"team_uuid\"] ?[\"channel_uuid\"] ?[\"thread_uuid\"]:\t");
    printf("use specify a context team/channel/thread\n");
    printf("\t/create:\tbased on what is being used create the sub resource ");
    printf("(see below)\n");
    printf("\t/list:\tbased on what is being used list all the sub resources ");
    printf("(see below)\n");
    printf("\t/info:\tbased on what is being used list the current ");
    printf("(see below)\n");
    display_create_help();
    display_list_help();
    display_info_help();
}

void help(ressources_t *res, char **params)
{
    (void)res;
    (void)params;
    printf("Usage:\n");
    printf("\t/help:\tshow help\n");
    printf("\t/login [\"username\"]:\tset the username used by client\n");
    printf("\t/logout:\tdisconnect the client from the server\n");
    printf("\t/users:\tget the list of all users that exist on the domain\n");
    printf("\t/user [\"user_uuid\"]:\tget information about a user\n");
    printf("\t/send [\"user_uuid\"] [\"message_body\"]:");
    printf("\tsend a message to a user\n");
    printf("\t/messages [\"user_uuid\"]:");
    printf("\tlist all messages exchange with an user\n");
    display_help();
}
