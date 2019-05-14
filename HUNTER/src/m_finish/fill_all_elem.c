/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void fill_all_elem_menu(f_s_t *s, f_tt_t *tt)
{
	sfSprite_setTexture(s->sprite_yes, tt->texture_yes, sfTrue);
	sfSprite_setTexture(s->sprite_no, tt->texture_no, sfTrue);
	sfSprite_setScale(s->sprite_no, (sfVector2f){0.5, 0.5});
	sfSprite_setScale(s->sprite_yes, (sfVector2f){0.5, 0.5});
	sfSprite_setPosition(s->sprite_no, (sfVector2f){500, 300});
	sfSprite_setPosition(s->sprite_yes, (sfVector2f){500, 300});
	sfSprite_setTexture(s->background, tt->my_background, sfTrue);
	sfSprite_setScale(s->background, (sfVector2f){0.42, 0.56});
}
