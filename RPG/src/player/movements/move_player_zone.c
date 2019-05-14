/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player_zone.c created: 22/03/18 18:52
*/

#include <my.h>
#include <rpg.h>

bool move_player_zone_up(game_t *game)
{
	if (ZONE_COOR_Y - 1 < 0) {
		return (false);
	}
	unload_my_zone(game);
	TILE_COOR_Y = TILE_TAB_Y - 2;
	AREA_COOR_Y = AREA_TAB_X - 1;
	ZONE_COOR_Y--;
	load_my_zone(game);
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	check_rain(game);
	return (true);
}

bool move_player_zone_down(game_t *game)
{
	if (ZONE_COOR_Y + 1 >= ZONE_TAB_X) {
		return (false);
	}
	unload_my_zone(game);
	TILE_COOR_Y = 0;
	AREA_COOR_Y = 0;
	ZONE_COOR_Y++;
	load_my_zone(game);
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	check_rain(game);
	return (true);
}

bool move_player_zone_left(game_t *game)
{
	if (ZONE_COOR_X - 1 < 0) {
		return (false);
	}
	unload_my_zone(game);
	TILE_COOR_X = TILE_TAB_X - 1;
	AREA_COOR_X = AREA_TAB_Y - 1;
	ZONE_COOR_X--;
	load_my_zone(game);
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	check_rain(game);
	return (true);
}

bool move_player_zone_right(game_t *game)
{
	if (ZONE_COOR_X - 1 >= ZONE_TAB_Y) {
		return (false);
	}
	unload_my_zone(game);
	TILE_COOR_X = 0;
	AREA_COOR_X = 0;
	ZONE_COOR_X++;
	load_my_zone(game);
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X, TILE_COOR_Y};
	check_rain(game);
	return (true);
}

bool move_player_zone(direction_t dir, game_t *game)
{
	switch (dir) {
		case UP:
			return (move_player_zone_up(game));
		case DOWN:
			return (move_player_zone_down(game));
		case LEFT:
			return (move_player_zone_left(game));
		case RIGHT:
			return (move_player_zone_right(game));
	}
	return (false);
}