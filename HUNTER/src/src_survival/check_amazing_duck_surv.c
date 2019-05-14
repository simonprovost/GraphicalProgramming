/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void func_run_or_dont_touch_surv(b_t *var, s_t *s, d_t *d, v_t *v)
{
	if (var->check_duck == 1) {
		sfMusic_play(var->duck);
		sfMusic_play(var->gun);
		var->t.duck = sfTexture_createFromFile("resources/s.png", NULL);
		sfSprite_setTexture(s->duck_sprite, var->t.duck, sfTrue);
		v->pos_duck.x = my_rand(v->pos_duck.x, v->pos_duck.x + 150);
		v->pos_duck.y = my_rand(0, 150);
		sfSprite_setPosition(s->duck_sprite, v->pos_duck);
		var->check_duck = 0;
		var->click += 1;
		var->stock_ball -= 1;
		var->variant += 0.09;
		check_if_win_surv(var, d, 1);
	}
	else if (var->check_duck == -1){
		check_if_win_surv(var, d, 0);
	}
}

void duck_pos_sprite_texture_surv(s_t *s, v_t *v, b_t *var)
{
	sfSprite_setPosition(s->duck_sprite, v->pos_duck);
	var->t.duck = sfTexture_createFromFile("resources/s_duck.png", NULL);
	sfSprite_setTexture(s->duck_sprite, var->t.duck, sfTrue);
	var->check_duck = 0;
}

void check_my_amazing_duck_surv(b_t *var, d_t *d, s_t *s, v_t *v)
{
	func_run_or_dont_touch_surv(var, s, d, v);
	if (var->check_duck == 1) {
		if (v->pos_duck.y >= 303) {
			v->pos_duck.y = my_rand(0, v->pos_duck.y);
			var->click += 1;
			var->stock_ball -= 1;
		}
		duck_pos_sprite_texture_surv(s, v, var);
	}
}
