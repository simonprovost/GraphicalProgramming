/*
** EPITECH PROJECT, 2017
** delivery
** File description:
** delivery made by Sanchez Lucas
*/

#include "map_editor.h"

sfRenderWindow *my_window_create(void)
{
	sfRenderWindow *window;
	sfVideoMode mode;

	mode.width = 1760;
	mode.height = 990;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "Map Editor By Lucas Sanchez",
							sfClose, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}

void main_loop(ressources_t *rsces, texture_list_t *list)
{
	sfEvent event;
	sfClock *my_clock = sfClock_create();

	while (sfRenderWindow_isOpen(rsces->window)) {
		sfRenderWindow_clear(rsces->window, sfWhite);
		display_map(rsces->rsces);
		draw_texture_list(list, rsces->window);
		while (sfRenderWindow_pollEvent(rsces->window, &event))
			on_event(rsces, list, event, my_clock);
		sfRenderWindow_display(rsces->window);
	}
}

int main(int ac, char **av)
{
	ressources_t rsces;
	my_w_t window;
	texture_list_t *list;

	rsces.window = my_window_create();
	rsces.mode = 0;
	window = init_ressource_window(rsces.window);
	list = read_hashmap_texture(window.textures_lib);
	if (ac != 4)
		return (84);
	if (!seek_zone(&window, av[1])) {
		my_printf("Zone Pas Encore Créée\n");
		return (84);
	}
	load_my_zone(&window);
	window.map.area_coord = V2I(my_getnbr(av[2]), my_getnbr(av[3]));
	rsces.rsces = &window;
	main_loop(&rsces, list);
	return (0);
}
