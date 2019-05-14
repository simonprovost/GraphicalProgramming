/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

void set_area_values(char *encounter, char *x, char *y, game_t *game)
{
	AREA_COOR_X = my_getnbr(x);
	AREA_COOR_Y = my_getnbr(y);
	AREA_ENCOUNTER = my_getnbr(encounter);
	for (int y = 0; y != TILE_TAB_Y; y++)
		for (int x = 0; x != TILE_TAB_X; x++)
			AREA.tiles[y][x].displayed_tiles = NULL;
}

int get_area(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	char **enc = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **x = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (!enc || !x || !y || !current_list)
		return (84);
	set_area_values(enc[1], x[1], y[1], game);
	if (check_already_existing_area_coords(type[1], game) != 0)
		return (84);
	if (check_already_existing_area_name(type[1], game) != 0)
		return (84);
	AREA_NAME = my_strdup(type[1]);
	if (!AREA_NAME)
		return (84);
	if (check_invalid_area_coords(type[1], game) != 0)
		return (84);
	my_destroy_tab(enc);
	my_destroy_tab(x);
	my_destroy_tab(y);
	return (0);
}

int get_tile(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	char **block = my_str_to_word_array(infos[1], KEYWORD_SEPARATOR_CHAR);
	char **x = my_str_to_word_array(infos[2], KEYWORD_SEPARATOR_CHAR);
	char **y = my_str_to_word_array(infos[3], KEYWORD_SEPARATOR_CHAR);

	if (!block || !x || !y || !current_list)
		return (84);
	TILE_COOR_X = my_getnbr(x[1]);
	TILE_COOR_Y = my_getnbr(y[1]);
	TILE_BLOCK = my_getnbr(block[1]);
	if (check_undefined_area(game) != 0)
		return (84);
	if (check_invalid_tile_coords(type[1], game) != 0)
		return (84);
	if (check_already_existing_tile_coords(game) != 0)
		return (84);
	my_destroy_tab(block);
	my_destroy_tab(x);
	my_destroy_tab(y);
	return (0);
}

int get_tile_texture(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	if (!current_list)
		return (84);
	if (check_undefined_tile(game) != 0)
		return (84);
	if (add_tile_to_list(type[1], game) != 0)
		return (84);
	(void)infos;
	return (0);
}
