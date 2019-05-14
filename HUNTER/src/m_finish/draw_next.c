/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void draw_next(sfRenderWindow *w, f_s_t *s, f_t_t *t)
{
	sfRenderWindow_clear(w, sfBlack);
	sfRenderWindow_drawSprite(w, s->background, NULL);
	sfRenderWindow_drawText(w, t->text, NULL);
	sfRenderWindow_drawText(w, t->info, NULL);
	sfRenderWindow_drawText(w, t->info_2, NULL);
	sfRenderWindow_drawText(w, t->count_kill, NULL);
	sfRenderWindow_drawText(w, t->stock_result, NULL);
	sfRenderWindow_drawText(w, t->my_time, NULL);
	sfRenderWindow_drawText(w, t->time_since_begin, NULL);
	sfRenderWindow_drawText(w, t->remains, NULL);
	sfRenderWindow_drawText(w, t->remains_count, NULL);
}
