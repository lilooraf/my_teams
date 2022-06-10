##
## EPITECH PROJECT, 2020
## 2ndYear
## File description:
## Makefile
##

SRC_DIR		=	./src/

CLI_DIR		=	$(SRC_DIR)client/

CLI_CMD		=	$(CLI_DIR)commands/

SERV_DIR	=	$(SRC_DIR)server/

DB_DIR		=	$(SRC_DIR)database/

SRC_CLI		=	$(CLI_DIR)main.c				\
				$(CLI_DIR)client.c				\
				$(CLI_DIR)init.c				\
				$(CLI_DIR)send_message.c		\
				$(CLI_DIR)receive_message.c		\
				$(CLI_DIR)command.c				\
				$(CLI_DIR)tools.c				\
				$(CLI_CMD)help.c				\
				$(CLI_CMD)login.c				\
				$(CLI_CMD)logout.c				\
				$(CLI_CMD)users.c				\
				$(CLI_CMD)user.c				\
				$(CLI_CMD)send.c				\
				$(CLI_CMD)messages.c			\
				$(CLI_CMD)subscribe.c			\
				$(CLI_CMD)subscribed.c			\
				$(CLI_CMD)unsubscribe.c			\
				$(CLI_CMD)use.c					\
				$(CLI_CMD)create.c				\
				$(CLI_CMD)list.c				\
				$(CLI_CMD)info.c				\
				$(CLI_CMD)error.c				\

SRC_SERV	=	$(SERV_DIR)server.c				\
				$(SERV_DIR)api.c				\
				$(SERV_DIR)server_func.c		\
				$(SERV_DIR)main.c				\
				$(SERV_DIR)request_create.c		\
				$(SERV_DIR)request_create_bis.c	\
				$(SERV_DIR)request_info.c		\
				$(SERV_DIR)request_list.c		\
				$(SERV_DIR)request_log.c		\
				$(SERV_DIR)request_msg.c		\
				$(SERV_DIR)request_sub.c		\
				$(SERV_DIR)request_subd.c		\
				$(SERV_DIR)request_use.c		\
				$(SERV_DIR)request_user.c		\
				$(DB_DIR)database.c				\
				$(DB_DIR)file_handling.c		\
				$(DB_DIR)parse.c				\
				$(DB_DIR)tool_box.c				\
				$(DB_DIR)free_tool_box.c		\
				$(DB_DIR)tab_bis.c				\
				$(DB_DIR)tab.c					\
				$(DB_DIR)list.c					\
				$(DB_DIR)box_str.c				\

OBJ_CLI		=	$(SRC_CLI:.c=.o)

OBJ_SERV	=	$(SRC_SERV:.c=.o)

CFLAGS		=	-L libs/myteams/ -lmyteams -L lib/my -lmy -g -Iinclude -Ilibs/myteams -W -Wall -Wextra -ldl

TEST_DIR	=	./tests/

SRC_T		=

NAME_CLI	=	myteams_cli

NAME_SERV	=	myteams_server

NAME_T		=	unit_test

NAME		=	myteams

all:	$(NAME)

$(NAME):	$(OBJ_CLI) $(OBJ_SERV)
	@make -C ./lib/my/
	@gcc -o $(NAME_CLI) $(OBJ_CLI) $(CFLAGS)
	@gcc -o $(NAME_SERV) $(OBJ_SERV) $(CFLAGS)

clean:
	@make clean -C ./lib/my/
	@rm -f $(OBJ_CLI) $(OBJ_SERV)
	@rm -f vg* *.gc*
	@rm -rf .vscode*

fclean:	clean
	@make fclean -C ./lib/my/
	@rm -f $(NAME_CLI) $(NAME_SERV) $(NAME_T)

re:	fclean all

tests_run:	re
	@gcc -o $(NAME_T) $(SRC_CLI) $(SRC_SERV) $(SRC_T) $(CFLAGS_T) $(CFLAGS)
	@./$(NAME_T)
	gcovr -e tests/

.PHONY:	all			\
		clean		\
		fclean		\
		re			\
		tests_run	\