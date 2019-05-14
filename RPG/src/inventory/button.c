/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_item_stats(slot_t *slot, game_t *game)
{
	static char *old_scene = NULL;
	scene_t *stats_scene = hm_get(game->scenes, STATS_GAME);
	obj_t *ico_item = hm_get(stats_scene->objs, "ITEM_ICO");

	if (!slot || !game || !slot->item || !slot->item->name)
		return (84);
	if (get_scene_from_displayed(STATS_GAME, game) == NULL) {
		if (my_strcmp(CURRENT_BUCKET->key, "STATS"))
			old_scene = CURRENT_BUCKET->key;
		if (button_display_hide_scene(STATS_GAME,
		&update_stats, game, old_scene) == 84)
			return (84);
	}
	if (update_item_info(slot, game) != 0)
		return (84);
	sfRectangleShape_setTexture(ico_item->obj,
	sfRectangleShape_getTexture(slot->item->obj->obj), sfTrue);
	return (0);
}

int select_slot(slot_t *slot, game_t *game)
{
	if (!slot->item)
		return (0);
	ITEM_SELECTED = slot->item;
	update_item_stats(sfFalse, slot, game);
	if (replace_mouse_skin(slot->item->obj, &V2F(16, 16), game) != 0)
		return (84);
	slot->item = NULL;
	return (0);
}

int drop_slot(slot_t *slot, game_t *game)
{
	item_t *tmp;

	if (!slot->item) {
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		update_item_stats(sfTrue, slot, game);
		return (reset_mouse_skin(game));
	} else {
		tmp = slot->item;
		update_item_stats(sfFalse, slot, game);
		slot->item = ITEM_SELECTED;
		sfRectangleShape_setPosition(slot->item->obj->obj, slot->pos);
		ITEM_SELECTED = NULL;
		ITEM_SELECTED = tmp;
		update_item_stats(sfTrue, slot, game);
		return (replace_mouse_skin(ITEM_SELECTED->obj,
		&V2F(16, 16), game));
	}
	return (0);
}

int click_slot(slot_t *slot, game_t *game)
{
	if (!slot || !game)
		return (84);
	if (!ITEM_SELECTED) {
		return (select_slot(slot, game));
	} else {
		return (drop_slot(slot, game));
	}
	return (0);
}
