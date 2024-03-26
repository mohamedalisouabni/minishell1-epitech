##
## EPITECH PROJECT, 2023
## make
## File description:
## file
##

CC 	=	gcc

SRC	=	my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c		\
		my_strlen.c		\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strcat.c		\
		my_strncpy.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	-Wextra

CPPFLAGS	=	-I../../include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) ../$(NAME)
	$(RM) *~

re:	fclean all

.PHONY:	all clean fclean re
