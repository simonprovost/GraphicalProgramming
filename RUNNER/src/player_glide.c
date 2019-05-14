/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void player_glide(public_class_t *all, int check)
{
	const char *mouse_fly = "ressources/mouse_fly.png";

	if (sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse
	    && all->my_pers[0]->my_pos.y <= 460
	    && sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse && check == 1) {
		if (all->my_pers[0]->my_texture != NULL)
			sfTexture_destroy(all->my_pers[0]->my_texture);
		all->my_pers[0]->my_texture =
			sfTexture_createFromFile(mouse_fly, NULL);
		sfSprite_setTexture(all->my_pers[0]->my_sprite,
				    all->my_pers[0]->my_texture, sfTrue);
	}
	all->my_pers[0]->my_pos.x += 1;
}