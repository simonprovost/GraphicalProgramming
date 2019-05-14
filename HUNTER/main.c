/*
** EPITECH PROJECT, 2017
** null
** File description:
** null
*/

#include "my_h.h"

void fill_elem(b_t *var, d_t *d, v_t *v, s_t *s)
{
	fill_var(var);
	fill_divers(d);
	fill_vector(v);
	fill_sprite(s);
}

void fill_surv_game(b_t *var)
{
	if (var->check_begin == 1) {
		var->stock_ball = 12;
		var->music = sfMusic_createFromFile("resources/surv_game.ogg");
	}
}

void choice_game(b_t *var, s_t *s, v_t *v, d_t *d)
{
	if (var->check_begin == 0)
		normal_game(var, s, v, d);
	else if (var->check_begin == 1)
		survival_game(var, s, v, d);
}

int main(int argc, char *argv[])
{
	b_t var;
	s_t s;
	v_t v;
	d_t d;

	usage_func(argv, argc);
	if (argv[1] == NULL || argc == 999) {
		fill_elem(&var, &d, &v, &s);
		fill_sprite_texture(&s, &var);
		var.check_begin = menu_begin(d.window);
		fill_surv_game(&var);
		sfMusic_play(var.music);
		while (sfRenderWindow_isOpen(d.window))
			choice_game(&var, &s, &v, &d);
	}
	return (0);
}
