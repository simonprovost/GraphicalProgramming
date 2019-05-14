/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"
#include "my.h"

int frame_rate_more(window_t *window, game_t *game)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (check_unexisting_scene(bucket_scene, OPTION_GAME) != 0
	|| !bucket_scene->value)
		return (84);
	scene_option = bucket_scene->value;
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (check_unexisting_text(text_bucket, "FRAME", OPTION_GAME) != 0)
		return (84);
	if ((FRAMERATE += 10) >= 120)
		FRAMERATE = 120;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(FRAMERATE));
	sfRenderWindow_setFramerateLimit(window->window,
	FRAMERATE);
	return (0);
}

int frame_rate_less(window_t *window, game_t *game)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
	scene_t *scene_option = NULL;
	bucket_t *text_bucket = NULL;

	if (check_unexisting_scene(bucket_scene, OPTION_GAME) != 0
	|| !bucket_scene->value)
		return (84);
	scene_option = bucket_scene->value;
	text_bucket = hm_get_bucket(scene_option->texts, "FRAME");
	if (check_unexisting_text(text_bucket, "FRAME", OPTION_GAME) != 0)
		return (84);
	if ((FRAMERATE -= 10) <= 30)
		FRAMERATE = 30;
	sfText_setString(text_bucket->value,
	(char *)int_to_str(FRAMERATE));
	sfRenderWindow_setFramerateLimit(window->window,
	FRAMERATE);
	return (0);
}