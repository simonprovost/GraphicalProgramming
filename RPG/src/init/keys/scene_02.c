/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_music(char **infos, char **type, hashmap_t **current_list,
	game_t *game)
{
	scene_t *current_scene;
	char **loop = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);

	(void)current_list;
	if (!loop || check_undefined_scene(CURRENT_BUCKET, infos[0]) != 0)
		return (84);
	current_scene = CURRENT_BUCKET->value;
	if (check_already_existing_music(current_scene->music.music,
		type[1]) != 0)
		return (84);
	current_scene->music.music = hm_get(AUDIO_LIB, type[1]);
	if (check_unexisting_music(current_scene->music.music, type[1]) != 0)
		return (84);
	current_scene->music.loop = my_getnbr(loop[1]);
	current_scene->music.play_music = 1;
	my_destroy_tab(loop);
	return (0);
}
