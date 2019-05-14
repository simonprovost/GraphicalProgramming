/*
** EPITECH PROJECT, 2018
** Sans titre(Espace de travail)
** File description:
** right_events
*/

#include "map_editor.h"

void put_rec_to_black(obj_t *obj)
{
	sfRectangleShape_setTexture(obj->obj, NULL, 1);
	sfRectangleShape_setFillColor(obj->obj, sfBlack);
}

void remove_tile_from_list(my_w_t *window)
{
	tile_list_t *tmp = TILE_LIST;

	if (!tmp->next)
		put_rec_to_black(tmp->tile);
	while (tmp->next && tmp->next->next)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void check_click_for_remove(ressources_t *rsces, my_w_t *window, int i, int j)
{
	v2i pos = sfMouse_getPositionRenderWindow(rsces->window);
	area_t area = AREA;

	if (button_is_clicked(area.tiles[i][j].displayed_tiles->tile->obj,
									pos)) {
		TILE_COOR_Y = i;
		TILE_COOR_X = j;
		remove_tile_from_list(rsces->rsces);
	}
}

void check_position_for_remove_in_map(ressources_t *rsces, my_w_t *window)
{
	for (int i = 0; i < TILE_TAB_Y; i++) {
		for (int j = 0; j < TILE_TAB_X; j++)
			check_click_for_remove(rsces, window, i, j);
	}
}

void right_click_event(ressources_t *rsces, texture_list_t *list)
{
	(void)list;
	check_position_for_remove_in_map(rsces, rsces->rsces);
}