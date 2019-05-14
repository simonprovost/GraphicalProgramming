/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** add.c
*/

#include "rpg.h"

int add_new_to_slot(char *name, sfVector2f *pos, slot_t *slot, game_t *game)
{
	item_t *item = create_item(name, game);

	if (!item)
		return (84);
	slot->item = item;
	sfRectangleShape_setPosition(item->obj->obj, *pos);
	return (0);
}

int seek_item_place(int y, item_t *item, game_t *game)
{
	for (int x = 0; x != INVENTORY_SIZE_X; x++) {
		if (ITEMS[y][x].item == NULL) {
			ITEMS[y][x].item = item;
			sfRectangleShape_setPosition(item->obj->obj,
			SLOT_POS(x, y));
			return (1);
		}
	}
	return (0);
}

int add_item(item_t *item, game_t *game)
{
	bucket_t *inventory = hm_get_bucket(SCENES, "INVENTORY");

	if (!inventory)
		return (84);
	for (int y = 0; y != INVENTORY_SIZE_Y; y++) {
		if (seek_item_place(y, item, game) != 0)
			return (0);
	}
	update_no_place_dialogue(game);
	return (add_scene_to_display_list(inventory, game));
}