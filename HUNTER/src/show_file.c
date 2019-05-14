/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void show_new_window(d_t *d, s_t *s)
{
	sfSprite_setTextureRect(s->duck_sprite, d->rect);
	sfRenderWindow_setMouseCursorVisible(d->window, sfFalse);
	sfRenderWindow_clear(d->window, sfBlack);
	sfRenderWindow_drawSprite(d->window, s->background, NULL);
}

void draw_display(d_t *d, s_t *s, b_t *var)
{
	char buffer[20];
	char buffer1[20];

	my_itoa(var->stock_ball, buffer);
	my_itoa(var->click, buffer1);
	sfText_setString(var->ammmount_ball, buffer1);
	sfText_setString(var->nb_click, buffer);
	sfRenderWindow_drawSprite(d->window, s->duck_sprite, NULL);
	sfRenderWindow_setVisible(d->window, sfTrue);
	sfRenderWindow_drawText(d->window, var->ammmount_ball, NULL);
	sfRenderWindow_drawText(d->window, var->nb_click, NULL);
	sfRenderWindow_drawSprite(d->window, s->sight_gun, NULL);
	sfRenderWindow_display(d->window);
}
