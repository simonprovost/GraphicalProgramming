/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** init_end_screen
*/

#include "rpg.h"

int init_end_screen(game_t *game, scene_t *end_screen)
{
	sfText *xp = hm_get(end_screen->texts, "XP");
	sfText *gold = hm_get(end_screen->texts, "GOLD");
	sfText *found = hm_get(end_screen->texts, "FOUND");
	sfText *result = hm_get(end_screen->texts, "RESULT");
	sfText *type = hm_get(end_screen->texts, "TYPE");
	sfText *rarity = hm_get(end_screen->texts, "RARITY");
	obj_t *item = hm_get(end_screen->objs, "ITEM");
	texture_t *texture = hm_get(TEXTURES_LIB, "EMPTY_ITEM");

	if (!xp || !gold || !found || !item)
		return (84);
	sfText_setString(xp, ":   0");
	sfText_setString(gold, ":   0");
	sfText_setString(found, "NO ITEMS FOUND");
	sfText_setString(result, "YOU  LOSE");
	sfText_setString(type, " ");
	sfText_setString(rarity, " ");
	sfRectangleShape_setTexture(item->obj, texture->texture, sfTrue);
	return (0);
}