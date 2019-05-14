/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** tile_block
*/

#include "map_editor.h"

void add_block_filter(ressources_t *rsces, my_w_t *window)
{
	tile_list_t *tmp = TILE.displayed_tiles;

	(void)rsces;
	while (tmp->next)
		tmp = tmp->next;
	sfRectangleShape_setFillColor(tmp->tile->obj, OVER_COLOR);
}

void remove_block_filter(ressources_t *rsces, my_w_t *window)
{
	tile_list_t *tmp = TILE.displayed_tiles;

	(void)rsces;
	while (tmp->next)
		tmp = tmp->next;
	sfRectangleShape_setFillColor(tmp->tile->obj, REGULAR_COLOR);
}

void check_click_for_block(ressources_t *rsces, my_w_t *window, int i, int j)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);
	area_t *area = &AREA;

	if (button_is_clicked(area->tiles[i][j].displayed_tiles->tile->obj,
									pos)) {
		TILE_COOR_Y = i;
		TILE_COOR_X = j;
		if (!sfRectangleShape_getTexture(area->tiles[i][j]. \
		displayed_tiles->tile->obj))
			return;
		if (!area->tiles[i][j].block) {
			area->tiles[i][j].block = true;
			add_block_filter(rsces, window);
		} else {
			area->tiles[i][j].block = false;
			remove_block_filter(rsces, window);
		}
	}
}