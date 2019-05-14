/*
** EPITECH PROJECT, 2017
** my_cook_2017
** File description:
** (enter)
*/

#include "map_editor.h"

void init_window_values(my_w_t *window)
{
	window->error_no = 0;
	MOUSE_POS = (sfVector2i){0, 0};
	window->displayed_scenes = NULL;
}

my_w_t init_ressource_window(sfRenderWindow *my_window)
{
	my_w_t window;

	init_window_values(&window);
	window.window = my_window;
	if (init_textures_lib(&window) != 0 || init_map(&window) != 0) {
		window.error_no = 84;
		return (window);
	}
	return (window);
}
