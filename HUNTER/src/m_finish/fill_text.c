/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void fill_text(f_t_t *t)
{
	t->text = sfText_create();
	t->time_since_begin = sfText_create();
	t->my_time = sfText_create();
	t->stock_result = sfText_create();
	t->count_kill = sfText_create();
	t->info = sfText_create();
	t->remains = sfText_create();
	t->remains_count = sfText_create();
	t->info_2 = sfText_create();
	t->a = 0.0;
}
