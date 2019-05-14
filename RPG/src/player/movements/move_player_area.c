/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_b.c created: 22/03/18 18:50
*/

#include <my.h>
#include <rpg.h>

bool move_player_aera_up(game_t *game)
{
	if (AREA_COOR_Y - 1 < 0)
		return (move_player_zone(UP, game));
	if (!(MAP.areas[AREA_COOR_Y - 1][AREA_COOR_X].name))
		return (false);
	TILE_COOR_Y = TILE_TAB_Y - 2;
	AREA_COOR_Y--;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	set_initial_player_pos(game);
	return (true);
}

bool move_player_aera_down(game_t *game)
{
	if (AREA_COOR_Y + 1 >= AREA_TAB_Y)
		return (move_player_zone(DOWN, game));
	if (!(MAP.areas[AREA_COOR_Y + 1][AREA_COOR_X].name))
		return (false);
	TILE_COOR_Y = -1;
	AREA_COOR_Y++;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	set_initial_player_pos(game);
	return (true);
}

bool move_player_aera_left(game_t *game)
{
	if (AREA_COOR_X - 1 < 0)
		return (move_player_zone(LEFT, game));
	if (!(MAP.areas[AREA_COOR_Y][AREA_COOR_X - 1].name))
		return (false);
	TILE_COOR_X = TILE_TAB_X - 1;
	AREA_COOR_X--;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	set_initial_player_pos(game);
	return (true);
}

bool move_player_aera_right(game_t *game)
{
	if (AREA_COOR_X + 1 >= AREA_TAB_X)
		return (move_player_zone(RIGHT, game));
	if (!(MAP.areas[AREA_COOR_Y][AREA_COOR_X + 1].name))
		return (false);
	TILE_COOR_X = 0;
	AREA_COOR_X++;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	set_initial_player_pos(game);
	return (true);
}

bool move_player_area(direction_t dir, game_t *game)
{
	switch (dir) {
		case UP:
			return (move_player_aera_up(game));
		case DOWN:
			return (move_player_aera_down(game));
		case LEFT:
			return (move_player_aera_left(game));
		case RIGHT:
			return (move_player_aera_right(game));
	}
	return (false);
}