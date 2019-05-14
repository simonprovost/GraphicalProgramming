/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_begin_text(b_t_t *t)
{
	t->text = sfText_create();
	t->option_normal = sfText_create();
	t->option_survival = sfText_create();
}
