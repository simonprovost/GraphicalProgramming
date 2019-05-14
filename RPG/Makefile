##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## all clean fclean re
##

SRC	=	src/main.c						\
		src/error_handlings_args.c				\
		src/init/buttons.c					\
		src/init/libs.c						\
		src/init/list_filling.c					\
		src/init/map.c						\
		src/init/zone.c						\
		src/init/inventory.c					\
		src/init/player.c					\
		src/init/entity.c					\
		src/init/scenes.c					\
		src/init/window.c					\
		src/init/game.c						\
		src/init/battle.c					\
		src/init/free_destroy/lobby.c				\
		src/init/free_destroy/list.c				\
		src/init/free_destroy/entity.c				\
		src/init/free_destroy/struct.c				\
		src/init/free_destroy/particles.c			\
		src/init/free_destroy/libs.c				\
		src/init/free_destroy/map.c				\
		src/init/read/savior.c					\
		src/init/read/file_analysing.c				\
		src/init/keys/audio.c					\
		src/init/keys/fonts.c					\
		src/init/keys/map.c					\
		src/init/keys/scene_01.c				\
		src/init/keys/scene_02.c				\
		src/init/keys/texture_01.c				\
		src/init/keys/texture_02.c				\
		src/init/keys/items.c					\
		src/init/keys/zone.c					\
		src/init/keys/monster.c					\
		src/init/keys/npc_01.c					\
		src/init/keys/npc_02.c					\
		src/save/lobby.c					\
		src/save/load.c						\
		src/list_management/create_01.c				\
		src/list_management/create_02.c				\
		src/list_management/add.c				\
		src/list_management/remove.c				\
		src/list_management/read.c				\
		src/list_management/get.c				\
		src/inventory/button.c					\
		src/inventory/get.c					\
		src/inventory/add.c					\
		src/inventory/lobby.c					\
		src/inventory/manage_buttons.c				\
		src/inventory/update_item_stats.c			\
		src/inventory/update_info_item.c			\
		src/inventory/update.c			\
		src/game/engine.c					\
		src/game/lobby.c					\
		src/game/start.c					\
		src/game/npcs.c						\
		src/game/music.c					\
		src/game/display/lobby.c				\
		src/game/display/map.c					\
		src/game/display/objs.c					\
		src/game/display/texts.c				\
		src/game/display/mouse.c				\
		src/game/display/animate.c				\
		src/game/dialogues.c					\
		src/game/action.c					\
		src/game/battle/init.c					\
		src/game/battle/update_battle_hud.c			\
		src/game/battle/display.c				\
		src/game/battle/attack.c				\
		src/game/battle/select_enemy.c				\
		src/game/battle/end_screen.c				\
		src/game/battle/lobby.c 				\
		src/game/battle/manage/hit.c 				\
		src/game/battle/manage/versus_animation.c 		\
		src/game/battle/manage/special_hit.c			\
		src/game/battle/manage/wait_enemy.c			\
		src/game/battle/manage/loot.c				\
		src/game/battle/battle_utils.c				\
		src/game/battle/init_end_screen.c			\
		src/game/battle/run_away.c				\
		src/game/battle/special.c				\
		src/game/battle/nothing.c				\
		src/game/battle/utils.c					\
		src/game/battle/clean_battle_scenes.c			\
		src/game/battle/init_boss_battle.c			\
		src/game/mouse/replace.c 				\
		src/hud/buttons/area.c					\
		src/hud/buttons/control_key.c 				\
		src/hud/buttons/credits.c 				\
		src/hud/buttons/exit.c 					\
		src/hud/buttons/frame_rate.c 				\
		src/hud/buttons/inventory.c 				\
		src/hud/buttons/how_to_play.c 				\
		src/hud/buttons/key_game.c 				\
		src/hud/buttons/main_menu.c 				\
		src/hud/buttons/map.c 					\
		src/hud/buttons/new_game.c 				\
		src/hud/buttons/option.c 				\
		src/hud/buttons/pause.c 				\
		src/hud/buttons/quetes.c 				\
		src/hud/buttons/quit.c 					\
		src/hud/buttons/reload.c 				\
		src/hud/buttons/resume.c 				\
		src/hud/buttons/save.c 					\
		src/hud/buttons/song.c 					\
		src/hud/buttons/stats.c 				\
		src/hud/buttons/cross.c					\
		src/hud/scene_hide_and_display.c 			\
		src/hud/life.c						\
		src/hud/opacity.c					\
		src/hud/process.c 					\
		src/hud/loading.c 					\
		src/hud/manage_text_loading.c 				\
		src/hud/manage_xp.c					\
		src/player/movements/move_player.c			\
		src/player/movements/move_player_area.c			\
		src/player/movements/move_player_zone.c			\
		src/player/movements/set_player_pos.c			\
		src/player/movements/smooth_move.c			\
		src/player/movements/is_player_moving.c			\
		src/player/animations/player_anim.c			\
		src/player/stats/stats.c				\
		src/warnings/unexisting_01.c				\
		src/warnings/unexisting_02.c				\
		src/warnings/invalid_01.c				\
		src/warnings/invalid_02.c				\
		src/warnings/invalid_03.c				\
		src/warnings/already_existing_01.c			\
		src/warnings/already_existing_02.c			\
		src/warnings/already_existing_03.c			\
		src/warnings/already_existing_04.c			\
		src/warnings/missing.c					\
		src/warnings/undefined_01.c				\
		src/warnings/undefined_02.c				\
		src/warnings/ingame.c					\
		src/particles/particle_spawn.c				\
		src/particles/particle_sys.c				\
		src/particles/particles_create.c			\
		src/particles/rain.c					\
		src/particles/free_system.c				\
		src/particles/feet_particles.c				\
		src/intro/lobby.c					\
		src/init/init_particles.c				\
		src/daynightcycle/daynightcycle.c			\
		src/quests/quest_1.c					\
		src/quests/quest_2.c					\
		src/quests/quest_3.c					\
		src/quests/xp.c						\

