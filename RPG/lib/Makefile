##
## EPITECH PROJECT, 2018
## Makefile compiling lib
## File description:
## Makefile
##

NAME	=	llist

all: prepare_lib

prepare_lib:
	make -C my/
	make -C llist/

clean:
	make clean -C my/
	make clean -C llist/

fclean: clean
	make fclean -C my/
	make fclean -C llist/

re: fclean all
