/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int get_font(char **infos, char **type,
	hashmap_t **current_list, game_t *game)
{
	sfFont *font;
	char **font_path = my_str_to_word_array(infos[1],
							KEYWORD_SEPARATOR_CHAR);

	*current_list = FONTS_LIB;
	font = hm_get(*current_list, type[1]);
	if (check_already_existing_font(font, type[1]) != 0)
		return (84);
	font = sfFont_createFromFile(font_path[1]);
	if (!font)
		return (84);
	hm_add(FONTS_LIB, type[1], font);
	my_destroy_tab(font_path);
	return (0);
}