OBJS	=	$(SRC:.c=.o)

NAME_BINARY	=	my_rpg

NAME	=	my_rpg

NAME2	=	unit-tests

CFLAGS	=	 -Wall -Wextra -W -g3 -I./include/ -lc_graph_prog

LDFLAGS	=	-L./lib/llist/ -lllist -L./lib/my/ -lmy -lm

CC	=	gcc

_END=$'\x1b[0m'
_RED=$'\x1b[31m'
NO_OF_FILES := $(words $(SRC))

all:	prepare_lib $(NAME)

prepare_lib:
	make -C lib/

map:	prepare_lib
	make -C bonus/map_creator/
	mv bonus/map_creator/map_editor ./

tests_run:	prepare_lib
	make -C tests/
	tests/unit-tests


$(NAME):	$(OBJS)
	@ echo "\033[1;36m[ FILES COMPILED ] \033[0m \033[1;35m$(NO_OF_FILES)\033[0m"
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS) $(CFLAGS)
	@ echo "\033[1;31m ------------------Name of Binary : \033[1;35m$(NAME)\033[0;31m®\033[1;31m Created Sucesfully ------------------\033[0m"

clean_map:
	make clean -C bonus/map_creator

fclean_map:
	make fclean -C bonus/map_creator

clean:
	make clean -C lib/
	make clean -C tests/
	$(RM) $(OBJS)

fclean:	clean
	make fclean -C lib/
	make fclean -C tests/
	$(RM) $(NAME)

re:	fclean all
re_game: fclean game


%.o:	%.c
	@ echo "\033[1;35m[ OK ]\033[0m Compiling" $<
	@ $(CC) -o $@ -c $< $(CFLAGS)

.SILENT:
