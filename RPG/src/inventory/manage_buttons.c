/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int is_button_clicked(obj_t *button, slot_t *slot, game_t *game)
{
	if (click_button((button), MOUSE_POS, sfMouseLeft) == 0
	&& click_button((button), MOUSE_POS, sfMouseRight) == 0){
		sfRectangleShape_setFillColor(button->obj,
		OVER_ITEM_COLOR);
	} else if (click_button((button), MOUSE_POS, sfMouseLeft) == 1
	&& CLICK_RELEASED == sfTrue) {
		CLICK_RELEASED = sfFalse;
		make_sound("SELECT_SOUND", game);
		return (button->callback ?
		button->callback(slot, game) : 84);
	} else if (click_button((button), MOUSE_POS, sfMouseRight) == 1
	&& CLICK_RELEASED == sfTrue) {
		CLICK_RELEASED = sfFalse;
		make_sound("SELECT_SOUND", game);
		return (slot->item ? display_item_stats(slot, game) : 0);
	}
	return (0);
}

int process_inventory_button_over(slot_t *slot, game_t *game)
{
	obj_t *button = slot->slot;

	if (button_fly_over(button, MOUSE_POS) == 1) {
		return (is_button_clicked(button, slot, game));
	} else if (!game->movement.is_moving
	&& sfRectangleShape_getFillColor(button->obj).a == 255)
		sfRectangleShape_setFillColor(button->obj, REGULAR_COLOR);
	return (0);
}

int manage_slots_buttons_line(int y, game_t *game)
{
	for (int x = 0; x != INVENTORY_SIZE_X; x++) {
		if (process_inventory_button_over(&ITEMS[y][x], game) != 0)
			return (84);
	}
	return (0);
}

int manage_slots_buttons(game_t *game)
{
	for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
		if (manage_slots_buttons_line(y, game) != 0)
			return (84);
	}
	return (0);
}

int manage_inventory_buttons(game_t *game)
{
	if (manage_slots_buttons(game) != 0)
		return (84);
	if (process_inventory_button_over(&HELMET, game) != 0
	|| process_inventory_button_over(&CHEST, game) != 0
	|| process_inventory_button_over(&GAUNTLETS, game) != 0
	|| process_inventory_button_over(&WEAPON, game) != 0
	|| process_inventory_button_over(&PANTS, game) != 0)
		return (84);
	return (0);
}
