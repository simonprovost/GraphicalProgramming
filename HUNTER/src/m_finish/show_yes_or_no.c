/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void show_yes_or_no(sfRenderWindow *w, f_s_t *s, f_t_t *t)
{
	if (t->a == 1)
		sfRenderWindow_drawSprite(w, s->sprite_yes, NULL);
	else if (t->a == 0)
		sfRenderWindow_drawSprite(w, s->sprite_no, NULL);
}
