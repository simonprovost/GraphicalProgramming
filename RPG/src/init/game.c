/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_tools(game_t *game)
{
	MOUSE_POS = V2I(0, 0);
	if (reset_mouse_skin(game) != 0)
		return (84);
	CLICK_RELEASED = sfTrue;
	FRAMERATE = 60;
	return (0);
}

void init_key_player(game_t *game)
{
	KEY_PLAYER.up = sfKeyZ;
	KEY_PLAYER.down = sfKeyS;
	KEY_PLAYER.left = sfKeyQ;
	KEY_PLAYER.right = sfKeyD;
	KEY_PLAYER.arrow_up = sfKeyUp;
	KEY_PLAYER.arrow_down = sfKeyDown;
	KEY_PLAYER.arrow_left = sfKeyLeft;
	KEY_PLAYER.arrow_right = sfKeyRight;
}

int set_game_version(game_t *game)
{
	if (!game
	|| !SCENES)
		my_printf("fail\n");
	scene_t *scene = hm_get(SCENES, PAUSE_GAME);
	bucket_t *text = NULL;

	if (!scene)
		return (84);
	text = hm_get_bucket(scene->texts, "VERSION_GAME");
	if (check_unexisting_text(text, "VERSION_GAME", PAUSE_GAME) != 0)
		return (84);
	sfText_setString(text->value, VERSION_GAME);
	return (0);
}

int init_movement(game_t *game)
{
	game->movement.target_tile = (sfVector2i) {0, 0};
	game->movement.anim_mult = 1;
	game->movement.is_moving = sfFalse;
	if (init_timer(&game->movement.timer) != 0)
		return (84);
	return (0);
}

int init_game(game_t *game, window_t *window)
{
	game->displayed_scenes = NULL;
	game->window = window;
	game->loading = false;
	if (init_map(game) != 0
	|| init_libs(game) != 0
	|| init_scenes(game) != 0
	|| init_inventory(game) != 0
	|| init_buttons(game) != 0
	|| init_particles(game) != 0
	|| init_tools(game) != 0
	|| init_day_night_cycle(game) != 0
	|| set_game_version(game) != 0
	|| init_movement(game) != 0)
		return (84);
	init_key_player(game);
	init_player(game);
	init_battle(game);
	return (0);
}