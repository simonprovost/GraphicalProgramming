/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void display_window_finish_over(sfRenderWindow *w, f_t_t *t, f_s_t *s, b_t *v)
{
	char time_calcul[50];
	char count[10];
	char result[50];

	my_itoa(v->click, result);
	sfText_setString(t->stock_result, result);
	my_itoa(v->seconds_s_z, time_calcul);
	sfText_setString(t->time_since_begin, time_calcul);
	my_itoa(v->stock_ball, count);
	sfText_setString(t->remains_count, count);
	draw_next(w, s, t);
	show_yes_or_no(w, s, t);
	sfRenderWindow_display(w);
}
