/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int getudio(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	sfMusic *audio;
	char **audio_path = my_str_to_word_array(infos[1],
							KEYWORD_SEPARATOR_CHAR);

	*current_list = AUDIO_LIB;
	audio = hm_get(*current_list, type[1]);
	if (check_already_existing_audio(audio, type[1]) != 0)
		return (84);
	audio = sfMusic_createFromFile(audio_path[1]);
	if (!audio)
		return (84);
	hm_add(AUDIO_LIB, type[1], audio);
	my_destroy_tab(audio_path);
	return (0);
}
