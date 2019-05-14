/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "rpg.h"

void update_text(scene_t *tmp_value, bucket_t *bucket_texts)
{
	if (tmp_value->music.play_music == sfFalse) {
		tmp_value->music.play_music = sfTrue;
		sfMusic_play(tmp_value->music.music);
		sfText_setString(bucket_texts->value, "ON");
	} else {
		sfMusic_stop(tmp_value->music.music);
		tmp_value->music.play_music = sfFalse;
		sfText_setString(bucket_texts->value, "OFF");
	}
}

int manage_song(window_t *window, game_t *game)
{
	bucket_t *tmp_scene = hm_get_bucket(SCENES, "GAME");
	bucket_t *bucket_scene = hm_get_bucket(SCENES, OPTION_GAME);
	bucket_t *bucket_texts = NULL;
	scene_t *tmp_value = NULL;
	scene_t *curr_scene = NULL;

	if (check_unexisting_scene(tmp_scene, "GAME") != 0 || !tmp_scene->value
	|| check_unexisting_scene(bucket_scene, OPTION_GAME) != 0
	|| !bucket_scene->value)
		return (84);
	tmp_value = tmp_scene->value;
	curr_scene = bucket_scene->value;
	bucket_texts = hm_get_bucket(curr_scene->texts, "OFFON");
	if (check_unexisting_text(bucket_texts, "OFF/ON", OPTION_GAME) != 0)
		return (84);
	update_text(tmp_value, bucket_texts);
	(void)window;
	return (0);
}
