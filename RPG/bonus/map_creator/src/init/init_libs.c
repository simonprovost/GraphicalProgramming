/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "map_editor.h"

int init_textures_lib(my_w_t *window)
{
	const key_word_t texture_keys[] = {{"TEXTURE", 0, &get_a_texture,
	NULL}, {"FILEPATH", 0, &get_a_texture_filepath, NULL},
	{"PRIORITY", 0, &get_a_priority, NULL},
	{"ANIMATED", 0, &get_an_animated, NULL},
	{"RECT_VALUES", 4, &get_a_rect_values,
		(char *[]) {"LEFT", "TOP", "WIDTH", "HEIGHT", NULL}},
	{"RECT_START", 2, &get_a_rect_start_values,
	(char *[]) {"X", "Y", NULL}},
	{"RECT_MAX", 2, &get_a_rect_max_values, (char *[]) {"X", "Y", NULL}},
	{"RECT_OFFSET", 2, &get_a_rect_max_offset, (char *[]) {"X", "Y", NULL}},
	{NULL, 0, NULL, NULL}};
	get_infos_t infos = {"pcf/textures.pcf", INIT_INDICATOR, texture_keys,
	&list_savior};

	window->textures_lib = hm_create(512, &texture_destroy);
	if (analyse_my_project_config_file(window, &infos) != 0) {
		my_printf("WARNING: ERROR IN TEXTURES LIB INIT !\n");
		return (84);
	}
	return (0);
}
