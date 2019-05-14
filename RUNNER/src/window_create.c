/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

sfRenderWindow	*my_window_create()
{
	sfRenderWindow	*window;
	sfVideoMode	mode;

	mode.width = 1200;
	mode.height = 800;
	mode.bitsPerPixel = 32;
	window = sfRenderWindow_create(mode, "My Runner", sfDefaultStyle, NULL);
	sfRenderWindow_setFramerateLimit(window, 30);
	return (window);
}