/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_map(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	char **path = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **x = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (!path || !x || !y || !current_list)
		return (84);
	ZONE_COOR_X = my_getnbr(x[1]);
	ZONE_COOR_Y = my_getnbr(y[1]);
	if (check_invalid_zone_coords(type[1], game) != 0)
		return (84);
	if (check_already_existing_zone_coords(type[1], game) != 0)
		return (84);
	if (check_already_existing_zone_name(type[1], game) != 0)
		return (84);
	ZONE_NAME = my_strdup(type[1]);
	ZONE_FILEPATH = my_strdup(path[1]);
	my_destroy_tab(path);
	my_destroy_tab(x);
	my_destroy_tab(y);
	return (0);
}
