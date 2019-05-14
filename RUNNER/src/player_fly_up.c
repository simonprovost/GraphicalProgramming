/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

void player_fly_up(public_class_t *all, int check)
{
	const char *mouse_fly = "ressources/mouse_fly_fire.png";

	if (sfKeyboard_isKeyPressed(sfKeyUp) && check == 1 &&
	    sfKeyboard_isKeyPressed(sfKeyDown) == sfFalse
	    && all->my_pers[0]->my_pos.y >= -5 && check == 1) {
		if (all->my_pers[0]->my_texture != NULL)
			sfTexture_destroy(all->my_pers[0]->my_texture);
		all->my_pers[0]->my_texture = sfTexture_createFromFile(
			mouse_fly, NULL);
		sfSprite_setTexture(all->my_pers[0]->my_sprite,
				    all->my_pers[0]->my_texture, sfTrue);
		all->my_pers[0]->my_pos.x += all->player->speed_x;
		all->my_pers[0]->my_pos.y -= all->player->speed_reactor_up;
		sfSprite_setPosition(all->my_pers[0]->my_sprite,
				     all->my_pers[0]->my_pos);
		sfRenderWindow_drawSprite(all->csfml_object->window,
					  all->my_pers[0]->my_sprite, NULL);
		all->my_pers[0]->my_pos.x += 1;
	}
}