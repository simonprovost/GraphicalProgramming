/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void move_rect(sfIntRect *rect, b_t *var)
{
	rect->top = 0;
	rect->left = var->offset;
	rect->width = 110;
	rect->height = 110;
}
