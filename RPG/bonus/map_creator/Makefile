##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	src/init/file_analysing.c			\
		src/init/init_from_file_readed.c		\
		src/init/list_filling_init.c			\
		src/init/init_libs.c				\
		src/init/init_map.c				\
		src/init/texture_keys_functions_01.c		\
		src/init/texture_keys_functions_02.c		\
		src/init/map_keys_functions.c			\
		src/init/zone_keys_functions.c			\
		src/init/my_initializer.c			\
		src/warnings/init_warning_unexisting.c		\
		src/warnings/init_warning_invalid.c		\
		src/warnings/init_warning_invalid_02.c		\
		src/warnings/init_warning_already_existing_01.c	\
		src/warnings/init_warning_already_existing_02.c	\
		src/warnings/init_warning_already_existing_03.c	\
		src/warnings/init_warning_missing.c		\
		src/warnings/init_warning_undefined.c		\
		src/map_creator/events.c			\
		src/map_creator/main.c				\
		src/map_creator/seek_zone.c			\
		src/map_creator/draw_list.c			\
		src/map_creator/display_map.c			\
		src/map_creator/button_clicked.c		\
		src/map_creator/move_rect.c			\
		src/map_creator/tile_block.c			\
		src/map_creator/left_event.c			\
		src/map_creator/right_event.c			\
		src/map_creator/add_texture.c			\
		src/map_creator/read_hashmap.c			\
		src/map_creator/write_area.c			\
		src/map_creator/save_map.c			\
		src/list_management/objs_list_create.c		\
		src/list_management/objs_list_add.c		\
		src/list_management/objs_list_remove.c		\
		src/free_destroy/free_and_destroy_lobby.c	\

OBJS	=	$(SRC:.c=.o)

NAME	=	map_editor

LFLAGS	=	-lcsfml-graphics -lcsfml-audio -lcsfml-system -lcsfml-window
#-lc_graph_prog

CFLAGS	=	-Wall -Wextra -W -g3 -I./include \
		-L./../../lib/my -lmy -lm

CC	=	gcc

all:	prepare_lib $(NAME)

prepare_lib:
	make -C ../../lib/my

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(CFLAGS) $(LFLAGS)

clean:
	make clean -C ../../lib/my
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C ../../lib/my/
	$(RM) $(NAME)

re:	fclean all
