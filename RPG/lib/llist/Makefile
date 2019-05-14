##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## compile libllist from files in lib/llist/.
##

CC	=	gcc

SRC	=	llist_add.c	\
		llist_create.c	\
		llist_destroy.c	\
		llist_get.c	\
		llist_order.c	\
		llist_process.c	\
		llist_remove.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	llist

NAMELIB	=	libllist.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib$(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMELIB)

re:	fclean all
