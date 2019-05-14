/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int init_slot(slot_t *slot, sfVector2f *pos, game_t *game)
{
	static char *chut[] = {"SLOT_HELMET", "SLOT_CHEST", "SLOT_PANTS",
	"SLOT_GAUNTLETS", "SLOT_WEAPON", "SLOT_00", "SLOT_01", "SLOT_02",
	"SLOT_03", "SLOT_04", "SLOT_10", "SLOT_11", "SLOT_12", "SLOT_13",
	"SLOT_14", "SLOT_20", "SLOT_21", "SLOT_22", "SLOT_23", "SLOT_24",
	"SLOT_30", "SLOT_31", "SLOT_32", "SLOT_33", "SLOT_34", "SLOT_40",
	"SLOT_41", "SLOT_42", "SLOT_43", "SLOT_44", NULL};
	static int i = 0;
	scene_t *inventory = hm_get(SCENES, "INVENTORY");

	if (!inventory)
		return (84);
	slot->item = NULL;
	slot->slot = hm_get(inventory->objs, chut[i]);
	if (!slot->slot || !slot->slot->obj)
		return (84);
	slot->pos = *pos;
	slot->slot->callback = &click_slot;
	i++;
	return (0);
}

int get_starting_items(game_t *game)
{
	if (add_new_to_slot("COMMON_HELMET_00", &HELMET_POS, &HELMET, game) != 0
	|| add_new_to_slot("COMMON_CHEST_00", &CHEST_POS, &CHEST, game) != 0
	|| add_new_to_slot("COMMON_PANTS_00", &PANTS_POS, &PANTS, game) != 0
	|| add_new_to_slot("COMMON_GAUNTLETS_00",
	&GAUNTLETS_POS, &GAUNTLETS, game) != 0) {
		my_printf("WARNING: ERROR IN STARTING ITEMS INITALISATION !\n");
		return (84);
	}
	return (0);
}

int init_inventory(game_t *game)
{
	GOLDS = 100;
	ITEM_SELECTED = NULL;
	init_slot(&HELMET, &HELMET_POS, game);
	init_slot(&CHEST, &CHEST_POS, game);
	init_slot(&PANTS, &PANTS_POS, game);
	init_slot(&GAUNTLETS, &GAUNTLETS_POS, game);
	init_slot(&WEAPON, &WEAPON_POS, game);
	items_foreach(game, NULL, init_slot);
	if (get_starting_items(game) != 0)
		return (84);
	return (0);
}
