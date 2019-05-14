/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** level_up
*/

#include "rpg.h"

int change_icon_texture(game_t *game, scene_t *scene)
{
	obj_t *icon = hm_get(scene->objs, "SPECIALITY");
	texture_t *texture = NULL;

	if (!icon)
		return (84);
	if (!my_strcmp(PLAYER_SPECIALITY_NAME, "Wisdom")) {
		texture = hm_get(TEXTURES_LIB, "WISDOM_ICON");
		sfRectangleShape_setTexture(icon->obj,
		texture->texture, sfTrue);
	} else if (!my_strcmp(PLAYER_SPECIALITY_NAME, "Agility")) {
		texture = hm_get(TEXTURES_LIB, "AGILITY_ICON");
		sfRectangleShape_setTexture(icon->obj,
		texture->texture, sfTrue);
	}
	return (0);
}

int update_level(game_t *game, scene_t *scene)
{
	sfText *level = hm_get(scene->texts, "LVL");
	char *level_nb = int_to_str(PLAYER_LEVEL);

	if (!level || !level_nb)
		return (84);
	sfText_setString(level, my_strcat("LEVEL    ", level_nb));
	free(level_nb);
	return (0);
}

int update_characteristics(game_t *game, scene_t *scene)
{
	sfText *health = hm_get(scene->texts, "HEALTH");
	sfText *armor = hm_get(scene->texts, "ARMOR");
	sfText *speciality = hm_get(scene->texts, "SPECIALITY");
	sfText *attack = hm_get(scene->texts, "ATTACK");
	char *health_nb = int_to_str(PLAYER_MAX_HP / 5);
	char *armor_nb = int_to_str(PLAYER_ARMOR / 5);
	char *speciality_nb = int_to_str(PLAYER_SPECIALITY / 5);
	char *attack_nb = int_to_str(PLAYER_DAMAGES / 5);

	if (!health || !armor || !speciality || !attack
	|| !health_nb || !armor_nb || !speciality_nb || !attack_nb)
		return (84);
	sfText_setString(health, my_strcat(":  + ", health_nb));
	sfText_setString(armor, my_strcat(":  + ", armor_nb));
	sfText_setString(speciality, my_strcat(":  + ", speciality_nb));
	sfText_setString(attack, my_strcat(":  + ", attack_nb));
	free(health_nb);
	free(armor_nb);
	free(speciality_nb);
	return (0);
}

int process_level_up(game_t *game)
{
	scene_t *scene = hm_get(SCENES, "LEVEL_UP");

	if (!scene
	|| change_icon_texture(game, scene) == 84
	|| update_level(game, scene) == 84
	|| update_characteristics(game, scene) == 84)
		return (84);
	PLAYER_MAX_HP += PLAYER_MAX_HP / 5;
	PLAYER_ARMOR += PLAYER_ARMOR / 5;
	PLAYER_SPECIALITY += PLAYER_SPECIALITY / 5;
	PLAYER_DAMAGES += PLAYER_DAMAGES / 5;
	PLAYER_HEALTH = PLAYER_MAX_HP;
	return (0);
}

int add_xp_to_player(game_t *game, int xp)
{
	int rest = 0;

	if (!game)
		return (84);
	PLAYER_XP += xp;
	rest = PLAYER_XP - PLAYER_MAX_XP;
	for (; rest >= 0; rest = PLAYER_XP - PLAYER_MAX_XP) {
		PLAYER_LEVEL += 1;
		PLAYER_XP = rest;
		PLAYER_MAX_XP += PLAYER_MAX_XP / 5;
		clean_displayed_scene_name(game, "LEVEL_UP");
		add_scene_to_display_list(hm_get_bucket(SCENES, "LEVEL_UP"),
									game);
		make_sound("LEVEL_UP_SOUND", game);
		process_level_up(game);
	}
	return (0);
}