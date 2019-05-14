/*
** EPITECH PROJECT, 2018
** NULL
** File description:
** NULL
*/

#include "rpg.h"

void replace_key(int choice, game_t *game)
{
	if (choice == 0) {
		KEY_PLAYER.up = sfKeyZ;
		KEY_PLAYER.down = sfKeyS;
		KEY_PLAYER.left = sfKeyQ;
		KEY_PLAYER.right = sfKeyD;
	} else {
		KEY_PLAYER.up = sfKeyW;
		KEY_PLAYER.down = sfKeyS;
		KEY_PLAYER.left = sfKeyA;
		KEY_PLAYER.right = sfKeyD;
	}
}

int key_french(window_t *window, game_t *game)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene || !bucket_scene->value)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "FRENCH");
	replace_key(0, game);
	(void)window;
	return (0);
}

int key_english(window_t *window, game_t *game)
{
	bucket_t *bucket_scene = hm_get_bucket(SCENES, CONTROL_KEY);
	bucket_t *bucket_texts = NULL;
	scene_t *curr_scene = NULL;

	if (!bucket_scene || !bucket_scene->value)
		return (84);
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "USER_KEY");
	sfText_setString(bucket_texts->value, "ENGLISH");
	replace_key(1, game);
	(void)window;
	return (0);
}