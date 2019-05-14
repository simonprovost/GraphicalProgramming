/*
** EPITECH PROJECT, 2017
** my_runner
** File description:
** null
*/

#include "my_runner.h"

game_object_t **collider_box(game_object_t **my_pers)
{
	usleep(20000);
	my_pers[0]->my_pos.x -= 100;
	sfSprite_setPosition(my_pers[0]->my_sprite, my_pers[0]->my_pos);
	return (my_pers);
}
