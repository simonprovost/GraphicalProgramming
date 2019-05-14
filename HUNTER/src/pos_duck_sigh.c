/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void position_cible(d_t *d, v_t *v, s_t *s)
{
	d->pos_mouse = sfMouse_getPosition((sfWindow*) d->window);
	v->tmp.x = d->pos_mouse.x;
	v->tmp.y = d->pos_mouse.y;
	sfSprite_setPosition(s->sight_gun, v->tmp);
}

void new_position_duck(v_t *v, b_t *var, float a, s_t *s)
{
	sfSprite_setPosition(s->duck_sprite, v->pos_duck);
	var->a = a;
	v->pos_duck.x += var->a;
	if (v->pos_duck.x >= 800)
		v->pos_duck.x *= -0.2;
}
