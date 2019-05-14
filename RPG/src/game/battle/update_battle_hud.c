/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** update_battle_hud
*/

#include "my.h"
#include "rpg.h"

int update_element_in_battle(game_t *game)
{
	scene_t *curr_scene = hm_get(SCENES, "BATTLE");
	obj_t *player_icon = NULL;
	bucket_t *check = NULL;
	sfTexture *new_texture;
	char *name_texture = found_icon(game);

	if (!curr_scene || !curr_scene->objs || !name_texture)
		return (84);
	check = hm_get(TEXTURES_LIB, name_texture);
	if (!check || !check->value)
		return (84);
	new_texture = check->value;
	player_icon = hm_get(curr_scene->objs, "STATS");
	if (!player_icon)
		return (84);
	sfRectangleShape_setTexture(player_icon->obj, new_texture, sfTrue);
	return (0);
}