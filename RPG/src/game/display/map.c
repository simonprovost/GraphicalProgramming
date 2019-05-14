/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_tiles(sfVector2i *tile_coord, int priority,
window_t *window, game_t *game)
{
	int x = tile_coord->x;
	int y = tile_coord->y;
	tile_list_t *tmp = AREA.tiles[y][x].displayed_tiles;

	if (check_invalid_tile_display(tmp, x, y, game) != 0)
		return (84);
	while (tmp) {
		if (tmp->tile->priority == priority) {
			sfRenderWindow_drawRectangleShape(window->window,
				tmp->tile->obj, NULL);
			time_animation(tmp->tile, 0.1, window);
		}
		tmp = tmp->next;
	}
	if (priority == 3)
		sfRenderWindow_drawRectangleShape(window->window,
			game->player.character->obj, NULL);
	return (0);
}

int display_area(int priority, window_t *window, game_t *game)
{
	int my_errno = 0;

	for (int y = 0; y != TILE_TAB_Y; y++) {
		for (int x = 0; x != TILE_TAB_X; x++)
			my_errno += display_tiles(&V2I(x, y), priority,
				window, game);
	}
	if (my_errno != 0)
		return (84);
	return (0);
}

int display_map(window_t *window, game_t *game)
{
	if (check_invalid_map_display(game) != 0)
		return (84);
	for (int priority = 0; priority != PRIORITY_MAX + 1; priority++)
		if (display_area(priority, window, game) != 0)
			return (84);
	return (0);
}
