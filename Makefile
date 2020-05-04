##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

CC	=	gcc

SRC	=	src/main.c							\
							\
		src/utils/my_atoi.c					\
		src/utils/cpy_tab.c					\
		src/utils/free_tab.c				\
		src/utils/my_malloc.c				\
		src/utils/my_strcat.c				\
		src/utils/my_strcmp.c				\
		src/utils/my_strcpy.c				\
		src/utils/my_strdup.c				\
		src/utils/my_str_to_word_array.c	\
		src/utils/my_puterror.c				\
		src/utils/realloc_tab.c				\
		src/utils/remove_str_from_tab.c 	\
							\
		src/execve.c						\
		src/exec_binary.c					\
		src/exec_path.c						\
		src/get_commands.c					\
		src/get_from_env.c					\
		src/input.c							\
		src/minishell.c						\
		src/my_cd.c							\
		src/my_commands.c					\
		src/setenv.c						\
		src/unsetenv.c						\
		src/redirect_out.c					\
		src/redirect_in.c					\
		src/pipe.c							\

OBJ	=	$(SRC:.c=.o)

NAME	=	mysh

CFLAGS	=	-W -Wall -g3

CPPFLAGS	=	-I include/

LIB	=	-L ./ -lmy

all:	$(NAME)

$(NAME):	$(OBJ)
	make -s -C lib/
	$(CC) -o $(NAME) $(OBJ) $(LIB)

tests_run:
	make test_run -C lib/

clean:
	make clean -s -C lib/
	rm -f $(OBJ)

fclean:	clean
	make fclean -s -C lib/
	rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
