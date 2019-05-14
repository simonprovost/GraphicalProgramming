/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

char *found_icon(game_t *game)
{
	char *icon_tab[4][2] = {
	{"Avelus", "AVELUS_ICON"},
	{"Varyan", "VARYAN_ICON"},
	{"Jaina", "JAINA_ICON"},
	{NULL, NULL}};

	if (!game)
		return (NULL);
	for (int i = 0; icon_tab[i][1] != NULL; i++) {
		if (my_strcmp(icon_tab[i][0], PLAYER_NAME) == 0)
			return (icon_tab[i][1]);
	}
	return (NULL);
}

int update_element(game_t *game)
{
	scene_t *curr_scene = hm_get(SCENES, "HEALTH_HUD");
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

int launch_game(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
	if (check_unexisting_scene(CURRENT_BUCKET, "GAME") != 0)
		return (84);
	if (update_element(game) != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, "GAME") != 0)
		return (84);
	if (add_scene_to_display_list(
		hm_get_bucket(SCENES, "HEALTH_HUD"), game) != 0)
		return (84);
	if (add_scene_to_display_list(
		hm_get_bucket(SCENES, "AREA_HUD"), game) != 0)
		return (84);
	(void)window;
	return (1);
}

int resume(window_t *window, game_t *game)
{
	if (!window || !game)
		return (84);
	CURRENT_BUCKET = hm_get_bucket(SCENES, "GAME");
	if (check_unexisting_scene(CURRENT_BUCKET, "GAME") != 0)
		return (84);
	clean_displayed_scene_name(game, PAUSE_GAME);
	(void)window;
	return (1);
}
