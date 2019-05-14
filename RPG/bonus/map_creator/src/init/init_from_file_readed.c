/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int init_from_pcf(char **infos, my_w_t *window, const key_word_t *keys)
{
	char **type = my_str_to_word_array(infos[0], '=');
	static hashmap_t *current_list;
	unsigned int i = 0;

	for (; keys[i].key_word; i++) {
		if (my_fastcmp(keys[i].key_word, type[0]) == 0
		&& check_missing_or_invalid_sub_keyword(keys, i, infos) != 0)
			return (84);
		if (my_fastcmp(keys[i].key_word, type[0]) == 0) {
			window->error_no = keys[i].fptr(infos, type,
				&current_list, window);
			break;
		}
	}
	if (check_invalid_key_word(keys[i].key_word, type, infos,
		window->error_no) != 0)
		return (84);
	return (0);
}
