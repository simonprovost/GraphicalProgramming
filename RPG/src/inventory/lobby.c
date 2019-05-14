/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** lobby.c
*/

#include "rpg.h"

int display_item(slot_t *slot, window_t *window, game_t *game)
{
	if (slot && slot->item && slot->item->obj && slot->item->obj->obj)
		sfRenderWindow_drawRectangleShape(window->window,
			slot->item->obj->obj, NULL);
	(void)game;
	return (0);
}

void display_inventory(window_t *window, game_t *game)
{
	display_item(&HELMET, window, game);
	display_item(&CHEST, window, game);
	display_item(&GAUNTLETS, window, game);
	display_item(&PANTS, window, game);
	display_item(&WEAPON, window, game);
	items_foreach(game, window, &display_item);
}

int inventory_lobby(window_t *window, game_t *game)
{
	display_inventory(window, game);
	if (manage_inventory_buttons(game) != 0)
		return (84);
	return (0);
}