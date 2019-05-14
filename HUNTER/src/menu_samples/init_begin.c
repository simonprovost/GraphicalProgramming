/*
** EPITECH PROJECT, 2017
** my_hunter_2017
** File description:
** null
*/

#include "my_h.h"

void init_begin(b_s_t *s, b_t_t *t, b_tt_t *tt)
{
	sfText_setString(t->option_normal, "Normal game");
	sfText_setString(t->option_survival, "Survival game");
	sfText_setCharacterSize(t->option_survival, 14);
	sfText_setCharacterSize(t->option_normal, 14);
	sfText_setPosition(t->option_normal, (sfVector2f){500, 510});
	sfText_setPosition(t->option_survival, (sfVector2f){650, 510});
	sfSprite_setTexture(s->sprite_top_arrow, tt->arrow_top, sfTrue);
	sfSprite_setTexture(s->sprite_bottom_arrow, tt->arrow_b, sfTrue);
	sfSprite_setScale(s->sprite_top_arrow, (sfVector2f){0.1, 0.1});
	sfSprite_setPosition(s->sprite_top_arrow, (sfVector2f){630, 220});
	sfSprite_setScale(s->sprite_bottom_arrow, (sfVector2f){0.1, 0.1});
	sfSprite_setPosition(s->sprite_bottom_arrow, (sfVector2f){470, 220});
	sfSprite_setTexture(s->background, tt->my_backg, sfTrue);
	sfSprite_setScale(s->background, (sfVector2f){0.42, 0.56});
}
