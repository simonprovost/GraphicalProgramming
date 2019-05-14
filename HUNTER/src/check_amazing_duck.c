/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void func_run_or_dont_touch(b_t *var, s_t *s, d_t *d, v_t *v)
{
	char *assets = "resources/s.png";

	if (var->check_duck == 1) {
		sfMusic_play(var->duck);
		sfMusic_play(var->gun);
	}
	else if (var->check_duck == -1){
		sfMusic_play(var->wings);
		sfMusic_play(var->gun);
		var->t.duck = sfTexture_createFromFile(assets, NULL);
		sfSprite_setTexture(s->duck_sprite, var->t.duck, sfTrue);
		v->pos_duck.x = my_rand(v->pos_duck.x, v->pos_duck.x + 100);
		v->pos_duck.y = my_rand(0, 300);
		sfSprite_setPosition(s->duck_sprite, v->pos_duck);
		var->check_duck = 0;
		var->click += 1;
		var->variant += 0.1;
		check_if_win(var, d);
	}
}

void duck_pos_sprite_texture(s_t *s, v_t *v, b_t *var)
{
	sfSprite_setPosition(s->duck_sprite, v->pos_duck);
	var->t.duck = sfTexture_createFromFile("resources/s_duck.png", NULL);
	sfSprite_setTexture(s->duck_sprite, var->t.duck, sfTrue);
	var->check_duck = 0;
}

void check_my_amazing_duck(b_t *var, d_t *d, s_t *s, v_t *v)
{
	func_run_or_dont_touch(var, s, d, v);
	if (var->check_duck == 1) {
		if (v->pos_duck.y >= 303) {
			v->pos_duck.y = my_rand(0, 403);
			var->click += 1;
		} else {
			v->pos_duck.x = -120.0;
			v->pos_duck.y = my_rand(0, 403);
			var->variant += 0.2;
			var->stock_ball -= 1;
			var->click += 1;
			check_if_win(var, d);
		}
		duck_pos_sprite_texture(s, v, var);
	}
}
