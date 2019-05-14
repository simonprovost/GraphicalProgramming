/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void display_window_finish_w(sfRenderWindow *w, b_t *var, fw_s_t *s, fw_t_t *t)
{
	char time_calcul[50];
	char result[50];

	my_itoa(var->click, result);
	sfText_setString(t->stock_result, result);
	my_itoa(var->seconds_s_z, time_calcul);
	sfText_setString(t->time_since_begin, time_calcul);
	draw_next_win(w, s, t);
	show_yes_or_no_win(w, s, t);
	sfRenderWindow_display(w);
}
