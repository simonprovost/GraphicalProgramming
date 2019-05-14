/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** area_hud
*/

#include "rpg.h"

int change_area_hud(game_t *game)
{
	scene_t *area = hm_get(SCENES, "AREA_HUD");
	sfText *pos_area;
	char *coor_x = int_to_str(AREA_COOR_X);
	char *coor_y = int_to_str(AREA_COOR_Y);
	char *cat_y = my_strcat(",", coor_y);
	char *pos = my_strcat(coor_x, cat_y);

	if (!area) {
		return (84);
	}
	pos_area = hm_get(area->texts, "POS");
	if (check_unexisting_text((bucket_t *)pos_area, "POS", "AREA_HUD") != 0)
		return (84);
	sfText_setString(pos_area, pos);
	free(coor_x);
	free(coor_y);
	free(cat_y);
	free(pos);
	return (0);
}