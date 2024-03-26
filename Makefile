##
## EPITECH PROJECT, 2023
## make
## File description:
## task1
##

NAME	= mysh

CC	= gcc

SRC =		shell.c			\
			builtins.c		\
			setenv.c		\
			gest_path.c		\
			gest_env.c		\

RM	= rm -f

OBJ	= $(SRC:.c=.o)

LIBFLAG	= -L./lib/my -lmy

TEST_NAME = mysh

all: $(NAME)

$(NAME):
	make -C ./lib/my/
	make clean -C ./lib/my/
	$(CC) -o $(NAME) $(SRC) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean: clean

	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
