/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void fill_object(b_t_t *t, sfFont *font)
{
	sfText_setFont(t->option_survival, font);
	sfText_setFont(t->option_normal, font);
}
