/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** set_hud_opacity
*/

#include "rpg.h"

void increment_opacity(sfRectangleShape *rec, int ratio)
{
	sfColor color = sfRectangleShape_getFillColor(rec);

	if ((ratio == -1 && color.a > 50) || (ratio == 1 && color.a < 255))
		color.a += (5 * ratio);
	sfRectangleShape_setFillColor(rec, color);
}

int set_hud_opacity(bucket_t *bucket, game_t *game)
{
	obj_t *obj = bucket->value;

	if (!obj)
		return (84);
	if (!obj->obj)
		return (84);
	if (game->movement.is_moving)
		increment_opacity(obj->obj, -1);
	else
		increment_opacity(obj->obj, 1);
	return (0);
}

int manage_hud_opacity(game_t *game)
{
	scene_t *health = hm_get(SCENES, "HEALTH_HUD");
	scene_t *game_hud = hm_get(SCENES, "GAME");

	if (check_undefined_scene((bucket_t *)health, "HEALTH_HUD") != 0)
		return (84);
	if (check_undefined_scene((bucket_t *)game_hud, "GAME") != 0)
		return (84);
	if (read_hashmap(NULL, game, game_hud->objs, &set_hud_opacity) != 0)
		return (84);
	if (read_hashmap(NULL, game, health->objs, &set_hud_opacity) != 0)
		return (84);
	return (0);
}