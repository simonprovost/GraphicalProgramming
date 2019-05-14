/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int get_an_area(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	char **enc = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **x = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (!enc || !x || !y || !current_list)
		return (84);
	AREA_ENCOUTER = my_getnbr(enc[1]);
	AREA_COOR_X = my_getnbr(x[1]);
	AREA_COOR_Y = my_getnbr(y[1]);
	if (check_invalid_area_coords(type[1], window) != 0)
		return (84);
	if (check_already_existing_area_coords(type[1], window) != 0)
		return (84);
	if (check_already_existing_area_name(type[1], window) != 0)
		return (84);
	AREA_NAME = my_strdup(type[1]);
	my_destroy_tab(enc);
	my_destroy_tab(x);
	my_destroy_tab(y);
	return (0);
}

int get_a_tile(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	char **block = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **x = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (!block || !x || !y || !current_list)
		return (84);
	TILE_COOR_X = my_getnbr(x[1]);
	TILE_COOR_Y = my_getnbr(y[1]);
	TILE_BLOCK = my_getnbr(block[1]);
	if (check_undefined_area(window) != 0)
		return (84);
	if (check_invalid_tile_coords(type[1], window) != 0)
		return (84);
	if (check_already_existing_tile_coords(window) != 0)
		return (84);
	my_destroy_tab(block);
	my_destroy_tab(x);
	my_destroy_tab(y);
	return (0);
}

int get_a_tile_texture(char **infos, char **type,
	hashmap_t **current_list, my_w_t *window)
{
	if (!current_list)
		return (84);
	if (check_undefined_tile(window) != 0)
		return (84);
	if (add_tile_to_list(type[1], window) != 0)
		return (84);
	(void)infos;
	return (0);
}
