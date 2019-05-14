/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void player_fly_down(public_class_t *all, int check)
{
	const char *mouse_down_fire = "ressources/mouse_down_fire.png";

	if (sfKeyboard_isKeyPressed(sfKeyDown)
	    && check == 1
	    && sfKeyboard_isKeyPressed(sfKeyUp) == sfFalse
	    && all->my_pers[0]->my_pos.y < 460) {
		if (all->my_pers[0]->my_texture != NULL)
			sfTexture_destroy(all->my_pers[0]->my_texture);
		all->my_pers[0]->my_texture =
			sfTexture_createFromFile(mouse_down_fire, NULL);
		sfSprite_setTexture(all->my_pers[0]->my_sprite,
				    all->my_pers[0]->my_texture, sfTrue);
		all->my_pers[0]->my_pos.y += all->player->speed_reactor_down;
		sfSprite_setPosition(all->my_pers[0]->my_sprite,
				     all->my_pers[0]->my_pos);
		sfRenderWindow_drawSprite(all->csfml_object->window,
					  all->my_pers[0]->my_sprite, NULL);
	}
}