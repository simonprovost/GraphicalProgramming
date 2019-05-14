/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** draw_list
*/

#include "map_editor.h"

void draw_texture_list(texture_list_t *list, sfRenderWindow *window)
{
	while (list) {
		sfRenderWindow_drawRectangleShape(window, list->rec, NULL);
		list = list->next;
	}
}