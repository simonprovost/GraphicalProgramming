/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_texture(b_tt_t *texture)
{
	texture->arrow_top = sfTexture_createFromFile("resources/a.png", NULL);
	texture->arrow_b = sfTexture_createFromFile("resources/a.png", NULL);
	texture->my_backg = sfTexture_createFromFile("resources/b.png", NULL);
}
