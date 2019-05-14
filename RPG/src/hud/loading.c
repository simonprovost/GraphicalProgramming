/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

static float offset = 0.0;

int open_scene(game_t *game, window_t *window, char *new_scene, int finished)
{
	bucket_t *hud = NULL;
	bucket_t *coord = NULL;

	CURRENT_BUCKET = hm_get_bucket(SCENES, new_scene);
	if (check_unexisting_scene(CURRENT_BUCKET, new_scene) != 0)
		return (84);
	if (clean_displayed_scenes_and_add_back(game, new_scene) != 0)
		return (84);
	if (finished == 1) {
		if ((!(hud = hm_get_bucket(SCENES, "HEALTH_HUD"))) ||
		(!(coord = hm_get_bucket(SCENES, "AREA_HUD"))))
			return (84);
		if (add_scene_to_display_list(hud, game) != 0)
			return (84);
		if (add_scene_to_display_list(coord, game) != 0)
			return (84);
	}
	(void)window;
	return (0);
}

int manage_ratios(int *finished, obj_t *obj)
{
	float ratios = 0.0;

	ratios = (float)offset / 100 * 100.0;
	obj->obj_rect.rect.width = MIN(ratios, 560);
	obj->obj_rect.rect.width = MAX(obj->obj_rect.rect.width, 0);
	sfRectangleShape_setTextureRect(obj->obj, obj->obj_rect.rect);
	sfRectangleShape_setSize(obj->obj,
	V2F(obj->obj_rect.rect.width, obj->obj_rect.rect.height));
	offset < 560 ? (offset += 10) : (offset = 0, *finished = 1);
	return (0);
}

int open_loading_scene(game_t *game, window_t *window)
{
	if (my_strcmp(CURRENT_BUCKET->key, S_LOAD) != 0)
		if (open_scene(game, window, S_LOAD, 0) != 0)
			return (84);
	return (0);
}

int manage_loading(game_t *game, window_t *window)
{
	scene_t *s_loading = hm_get(SCENES, S_LOAD);
	obj_t *obj = NULL;
	sfText *percent = NULL;
	int finished = 0;

	if (check_unexisting_scene((bucket_t *)s_loading, S_LOAD) != 0)
		return (84);
	if (open_loading_scene(game, window) != 0)
		return (84);
	obj = hm_get(s_loading->objs, "BAR_LOADING");
	percent = hm_get(s_loading->texts, "PERCENT");
	if (check_unexisting_obj((bucket_t *)obj, "BAR_LOADING", S_LOAD) != 0
	|| check_unexisting_text((bucket_t *)percent, "PERCENT", S_LOAD) != 0)
		return (84);
	if (manage_ratios(&finished, obj) != 0)
		return (84);
	if (finished == 1 || manage_text(game, window, s_loading) != 0)
		return (finished == 1 ? 1 : 84);
	sfText_setString(percent, my_strcat(int_to_str(offset / 5.6), " %"));
	return (0);
}

int manage_loading_scene(game_t *game, window_t *window, char *new_scene)
{
	int my_errno = 0;

	if (!game || !window || !CURRENT_BUCKET)
		return (84);
	if ((my_errno = manage_loading(game, window)) != 0) {
		game->loading = false;
		if (my_errno == 84)
			return (84);
		if (my_errno == 1 && (open_scene(game, window,
		new_scene, 1) != 0))
			return (84);
	}
	return (0);
}