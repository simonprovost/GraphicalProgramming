##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	= main.c \
	src/fill_var.c \
	src/fill_sprite.c \
	src/fill_vector.c \
	src/fill_divers.c \
	src/fill_sprite_texture.c \
	src/show_file.c \
	src/pos_duck_sigh.c \
	src/poll_event.c \
	src/time_clock.c \
	src/move_rect.c \
	src/manage_mouse_click.c \
	src/check_amazing_duck.c \
	src/check_if_win.c \
	src/my_rand.c \
	src/my_itoa.c \
	src/menu_finish.c \
	src/menu_begin.c \
	src/menu_samples/display_window_begin.c \
	src/menu_samples/fill_object.c \
	src/menu_samples/init_begin_text.c \
	src/menu_samples/init_begin.c \
	src/menu_samples/init_sprite.c \
	src/menu_samples/init_texture.c \
	src/m_finish/display_w_finish.c \
	src/m_finish/draw_next.c \
	src/m_finish/fill_all_elem.c \
	src/m_finish/fill_elem_menu.c \
	src/m_finish/fill_sprite_menu.c \
	src/m_finish/fill_text.c \
	src/m_finish/fill_texture.c \
	src/m_finish/init_text.c \
	src/m_finish/set_string.c \
	src/m_finish/show_yes_or_no.c \
	src/w_finish/display_window_finish_win.c \
	src/w_finish/draw_next_win.c \
	src/w_finish/fill_sprite_win.c \
	src/w_finish/fill_text_win.c \
	src/w_finish/fill_texture_win.c \
	src/w_finish/fill_win_elem.c \
	src/w_finish/init_text_win.c \
	src/w_finish/set_string_font_win.c \
	src/w_finish/show_yes_or_no_win.c \
	src/option_game/normal_game.c \
	src/clock_time_since_beginning.c \
	src/option_game/survival_game.c \
	src/src_survival/check_amazing_duck_surv.c \
	src/src_survival/check_if_win_surv.c \
	src/usage_func.c

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc

NAME	=	my_hunter

CFLAGS	=	-I./printf/include -g3 -I./include -Wall -Wextra -W

LDFLAGS	=	-L./printf/ -lmy -lcsfml-window -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-graphics -lm

all:	prepare_lib $(NAME)

prepare_lib:
	make -C printf/

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(LDFLAGS)

clean:
	make clean -C ./printf
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
