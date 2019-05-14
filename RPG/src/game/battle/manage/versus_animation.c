/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int update_alpha_icon(sfRectangleShape *rec)
{
	static int offset = 1;
	static int check = 0;

	if (!rec)
		return (84);
	if (offset != 0 && offset < 255 && check == 0)
		offset += 1;
	else if (offset >= 254 || check == 1) {
		offset -= 1;
		check = 1;
	}
	if (offset < 1) {
		offset = 0;
		check = 0;
	}
	sfRectangleShape_setFillColor(rec, (sfColor){255, 255, 255, offset});
	return (0);
}

int manage_versus_animation(game_t *game)
{
	scene_t *battle_game = hm_get(SCENES, "BATTLE");
	obj_t *obj = NULL;
	sfRectangleShape *versus_icon = NULL;

	if (!battle_game || !game || !battle_game->objs)
		return (84);
	if (!(obj = hm_get(battle_game->objs, "VERSUS_ICO")))
		return (84);
	if (!(versus_icon = obj->obj))
		return (84);
	if (update_alpha_icon(versus_icon) != 0)
		return (84);
	return (0);
}