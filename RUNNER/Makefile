##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=  main.c \
src/window_create.c \
src/display_all.c \
src/fill_divers.c \
src/poll_event.c \
src/time_clock.c \
src/move_rect.c \
src/add_type.c \
src/fill_object.c \
src/create_object.c \
src/fill_var.c \
src/collider_box.c \
src/fill_player_assets.c \
src/top_collider.c \
src/player_glide.c \
src/player_fly_up.c \
src/player_fly_down.c \
src/player_walk.c \
src/init_rect.c \
src/destroy_clock.c \
src/destroy_sprite.c \
src/destroy_texture.c \
src/destroy_window.c \
src/destroy_all.c \
src/free_all.c \
src/malloc_struct_all.c \
src/fill_all.c \
src/manage_player.c \
src/create_player.c \
src/manage_before_game.c \
src/fill_enemy.c \
src/create_enemy.c \
src/my_itoa.c \
src/my_strlen.c \
src/assign_w_h.c \
src/fs_open_file.c \
src/parsing_map.c \
src/colider_enemy_player.c \
src/gui.c \
src/menu/menu_begin/menu_begin.c \
src/poll_event_finish.c \
src/draw_element_display.c \
src/notify_mission_obstacle.c

OBJ	=	$(SRC:.c=.o)

CC	= 	gcc

NAME	=	my_runner

CFLAGS	=	-I./include -Wall -Wextra -W -lcsfml-window -lcsfml-system -lcsfml-audio -lcsfml-graphics -lm
#-lc_graph_prog

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
