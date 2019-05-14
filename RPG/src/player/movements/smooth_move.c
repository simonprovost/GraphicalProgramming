/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** smooth_move.c created: 18/04/18
*/

#include <rpg.h>
#include <SFML/Audio.h>

void set_initial_player_pos(game_t *game)
{
	sfRectangleShape_setPosition(game->player.character->obj, \
	(sfVector2f) {TILE_COOR_X * 50, TILE_COOR_Y * 50});
}

bool is_pressing_controls(game_t *game)
{
	if (sfKeyboard_isKeyPressed(KEY_UP)
	|| sfKeyboard_isKeyPressed(KEY_DOWN)
	|| sfKeyboard_isKeyPressed(KEY_LEFT)
	|| sfKeyboard_isKeyPressed(KEY_RIGHT)
	|| sfKeyboard_isKeyPressed(ARROW_KEY_UP)
	|| sfKeyboard_isKeyPressed(ARROW_KEY_DOWN)
	|| sfKeyboard_isKeyPressed(ARROW_KEY_LEFT)
	|| sfKeyboard_isKeyPressed(ARROW_KEY_RIGHT))
		return (true);
	return (false);
}

void stop_anim(game_t *game, sfVector2i *target_pos)
{
	TILE_COOR_X = target_pos->x;
	TILE_COOR_Y = target_pos->y;
	game->player.character->obj_rect.animated = sfFalse;
	if (!is_pressing_controls(game))
		set_waiting_player_rect(game);
}

void smooth_move_player(game_t *game)
{
	sfVector2i act_pos = MAP.tile_coord;
	sfVector2i *target_pos = &(game->movement.target_tile);
	sfVector2f s_pos;
	static bool is_check = false;

	if (!is_check) {
		set_initial_player_pos(game);
		is_check = true;
	}
	s_pos = sfRectangleShape_getPosition(PLAYER.character->obj);
	if (!game->player.character->obj_rect.animated)
		return;
	if (s_pos.x == target_pos->x * 50 && s_pos.y == target_pos->y * 50) {
		stop_anim(game, target_pos);
		return;
	}
	if (act_pos.x == target_pos->x && act_pos.y == target_pos->y)
		return;
	sfRectangleShape_move(PLAYER.character->obj, (sfVector2f) \
	{(target_pos->x - act_pos.x) * 5, (target_pos->y - act_pos.y) * 5});
}