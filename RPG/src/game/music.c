/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** music.c
*/

#include "rpg.h"

int make_sound(char *sound_name, game_t *game)
{
	sfMusic *sound = hm_get(AUDIO_LIB, sound_name);

	if (!sound)
		return (84);
	sfMusic_play(sound);
	return (0);
}