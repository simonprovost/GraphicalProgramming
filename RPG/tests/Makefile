##
## EPITECH PROJECT, 2017
## my_rpg_2017
## File description:
## Makefile
##

CC	=	gcc

WFLAGS		=	-Wextra -W -Wall -Wparentheses -Wsign-compare -Wpointer-sign -Wuninitialized -Wunused-but-set-variable

CFLAGS		=	-I../include -L../lib/my/ -lmy --coverage -lcriterion

RM	=	rm -rf

SRCTEST	=	main.c	\

OBJTEST	=	$(SRCTEST:.c=.o)

NAMETEST	=	unit-tests

all:	tests_run

tests_run:	$(OBJTEST)
	$(CC) -o $(NAMETEST) $(OBJTEST) $(CFLAGS) $(WFLAGS)

clean:
	$(RM) $(OBJTEST)
	$(RM) ../sources/*.gcda
	$(RM) ../sources/*.gcno
	$(RM) ./*.gcda
	$(RM) ./*.gcno

fclean: clean
	$(RM) $(NAMETEST)

re:	fclean all
