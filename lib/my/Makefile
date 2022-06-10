##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile qui compile le libmy
##

SRC	=	my_putchar.c			\
		my_put_nbr.c			\
		my_put_nbrn.c			\
		my_strlen.c				\
		my_put_in_alpha.c		\
		my_putstr.c				\
		my_putstrn.c			\
		my_getnbr.c				\
		my_get_unsnbr.c			\
		my_strdup.c				\
		my_strcpy.c				\
		my_strcat.c				\
		char_from_file.c		\
		my_strupcase.c			\
		my_isnum.c				\
		my_putnbr_base.c		\
		my_putunsigned_nbr.c	\
		my_revstr.c				\
		my_str_to_word_array.c	\
		my_strcmp.c				\
		my_strncmp.c			\
		my_swap_string.c		\
		my_putstr_err.c			\
		my_clean_string.c		\
		my_calloc.c				\
		my_array_height.c		\
		my_arraydup.c			\
		array_cat.c				\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

lib	=	./lib/my/

all:	$(NAME)

$(NAME):	$(OBJ)
	@ar rc libmy.a $(OBJ)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all
