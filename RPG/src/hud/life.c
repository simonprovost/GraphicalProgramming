/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** manage_life
*/

#include "rpg.h"

int manage_xp_in_game(game_t *game, char *scene)
{
	float ratios;
	scene_t *health_hud = hm_get(SCENES, scene);
	obj_t *obj = NULL;

	if (check_unexisting_scene((bucket_t *)health_hud, scene) != 0)
		return (84);
	obj = hm_get(health_hud->objs, "XP_BAR");
	if (check_unexisting_obj((bucket_t *)obj,
	"XP_BAR", scene) != 0)
		return (84);
	ratios = (float)PLAYER_XP /
		(float)PLAYER_MAX_XP * 100.0;
	obj->obj_rect.rect.width = MIN(ratios, 100);
	obj->obj_rect.rect.width = MAX(obj->obj_rect.rect.width, 0);
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
	sfRectangleShape_setSize(obj->obj,
	V2F(obj->obj_rect.rect.width, obj->obj_rect.rect.height));
	return (0);
}

int manage_life_in_game(game_t *game, char *scene)
{
	float ratios;
	scene_t *health_hud = hm_get(SCENES, scene);
	obj_t *obj = NULL;

	if (check_unexisting_scene((bucket_t *)health_hud, scene) != 0)
		return (84);
	obj = hm_get(health_hud->objs, "HEALTH_BAR");
	if (check_unexisting_obj((bucket_t *)obj,
	"HEALTH_BAR", scene) != 0)
		return (84);
	if (PLAYER_MAX_HP <= 0)
		return (0);
	ratios = (float)PLAYER_HEALTH /
		(float)PLAYER_MAX_HP * 100.0;
	obj->obj_rect.rect.width = MIN(ratios, 100);
	obj->obj_rect.rect.width = MAX(obj->obj_rect.rect.width, 0);
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
	sfRectangleShape_setSize(obj->obj,
	V2F(obj->obj_rect.rect.width, obj->obj_rect.rect.height));
	return (0);
}

int manage_life(game_t *game)
{
	if (!my_strcmp(CURRENT_BUCKET->key, "BATTLE")) {
		if (manage_life_in_game(game, "BATTLE") == 84)
			return (84);
		else if (manage_xp_in_game(game, "BATTLE") == 84)
			return (84);
	} else {
		if (manage_life_in_game(game, "HEALTH_HUD") == 84)
			return (84);
		else if (manage_xp_in_game(game, "HEALTH_HUD") == 84)
			return (84);
	}
	return (0);
}