/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** update.c
*/

#include "rpg.h"

void add_item_stats(slot_t *slot, game_t *game)
{
	PLAYER_HEALTH += slot->item->stats.health;
	PLAYER_MAX_HP += slot->item->stats.health;
	PLAYER_ARMOR += slot->item->stats.armor;
	PLAYER_SPECIALITY += slot->item->stats.special;
	PLAYER_DAMAGES += slot->item->stats.damages;
}

void remove_item_stats(slot_t *slot, game_t *game)
{
	PLAYER_HEALTH -= slot->item->stats.health;
	PLAYER_MAX_HP -= slot->item->stats.health;
	PLAYER_ARMOR -= slot->item->stats.armor;
	PLAYER_SPECIALITY -= slot->item->stats.special;
	PLAYER_DAMAGES -= slot->item->stats.damages;
}

void update_all_stats(game_t *game)
{
	scene_t *stats = hm_get(SCENES, "STATS");
	scene_t *bar = hm_get(SCENES, "HEALTH_HUD");

	if (!stats || !bar)
		return;
	update_stats(stats, game);
	update_stats(bar, game);
}

void update_item_stats(sfBool add, slot_t *slot, game_t *game)
{
	sfVector2f pos_tab[6] = {HELMET_POS, CHEST_POS, PANTS_POS, WEAPON_POS,
	GAUNTLETS_POS, V2F(-1, -1)};
	int i = 0;

	for (; i != 6; i++) {
		if (slot->pos.x == pos_tab[i].x && slot->pos.y == pos_tab[i].y)
			break;
	}
	if (pos_tab[i - 1].x == -1)
		return;
	if (add == sfTrue)
		add_item_stats(slot, game);
	else
		remove_item_stats(slot, game);
	update_all_stats(game);
}