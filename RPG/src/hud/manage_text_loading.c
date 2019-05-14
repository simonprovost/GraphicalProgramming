/*
** EPITECH PROJECT, 2018
** null
** File description:
** null
*/

#include "my.h"
#include "rpg.h"

int manage_text(game_t *game, window_t *window, scene_t *s_load)
{
	sfText *next_zone = NULL;

	if (!game || !window || !s_load)
		return (84);
	next_zone = hm_get(s_load->texts, "NEXT_ZONE");
	if (check_unexisting_text((bucket_t *)next_zone,
	"NEXT_ZONE", S_LOAD) != 0)
		return (84);
	sfText_setString(next_zone, my_strcat("En route vers : ", ZONE_NAME));
	return (0);
}