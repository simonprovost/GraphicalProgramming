##
## EPITECH PROJECT, 2017
## Makefile t01 d10
## File description:
## compil libmy. from files in lib/my/, copy it in lib, copi .h in include
##

CC	=	gcc -g3

SRC	=	hashb.c	\
		hash.c	\
		int_to_str.c	\
		my_cleanstr.c	\
		my_compute_power_rec.c	\
		my_compute_square_root.c	\
		my_destroy_tab.c	\
		my_fastcmp.c	\
		my_find_char.c	\
		my_find_prime_sup.c	\
		my_get_filename.c	\
		my_getnbr.c	\
		my_get_next_line.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_printf.c	\
		my_print_fct1.c	\
		my_print_fct2.c	\
		my_print_fct3.c	\
		my_putchar.c	\
		my_put_llnbr.c	\
		my_putnbr_base.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_puttab.c	\
		my_put_ull.c	\
		my_replace_char.c	\
		my_revstr.c	\
		my_showmem.c	\
		my_showstr.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_strdup.c	\
		my_str_isalpha.c	\
		my_str_isalphanum.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_str_to_word_array.c	\
		my_strupcase.c	\
		my_swap.c	\
		my_tab_len.c	\
		put_a_square_csfml.c	\
		sum_n_even_numbers.c	\
		sum_n_odd_numbers.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my

NAMELIB	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc lib$(NAME).a $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMELIB)

re:	fclean all
