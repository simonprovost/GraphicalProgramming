/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** end_screen
*/

#include "rpg.h"

int update_type_rarity(scene_t *scene, char *item)
{
	char *type = get_item_type(item);
	char *rarity = get_item_rarity(item);
	sfText *txt_type = hm_get(scene->texts, "TYPE");
	sfText *txt_rarity = hm_get(scene->texts, "RARITY");

	if (!txt_type || !txt_rarity)
		return (84);
	sfText_setString(txt_type, my_strcat("TYPE      ", type));
	sfText_setString(txt_rarity, my_strcat("RARITY    ", rarity));
	return (0);
}

int compute_xp_won(game_t *game)
{
	int bonus = 3;
	int xp = 0;
	int bonus_sup = (rand() % 20) - 9;

	if (!my_strcmp(ZONE_NAME, "MORIA"))
		bonus = 1;
	else if (!my_strcmp(ZONE_NAME, "CURSED_FOREST"))
		bonus = 2;
	xp = (NBR_ENEMIES * 40 * bonus) + bonus_sup;
	if (add_xp_to_player(game, xp) == 84)
		return (84);
	return (xp);
}

int compute_gold_won(game_t *game)
{
	int bonus = 3;
	int gold = 0;
	int bonus_sup = (rand() % 20) - 9;

	if (!my_strcmp(ZONE_NAME, "MORIA"))
		bonus = 1;
	else if (!my_strcmp(ZONE_NAME, "CURSED_FOREST"))
		bonus = 2;
	gold = (NBR_ENEMIES * 20 * bonus) + bonus_sup;
	GOLDS += gold;
	return (gold);
}

int update_battle_result(game_t *game, scene_t *end_screen)
{
	sfText *xp = hm_get(end_screen->texts, "XP");
	sfText *gold = hm_get(end_screen->texts, "GOLD");
	sfText *found = hm_get(end_screen->texts, "FOUND");
	obj_t *item_icon = hm_get(end_screen->objs, "ITEM");
	char *item_name = compute_loot(game);
	item_t *item = create_item(item_name, game);

	if (!xp || !found || !item_icon || !gold)
		return (84);
	sfText_setString(xp, my_strcat(":   ", XP_WON));
	sfText_setString(gold, my_strcat(":   ", GOLD_WON));
	if (item) {
		sfRectangleShape_setTexture(item_icon->obj,
		sfRectangleShape_getTexture(item->obj->obj), sfTrue);
		sfText_setString(found, "YOU GOT AN ITEM!");
		if (update_type_rarity(end_screen, item_name) == 84
		|| add_item(item, game) == 84)
			return (84);
	}
	return (0);
}

int battle_end_screen(game_t *game, char *result)
{
	scene_t *end_screen = hm_get(SCENES, "WIN_SCREEN");
	sfText *res = NULL;

	if (!game || !end_screen)
		return (84);
	if (!(res = hm_get(end_screen->texts, "RESULT")))
		return (84);
	if (init_end_screen(game, end_screen) == 84)
		return (84);
	clean_battle_scenes(game);
	if (!my_strcmp(result, "WIN")) {
		sfText_setString(res, "YOU  WIN !");
		if (update_battle_result(game, end_screen) == 84)
			return (84);
	} else
		PLAYER_HEALTH = 0;
	return (1);
}