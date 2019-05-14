/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** (enter)
*/

#include "my.h"
#include "rpg.h"

int display_texts(bucket_t *text, window_t *window)
{
	sfText *display = text->value;

	sfRenderWindow_drawText(window->window, display, NULL);
	return (0);
}
