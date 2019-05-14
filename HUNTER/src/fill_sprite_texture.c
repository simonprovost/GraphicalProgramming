/*
** EPITECH PROJECT, 2017
** My_hunter
** File description:
** null
*/

#include "my_h.h"

void fill_sprite_texture(s_t *s, b_t *var)
{
	char *assets = "resources/backg.png";

	var->t.duck = sfTexture_createFromFile("resources/fail.png", NULL);
	var->t.sight = sfTexture_createFromFile("resources/sight.png", NULL);
	var->t.my_background = sfTexture_createFromFile(assets, NULL);
	sfSprite_setTexture(s->duck_sprite, var->t.duck, sfTrue);
	sfSprite_setTexture(s->sight_gun, var->t.sight, sfTrue);
	sfSprite_setTexture(s->background, var->t.my_background, sfTrue);
	sfSprite_setScale(s->sight_gun, (sfVector2f){0.1, 0.1});
}
