/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void display_window_begin(sfRenderWindow *w, int a, b_t_t *text, b_s_t *sprite)
{
	static int check_top = 0;

	sfRenderWindow_drawSprite(w, sprite->background, NULL);
	if (a == 1) {
		sfRenderWindow_drawSprite(w, sprite->sprite_top_arrow, NULL);
		if (check_top == 1) {
			sfMusic_play(sprite->bip);
			check_top = 0;
		}
	} else {
		sfRenderWindow_drawSprite(w, sprite->sprite_bottom_arrow, NULL);
		if (check_top == 0) {
			sfMusic_play(sprite->bip);
			check_top = 1;
		}
	}
	sfRenderWindow_drawText(w, text->option_survival, NULL);
	sfRenderWindow_drawText(w, text->option_normal, NULL);
	sfRenderWindow_display(w);
}
