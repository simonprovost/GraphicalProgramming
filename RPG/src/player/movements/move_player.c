/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** move_player.c created: 22/03/18 18:31
*/

#include <my.h>
#include <rpg.h>
#include <SFML/Graphics/Rect.h>

bool move_player_up(game_t *game)
{
	game->player.character->obj_rect.rect_start.x = 0;
	game->player.character->obj_rect.rect_start.y = 300;
	game->player.character->obj_rect.rect_max.x = 100;
	game->player.character->obj_rect.rect_max.y = 300;
	game->player.character->obj_rect.rect_offset.x = 50;
	game->player.character->obj_rect.rect_offset.y = 0;
	set_anim_side(game);
	if (TILE_COOR_Y - 1 < -1)
		return (move_player_area(UP, game));
	if (AREA.tiles[TILE_COOR_Y][TILE_COOR_X].block) {
		game->player.character->obj_rect.animated = sfFalse;
		set_waiting_player_rect(game);
		return (false);
	}
	game->player.character->obj_rect.animated = sfTrue;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X,
							TILE_COOR_Y - 1};
	return (true);
}

bool move_player_down(game_t *game)
{
	game->player.character->obj_rect.rect_start.x = 0;
	game->player.character->obj_rect.rect_start.y = 0;
	game->player.character->obj_rect.rect_max.x = 100;
	game->player.character->obj_rect.rect_max.y = 0;
	game->player.character->obj_rect.rect_offset.x = 50;
	game->player.character->obj_rect.rect_offset.y = 0;
	set_anim_side(game);
	if (TILE_COOR_Y + 1 > TILE_TAB_Y - 2)
		return (move_player_area(DOWN, game));
	if (AREA.tiles[TILE_COOR_Y + 2][TILE_COOR_X].block) {
		game->player.character->obj_rect.animated = sfFalse;
		set_waiting_player_rect(game);
		return (false);
	}
	game->player.character->obj_rect.animated = sfTrue;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X,
							TILE_COOR_Y + 1};
	return (true);
}

bool move_player_left(game_t *game)
{
	game->player.character->obj_rect.rect_start.x = 0;
	game->player.character->obj_rect.rect_start.y = 100;
	game->player.character->obj_rect.rect_max.x = 100;
	game->player.character->obj_rect.rect_max.y = 100;
	game->player.character->obj_rect.rect_offset.x = 50;
	game->player.character->obj_rect.rect_offset.y = 0;
	set_anim_side(game);
	if (TILE_COOR_X - 1 <= -1)
		return (move_player_area(LEFT, game));
	if (AREA.tiles[TILE_COOR_Y + 1][TILE_COOR_X - 1].block) {
		game->player.character->obj_rect.animated = sfFalse;
		set_waiting_player_rect(game);
		return (false);
	}
	game->player.character->obj_rect.animated = sfTrue;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X - 1,
							TILE_COOR_Y};
	return (true);
}

bool move_player_right(game_t *game)
{
	game->player.character->obj_rect.rect_start.x = 0;
	game->player.character->obj_rect.rect_start.y = 200;
	game->player.character->obj_rect.rect_max.x = 100;
	game->player.character->obj_rect.rect_max.y = 200;
	game->player.character->obj_rect.rect_offset.x = 50;
	game->player.character->obj_rect.rect_offset.y = 0;
	set_anim_side(game);
	if (TILE_COOR_X + 1 > TILE_TAB_X - 1)
		return (move_player_area(RIGHT, game));
	if (AREA.tiles[TILE_COOR_Y + 1][TILE_COOR_X + 1].block) {
		game->player.character->obj_rect.animated = sfFalse;
		set_waiting_player_rect(game);
		return (false);
	}
	game->player.character->obj_rect.animated = sfTrue;
	game->movement.target_tile = (sfVector2i) {TILE_COOR_X + 1,
							TILE_COOR_Y};
	return (true);
}

bool move_player(direction_t dir, game_t *game)
{
	if (game->player.character->obj_rect.animated)
		return (false);
	switch (dir) {
		case UP:
			return (move_player_up(game));
		case DOWN:
			return (move_player_down(game));
		case LEFT:
			return (move_player_left(game));
		case RIGHT:
			return (move_player_right(game));
	}
	return (false);
}
