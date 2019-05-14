/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_sprite(b_s_t *sprite)
{
	sprite->sprite_top_arrow = sfSprite_create();
	sprite->sprite_bottom_arrow = sfSprite_create();
	sprite->background = sfSprite_create();
	sprite->bip = sfMusic_createFromFile("resources/bip.ogg");
}
