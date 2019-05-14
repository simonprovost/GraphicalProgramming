/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** left_event
*/

#include "map_editor.h"

void replace_black_tile(sfTexture *texture, char *name, my_w_t *window)
{
	tile_list_t *tmp = TILE_LIST;

	sfRectangleShape_setTexture(tmp->tile->obj, texture, 1);
	sfRectangleShape_setFillColor(tmp->tile->obj, REGULAR_COLOR);
	tmp->tile->name = name;
}

void check_click_for_add(ressources_t *rsces, my_w_t *window, int i, int j)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);
	area_t area = AREA;

	if (button_is_clicked(area.tiles[i][j].displayed_tiles->tile->obj,
									pos)) {
		TILE_COOR_Y = i;
		TILE_COOR_X = j;
		if (sfRectangleShape_getTexture(area.tiles[i][j]. \
		displayed_tiles->tile->obj))
			add_tile_to_list(rsces->selected_texture_name, window);
		else
			replace_black_tile(rsces->selected,
					rsces->selected_texture_name, window);
	}
}

void check_position_in_map(ressources_t *rsces, my_w_t *window)
{
	for (int i = 0; i < TILE_TAB_Y; i++) {
		for (int j = 0; j < TILE_TAB_X; j++)
			rsces->mode == 0 ? check_click_for_add(rsces, \
			window, i, j) : check_click_for_block(rsces, \
			window, i, j);
	}
}

void check_position_in_texture_list(ressources_t *rsces, texture_list_t *list)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);

	while (list) {
		if (button_is_clicked(list->rec, pos)) {
			rsces->selected = list->texture;
			rsces->selected_texture_name = list->name;
			return;
		}
		list = list->next;
	}
}

void left_click_event(ressources_t *rsces, texture_list_t *list)
{
	check_position_in_map(rsces, rsces->rsces);
	check_position_in_texture_list(rsces, list);
	return;
}